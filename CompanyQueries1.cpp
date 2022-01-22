// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N= 2e5+1;

vector<vector<int> >up;

void init(vector<int>boss){
    int  n = boss.size();
    for(int i =1 ; i<=log2(boss.size()) ;i++){
        for(int j= 0; j<n ; j++){
            if(up[j][i-1]!=-1)up[j][i] = up[up[j][i-1]][i-1];
            else up[j][i] = -1;
        }
    }
}

void query(int x , int k){
    int p =1;
    x--;
    int ans = x;
    
    while(k>=p){
        if(k&p){
            ans = up[ans][log2(p)];
        }
        
        if(ans == -1)break;
        p<<=1;
    }
    if(ans>=0)ans++;
    cout << ans << '\n';
}

void solve(){
    int n,q; cin >> n >> q;
    up.resize(n);
    fill(up.begin() , up.end() , vector<int>(log2(n)+1));
    vector<int>boss(n,-1);
    up[0][0] = -1;
    for(int i = 1; i<n ; i++){
        cin >> boss[i]; boss[i]--;up[i][0] = boss[i]; 
    }
    
    init(boss);
    // for(auto&e:up){
    //     for(auto& f:e){
    //         cout << f << ' ';
    //     }
    //     cout << '\n';
    // }
    while(q--){
        int x,k; cin >> x >> k;
        query(x,k);
    }
}

signed main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin>> t; while(t--)
    solve();
}
