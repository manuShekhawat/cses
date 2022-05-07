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
int n ;
vector<vector<int> >dp; 
vector<int>a;
int dfs(int i , int j){
    int bing = n - (j-i+1);
    if(i<0 or j<0 or i==n or j==n)return 0;
    int ans = 0;
    if(dp[i][j] != inf)return dp[i][j];
    if(i>j)return dp[i][j] = 0;

    if(bing%2 == 0){
      ans = -1e9;
        ans = max(dfs(i , j-1) + a[j], dfs(i+1 , j) + a[i]);
    }
    else{
       ans = 1e9;
       ans = min(dfs(i , j-1) - a[j] , dfs(i+1 , j) - a[i]);
    }
    return dp[i][j] = ans ;
}

void solve(){   
  int N ; cin >> N  ;a.resize(N);
  n = N; dp.resize(n); fill(dp.begin() , dp.end() , vector<int>(n ,inf));
  for(int i =0; i<N; i++)cin>> a[i];

  cout << dfs(0 , N - 1);
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  

  #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif

//   int t; cin >> t; while(t--)
solve();
}
