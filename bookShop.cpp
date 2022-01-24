// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int>c,p;
vector<vector<int> >dp;

int dfs(int x,int i){
    if(i==c.size()||x<=0)return 0;
    if(dp[i][x]>=0)return dp[i][x];
    
    // either i take that book or just ignore it
    
    if(i==p.size())return 0; if(x==0)return 0;
    int ans = 0;
    if(x>=c[i])ans = p[i]+dfs(x-c[i],i+1);
    
    ans = max(ans , dfs(x,i+1));
    dp[i][x]= ans;
    return ans;
}

void solve(){
   int n,x; cin >> n >> x;
   
   c.resize(n); p.resize(n);
   for(auto& e:c)cin >> e; for(auto& e:p)cin >> e;
   
// assume there is a state , where i have some money
// i can either take in this book or ignore this book
// ans(money,i) = ans(money-c[i],i-1)+p[i],ans(money,i-1)
// money can take upto x+1 states [0,x]
// i can take upto n states [0,n]

dp.resize(n); fill(dp.begin(), dp.end(),vector<int>(x+1,-1));
dfs(x,0);
cout << dp[0][x] << '\n';

}

signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
   solve();
}
