#include<stdio.h>

int a[20][20], q[20], visited[20], n, f = 0, r = -1;
void bfs(int v) {
	for (int i = 1; i <= n; i++) {
		if (a[v][i] && !visited[i]) {
			q[++r] = i;
		}
	}
	if (f <= r) {
		visited[q[f]] = 1;
		bfs(q[f++]);
	}
}

int main() {
	int v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		q[i] = 0;
		visited[i] = 0;
	}
	// Enter graph data in matrix form
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	// Enter the starting vertex
	scanf("%d", &v);
	bfs(v);
	// The node which are reachable
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			printf("%d ", i);
		} else printf("\n Bfs is not possible");
	}
}
