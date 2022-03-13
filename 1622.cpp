// Слава матушке-России
 
// Мир в Україні
 
#include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
set<string>st;
string s;
int ct = 0;
 
 
void dfs(string p , int i){
 if(i == s.length()){st.insert(p);return ;}
 
 string c = p; sort(c.begin() , c.end());
 vector<char>v(s.length());
 auto it = set_difference(s.begin() , s.end() , c.begin() , c.end() , v.begin());
 v.resize(it - v.begin());
 
 for(auto& e:v){
   string p1 = p + e; dfs(p1 , i+1);
 }
 
}
 
void solve(){
   cin >> s; sort(s.begin() , s.end());
  dfs("" , 0);
  cout << st.size() << '\n';
  for(auto& e:st){
    cout << e<< '\n';
  }
}
 
signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin >> t; while(t--)
  solve();
}
