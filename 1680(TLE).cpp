/*

Uolevi has won a contest, and the prize is a free flight trip that can consist of one or more flights through cities. Of course, Uolevi wants to choose a trip that has as many cities as possible.

Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum number of cities. You are given the list of possible flights, and you know that there are no directed cycles in the flight network.

Input

The first input line has two integers n and m: the number of cities and flights. The cities are numbered 1,2,…,n. City 1 is Syrjälä, and city n is Lehmälä.

After this, there are m lines describing the flights. Each line has two integers a and b: there is a flight from city a to city b. Each flight is a one-way flight.

Output

First print the maximum number of cities on the route. After this, print the cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

*/

/*************************************************************SOLUTION***********************************************************************/

// Слава матушке-России
 
// Мир в Україні

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
const int inf = 1e18;
const int mod = 998244353;

vector<vector<int> >adj;

void solve(){
  int n,m;cin >> n >> m ; adj.resize(n);

  for(int i =0; i<m ; i++){
    int a,b; cin>> a >> b; a--; b--; adj[a].push_back(b);
  }

  // dijkstra algo with every edge weight as -1
  auto cmp = [](pair<int,int>& p1 , pair<int,int>& p2){
      return p2.first > p1.first;;
  };
  priority_queue<pair<int,int> , vector<pair<int,int> >, decltype(cmp)>pq(cmp);

  pq.push({0 , 0});vector<int>par(n  , -1);
  vector<bool>vis(n , false);
  vector<int>d(n , 0); 
  while(pq.size() > 0){
    auto [u , v] = pq.top();pq.pop();

    vis[u] = true;
    
    for(auto& e:adj[u]){
        if(v-1 < d[e]){
          d[e] = v-1; par[e] = u; pq.push({e , d[e]});
        }
    }
  }
  vector<int>path; int cur = n-1;

  while(cur >= 0){
    path.push_back(cur); cur = par[cur]; 
  }
  reverse(path.begin() , path.end());
  if(path.size() ==1){
    cout <<"IMPOSSIBLE\n"; return ;
  }
  
  cout << path.size() << '\n';


  for(auto& e:path){
    cout << e +1<< ' ';
  }cout << '\n';
}

signed main(){

  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
