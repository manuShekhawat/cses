// हौसला दिलाएगा मंज़िल  
 
#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int mod = 998244353;
#define F first
#define S second
#define pb push_back
 
const int N= 2e5+1;
 
struct cell{
   char ch ; int dis ; char move ; 
   cell(){
        ch = '#' ; dis = 1e18; move ='#';
   }
};
 
bool isValid(int r , int c, vector<vector<cell> >& vec){
    int n = vec.size(); int m = vec[0].size();
    
    if(r>=0 and r<n and c>=0 and c<m){
        return true;
    }
    return false;
}
 
void dfs_m(int r , int c, vector<vector<cell> >& vec ,int d){
    if(!isValid(r,c,vec))return ;
    
    if(vec[r][c].ch =='#')return;
    
    if(vec[r][c].ch =='.'||d==0){
        if(d<vec[r][c].dis){
            vec[r][c].dis = d;
            dfs_m(r+1,c,vec,d+1);
            dfs_m(r,c+1,vec,d+1);
            dfs_m(r-1,c,vec,d+1);
            dfs_m(r,c-1,vec,d+1);
        }
    }
    
    return;
}
 
char sett(int r , int c, int pr , int pc){
    int R = r-pr; int C = c - pc;
    
    if(R==1)return 'D';
    if(C==1)return 'R';
    if(R==-1)return 'U';
    if(C==-1)return 'L';
    return '#';
}
 
void dfs_h(int r, int c , vector<vector<cell> >& vec, int pr , int pc, int d){
    if(!isValid(r,c,vec))return ;
    
    if(vec[r][c].ch =='#')return;
    
    if(vec[r][c].ch=='.' ){
        if(d<vec[r][c].dis){
            vec[r][c].dis = d;
            vec[r][c].move = sett(r, c , pr, pc);
            dfs_h(r+1,c,vec,r,c,d+1);
            dfs_h(r,c+1,vec,r,c,d+1);
            dfs_h(r-1,c,vec,r,c,d+1);
            dfs_h(r,c-1,vec,r,c,d+1);
        }
    }
    
    return;
}
 
void swc(int& r, int& c, vector<vector<cell> >& vec){
    if(vec[r][c].move == 'R'){
        c--;
    }
    else if(vec[r][c].move =='L')c++;
    else if(vec[r][c].move == 'D')r--;
    else r++;
}
 
void TRACE(vector<vector<cell> >& vec){
    // first row
    vector<char>ans; int n = vec.size() ; int m = vec[0].size();
    for(int i = 0 ; i<vec[0].size() ; i++){
        if(vec[0][i].move != '#'){
            int r = 0 ; int c = i;
            while(vec[r][c].move!='#'){
                ans.push_back(vec[r][c].move);
                swc(r,c,vec);
            }
            reverse(ans.begin() , ans.end());
            cout << "YES\n" << ans.size() << '\n';
            for(auto& e:ans)cout << e ; cout <<'\n';
            return ;
        }
    }
    
     for(int i = 0 ; i<vec[0].size() ; i++){
        if(vec[n-1][i].move != '#'){
            int r = n-1 ; int c = i;
            while(vec[r][c].move!='#'){
                ans.push_back(vec[r][c].move);
                swc(r,c,vec);
            }
            reverse(ans.begin() , ans.end());
                cout << "YES\n" << ans.size() << '\n';
            for(auto& e:ans)cout << e ; cout <<'\n';
            return ;
        }
    }
     for(int i = 0 ; i<vec.size() ; i++){
        if(vec[i][0].move != '#'){
            int r = i ; int c = 0;
            while(vec[r][c].move!='#'){
                ans.push_back(vec[r][c].move);
                swc(r,c,vec);
            }
            reverse(ans.begin() , ans.end());
                cout << "YES\n" << ans.size() << '\n';
            for(auto& e:ans)cout << e ; cout <<'\n';
            return ;
        }
    }
    
     for(int i = 0 ; i<vec.size() ; i++){
        if(vec[i][m-1].move != '#'){
            int r = i ; int c = m-1;
            
            while(vec[r][c].move!='#'){
                ans.push_back(vec[r][c].move);
                swc(r,c,vec);
                // cout << r << ' ' << c << '\n';
            }
            reverse(ans.begin() , ans.end());
                cout << "YES\n" << ans.size() << '\n';
            for(auto& e:ans)cout << e ; cout <<'\n';
            return ;
        }
    }
    cout << "NO\n"; return ;
}
 
void solve(){
  int n,m; cin >> n >> m;
  
  vector<vector<cell> >vec(n , vector<cell>(m));
  
  for(int i =0 ; i<n; i++){
      for(int j =0 ; j<m ; j++){
          cin >> vec[i][j].ch; 
      }
  }
  
  // mujhe har ek monster cell se dfs chlana h
  
  for(int i =0 ; i<n ; i++){
      for(int j =0 ; j<m ; j++){
          if(vec[i][j].ch == 'M')dfs_m(i,j,vec,0);
      }
  }
  
  for(int i =0 ; i<n ; i++){
      for(int j =0 ; j<m ; j++){
          if(vec[i][j].ch == 'A'){
              vec[i][j].dis = 0;
              dfs_h(i+1,j,vec,i,j,1);
              dfs_h(i,j+1,vec,i,j,1);
              dfs_h(i-1,j,vec,i,j,1);
              dfs_h(i,j-1,vec,i,j,1);
          }
      }
  }
  
  TRACE(vec);
//   for(int i=0 ; i<n ; i++){
//       for(int j =0 ; j<m ; j++){
//           cout << vec[i][j].ch << ' ';
//       }
//       cout << '\n';
//   }
  
//   cout << "\n\n";
//   for(int i=0 ; i<n ; i++){
//       for(int j =0 ; j<m ; j++){
//           if(vec[i][j].dis>1e9)cout << "-1 ";
//           else cout << vec[i][j].dis << ' ';
//       }
//       cout << '\n';
//   }
  
//   cout << "\n\n";
//   for(int i=0 ; i<n ; i++){
//       for(int j =0 ; j<m ; j++){
//           cout << vec[i][j].move << ' ';
//       }
//       cout << '\n';
//   }
}
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin>> t; while(t--)
    solve();
}
