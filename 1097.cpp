// Слава матушке-России
 
// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
const int mod = 1e9 + 7;

int n; vector<int>x; vector<vector<int> >dp;
int s1 ; int s2;

// dp stores s1-s2

void dfs(int i , int j){
 
  // if(dp[i][j]!=0)return ;
  int ch = i + n - 1 - j;

  if(ch%2== 0){
     // p1 ki chance h lauda 
     if(i==j){dp[i][j] = x[i]; return ;}
     if(dp[i][j-1]==-inf)dfs(i , j-1);
     if(dp[i+1][j]==-inf)dfs(i+1 , j);
     dp[i][j] = max(x[i]+ dp[i+1][j] ,x[j]+ dp[i][j-1]);
  }
  else{
      if(i==j){dp[i][j] = -x[i];return ;}
      if(dp[i][j-1]==-inf)dfs(i , j-1);
      if(dp[i+1][j]==-inf)dfs(i+1 , j);
      dp[i][j] = min(dp[i+1][j]-x[i] , dp[i][j-1]-x[j]);
  }

  return;
}

void solve(){
  cin >> n; x.resize(n); dp.resize(n); fill(dp.begin() , dp.end() , vector<int>(n , -inf));

  for(auto& e:x)cin >> e;

  dfs(0 , n-1);
  // for(auto& e:dp){
  //   for(auto& f:e){
  //     cout << f << ' ';
  //   }cout << '\n';
  // }
  int s = 0; for(auto& e:x)s = s+ e;

  cout << (s+dp[0][n-1])/2 << '\n';
}

signed main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
