#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;


void solve(){
  int N ; cin >> N ; int W ; cin >> W;
  vector<pair<int,int> >vec(N+1);

  for(int i = 1; i<=N ; i++){
    int a, b; cin >> a >> b ; vec[i] = {a , b};
  }

  vector<vector<int> >dp(N +1, vector<int>(W+1, 0));

  for(int i = 1; i<=N ; i++){
    for(int j = 0 ; j<=W ; j++){
        if(j-vec[i].first >= 0){
          dp[i][j] = max(dp[i][j] , dp[i-1][j - vec[i].first] + vec[i].second);
        }
          dp[i][j] = max(dp[i][j] , dp[i-1][j]);

    }
  }

  cout << dp[N][W] << '\n';
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
