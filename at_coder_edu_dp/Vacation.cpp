#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;


void solve(){
    int N ; cin >> N;
    vector<vector<int> >v(N+1 , vector<int>(3));
    for(int i = 1 ; i<=N ; i++){
      for(int j = 0;j<3 ; j++){
        cin >> v[i][j];
      }
    }
    
    vector<vector<int> >dp(N+1 , vector<int>(3));
    dp[1][0] = v[1][0]; dp[1][1] = v[1][1]; dp[1][2] = v[1][2];
    for(int i = 2; i<=N ; i++){
        for(int j = 0 ; j<3 ; j++){
          if(j==0){
              dp[i][j] = max(v[i][0]+dp[i-1][1], v[i][0]+dp[i-1][2]);
              dp[i][j] = max(v[i][0]+dp[i-1][1] , v[i][0] + dp[i-1][2]);
          }
          else if(j==1){
              dp[i][j] = max(v[i][1]+dp[i-1][0],v[i][1]+dp[i-1][2]);
              dp[i][j] = max(v[i][1]+dp[i-1][0] ,v[i][1]+ dp[i-1][2]);
          }
          else{
              dp[i][j] = max(v[i][2]+dp[i-1][0], v[i][2]+dp[i-1][1]);
              dp[i][j] = max(v[i][2]+dp[i-1][0] , v[i][2] + dp[i-1][1]);
          }
        }   
    }

    cout << max(dp[N][0] , max(dp[N][1] , dp[N][2])) << '\n';
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
