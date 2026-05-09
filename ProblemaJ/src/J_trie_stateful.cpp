#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Trie con estado de consulta encapsulado: tras cada step(c) recuerda
// el nodo en el que se ha quedado y el premio acumulado, sin que el
// llamante tenga que repasar el prefijo completo en cada paso.
struct Trie {
	vector<array<int, 4>> hijos;
	vector<int> cnt;

	int actual;        // nodo en curso durante una consulta
	ll acumulado;      // suma de cnt[] de los nodos atravesados
	bool atascado;     // verdadero si en algún paso no había hijo

	Trie() {
		hijos.push_back({0, 0, 0, 0});
		cnt.push_back(0);
		reset();
	}

	static int idx(char c) {
		switch (c) {
			case '2': return 0;
			case '3': return 1;
			case '5': return 2;
			case '7': return 3;
		}
		return -1;
	}

	void insertar(const string& s) {
		int u = 0;
		for (char c : s) {
			int k = idx(c);
			if (hijos[u][k] == 0) {
				hijos.push_back({0, 0, 0, 0});
				cnt.push_back(0);
				hijos[u][k] = (int)hijos.size() - 1;
			}
			u = hijos[u][k];
			++cnt[u];
		}
	}

	void reset() {
		actual = 0;
		acumulado = 0;
		atascado = false;
	}

	void step(char c) {
		if (atascado) return;
		int sig = hijos[actual][idx(c)];
		if (sig == 0) { atascado = true; return; }
		actual = sig;
		acumulado += cnt[actual];
	}

	ll premio() const { return acumulado; }
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int m;
	while (cin >> m && m != 0) {
		Trie trie;
		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			trie.insertar(s);
		}

		int n;
		cin >> n;
		ll total = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			trie.reset();
			for (char c : s) trie.step(c);
			ll p = trie.premio();
			cout << p << '\n';
			total += p;
		}
		cout << total << '\n';
		cout << "---\n";
	}
	return 0;
}
