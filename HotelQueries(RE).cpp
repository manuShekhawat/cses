// हौसला दिलाएगा मंज़िल
 
#include<bits/stdc++.h>

using namespace std;

#define int long long

struct SegTree{

    vector<pair<int,int> >tree; 
    vector<pair<int,int> >A;
    SegTree(vector<pair<int,int> >& a){
          A  = a;
          int n = a.size();
          tree.resize(4*(n+1));
          build(1,1,n);
    }

    pair<int,int> cmp(pair<int,int>& p1 , pair<int,int>& p2){
        if(p1.first == p2.first){
           if(p1.second>p2.second)return p2;
           else return p1;
        }
        else return max(p1,p2);
    }

    void build(int node , int s, int e){
         if(s==e){
             tree[node] = A[e-1]; return ;
         }
         int mid = (s+e)/2;
         build(2*node, s,mid); build(2*node+1, mid+1, e);
         tree[node] = cmp(tree[2*node] , tree[2*node+1]);
    }
    
    void update(int node , int s, int e,pair<int,int>& val){ 
          if(s==e && e==(val.second+1)){
              tree[node] =val; return ;
          }
          int tar = val.second+1;
          if(s>tar or e<tar){
              return ;
          } 
          int mid = (s+e)/2;

          update(2*node, s, mid, val); update(2*node+1,mid+1,e,val);
          tree[node] = cmp(tree[2*node] , tree[2*node+1]);         
    }

    int query(int node , int r){
         if(tree[node].first<r)return 0;
         if(tree[2*node].first>=r){
             return query(2*node,r);
         }
         else if(tree[2*node+1].first>=r){
             return query(2*node+1,r);
         }
         else return tree[node].second+1;
    }

    void Print(){
        cout<< "YES\n";
        for(auto&e:tree){
            cout << e.first << ' ';
        }
        cout << '\n';
        for(auto& e:tree){
            cout << e.second << ' ';
        }cout << '\n';
    }

};

void solve(){
  int n,q; cin >> n >> q;
  vector<pair<int,int> >a(n); for(int i = 0; i<n ; i++)cin >> a[i].first; for(int i =0 ; i<n ; i++)a[i].second = i;
  SegTree S(a);
//   S.Print();

  while(q--){
      pair<int,int>k;
      int r; cin >> r; int temp;
      cout << (temp = S.query(1,r)) << ' ';
      temp--; 
      if(temp>=0){a[temp].first-=r;S.update(1,1,n, k = {a[temp].first,a[temp].second});}
  }
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   
//   int t;cin >> t; while(t--)
   solve();
}
