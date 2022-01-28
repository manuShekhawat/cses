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
    int x,n; cin >> x>> n;
    vector<int>p(n);

    for(auto& e:p)cin >> e;
    set<int>s; multiset<int>ms;
    s.insert(0); s.insert(x); ms.insert(x);

    for(int i =0 ; i< n ; i++){
        // cout << "YES\n";
        auto it2 = s.lower_bound(p[i]);
        auto it1 = --it2;it2++;
        // cout << *it1 << ' ' << *it2 << '\n';
        int sz1 = p[i] - *it1;
        int sz2 = *it2 - p[i];

        s.insert(p[i]); ms.erase(ms.find(sz1+sz2));
        ms.insert(sz1); ms.insert(sz2);
        cout << *ms.rbegin() << '\n';
    }    
    
}

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // int t; cin >> t ; while(t--)
    solve();
}
