#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(int in, stack<int> &st, vector<bool>&visited, vector<int> graph[])
{
	visited[in]=true;
	for(auto it:graph[in])
	{
		if(!visited[it])
		{
			dfs(it,st,visited,graph);
		}
	}
	st.push(in);
}
void revDFS(int node, vector<bool> &visited, vector<int> transpose[], vector<int>&result)
{
	// cout<<node<<" ";
	result.push_back(node);
	visited[node]=true;
	for(auto it:transpose[node])
	{
		if(!visited[it])
		{
			revDFS(it,visited,transpose,result);
		}
	}
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
    auto start=chrono::high_resolution_clock::now();
    
    //code here
    
    int n, m;
    cin>>n>>m;
    vector<int> graph[n+1];
    for(int i=0;i<m;i++)
    {
    	int u, v;
    	cin>>u>>v;
    	graph[u].push_back(v);
    }

    //TOPO SORT
    stack<int> st;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++)
    {
    	if(!visited[i])
    	{
    		dfs(i,st,visited,graph);
    	}
    }

    //TRANSPOSE GRAPH
    vector<int> transpose[n+1];
    for(int i=1;i<=n;i++)
    {
    	visited[i]=false;
    	for(auto v:graph[i])
    	{
    		transpose[v].push_back(i);
    	}
    }


    while(!st.empty())
    {
    	int u=st.top();
    	st.pop();
    	if(!visited[u])
    	{
    		cout<<"SCC: ";
    		vector<int> result;
    		revDFS(u,visited,transpose,result);
    		for(int i=0;i<result.size();i++)
    		{
    			cout<<result[i]<<" ";
    		}
    		cout<<endl;
    	}
    }

    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr<<duration.count()/1000.0<<" ms\n";
}
