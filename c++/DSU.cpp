#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const int M = 1000000007;

//implementing DSU

ll findpar(ll node, vector<ll> &par)
{
    if (node == par[node])
        return node;
    return par[node] = findpar(par[node], par);
}

void unite(ll u, ll v, vector<ll> &rank, vector<ll> &par)
{
    u = findpar(u, par);
    v = findpar(v, par);

    if (rank[u] < rank[v])
    {
        par[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        par[v] = u;
    }
    else
    {
        par[u] = v;
        rank[v]++;
    }
}

int main()
{
    ll n, q;
    cin >> n >> q;

    vector<ll> par(n, 0);
    for (ll i = 0; i < n; i++)
    {
        par[i] = i;
    }

    vector<ll> rank(n, 0);

    while (q--)
    {
        ll t, a, b;
        cin >> t >> a >> b;

        if (t == 0)
        {
            unite(a, b, rank, par);
        }
        else
        {
            ll p1 = findpar(a, par);
            ll p2 = findpar(b, par);

            if (p1 == p2)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }
}
