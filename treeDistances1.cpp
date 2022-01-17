// हौसला दिलाएगा मंज़िल  

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
void bfs(int s , vector<vector<int> >& adj , vector<bool>& visited , vector<int>& d){
	queue<int>q; visited[s] = true;
	q.push(s);
	
	while(q.size() > 0){
		int t= q.front(); q.pop();
		
		for(auto& e:adj[t]){
			if(!visited[e]){
				q.push(e); visited[e] = true; d[e] = max(d[e],d[t]+1);
			}
		}
	}
	
	return;
}
 
void solve(){
	int n; cin >> n;
	vector<vector<int> >adj(n);
	vector<int>d(n); 
	for(int i =1 ; i<n  ; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	vector<bool>visited(n,false);
	
	bfs(0 , adj , visited , d); 
	int mx = 0; int s =0;
    for(int i =0 ; i<n ; i++){
    	if(mx<=d[i]){
    		mx = d[i]; s = i;
		}
	}
//	cout << s << "dfhkjn\n";
	fill(d.begin() , d.end(), 0); for(int i =0 ; i<n ; i++)visited[i] = false; 
	
	bfs(s , adj , visited, d);
    
	for(int i =0 ; i<n ; i++){
    	if(mx<=d[i]){
    		mx = d[i]; s = i;
		}
	}
//	cout << s << "dfhkjn\n";
	vector<int>ans = d;
	fill(d.begin(), d.end() , 0);
	
   for(int i = 0 ;i<n ; i++){
   	visited[i] = false;
   }
   
   bfs(s,adj,visited,d);
   for(int i =0 ; i<n ; i++){
   	  ans[i] = max(ans[i],d[i]);
   }
   
   for(auto& e:ans){
   	cout << e<< ' ';
   }
   
   cout<< '\n';
}
 
signed main(){
//	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	
//	int t; cin >> t; while(t--)
	solve();
}
