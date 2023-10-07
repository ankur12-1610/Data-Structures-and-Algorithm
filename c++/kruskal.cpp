#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e5;
class DSU
{
public:
	int parent[N+1];
	int Rank[N+1];
	DSU(int n)
	{
		for(int i=1;i<=n;i++)
		{
			parent[i]=i;
			Rank[i]=0;
		}
	}
	int findPar(int node)
	{
		if(node==parent[node])
			return node;
		else return parent[node] = findPar(parent[node]);
	}
	void Union(int u, int v)
	{
		u=findPar(u);
		v=findPar(v);
		if(u!=v)
		{
			if(Rank[u]<Rank[v])
			{
				parent[u]=v;
			}	
			else if(Rank[u]>Rank[v])
			{
				parent[v]=u;
			}
			else
			{
				parent[v]=u;
				Rank[u]++;
			}
		}
	}	
};
bool cmp(pair<pair<int,int>,int> p1, pair<pair<int,int>,int> p2)
{
	return p1.second<p2.second;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    auto start=chrono::high_resolution_clock::now();
    
    //code here
   	int vertices, edges;
   	cin>>vertices>>edges;
   	pair<pair<int,int>,int> graph[edges];
   	for(int i=0;i<edges;i++)
   	{
   		int u, v, w;
   		cin>>u>>v>>w;
   		graph[i]={{u,v},w};
   	}
   	sort(graph,graph+edges,cmp);
   	DSU d(vertices);
   	int cnt=0;
   	int cost=0;
   	vector<pair<pair<int,int>,int>> ans;
   	for(int i=0;i<edges;i++)
   	{
   		if(cnt==vertices-1)
   		{
   			break;
   		}
   		int u, v, w;
   		u=graph[i].first.first;
   		v=graph[i].first.second;
   		w=graph[i].second;
   		if(d.findPar(u)==d.findPar(v))
   		{
   			continue;
   		}	
   		ans.push_back({{u,v},w});
   		cnt++;
   		cost+=w;
   		d.Union(u,v);
   	}
   	cout<<"Minimum Cost of the MST is  = "<<cost<<endl;
   	cout<<"MST is as follows :--"<<endl;
   	for(int i=0;i<ans.size();i++)
   	{
   		int u, v, w;
   		u=ans[i].first.first;
   		v=ans[i].first.second;
   		w=ans[i].second;
   		cout<<u<<"----"<<v<<" == "<<w<<endl;
   	}




    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr<<duration.count()/1000.0<<" ms\n";
}