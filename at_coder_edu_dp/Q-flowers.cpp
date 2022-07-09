#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> indexed_set;


// Defines
#define int long long
#define nl cout << '\n'
#define FF first
#define SS second  
#define all(x) x.begin() , x.end()
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pii>
// Constansts 
const int mod = 1e9+7;
const int inf = 1e18;
const int N = 1e5+1;

// Helpers
template<typename U,typename V>ostream& operator<<(ostream&os,pair<U,V>&p){os<<p.FF<<' '<<p.SS;nl;return os;}
template<typename T>ostream& operator<<(ostream&os,vector<T>&p){for(auto& e:p){os << e << ' ';}nl;return os;}
template<typename...  Args>void de(Args&&... args){((cout << args << ' '),...);}

template<typename U,typename V>istream& operator>>(istream&is,pair<U,V>&p){is>>p.FF>>p.SS;return is;}
template<typename T>istream& operator>>(istream&is,vector<T>& p){for(auto& e:p){is>>e;}return is;}
template<typename...  Args>void le(Args&&... args){((cin >> args),...);}
int TEST = 0;
void google(){
    cout << "Case #" << TEST+1 << ": " ;
}

// CODE /////////////////////////////////////////////////////////////////////////////////////////////////////

void solve(){
   int N ; cin >> N ; 
   vector<int>h(N) , a(N) , dp(N);

   le(h , a);
   dp[0] = a[0]; map<int,int>mp; // map for storing height and dp

   // i will maintain a property that if height of the 
mp[h[0]] = a[0];
   for(int i = 1; i<N ; i++){
    int ans = a[i];
    // search this index in map 

    auto it = mp.lower_bound(h[i]); 
    // as heights are unique this element points to the element grater than prev
    
    if(it!=mp.begin()){it--; ans = ans + it->second ;}
    mp[h[i]] = ans;  // isse chhoti height exist nhi krti , jiska ans isse better ho 
    auto tmp = mp.upper_bound(h[i]);it = tmp;
    while(it!=mp.end() && it->second<=ans){
      tmp++; mp.erase(it); it = tmp;
    }
    dp[i] = ans ;
   }
   int ans = 0;
   for(auto& e:dp)ans = max(e , ans);
  //  de(dp);
   cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) ;
    #ifndef ONLINE_JUDGE
      freopen("input.txt" , "r" , stdin);
      freopen("output.txt" , "w" , stdout);
      freopen("error.txt" , "w" ,stderr);
  #endif
  
  // int t; cin >> t; for(TEST = 0; TEST<t ; TEST++)
  solve();
}
