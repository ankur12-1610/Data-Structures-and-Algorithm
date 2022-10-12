struct DSU {
	int par[N], _rank_[N], _size_[N], comp;
	
	void make_set(int v) {
		par[v] = v;
		_rank_[v] = 0;
		_size_[v] = 1;
		comp++;
	}
	void init(int n) {
		comp = 0;
		for (int i = 0; i < n; ++i) {
			make_set(i);
		}
	}
	int get(int v) {
		return par[v] = (v == par[v] ? v : get(par[v]));
	}
	bool merge(int a, int b) {
		a = get(a);
		b = get(b);
		if (a != b) {
			if (_rank_[a] < _rank_[b])
				swap(a, b);
			par[b] = a;
			if (_rank_[a] == _rank_[b])
				_rank_[a]++;

			if (_size_[a] < _size_[b])
			    swap(a, b);
			par[b] = a;
			_size_[a] += _size_[b];
			comp--;
			return true;
		}
		return false;
	}
} dsu;
