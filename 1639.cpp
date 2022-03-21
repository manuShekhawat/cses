// Слава матушке-России
 
// Мир в Україні
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
 
int dp[5000][5000];
string a,b;
 
int edit(int i , int j){
     if(i==0 or j==0){
       return 1+max(i , j);
     }
     
    if(dp[i][j] > -1){
      return dp[i][j] ;
    }
    
     if(a[i] == b[j]){
       return (dp[i][j] = edit(i-1 , j -1));
     }
    
    int ans = 1e18;
    // replace 
       ans = min(ans ,1+edit(i-1 , j-1));
    // insert 
       ans = min(ans ,1+edit(i-1 , j));
    // remove
       ans = min(ans ,1+edit(i , j-1));
 
       dp[i][j] = ans ;
       return ans; 
}
 
void solve(){
  cin>> a >> b;
  for(int i =0 ; i<5000 ; i++)for(int j= 0 ; j<5000; j++)dp[i][j] = -1;
 
  cout << edit( a.length()-1 , b.length() - 1) << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
