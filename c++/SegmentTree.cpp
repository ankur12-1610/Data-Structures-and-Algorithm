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

template<typename T>
struct SegmentTree{
	vector<T> st;
	void assign(vector<int> &v1) {
		int n = sz(v1);
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

int code() {

	// enter main code here

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
