#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const int M = 1000000007;

//implementing Topological Sort

void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &state, stack<ll> &s, ll &fl)
{

    state[node] = 1;
    for (ll i = 0; i < adj[node].size(); i++)
    {
        ll ch = adj[node][i];
        if (fl == 0)
            return;

        if (state[ch] == 0)
        {
            dfs(ch, adj, state, s, fl);
        }
        else if (state[ch] == 1)
        {
            fl = 0;
            return;
        }
    }

    s.push(node);
    state[node] = 2;
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
    // auto start = chrono::high_resolution_clock::now();

    // code here. dont use mbinpow,binpow,right, fact and isprime as function names

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;

        adj[a - 1].push_back(b - 1);
    }

    vector<ll> state(n, 0);
    stack<ll> s;
    ll fl = 1;

    for (ll i = 0; i < n; i++)
    {
        if (state[i] == 0)
        {
            dfs(i, adj, state, s, fl);
        }
    }

    if (fl == 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    while (s.empty() == 0)
    {
        ll node = s.top();
        s.pop();

        cout << node + 1 << " ";
    }
}
