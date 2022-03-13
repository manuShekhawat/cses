// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long

void solve(){
  int n;cin >> n; vector<int>p(n); for(auto&  e:p)cin >> e;
  int sm = 0; int ans = 1e18; int st = 0; for(auto& e:p)st =st + e;

  for(int i =0 ; i<(2<<n) ; i++){
    sm = 0;
    for(int j =0 ; j<n ; j++){
      if((i >> j) & 1){
        sm = sm + p[j];
      }
    }
    ans = min(ans , abs(st - 2*sm));
  }
  cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
