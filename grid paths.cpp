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
int n; 
bool isValid(int i , int j){
  return (i>=0 and j>=0 and i<n and j<n);
}

void solve(){
  cin >> n;
   vector<string>vec(n); for(auto& e:vec)cin>> e;
    vector<vector<int> >cnt(n , vector<int>(n)); if(vec[0][0]=='.')cnt[0][0] = 1;
   for(int i = 0 ;i<n ; i++){
     for(int j = 0;j<n ; j++){
         if(vec[i][j]!='*'){
           if(isValid(i-1,j))cnt[i][j]+=cnt[i-1][j];
           if(isValid(i,j-1))cnt[i][j]+=cnt[i][j-1];
           cnt[i][j]%=mod;
         }
     }
   }

   cout << cnt[n-1][n-1] << '\n';
}

signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
