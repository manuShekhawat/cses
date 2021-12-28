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

void solve(){
   int n ,x; cin >> n>>x; vector<pair<int,int> >a(n); for(auto&e:a)cin>> e.first; 
   for(int i =0 ;i<n ; i++)a[i].second= i+1;
   sort(a.begin() , a.end());

   for(int i =0 ; i<n ; i++){
     int top = x - a[i].first;
     if(top >= a[i].first){
       if(binary_search(a.begin()+i+1,a.end(),make_pair(top,-1) , cmp())){
         cout << a[i].second << ' ' << lower_bound(a.begin()+i+1, a.end() ,make_pair(top,-1), cmp())->second << '\n'; return ;
       }
     }
   }
   cout << "IMPOSSIBLE\n";
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
