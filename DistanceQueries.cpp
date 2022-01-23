// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ull unsigned long long
#define vi vector<int>
#define rep(i,a,b) for(int i =a; i<b ; i++)
#define rev(i,a,b) for(int i =a ; i>b ; i--)
#define pii pair<int,int>
#define vpi vector<pair<int,int> >
#define setpr(x) cout<<setprecision(x)<<fixed
#define tiii tuple<int,int,int>
#define get(i,a) get<i>(a)
#define vvi vector<vector<int> >
#define ren(e,a) for(auto& e:a)
 
vvi adj;
vvi p;
vi vis;
vi lvl;
 
void dfs(int u, int v){
   if(vis[u])return ;
   lvl[u] = lvl[v]+1;
   vis[u] = 1;
   p[u][0] = v;
   
   for(auto& e:adj[u]){
       dfs(e,u);
   }
}
 
void init(){
    int n = adj.size();
    for(int i= 1; i<=log2(n); i++){
        rep(j,0,n){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
}
 
void query(int a , int b){
    if(lvl[a] < lvl[b])swap(a,b);
    
    int ld = lvl[a] - lvl[b];
    int pw = p[0].size()-1;
    int temp = pow(2,pw);
    int ans = 0;
    for(int i = pw; i>=0 ; i--){
       if(ld>=temp)ld-=temp,ans+=temp,a = p[a][i];
       temp>>=1;
    }
    
    if(a==b){
        cout << ans << '\n'; return;
    }
    temp = pow(2,pw);
    for(int i = pw; i>=0 ; i--){
        if(p[a][i]==p[b][i]);
        else{
            ans = ans + 2*temp;
            a = p[a][i]; b = p[b][i];
        }
        temp>>=1;
    }
    
    cout << ans+2 << '\n';
}
 
void solve(){
   int n; cin >> n; int q; cin >> q;lvl.resize(n); 
   vis.resize(n); adj.resize(n); p.resize(n); fill(p.begin(),p.end(),vi(log2(n)+1));
   for(int i=1 ; i<n ; i++){
       int a,b; cin >> a >> b; a--; b--;
       adj[a].push_back(b); adj[b].push_back(a);
   }
   rep(i,0,n)vis[i] = false;
   
   dfs(0,0);      
   
   init();
   
   while(q--){
       int a,b; cin >> a >> b; query(--a,--b);
   }
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
   solve();
}
