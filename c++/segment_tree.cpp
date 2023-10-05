#include<bits/stdc++.h>                                        //  ॐ           
#include<ext/pb_ds/tree_policy.hpp>                            // Har Har Mahadev                                                    
#include<ext/pb_ds/assoc_container.hpp>
                                                                                                                
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


#define rep(i, zz, n) for (int i = zz; i < (n); ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define F first
#define S second
#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define PI 3.14159265358979323846
#define el '\n'
#define sp " "
#define vl vector<ll>
#define dbg(x) cout << #x << ": " << x << " ";

const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll N = 1e6 + 5;

#define     debug(x)    cout << #x << " "; _print(x); cout << '\n';
#define     _debug(a,b) cout << #a << " [ "; array_debug(a,b); cout << "]\n";
template <class T, class V> void array_debug(T *a, V n){ rep(i,0,n) cout << a[i] << ' ';}
template <class T>          void _print(T t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T>          void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>          void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>          void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

//greedy/brute force/DP/Graph/binary search/?

template<typename T>
struct SegmentTree{
     vector<T> st;
     void assign(vector<int> &v1) {
          int n = (v1.size());
          st = vector<T>(4 * n + 1);
          build(v1, 1, 0, n - 1);
     }
     T combine(T x, T y) {
          // T z;
          // return z;
          return { x.sum + y.sum }; // check which opeartion is to be performed
     }
     void build(vector<int>& v1, int v, int tl, int tr) {
          if (tl == tr) {
               st[v].sum = v1[tl]; //  check
          }
          else{
               int mid = (tl + tr) / 2;
               build(v1, 2 * v, tl, mid);
               build(v1, 2 * v + 1, mid + 1, tr);
               st[v] = combine(st[2 * v], st[2 * v + 1]);
          }
     }
     // tl, tr   : the current segment/range whose node/vertex is v
     //  l,  r   : the segment/range on which the 'range query' is to be performed
     T query(int v, int tl, int tr, int l, int r) {
          if (tr < l || r < tl) {
               return { 0 }; // check which opeartion is to be performed
          }
          else if (tl == l && tr == r) {
               return st[v];
          }
          int mid = (tl + tr) / 2;
          return combine(query(2 * v, tl, mid, l, min(r, mid)), query(2 * v + 1, mid + 1, tr, max(l, mid + 1), r));
     }
     void update_one(int v, int tl, int tr, int pos, int newVal) {
          if (tl == tr) {
               st[v].sum = newVal;
               // check whether the newVal is added or updated
               return;
          }
          int mid = (tl + tr) / 2;
          if (pos <= mid) {
               update_one(2 * v, tl, mid, pos, newVal);
          }
          else{
               update_one(2 * v + 1, mid + 1, tr, pos, newVal);
          }
          st[v] = combine(st[2 * v], st[2 * v + 1]);
     }
};
struct Node{
     int sum;
};
SegmentTree<Node> seg;


void __roOTs(){          
               // main code here

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tt = 1; cin >> tt;
    for (int i = 1; i <= tt; i++){
        // cout << "Case #" << i << ": ";
        __roOTs(); cout << '\n';
        
    }
    return 0;
}