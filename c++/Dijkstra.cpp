#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const int M = 1000000007;

// implemeting Dijkstra Algorithm

void dfs(ll node, vector<vector<ll>> &adj, vector<ll> &state, stack<ll> &s, ll &fl, vector<ll> &cycle)
{

    state[node] = 1;
    s.push(node);
    for (ll i = 0; i < adj[node].size(); i++)
    {
        ll ch = adj[node][i];
        if (fl == 0)
            return;

        if (state[ch] == 0)
        {
            dfs(ch, adj, state, s, fl, cycle);
        }
        else if (state[ch] == 1)
        {
            fl = 0;

            cycle.push_back(ch);

            while (s.top() != ch)
            {
                ll c = s.top();
                cycle.push_back(c);
                s.pop();
            }
            cycle.push_back(ch);

            return;
        }
    }

    s.pop();
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
    ll src;
    cin >> src;

    vector<vector<pair<ll, ll>>> adj(n);
    for (ll i = 0; i < m; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    vector<ll> dist(n, INT_MAX);
    dist[src] = 0;
    set<pair<ll, ll>> s;
    s.insert({0, src});

    while (s.empty() == 0)
    {
        auto ptr = s.begin();
        auto p = *ptr;
        s.erase(ptr);

        ll node = p.second;
        ll d = p.first;

        if (d <= dist[node])
        {
            for (ll i = 0; i < adj[node].size(); i++)
            {
                ll ch = adj[node][i].first;
                ll t = adj[node][i].second;

                if (t + d < dist[ch])
                {
                    dist[ch] = t + d;
                    s.insert({dist[ch], ch});
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}
