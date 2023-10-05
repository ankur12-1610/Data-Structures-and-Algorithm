vector<vector<ll>> g(N), up(N, vector<ll> (100, -1));
vector<ll> lvl(N);

void dfs(ll node, ll par, ll level){
	lvl[node] = level;

	for(auto it: g[node]){
		if(it != par){
			dfs(it, node, level + 1);
		}
	}
}


void binary_lift(ll src, ll par){
	up[src][0] = par;
	for(ll i = 1; i < 20; i++){
		if(up[src][i-1] != -1){
			up[src][i] = up[up[src][i-1]][i-1];
		}
		else up[src][i] = -1;
	}

	for(auto it: g[src]){
		if(it != par){
			binary_lift(it, src);
		}
	}
}

ll lift_node(ll node, ll jump_req){

	for(ll i = 19; i>=0; i--){
		if(node == -1 or jump_req == 0){
			break;
		}
		if(jump_req >= (1<<i)){
			jump_req -= (1<<i);
			node = up[node][i];
		}
	}
	return node;
}

ll LCA(ll u, ll v){
	if(lvl[u] < lvl[v]){
		swap(u,v);
	}

    // u and v are now at the same level
	u = lift_node(u, lvl[u] - lvl[v]);

	if(u == v) return u;

	for(ll i = 19; i >=0; i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i]; v = up[v][i];
		}
	}
	return lift_node(u,1);
}