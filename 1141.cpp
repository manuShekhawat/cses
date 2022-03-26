// Слава матушке-России
 
// Мир в Україні
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
 
void solve(){
   int n; cin>> n ; vector<int>k(n); for(int i =0 ; i<n ; i++)cin >> k[i];

   map<int,int>mp;
   int ans = 0;  int temp = 0;
   for(int i =0 ; i<n ; i++){
      if(mp[k[i]]==0 || mp[k[i]]<i+1-temp){
          temp++; mp[k[i]] = i+1; 
      }
      else{
         ans = max(ans , temp);
          ans = max(ans,temp = (i+1 - mp[k[i]])); mp[k[i]] = i+1;
      }
   }
   ans = max(ans , temp);
   cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t; cin >> t; while(t--)
  solve();
}
