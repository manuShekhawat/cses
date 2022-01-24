// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>

using namespace std;

#define int long long

int sum(int r,int c,vector<vector<int> >& s){
    if(r<0 || c<0)return 0;
    else return s[r][c];
}

void query(int r1 , int c1 , int r2 ,int c2, vector<vector<int> >& sm){
    int ans = sum(r2,c2,sm) - sum(r2,c1-1,sm) -sum(r1-1,c2,sm)+sum(r1-1,c1-1,sm);
    cout << ans << '\n';
}

void solve(){
    int n,q; cin >> n>> q;
    vector<string>f(n);
    for(auto& e:f)cin >> e;
    
    vector<vector<int> >s(n,vector<int>(n));
    
    for(int i =0 ; i<n ; i++){
        for(int j = 0; j<n ; j++){
            s[i][j] = sum(i,j-1,s) + sum(i-1,j,s) - sum(i-1,j-1,s);
            if(f[i][j]=='*')s[i][j]++;
        }
        // cout<<'\n';
    }
    
    while(q--){
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
        query(--r1,--c1,--r2,--c2,s);
    }
}

signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
   solve();
}
