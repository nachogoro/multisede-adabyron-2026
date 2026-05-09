#include <bits/stdc++.h>
using namespace std;

int contar(int a, int b) {
	int n = a + b;
	string s = string(a, 'A') + string(b, 'B');

	// "vistas" guarda TODAS las rotaciones de los collares ya contados.
	// Si el siguiente candidato aparece ahí, es una rotación de uno
	// ya contado y se ignora.
	set<string> vistas;
	int total = 0;

	do {
		if (vistas.count(s)) continue;
		++total;

		// Generamos y guardamos todas las rotaciones
		string doble = s + s;
		for (int i = 0; i < n; ++i)
			vistas.insert(doble.substr(i, n));
	} while (next_permutation(s.begin(), s.end()));

	return total;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// Memoizamos por (a, b). Como intercambiar los dos colores no
	// cambia la cuenta, normalizamos la clave a (min, max): el caché
	// pasa de 441 a 120 entradas distintas.
	map<pair<int,int>, int> cache;

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		pair<int,int> clave{min(a, b), max(a, b)};
		auto it = cache.find(clave);
		if (it == cache.end())
			it = cache.emplace(clave, contar(a, b)).first;
		cout << it->second << '\n';
	}
	return 0;
}
