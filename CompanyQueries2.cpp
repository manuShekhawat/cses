// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>
 
#define int long long
using namespace std;
 
vector<vector<int> >up;
vector<int>lvl;
int n;
void init(){
    for(int i =1  ; i<=log2(n); i++){
        for(int j =0 ; j<n ; j++){
            up[j][i] = up[up[j][i-1]][i-1];
        }    
    }
}
 
void query(int a , int b){
    if(lvl[a]<lvl[b])swap(a,b);
    
    //a is deeper than b.
    // cout << lvl[a] << ' ' << lvl[b] << '\n'; 
    int ld = lvl[a]-lvl[b];
    int temp = pow(2,(int)log2(n));
    for(int i = log2(n); i>=0 ; i--){
        // cout << ld << '\n';
        if(ld>=temp){
            ld-=temp; a = up[a][i];
        }
        temp/=2;
    }
   
    
    if(a==b){
        cout << a+1 << '\n'; return ;
    }
    
    for(int i = log2(n) ; i>=0 ; i--){
       if(up[a][i]==up[b][i]){
           ;
       }
       else{
           a = up[a][i]; b = up[b][i];
       }
    }
    
    cout << up[a][0]+1 << '\n';
}
 
void solve(){
     cin >> n; int q; cin>> q;
    
    up.resize(n); lvl.resize(n);
    for(int i =0 ; i<n ; i++)up[i].resize(log2(n)+1);
    up[0][0] = 0;
    for(int i =1 ; i<n ; i++){
        cin >> up[i][0]; up[i][0]--;lvl[i] = lvl[up[i][0]]+1;
    }
    
    init();
    
    // for(int i =0 ; i<n ; i++){
    //     for(int j =0 ; j<=log2(n) ; j++){
    //         cout << up[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for(auto& e:lvl)cout << e << ' '; cout<< '\n';
    while(q--){
        int a,b; cin >> a>> b; a--; b--;
        
        query(a,b);
    }
}
 
signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
   solve();
}
