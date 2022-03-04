// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
struct port{
   int a,w; bool used;
};
 
void solve(){
   int n,m ; cin >> n >> m;

   vector<vector<pair<int,int> > >adj(n);
   for(int i =  0 ; i<m ; i++){
      int a,b,c; cin >> a >> b >> c; a-- ; b-- ; 
      adj[a].push_back({b,c});
   }
   auto cmp = [](port& p1 , port& p2 ){
        return p2.w < p1.w ;
   };
   priority_queue<port , vector<port> , decltype(cmp) >pq(cmp);
   pq.push({0 , 0 , false}); d[0] = {0,0};
   while(pq.size()){
      auto e = pq.top(); int a = e.a , w = e.w ; bool used = e.used;
      if(a == n-1){
         cout << w<< ' '; return;
      }
      pq.pop();
      for(auto&& [u,l]:adj[a]){
         pq.push({u , w + l , used});

          if(!used){
         pq.push({u , w+ l/2 , true});
         }
      }
   }
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin >> t; while(t--)
   solve();
}
