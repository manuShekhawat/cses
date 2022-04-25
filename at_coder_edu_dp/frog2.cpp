#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;


void solve(){
    int N ; cin >> N;
    int K ; cin >> K;
    vector<int>dp(N+1);
    vector<int>h(N+1);

    for(int i = 1; i<=N ; i++)cin >> h[i];

    // let dp(i) denote the minimum cost to reach stone i.

    dp[1] = 0;
    
    for(int i = 2 ; i<=N ;i++){
        // either i could have come from i-1 or i-2
        int tmp = 1e18;
        for(int j = 1; j<=K ; j++){
           int chl ;
           if(i-j>=1){chl = abs(h[i] - h[i-j]);
           tmp = min(tmp , dp[i-j] + chl);}
        }
        dp[i] = tmp;
    }

    cout << dp[N] << '\n';
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
