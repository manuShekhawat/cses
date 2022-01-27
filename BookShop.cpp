// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;

void solve(){
   int n,x; cin >> n >> x;

   vector<int>c(n); vector<int>p(n); for(auto& e:c)cin >> e; for(auto& e:p)cin >> e;

   vector<vector<int> >dp(n +1, vector<int>(x+1,0));

   // top down approach chlte h  . jhan p ehm hr ek state k liye compute krte h
   // dp(i,x) = max(dp(i-1,x),p[i]+dp(i-1,x+c[i]))

   for(int i = 1; i<=n ; i++){
     for(int j =0 ; j<=x ; j++){
       if(j+c[i-1]<=x){
         dp[i][j] = max(dp[i-1][j] , p[i-1]+dp[i-1][j+c[i-1]]);
       }
       else dp[i][j] = dp[i-1][j];
     }
   }

  //  for(auto& e:dp){
  //    for(auto& f:e){
  //      cout << f << ' ';
  //    }
  //    cout << '\n';
  //  }    

   cout << dp[n][0] << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
