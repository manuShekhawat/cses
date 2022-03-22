// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;

void solve(){
  int n ; cin >> n ; vector<int>x(n); for(int i = 0 ; i<n ; i++)cin >> x[i];
  int mxv = 0 ;; for(int i =0 ; i<n ; i++)mxv+=x[i];
  vector<vector<bool> >dp(n+ 1, vector<bool>(mxv+1 , false));
  for(int i =0 ; i<=mxv ; i++)dp[0][i] = false;
  for(int i =0 ; i<=n ; i++)dp[i][0] = true;



  // dp[i][x] , can x be created using first i coins?
  // dp[1][5] , can 5 be created using the first coin?
  /*
     1 0 0 0 0 0  0
     1
     1
     1
     1
  
  */

   for(int i =1 ; i<=n ; i++){
     for(int j = 1 ; j<=mxv ; j++){
       dp[i][j] = dp[i-1][j];
       if(j>=x[i-1])dp[i][j] = dp[i][j]|dp[i-1][j-x[i-1]];
     }
   }

  //  for(int i =0 ; i<=n ; i++){
  //    for(int j =0 ; j<=mxv ; j++){
  //      cout << dp[i][j] << ' '; 
  //    }
  //    cout << '\n';
  //  }
   int ans = 0  ; vector<int>members;

   for(int i = 1 ;i<=mxv ; i++){
     if(dp[n][i]){
        ans++; members.push_back(i);
     }
   }

   cout << ans << '\n'; for(auto& e:members)cout << e << ' '; cout << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
