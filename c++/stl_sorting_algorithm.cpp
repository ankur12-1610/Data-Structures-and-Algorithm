#include <bits/stdc++.h>
using namespace std;

static mt19937_64 gen(chrono::duration_cast<chrono::nanoseconds>
                      (chrono::high_resolution_clock::now().time_since_epoch()).count());

// random numbers in [L, R] (inclusive)
int GetRand(int L = 0, int R = numeric_limits<int>::max()) {
	uniform_int_distribution<int> dis(L, R);
	return dis(gen);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> v(10);
	for (int i = 0; i < 10; i++) {
		v[i] = GetRand(0, 10000);
	}
	sort(v.begin(), v.end());
	for (auto &x: v) {
		cout << x << ' ';
	}
}
