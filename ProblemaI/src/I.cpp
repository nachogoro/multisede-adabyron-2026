#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		vector<ll> puntos(n + 1, 0);
		vector<bool> en_top(n + 1, false);

		// (puntuación, identificador). El multiset queda ordenado por
		// el primer campo y, en caso de empate, por el segundo.
		multiset<pair<ll,int>> top_set;   // los k mayores
		multiset<pair<ll,int>> rest_set;  // los n-k restantes

		for (int i = 1; i <= k; ++i) {
			en_top[i] = true;
			top_set.insert({0, i});
		}
		for (int i = k + 1; i <= n; ++i) {
			rest_set.insert({0, i});
		}

		for (int e = 0; e < m; ++e) {
			int p, d;
			cin >> p >> d;

			// Sacamos la entrada vieja, actualizamos y volvemos a insertar.
			if (en_top[p]) top_set.erase(top_set.find({puntos[p], p}));
			else rest_set.erase(rest_set.find({puntos[p], p}));
			puntos[p] += d;
			if (en_top[p]) top_set.insert({puntos[p], p});
			else rest_set.insert({puntos[p], p});

			// Si el mejor del resto supera al peor del top, basta un
			// intercambio: el envío solo ha cambiado un puntaje.
			if (!rest_set.empty() &&
			    rest_set.rbegin()->first > top_set.begin()->first) {
				auto sube = *rest_set.rbegin();
				auto baja = *top_set.begin();
				rest_set.erase(prev(rest_set.end()));
				top_set.erase(top_set.begin());
				en_top[sube.second] = true;
				en_top[baja.second] = false;
				top_set.insert(sube);
				rest_set.insert(baja);
			}

			cout << top_set.begin()->first;
			cout << (e + 1 == m ? '\n' : ' ');
		}
	}
	return 0;
}
