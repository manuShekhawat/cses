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

void solve(){
   int n,m; cin >> n >> m;

   vector<int>h(n); vector<int>t(m);

   for(auto& e:h)cin >> e; for(auto& e:t)cin >> e;

   multiset<int>mt;

   for(int i =0 ; i<n ; i++)mt.insert(h[i]);

   for(int i =0 ; i<m ; i++){
     int x = t[i];
     auto it = mt.upper_bound(x);
     if(it == mt.begin() || mt.size()==0){
       t[i] = -1;
     }
     else{
       it--;
        t[i] =  *it; mt.erase(it);
     }
   }   

   for(int i =0 ; i<m ; i++)cout << t[i] << ' ';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
