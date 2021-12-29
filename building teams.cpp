// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;
 
 
template<typename... T>
void debug(T&... args){
  cout << "\n==================\n";
  ((cout<< args<<", "), ...);
  cout << "\n==================\n";
}
template<typename T>
void debug(vector<T>& a){
  cout << "\n==============\n";
  for(auto& e:a)cout << e << ' ';
  cout << "\n==============\n";
}
 
template<typename... T>
void put(T&... args) { ((cout << args << " "), ...);}

bool f = true;

void dfs(int i , vector<int>& t, int sw , vector<vector<int> >& adj){
     if(t[i]>0)return ;

     t[i] = sw;
     for(auto& e:adj[i]){
       dfs(e,t,3-sw,adj);
     }
}

void dfs2(int i , vector<int>& t , int sw , vector<vector<int>>& adj , vector<bool>& vis){
  if(vis[i])return ;
  vis[i] = true;
  for(auto& e:adj[i]){
    if(t[e]==sw){
      f = false;
    }
    dfs2(e,t,3-sw,adj , vis);
  }
}

void solve(){
  int n,m; cin >> n >> m;

  vector<vector<int> >adj(n);
  vector<pair<int,int> >frnd;
  for(int i =0 ;i<m ; i++){
    int a,b; cin >> a >> b; a--; b--;adj[a].push_back(b); adj[b].push_back(a);
    frnd.push_back({a,b});
  }   

  vector<int>t(n,-1);
  // vector<bool>vis(n, false);
  for(int i =0 ; i<n ; i++)if(t[i]==-1)dfs(i,t,1,adj);
  // for(int i =0 ; i<n ; i++)if(t[i]==-1)dfs2(i,t,1,adj,vis);

  for(int i =0 ;i<frnd.size() ; i++){
     if(t[frnd[i].first]==t[frnd[i].second]){
    cout << "IMPOSSIBLE\n"; return ;
     }
  }
  
  for(auto& e:t)cout << e << ' ';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
