
#include<bits/stdc++.h>

using namespace std;

#define int long long

void dj(vector<vector<pair<int,int> > >& adj , vector<int>& d, vector<bool>& vis , int s){
      priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > >pq; 
      
      pq.push({s, 0});
      
      while(pq.size() > 0){
      	pair<int,int> p = pq.top() ; pq.pop();
      	if(vis[p.first])continue;
      	vis[p.first] = true;
      	
      	for(auto& e:adj[p.first]){
      	    if(d[e.first] > (d[p.first]+e.second)){
      	    	  d[e.first] = d[p.first] + e.second ; pq.push({e.first , d[e.first]});
			  }	
		}
	  }  
}

void solve(){
    int n,m; cin>> n >> m;
    
    vector<vector<pair<int,int> > >adj1(n); vector<vector<pair<int,int> > >adj2(n);
    
    for(int i =0 ; i<m ; i++){
    	int a , b, c; cin >> a >> b >> c; a--; b--;
    	adj1[a].push_back({b , c}); adj2[b].push_back({a,c});
	}
	
	vector<int>d1(n, 5e18); vector<int>d2(n, 5e18); vector<bool>vis1(n , false) , vis2(n , false); d1[0] = 0; d2[n-1]= 0;
	
	dj(adj1 , d1 , vis1 , 0); dj(adj2 , d2 , vis2 , n-1);
	
	int ans = 1e18;
	for(int i =0 ; i<n ; i++){
		for(auto& e:adj1[i]){
			ans = min(ans , d1[i] + d2[e.first] + e.second/2);
		}
	}
	
	cout << ans << '\n';
}

signed main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
//
//   #ifdef MANU
//     freopen("in.txt" ,"r" , stdin);
//     freopen("out.txt" , "w" , stdout);
//    #endif
   solve();
  
}

