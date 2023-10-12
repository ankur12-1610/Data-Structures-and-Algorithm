#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// orderded_set ->  find_by_order(x)<itr, x being 0-indexed>; order_of_key(x)<count, strictly less>

typedef long long       ll;
typedef long double     lld;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
#define loop(n)         for(ll i = 0; i < (n); ++i)
#define rep(i,zz,n)     for(ll i = zz; i < (n); ++i)
#define repi(i,zz,n)    for(ll i = zz; i >= (n); --i)
#define all(v)          v.begin(),v.end()
#define pb              push_back
#define ff              first
#define ss              second
#define sz(x)           (int)x.size()
#define nline           cout << '\n'

#define     debug(x)    cout << #x << " "; _print(x); cout << '\n';
#define     _debug(a,b) cout << #a << " [ "; array_debug(a,b); cout << "]\n";
template <class T, class V> void array_debug(T *a, V n){ rep(i,0,n) cout << a[i] << ' ';}
template <class T>          void _print(T t) {cout << t;}
template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.ff); cout << ","; _print(p.ss); cout << "}";}
template <class T>          void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>          void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T>          void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]";}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]";}

const lld eps = 1e-9;
const int mod = 1e9 + 7;
const ll inf = 1e18;
const int N1 = 2e5 + 10;

// vector<vector<int>> adj;
// vector<ll> val;
// the vector to work on ..... lets call that "val"

// need to call segtree as well ???
template<typename T>
struct HeavyLight {
    vector<vector<int>> up;
    vector<int> depth, tin, tout, pos, heavy_child, chain_head;
    vector<T> tmp;
    int tmm, n, n1;
    // SegmentTree<Node> seg;

    void assign() {
        n = sz(adj), n1 = __lg(n) + 1, tmm = 0;
        up = vector<vector<int>>(n, vector<int>(n1, -1));
        depth = vector<int>(n, -1);
        tin = vector<int>(n);
        tout = vector<int>(n);
        pos = vector<int>(n);
        heavy_child = vector<int>(n, -1);
        chain_head = vector<int>(n);
        tmp = vector<T>(n);

        dfs_init(0);
        rep(i, 1, n1) {
            rep(j, 0, n) {
                if (up[j][i - 1] != -1) {
                    up[j][i] = up[up[j][i - 1]][i - 1];
                }
            }
        }

        tmm = 0;
        decompose(0, 0);
        seg.assign(tmp);
    }

    int dfs_init(int i) {
        int sz = 1, mxx_chldsz = 0;
        tin[i] = tmm++;
        for (int x : adj[i]) {
            if (x == up[i][0])   continue;

            up[x][0] = i, depth[x] = depth[i] + 1;
            int cur_sz = dfs_init(x);
            if (cur_sz > mxx_chldsz)    mxx_chldsz = cur_sz, heavy_child[i] = x;
            sz += cur_sz;
        }
        tout[i] = tmm++;
        return sz;
    }

    void decompose(int i, int cur_head) {
        chain_head[i] = cur_head, pos[i] = tmm++;
        tmp[pos[i]] = val[i];

        if (heavy_child[i] != -1) decompose(heavy_child[i], cur_head);
        for (int x : adj[i]) {
            if (x == up[i][0] || x == heavy_child[i])    continue;
            decompose(x, x);
        }
    }

    bool is_anc(int i, int j) {
        return tin[i] <= tin[j] && tout[i] >= tout[j];
    }

    int lca(int x, int y) {
        if (depth[x] > depth[y])    swap(x, y);
        if (is_anc(x, y))   return x;

        repi(i, n1 - 1, 0) {
            if (up[x][i] != -1 && is_anc(up[x][i], y) == 0) {
                x = up[x][i];
            }
        }
        return up[x][0];
    }

    // including lca, [lca, i]
    T query_chain(int i, int lc) {
        T z = 0;
        while (chain_head[i] != chain_head[lc]) {
            z = z + seg.query(1, 0, n - 1, pos[chain_head[i]], pos[i]).sum; //  check !!!!
            i = up[chain_head[i]][0];
        }
        z = z + seg.query(1, 0, n - 1, pos[lc], pos[i]).sum;     //  check !!!!
        return z;
    }

    T query(int x, int y) {
        int lc = lca(x, y);
        return query_chain(x, lc) + query_chain(y, lc) - val[lc];     //  check !!!!
        // lc has been included TWICE !!!
    }

    void update(int i, T x) {
        val[i] = x;
        seg.update_one(1, 0, n - 1, pos[i], x);
        // whether adding or changing should be checked in segtree
    }
};
HeavyLight<ll> hld;   //  check int or ll !!!!

int code() {

    // enter main code

    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    int tc = 1;
    cin >> tc;

    loop(tc)  code();
    // rep(i, 1, tc + 1)  cout << "Case #" << i << ": ", code();

    return 0;
}