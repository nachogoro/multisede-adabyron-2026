#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int V;
	cin >> V;

	// Punto de partida: el menor número que acaba en 5 y es >= V.
	int v = (V / 10) * 10 + 5;
	if (v < V) v += 10;

	// A partir de aquí solo visitamos números acabados en 5 (vamos
	// subiendo de 10 en 10) hasta no acabar en 15.
	if (v % 100 == 15) v += 10;

	cout << v << '\n';
	return 0;
}
