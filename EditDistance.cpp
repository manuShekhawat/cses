// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;

void solve(){
    string a,b; cin>>a>>b; int n = a.length(); int m = b.length();
    // 3^n ki bjaye mujhe pta h maximum states of measurements matr a*b h.

    vector<vector<int> >dp(n+1 , vector<int>(m+1,0));
    for(int i = 1; i<=n; i++)dp[i][0] = i;
    for(int i = 1; i<=m ; i++)dp[0][i] = i;

    for(int i = 1; i<=n ; i++){
      for(int j = 1; j<=m ; j++){
        if(a[i-1]==b[j-1]){
          dp[i][j]  = dp[i-1][j-1];
        }
        else{
          dp[i][j] = 1e18;
          dp[i][j] = min(dp[i][j] , min(dp[i-1][j]+1 , min(dp[i-1][j-1]+1 , 1+dp[i][j-1])));
        }
      }
    }

    cout << dp[n][m] << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
