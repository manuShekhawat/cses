#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> PBDS;
 
#define int long long
#define nl cout << '\n'
const int mod = 1e9+7;
 
double dp[301][301][301];
int N ;
 
double recurse(vector<int> b){
    if(dp[b[0]][b[1]][b[2]] != -1)return dp[b[0]][b[1]][b[2]];
    if(b[0] + b[1] + b[2] == 0){
      return dp[b[0]][b[1]][b[2]] = 0;
    } 
    double ans = static_cast<double>(N)/static_cast<double>(b[1] + b[2] +b[0]);
    double temp = 0;
    double ok = 0;
    for(int i = 0; i<3 ; i++){
        if(b[i]==0)continue;
        vector<int>c = b ; ok+=b[i];
        c[i]--;if(i-1>=0)c[i-1]++; temp = temp + b[i]*recurse(c);
    }
    temp = temp / (ok);ans = ans + temp;  return dp[b[0]][b[1]][b[2]] = ans ;
}
 
void solve(){
     /*
         Form a solution before jumping onto an implementation
     */
    cin>> N; vector<int>a(N); for(auto& e:a)cin >> e;
    vector<int>b(3);
    for(int i = 0 ; i<N;i++)b[a[i]-1]++;
    cout << setprecision(15);
 
    for(int i= 0; i<=300;i++)for(int j=0;j<=300;j++)for(int k=0;k<=300;k++)dp[i][j][k] = -1;
    cout << recurse(b) << '\n';
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  
 
  #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
 
  // int t; cin >> t; while(t--)
solve();
}
