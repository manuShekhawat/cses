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

int clc(int og , vector<int>& p){
  int cost = 0;
  for(auto& e:p)cost = cost + abs(og - e);
  return cost ;
}

void solve(){
  int n; cin >> n; vector<int>p(n); for(auto& e:p)cin >> e;
  sort(p.begin() , p.end()); int ans = p[n/2];

    cout<< clc(ans , p) << '\n';
}
 
signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
