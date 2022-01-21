// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N= 2e5+1;
 
int cvt(int n){
   return n^(n/2); 
}
 
void print(int l , int n){
    
    int p = 1;
    int sz = n-1; vector<char>vec(n , '0');
    while(p<=l){
        
        if(p&l){
            vec[sz--] = '1';
        }
        else vec[sz--] = '0';
        p*=2; 
    }
    for(auto& e:vec){
        cout << e;
    }
    cout<< '\n';
}
 
void solve(){
   int n; cin >> n;
   for(int i =0 ; i<pow(2,n) ; i++){
       int l = cvt(i);
       print(l , n);
   }
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin>> t; while(t--)
    solve();
}
