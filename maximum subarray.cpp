// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
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

struct cmp{
   bool operator()(const pair<int,int>& p1 ,const pair<int,int>& p2){
     return p2.first > p1.first;
   }
  
};

int clc(int l ,int r , vector<int>& s){
   if(l-1 < 0){
     return s[r];
   }
   else return s[r] - s[l-1];
}

void solve(){
  int n; cin>> n; vector<int>x(n); for(auto& e:x)cin >> e;
  int crs = 0; int r = 0; int l = 0; int ans = -1e18;
  for(auto& e:x)ans = max(e,ans);
  vector<int>s(n) ; s[0] = x[0]; for(int i =1 ; i<n ; i++)s[i] = s[i-1]+x[i];
  for(r = 0; r<n ; r++){
    while(x[l]<0 and l<r){
      l++;
    }
    crs = clc(l,r,s);

    if(crs < 0)l = r;
    ans = max(ans , crs);
  }
  cout << ans << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
