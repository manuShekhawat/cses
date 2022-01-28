// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9+7;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;

void solve(){
   int n; cin >> n; vector<int>k(n); for(auto& e:k)cin >> e;

   multiset<int>ms;

   for(int i =0; i<n ; i++){
       int p = k[i];
       
       if(ms.upper_bound(p)==ms.end()){
           ms.insert(p);
       }
       else{
          auto it = ms.upper_bound(p);
          ms.erase(it); ms.insert(p);   
       }
   }

   cout << ms.size() << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // int t; cin >> t ; while(t--)
    solve();
}
