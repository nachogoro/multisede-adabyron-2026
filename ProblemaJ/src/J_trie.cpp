#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	auto idx = [](char c) {
		switch (c) {
			case '2': return 0;
			case '3': return 1;
			case '5': return 2;
			case '7': return 3;
		}
		return -1;
	};

	int m;
	while (cin >> m && m != 0) {
		// Trie en una arena de vectores. El nodo 0 es la raíz; el
		// índice 0 se usa también como sentinela "sin hijo".
		vector<array<int, 4>> hijos;
		vector<int> cnt;
		hijos.push_back({0, 0, 0, 0});
		cnt.push_back(0);

		auto nuevo_nodo = [&]() {
			hijos.push_back({0, 0, 0, 0});
			cnt.push_back(0);
			return (int)hijos.size() - 1;
		};

		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			int u = 0;
			for (char c : s) {
				int k = idx(c);
				if (hijos[u][k] == 0) {
					int nuevo = nuevo_nodo();
					hijos[u][k] = nuevo;
				}
				u = hijos[u][k];
				++cnt[u];
			}
		}

		int n;
		cin >> n;
		ll total = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			ll premio = 0;
			int u = 0;
			for (char c : s) {
				int k = idx(c);
				if (hijos[u][k] == 0) break;
				u = hijos[u][k];
				premio += cnt[u];
			}
			cout << premio << '\n';
			total += premio;
		}
		cout << total << '\n';
		cout << "---\n";
	}
	return 0;
}
