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
 
template<typename... T>
void put(T&... args) { ((cout << args << " "), ...);}
 


void solve(){
    int n,x; cin >> n >> x;

    vector<int>p(n); for(auto& e:p)cin >> e;
    if(n==1){
      cout << "1\n"; return ;
    }
    sort(p.begin() , p.end()); int i = 0 ; int j = n-1;
    int ans = 0;
    while(i<=j){
       int tp = x;
       tp-=p[j--];
       if(p[j]<=tp && j>=i)j--;
       else if(p[i]<=tp && i<=j)i++;
       ans++;
    }
   
   cout << ans << '\n'; 
}
 
signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
