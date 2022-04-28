#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

string s,t;int n  , m;
string ans ;
vector<vector<int> >dp;

void dfs(int i , int j){
  if(i<0 or j<0)return ;
  
  if(s[i] == t[j]){
    ans.push_back(s[i]);; dfs(i-1 , j-1);
  }

  else{
    int l , u;
    if(i-1>=0)u = dp[i-1][j]; else u = -1;
    if(j-1 >=0)l = dp[i][j-1]; else l = -1;

    if(u > l)dfs(i-1, j);
    else dfs(i, j-1);
  }
}

void solve(){
  cin >> s >> t; n  = s.length() ; m = t.length();

  dp.resize(n); fill(dp.begin() , dp.end() , vector<int>(m));
  bool done = false;
  for(int i= 0 ; i<n ; i++){
       if(s[i] == t[0])done = true;
       if(done)dp[i][0] = 1; else dp[i][0] = 0;
  }
  done = false;
  for(int i= 0 ; i<m ; i++){
       if(s[0] == t[i])done = true;
       if(done)dp[0][i] = 1; else dp[0][i] = 0;
  }

  for(int i = 1; i<n ; i++){
    for(int j = 1; j<m ; j++){
      if(s[i] == t[j]){
         dp[i][j] = 1 + dp[i-1][j-1];
      }
      else dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
    }
  }

  dfs(s.length() - 1 , t.length() - 1);
  reverse(ans.begin() , ans.end());
  cout << ans<< '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  

  #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
  
  // int t; cin >> t; while(t--)
  solve();
}
