#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int , null_type , less<int> ,rb_tree_tag , tree_order_statistics_node_update> PBDS;

// Defines
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int > >
#define nl cout << '\n'
#define FF first
#define SS second  


// Constansts 
const int mod = 1e9+7;
const int inf = 1e18;


// Helpers
void deb(pair<int,int>p1){
	cout << p1.first << ' ' << p1.second << '\n';
}
template<typename T>
void deb(vector<vector<T> >& vec){
    for(auto& e:vec){
        for(auto& f:e)cout << f << ' '; 
        cout << '\n';
    }
}
template<typename T>
void deb(vector<T>& v){
    for(auto& e:v)cout << e << ' ';
     nl;
}
bool operator < (pair<int,int>p1 , pair<int,int>p2){
	if(p1.first < p2.first && p1.second < p2.second)return true;
	else return false;
}
bool operator > (pair<int,int>p1 , pair<int,int>p2){
	return (p1.first>p2.first and p1.SS > p2.SS);
} 

// CODE /////////////////////////////////////////////////////////////////////////////////////////////////////



void solve(){
	int n ; cin>> n ; vector<int>a(n); for(int i = 0; i<n ; i++)cin >> a[i];
	
	
	vector<int>d(n+1 , inf);
	d[0] = -inf;
	for(int i = 0; i<n ; i++){
		// For each element m search krna chahta the maximum range/improvement i can achieve
		int it = upper_bound(d.begin() , d.end() , a[i]) - d.begin();
		
		if(d[it] > a[i] && d[it-1]<a[i]){
			d[it] = a[i];
		}
	}
	
	int ans = 0;
	for(int i = 0; i<=n ; i++){
		if(d[i]!=inf)ans = i;
	}
	cout << ans << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


  // int t; cin >> t; while(t--)
 solve();
}
