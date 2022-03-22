// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;

void solve(){
   int a,b;cin >> a >> b;

   vector<vector<int> >dp(a+ 1, vector<int>(b+1 , 0));

   for(int i =1 ; i<=a; i++){
       for(int j = 1; j<=b ; j++){
          dp[i][j] = inf;
          if(i==j){
            dp[i][j] = 0;
          }
          else{
            for(int k = 1; k<i ; k++){
              dp[i][j] = min(dp[i][j] , 1+ dp[i-k][j] + dp[k][j]);
            }

            for(int k = 1; k<j ; k++){
              dp[i][j] = min(dp[i][j] , 1+dp[i][j-k] + dp[i][k]);
            }
          }
       }
   }

   cout << dp[a][b] << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
