#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
const int M = 1000000007;

// implemeting Kruskal Algorithm

bool comparator(tuple & a, tuple &b){
    return get<2>(a) < get<2>(b);
}

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
  

    ll n,m;
    cin >> n >> m;

    vector<tuple<ll, ll, ll>> edges;
    for (ll i = 0;i<m;i++){
        ll a, b, wt;
        cin >> a >> b >> wt;
        a--, b--;
        edges.push_back(make_tuple(a, b, wt));
    }

    sort(edges.begin(), edges.end(), comparator);

    vector<ll> par(n, 0);
    for (ll i = 0; i < n; i++)
    {
        par[i] = i;
    }

    vector<ll> rank(n, 0);

    vector<pair<ll, ll>> mst;
    ll wt=0;

    for(auto &i: edges){
        ll n1 = get<0>(i);
        ll n2 = get<1>(i);

        ll p1 = findpar(n1, par);
        ll p2 = findpar(n2, par);

        if(p1!=p2){
            unite(n1, n2, rank, par);
            wt += get<2>(i);
            mst.push_back({n1, n2});
        }
    }

    cout << wt << endl;
    for (ll i = 0; i < n - 1;i++){
        cout << mst[i].first << " " << mst[i].second << endl;
    }
}
