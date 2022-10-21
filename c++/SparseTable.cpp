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
struct SparseTable{
	vector<vector<T>> st0, st1;
	void build(vector<T> &v1){
		int n = sz(v1);
		int n1 = __lg(n) + 1;
		st0 = vector<vector<T>>(n1, vector<T>(n));
		st1 = vector<vector<T>>(n1, vector<T>(n));
		rep(i, 0, n1) {
			rep(j, 0, n + 1 - (1 << i)) {
				if (!i)  st0[0][j] = st1[0][j] = v1[j];    //  base condition
				else {
					st0[i][j] = min(st0[i - 1][j], st0[i - 1][j + (1 << (i - 1))]);
					st1[i][j] = max(st1[i - 1][j], st1[i - 1][j + (1 << (i - 1))]);
				}
			}
			if (n < (1 << i))    break;
		}
	}
	T query(int lo, int hi, int tp) {
		// 0-indexed
		int x = __lg(hi - lo + 1);
		int y = 1 << x;
		if (tp == 0) return min(st0[x][lo], st0[x][hi - y + 1]);
		return max(st1[x][lo], st1[x][hi - y + 1]);
	}
};
// struct Node{
//     ll sum;
// };
SparseTable<ll> spar;

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
