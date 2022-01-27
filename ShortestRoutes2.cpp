// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;

void solve(){
   int n,m,q; cin >> n >> m>> q;
  vector<vector<int> >adj(n, vector<int>(n,1e18));

  for(int i =0 ; i<n ; i++){
    adj[i][i] = 0;
  }
   for(int i =0 ; i<m ; i++){
     int u,v,w; cin >> u >> v >> w;u--; v--; adj[u][v] = min(adj[u][v],w); adj[v][u] = min(adj[v][u],w);
   }

   for(int k =0 ; k<n ; k++){
     for(int i =0 ; i<n ; i++){
       for(int j =0 ; j<n ; j++){
             adj[i][j] = min(adj[i][j] , adj[i][k]+adj[k][j]);
             adj[j][i] = adj[i][j];
       }
     }
   }

   while(q--){
     int u,v; cin >> u>> v;cout << (adj[--u][--v]>1e16?-1:adj[u][v]) << '\n';
   }
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
