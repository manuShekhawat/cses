
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9+7;

void solve(){
  int H , W; cin >> H >> W;
  vector<string>vec(H);

  for(int i= 0; i<H ; i++){
    cin>> vec[i];
  }

  vector<vector<int> >dp(H+1 , vector<int>(W+1 , 0));

  /*
      TO reach a square (i , j) ,
      we can either go from left cell or from upper cell 
      dp( i , j)  = up + left 
  */
   dp[1][0] = 1;
   for(int i= 1 ;i<=H ; i++){
     for(int j = 1; j<=W ; j++){
       if(vec[i-1][j-1] == '.'){
         dp[i][j] = dp[i-1][j] + dp[i][j-1]; dp[i][j] %= mod;
       } 
       else dp[i][j] = 0;
     }
   }

   cout << dp[H][W] << '\n';
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
