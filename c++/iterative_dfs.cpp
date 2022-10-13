#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cout << "\nEnter the number of vertices : ";
	cin >> n;
	
	cout << "\nEnter the number of edges : ";
	cin >> m;

	vector<vector<int>> adj(n);
	// adjacency list of the graph
	cout << "\nEnter the vertices which are connected using the edges.\n";
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	vector<bool> vis(n);
	// visited array, to check if the node has been traversed yet or not
	vector<int> dfs;
	// to maintain the order of nodes in which they are traversed

	stack<int> stack1;
	for (int i = 0; i < n; i++) {
		if (vis[i])	continue;

		stack1.push(i);
		while (!stack1.empty()) {
			int x = stack1.top();
			stack1.pop();

			if (vis[x])	continue;

			vis[x] = 1;
			dfs.push_back(x);
			for (auto it = adj[x].rbegin(); it != adj[x].rend(); it++){
				if (vis[*it])	continue;
				stack1.push(*it);
			}
		}
	}
	
	cout << "\nThe DFS traversal order is : \n";
	for (int i = 0; i < n; i++) {
		cout << dfs[i] << ' ';
	}
	cout << "\n\n";

	return 0;
}
