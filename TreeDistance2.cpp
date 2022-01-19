// हौसला दिलाएगा मंज़िल

#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
int init_g(int s, vector<vector<int> >& adj , vector<bool>& vis , vector<int>& undr){
	if(vis[s])return 0;
	vis[s] =true;
	for(auto& e:adj[s]){
		undr[s] += init_g(e , adj , vis, undr);
	}
	undr[s]+=1;
	return undr[s];
}
 
int dfs(int v , vector<vector<int> >&adj , vector<bool>& vis , vector<int>& undr){
	
	if(vis[v])return 0 ;
	int temp = 0;
	vis[v] = true;
	for(auto& e:adj[v]){
	   temp = temp + dfs(e,adj,vis,undr);	
	}
	return (temp + undr[v]);
}
 
void dfs(int u ,int p, vector<vector<int> >& adj , vector<bool>& vis , vector<int>& undr ,vector<int>& ans, int left){
	if(p == -1){
		for(auto& e:adj[u]){
			dfs(e , u, adj, vis , undr ,ans , left);
		}
		
	}
	
	if(vis[u])return ;
	vis[u] = true;
	ans[u] = ans[p] + left + undr[p] - 2*undr[u];
	left = left + undr[p] - undr[u];
	
	for(auto& e:adj[u]){
		dfs(e,u,adj,vis,undr,ans,left);
	}
}
 
void solve(){
	int n; cin >> n;
	vector<vector<int> >adj(n);
	for(int i = 1;i<n ; i++){
		int u,v; cin>> u >> v; u--;v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}
	
	// har ek node k lie uske neeche kitne bnde h.
	vector<int>undr(n);
	vector<bool>vis(n , false);
	init_g(0,adj,vis,undr);
	
//	for(auto& e:undr){
//		cout << e <<' ';
//	}cout << '\n';
 
    vector<int>ans(n);
    for(int i =0 ; i<n  ; i++)vis[i]= false;
    ans[0] = dfs(0 , adj , vis,undr) - undr[0];
//    cout << ans[0];
    
//    return;
    for(int i =0; i<n ; i++)vis[i] = false;
    vis[0] =true;
    dfs(0 ,-1, adj , vis , undr ,ans , 0);
    
    
    for(auto& e:ans){
    	cout << e << ' ';
	}
	cout << '\n';
}
 
signed main(){
//	ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
	
//	int t; cin >> t; while(t--)
	solve();
}
