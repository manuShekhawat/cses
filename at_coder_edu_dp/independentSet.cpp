#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> indexed_set;
 
 
// Defines
#define int long long
#define nl cout << '\n'
#define FF first
#define SS second  
#define all(x) x.begin() , x.end()
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
// Constansts 
const int mod = 1e9+7;
const int inf = 1e18;
 
 
// Helpers
template<typename U,typename V>ostream& operator<<(ostream&os,pair<U,V>&p){nl;os<<p.FF<<' '<<p.SS;nl;return os;}
template<typename T>ostream& operator<<(ostream&os,vector<T>&p){nl;for(auto& e:p){os << e << ' ';}nl;return os;}
template<typename...  Args>void de(Args&&... args){((cout << args << ' '),...);}
 
template<typename U,typename V>istream& operator>>(istream&is,pair<U,V>&p){is>>p.FF>>p.SS;return is;}
template<typename T>istream& operator>>(istream&is,vector<T>& p){for(auto& e:p){is>>e;}return is;}
template<typename...  Args>void le(Args&&... args){((cin >> args),...);}
 
// CODE /////////////////////////////////////////////////////////////////////////////////////////////////////
vector<vector<int> >adj; 
vector<int>vis;
 
vector<vector<int> >dp;
 
void dfs(int u , int p){
  if(vis[u])return ;
  int kds = 0;
  vis[u] = true;;
  dp[u][0] = dp[u][1] = 1;
  for(auto e: adj[u]){
    if(e == p)continue; 
    
      dfs(e , u);
      dp[u][0] *= dp[e][1]; dp[u][0] %=mod;
      dp[u][1] *= (dp[e][0] + dp[e][1]); dp[u][1]%=mod;
    
  }
}
 
void solve(){
    int N ; cin >>N ; 
    
    adj.resize(N); dp.resize(N); fill(dp.begin() , dp.end() , vector<int>(2));
    vis.resize(N);  fill(vis.begin() , vis.end() , 0);
    for(int i = 0; i<N-1 ; i++){
      int u ,v; cin >> u >> v; u--; v--; adj[u].push_back(v); adj[v].push_back(u);
    }   
 
 
    /*
      What is the reccurence ? 
         dp(root , white ) = (dp(c1 | W) + dp(c1|B))*(dp(c2|W)+dp(c2|B))....
         dp(root , black)  =  dp(c1|W)*dp(c2|W)...
    */
 
   dfs(0 , -1);  
  // de(dp);
   cout << (dp[0][0]+dp[0][1])%mod << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) ;
    #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
 
  // int t; cin >> t; while(t--)
  solve();
}
