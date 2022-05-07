#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> PBDS;

#define int long long

#define nl cout << '\n'
const int mod = 1e9+7;


void solve(){   
  int N , K ; cin >> N >> K;
  vector<int>a(N); for(int i =0 ; i<N ; i++)cin >> a[i];
  vector<int>dp(K+1);dp[0] = 0;

  for(int i = 1; i<=K ; i++){
      for(auto& e:a){
        if(i-e>=0){
           dp[i] = dp[i] | ~dp[i-e];     
        }
      }
  }

  if(dp[K]){
    cout << "First\n";
  }
  else cout << "Second\n";
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
