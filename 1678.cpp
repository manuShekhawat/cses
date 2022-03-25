// Слава матушке-России
 
// Мир в Україні
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
 
vector<int>vis;
vector<vector<int> >adj;
vector<int>cyc; 
bool f = false;
void dfs(int v , int par){
   if(f) return ;
   if(vis[v] == 1){
      if(cyc.size() > 0 && v == cyc[0]){f = true;cyc.push_back(v); return ;}
      cyc.push_back(v);
   }
 
   if(vis[v]==2)return ;
   vis[v] = 1;
   for(auto& e:adj[v]){
      dfs(e , v);
   }
   vis[v] = 2;
}
 
void solve(){
   int n,m ; cin >> n >> m;
   vis.resize(n); adj.resize(n); fill(vis.begin() , vis.end() , 0);
 
   for(int i =0 ; i<m ; i++){
      int a,b; cin>> a >> b ; a--; b--; adj[a].push_back(b);
   }
 
   for(int i =0 ; i<n ; i++){if(vis[i]==0 && cyc.size()==0)dfs(i , -1);}
   // reverse(cyc.begin() , cyc.end());
   if(cyc.size() == 0){
      cout << "IMPOSSIBLE"; return ;
   }
   cout << cyc.size() << '\n';
   for(auto& e:cyc)cout << e+1 << ' '; cout << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t; cin >> t; while(t--)
  solve();
}
