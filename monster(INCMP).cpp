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
int n,m;
vector<string>grid;


bool isValid(int i, int j){
  if(i>=0 and i<n and j>=0 and j<m and grid[i][j]!='#')return true;
  else return false;
}

void bfs(int i , int j , vector<vector<int> >& a , function<bool(int a , int b)>& fn , bool sw){
     queue<tuple<int,int,int> >q;

     tuple<int,int,int> p = {i,j,0};
     q.push(p);
     
     while(q.size()>0){
         tuple<int,int,int>curr = q.front();
          
         if(fn(get<2>(curr) , a[get<0>(curr)][get<1>(curr)])){
           a[get<0>(curr)][get<1>(curr)] = get<2>(curr);
           if(sw){
             grid[get<0>(curr)][get<1>(curr)] = clc();
           }
           if(isValid(i+1,j))q.push({i+1,j,get<2>(curr)+1});
           if(isValid(i-1,j))q.push({i-1,j,get<2>(curr)+1});
           if(isValid(i,j+1))q.push({i,j+1,get<2>(curr)+1});
           if(isValid(i,j-1))q.push({i,j-1,get<2>(curr)+1});

         }

         q.pop();
     }
}

void solve(){
  cin >> n >> m; grid.resize(n);
  for(int i =0 ;i<n ; i++)cin >> grid[i];

  vector<vector<int> >bulb(n , vector<int>(m));

  path.resize(n); fill(path.begin() , path.end() , vector<char>(m , '#'));

  for(int i =0 ;i<n ; i++){
    for(int j = 0 ;j<m; j++){
      if(grid[i][j]=='#'){
          bulb[i][j] = -1;
      }
      else if(grid[i][j]=='M' or grid[i][j]=='A'){
        bulb[i][j] = 0;
      }
      else{
        bulb[i][j] = 1e18;
      }
    }
  }

  function<bool(int a, int b)> sc = [&](int a , int b){return b>a;};
  function<bool(int a , int b)> lc = [&](int a , int b){return b>=a;};
  for(int i =0 ; i<n ; i++){
    for(int j =0 ; j<m ; j++){
      if(grid[i][j] == 'M'){
           bfs(i , j , bulb ,lc,false);
      }
    }
  }

  for(int i =0 ; i<n ; i++){
    for(int j =0 ; j<m ; j++){
      if(grid[i][j]=='A')bfs(i,j,bulb,sc,true);
    }
  }
  

}

signed main(){
  // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // int t; cin>> t; while(t--)
  solve();
}
