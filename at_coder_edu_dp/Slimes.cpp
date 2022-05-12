#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> PBDS;

#define int long long

#define nl cout << '\n'
const int mod = 1e9+7;
const int inf = 1e18;

int clc(int i ,int j , vector<int>& sum){
    if(i==0)return sum[j];

    return sum[j]- sum[i-1];
}

int dfs(int i , int j , vector<vector<int> >&dp , vector<int>& sm){
   if(j<=i)return 0 ; 

   if(dp[i][j]> 0)return dp[i][j];

   int ans = 1e18;
   int bc = clc(i , j , sm);
   for(int k = 0; k+i<j ; k++){
       ans = min(ans , dfs(i , i+k , dp ,sm) + dfs(i+k+1,j,dp,sm) + bc);
   }
   return dp[i][j]=ans;
}

void solve(){
    int N ; cin >> N ; vector<int>a(N); for(auto& e:a)cin >> e;

    /*
         dp(i , j) = min(dp(i , j) , sum(i , j) + dp(i , i +k) + dp(i+k +1 , j))
    */

   vector<int>sm(N); sm[0] = a[0]; for(int i = 1; i<N ; i++)sm[i]+=(sm[i-1]+a[i]);

   vector<vector<int> >dp( N , vector<int>(N));

   int ans = dfs(0 , N-1  , dp , sm);
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
