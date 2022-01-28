// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 1e9+7;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;

void solve(){
    int n,m; cin>> n >> m;

    vector<vector<int> >vec(n, vector<int>(m+1,0));

    vector<int>a(n); for(int i =0 ; i<n ; i++)cin >> a[i];
    if(a[0]==0){
        fill(vec[0].begin() , vec[0].end() , 1);vec[0][0] =0 ;
    }
    else{
       vec[0][a[0]] = 1;
    }

    for(int i =1 ; i<n ; i++){
       if(a[i]==0){ 
        for(int j =1 ; j<=m ; j++){    
            for(auto& e:{j-1,j,j+1}){
                if(e>0 && e<=m){
                    vec[i][j]+=vec[i-1][e];
                    vec[i][j]%=mod;
                }
            }
        }
       }
            else{
                int j = a[i];for(auto& e:{j-1,j,j+1}){
                if(e>=0 && e<=m){
                    vec[i][j]+=vec[i-1][e];
                    vec[i][j]%=mod;
                }
            }
                
            }       
    }

    int ans = 0;

    for(auto& e:vec.back())ans+=e,ans%=mod;

    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // int t; cin >> t ; while(t--)
    solve();
}
