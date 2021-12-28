// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N = 2e5+1;
 
 
template<typename... T>
void debug(T&... args){
  cout << "\n==================\n";
  ((cout<< args<<", "), ...);
  cout << "\n==================\n";
}
template<typename T>
void debug(vector<T>& a){
  cout << "\n==============\n";
  for(auto& e:a)cout << e << ' ';
  cout << "\n==============\n";
}
 
template<typename... T>
void put(T&... args) { ((cout << args << " "), ...);}

struct dsu{
   vector<int>parent,rank; int n;
   
   dsu(int n_){
     n = n_; parent.resize(n); rank.resize(n);

     iota(parent.begin() , parent.end() ,0); fill(rank.begin() , rank.end() , 1);
   }
   
   int find(int a){
       if(parent[a]!=a)parent[a] = find(parent[a]);
       return parent[a];
   }

   bool same(int a , int b){
      return find(a)==find(b);
   }

   void unite(int a, int b){
     if(same(a,b))return ;
     int p1 = find(a);
     int p2 = find(b);
     if(rank[p2]>rank[p1]){
       rank[p2]+=rank[p1];
       parent[p1] = p2;
     }
     else{
       rank[p1]+=rank[p2];
       parent[p2] = p1;
     }
   }
};

void solve(){
 int n,m; cin >> n >> m;
//  vector<vector<int>>adj(n);
dsu d(n);
 for(int i =0 ; i<m ; i++){
   int a,b; cin >> a>> b;a--; b--;
   d.unite(a,b);
 }

 map<int,int>mp;

 for(int i =0 ; i<n ; i++){
   mp[d.find(i)]++;
 }

 vector<pair<int,int> >ans;
  auto it = mp.begin(); it++; auto pt = it; pt--;
 for(it; it!=mp.end() ; it++){
    ans.push_back({it->first+1 , pt->first+1});
    pt++;
 }
  cout << ans.size() << '\n';
 for(auto& e:ans){
   cout << e.first << ' ' << e.second << '\n';
 }
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
