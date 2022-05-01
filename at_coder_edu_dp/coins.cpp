#include<bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9+7;


void solve(){
   int N ; cin >> N ;
   vector<double>p(N);

   for(auto& e:p)cin >> e;

   vector<vector<double> >dp(p.size() +1 , vector<double>(N+1));
   dp[0][0] = 1;
   for(int i = 1; i<=p.size() ; i++){
     for(int j = 0 ; j<=N ; j++){
       // ya to m upar se utha lun
      dp[i][j] = (1 - p[i-1])*dp[i-1][j];
      // ya to m upar k peeche vale se utha lun
      if(j-1>=0)dp[i][j] = dp[i][j] + p[i-1]*dp[i-1][j-1];
     }
   }

   
   double ans = 0;
   for(int i = (N+1)/2 ; i<=N ; i++){
     ans = ans + dp[p.size()][i];
   }
   cout << setprecision(15) ;
   cout << ans << '\n'; 
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
