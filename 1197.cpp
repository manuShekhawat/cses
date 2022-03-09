// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long

vector<vector<pair<int,int> > >adj; vector<pair<int,int> >E; 
vector<int>color; vector<bool>vis;

void cycle(vector<int>& par , int node){
    // go back n-1 parents to discover the cycle
    int n = par.size();

    /*
      jo bhi node ne violate kiya h bellman ko pehle ya to vo cycle ka part h , ya to cycle k bahar 
      h jo cycle se go through hoga . maximum length of cycle n ho skti 
    */
    for(int i = 1; i<n ; i++){
      node = par[node];
    }

    int tmp = node;
    vector<int>cyc; cyc.push_back(tmp); tmp = par[tmp];

    while(tmp!=node){
      cyc.push_back(tmp); tmp = par[tmp];
    }
     cyc.push_back(node);
     reverse(cyc.begin() , cyc.end());
     cout << "YES\n";
    for(auto& e:cyc){
      cout << e+1 << ' ';
    }
}

void solve(){
  int n,m ; cin >> n >>  m;
  adj.resize(n) ; 
  for(int i = 0  ; i<m ; i++){
    int a,b,c; cin >> a >> b >> c; a--; b--; adj[a].push_back({b,c});
  }

  // bellman ford
  
  vector<int>d(n , 1e18); d[0] = 0;
  vector<int>par(n);
  for(int i = 1; i<n ; i++){
    for(int k = 0 ; k<n ; k++){
      for(auto& f:adj[k]){
          int chl = d[k] + f.second;
          if(chl < d[f.first]){
            d[f.first] = chl ; par[f.first] = k; 
          }
      }
    }
  } 

  for(int k =0 ; k<n ; k++){
      for(auto& e:adj[k]){
        if(d[k]+e.second < d[e.first]){
            par[e.first] = k;cycle(par , e.first); return ;
        }
      }
  }
  cout << "NO\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
