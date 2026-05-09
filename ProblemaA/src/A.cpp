#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		// Guardamos (prioridad, cliente) para que el orden lexicográfico
		// por defecto de pair coincida con el criterio pedido.
		vector<pair<int,int>> archivadores(n);
		for (int i = 0; i < n; ++i) {
			int w, p;
			cin >> w >> p;
			archivadores[i] = {p, w};
		}

		sort(archivadores.begin(), archivadores.end());

		for (int i = 0; i < n; ++i) {
			auto [p, w] = archivadores[i];
			cout << w << ' ';
			if (p == 6) cout << "ROTO";
			else cout << p;
			if (i + 1 < n) cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}
