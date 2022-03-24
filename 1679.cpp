// Слава матушке-России

// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;

void solve(){
  int n,m; cin >> n >> m;

  vector<vector<int> >adj(n);
  vector<int>flw(n);
  for(int i=0 ; i<m ; i++){
     int a,b; cin >> a >> b; a--; b--; adj[a].push_back(b); flw[b]++;
  }
  vector<int>ans;
  queue<int>q;
  for(int i =0 ; i<n  ; i++){
     if(flw[i]==0)q.push(i);
  }
  vector<bool>done(n , false);
  while(q.size() > 0){
     int top = q.front(); q.pop();
     done[top] = true; ans.push_back(top);
     for(auto& e:adj[top]){
         flw[e]--;
         if(flw[e]==0)q.push(e);
     }
  }
  
  if(ans.size()==n){
     for(auto& e:ans)cout << e+1 << ' ' ; cout << '\n';
  }
  else cout << "IMPOSSIBLE\n";
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//   int t; cin >> t; while(t--)
  solve();
}
