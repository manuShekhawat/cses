// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int> >adjf;
vector<vector<int> >adjb;

vector<bool>visf,visb;

void dfs1(int s){
  if(visf[s])return ;
  visf[s] = true;
  for(auto& e:adjf[s])dfs1(e);
}


void dfs2(int s){
  if(visb[s])return ;
  visb[s] = true;
  for(auto& e:adjb[s])dfs2(e);
}


void solve(){
    // bellman ford algorithms

    int n,m; cin >> n >> m;
    visf.resize(n); visb.resize(n); adjf.resize(n); adjb.resize(n);
    for(int i =0 ; i<n ; i++)visf[i] = visb[i] = false; 
    vector<int>d(n,-1e15);
    d[0] =0 ; vector<tuple<int,int,int> >edges;
    
    for(int i=0 ; i<m ; i++){
        int a,b; int x; cin >> a >> b >> x; a--; b--; edges.push_back({a,b,x});
        adjf[a].push_back(b); adjb[b].push_back(a);
    }

    for(int i =1 ; i<n ; i++){
      for(auto& e:edges){
          int a,b,x; tie(a,b,x) = e;
          d[b] = max(d[b] , d[a]+x);
      }
    }
    // i am gonna see if there exist a cycle in the path from start to the ending node.
    dfs1(0); dfs2(n-1);
    // for(int i =0; i<n ; i++)cout << visf[i] << ' '; cout << '\n';
    // for(int i = 0; i<n ; i++)cout << visb[i] << ' ';cout << '\n';
    for(int i = 1 ; i< n ; i++){
      for(auto& e:edges){
        int a,b,x; tie(a,b,x) = e;
        if((d[b]<(d[a]+x)) && visf[b] && visb[b]){
          cout << "-1\n"; return ;
        }
        if(d[b]<(d[a]+x))d[b] = d[a]+x;
      }
    }
    cout << d[n-1] << '\n';
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t;cin >> t; while(t--)
   solve();
}
