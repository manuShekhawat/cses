// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long

vector<vector<pair<int,int> > >adj;

struct node{
    vector<int>dis; int fld  = 0;

    node(int k){
      dis.resize(k)  ; fill(dis.begin() , dis.end() , 1e18);
    }
};

void solve(){
  int n,m, k ; cin >>  n >> m >> k;
  adj.resize(n);
  for(int i =0 ; i<m ; i++){
    int a,b,c; cin >> a >> b >> c; a--; b--; adj[a].push_back({b,c});
  }
  vector<node>vec(n , node(k));
  auto cmp = [](pair<int,int> n1 , pair<int,int> n2){
    return n1.first > n2.first;
  };

  priority_queue<pair<int,int> , vector<pair<int,int> > , decltype(cmp)>pq(cmp);

  pq.push({0  , 0});

  while(pq.size()){
    auto top = pq.top(); int u = top.second; int w = top.first; pq.pop(); 
    if(vec[u].fld == k){
         continue;
    }
    else{
       vec[u].dis[vec[u].fld++] = w; 
    }

    for(auto& e:adj[u]){
       pq.push({w + e.second  , e.first});
    }
    
  }

  for(auto& e:vec[n-1].dis){
    cout << e<< ' ';
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
