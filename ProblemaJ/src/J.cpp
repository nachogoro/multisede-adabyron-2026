#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// Mapeo de los dígitos primos {2,3,5,7} a índices {0,1,2,3}.
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
		// Cada prefijo se codifica como un long long: arrancamos en 1
		// (un bit "raíz" que evita colisiones entre prefijos de distinta
		// longitud) y, por cada dígito, hacemos shift de 2 bits y OR
		// con su índice. Hasta 30 dígitos caben sin desbordar.
		unordered_map<ll, int> contador;
		contador.reserve(m * 30);  // evita rehashes durante la construcción

		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			ll v = 1;
			for (char c : s) {
				v = (v << 2) | idx(c);
				++contador[v];
			}
		}

		int n;
		cin >> n;
		ll total = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			ll premio = 0;
			ll v = 1;
			for (char c : s) {
				v = (v << 2) | idx(c);
				auto it = contador.find(v);
				if (it == contador.end()) break;
				premio += it->second;
			}
			cout << premio << '\n';
			total += premio;
		}
		cout << total << '\n';
		cout << "---\n";
	}
	return 0;
}
