#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;
int N , W;
map<pair<int,int> , int>mp;
vector<pair<int,int> >vec;

int dfs(int i , int w){
     if(i==N)return 0 ;
     
     if(mp.find({i,w})!=mp.end()){
       return mp[{i,w}];
     }

     int temp = 0;
     temp = max(temp , dfs(i+1 , w));

     if(w-vec[i].first>=0)temp = max(temp , dfs(i+1 , w-vec[i].first) + vec[i].second);
     return temp;
}

void solve(){
    cin >> N >> W;
    vec.resize(N); 
    for(int i = 0; i<N ; i++) {cin>> vec[i].first >> vec[i].second;}
    cout << dfs(0 , W) << '\n'; 
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
