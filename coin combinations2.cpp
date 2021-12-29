// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9+7;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;
 
template<typename... T>
void debug(T&... args){
  cout << "\n==================\n";
  ((cout<< args<<", "), ...);
  cout << "\n==================\n";
}
template<typename T>
void debug(vector<T>& a){
  cout << "\n==============\n";
  for(auto& e:a)cout << e << ' ';
  cout << "\n==============\n";
}

void solve(){
    int n,x; cin >> n >> x; vector<int>c(n); for(auto&e:c)cin >> e;

    vector<int>dp(x+1);
    dp[0] = 1;
    for(int i = 0  ; i<n ; i++){
      for(int j = 1 ; j<=x ; j++){
        if(c[i]<=j){
          dp[j] = dp[j] + dp[j-c[i]];
          dp[j]%=mod;
        }
      }
    }

    cout<< dp[x]  << '\n';
}

signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
