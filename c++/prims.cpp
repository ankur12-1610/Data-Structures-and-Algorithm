#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int INF = 1e9;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    auto start=chrono::high_resolution_clock::now();
    
    //code here
    
    int vertices, edges;
    cin>>vertices>>edges;
    vector<pair<int,int>> graph[vertices+1];
    for(int i=0;i<edges;i++)
    {
    	int u, v, w;
    	cin>>u>>v>>w;
    	graph[u].push_back({v,w});
    	graph[v].push_back({u,w});
    }
    int parent[vertices+1];
    int key[vertices+1];
    bool mst[vertices+1];
    for(int i=1;i<=vertices;i++)
    {
    	key[i]=INF;
    	mst[i]=false;
    	parent[i]=-1;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
    key[1]=0;
    pq.push({0,1});
    for(int i=0;i<vertices-1;i++)
    {
    	int u=pq.top().second;
    	pq.pop();
    	mst[u]=true;
    	for(auto it:graph[u])
    	{
    		int v=it.first;
    		int w=it.second;
    		if(mst[v]==false && w<key[v])
    		{
    			key[v]=w;
    			parent[v]=u;
    			pq.push({key[v],v});
    		}
    	}
    }
    
   	cout<<"MST is as follows :--"<<endl;
   	for(int i=2;i<=vertices;i++)
   	{
   		cout<<parent[i]<<"---"<<i<<endl;
   	}


    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr<<duration.count()/1000.0<<" ms\n";
}