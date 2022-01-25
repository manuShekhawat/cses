// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>

using namespace std;

#define int long long


void solve(){
   int n; cin >> n;
   
   vector<int>a(n); for(auto& e:a)cin >> e;
   int ans = 0; map<int,int>mp; int temp =0 ;
   for(int i =0 ; i<n ; i++){
       if(mp[a[i]]>0){ans=max(temp,ans); mp.clear();mp[a[i]]++;temp=1;}
       else {temp++; mp[a[i]]++;}
   }
    ans = max(ans,temp);
   cout << ans << '\n';
}

signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
   solve();
}
