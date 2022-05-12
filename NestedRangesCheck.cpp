#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> PBDS;

#define int long long

#define nl cout << '\n'
const int mod = 1e9+7;
const int inf = 1e18;

struct range{
    int in ; int l ; int r;

    bool operator < (const range& othr)const{
        if(othr.l == l){
            return r > othr.r;
        }
        return l < othr.l;
    }
};

void solve(){
    int N ; cin >> N ; vector<range >rng(N); 
    for(int i = 0; i<N ; i++){
        int x,y; cin>> x >> y; rng[i] = {i, x , y};
    }

    sort(rng.begin() , rng.end() );

    // Lets calculte;
    vector<bool>cntd(N); vector<bool>cnts(N);
  // is contained ? Every range is unique 
  int mxR = -1;
    for(int i = 0; i<N ; i++){
         if(mxR < rng[i].r)mxR = rng[i].r;
         else cntd[rng[i].in] = 1;
    }

// does it contains someone? Ranges are unique bro
 int mnR = 1e18;
 for(int i = N-1 ; i>=0 ; i--){
     if(mnR > rng[i].r)mnR = rng[i].r;
     else cnts[rng[i].in] = 1;
 }

 for(int i = 0; i<N ; i++){
     cout << cnts[i] << ' ';
 }nl;
 for(int i = 0; i<N ; i++){
     cout << cntd[i] << ' ';
 }nl ;
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
