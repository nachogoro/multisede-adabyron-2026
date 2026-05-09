#include <bits/stdc++.h>
using namespace std;

const int LINF = INT_MAX;

vector<int> h;
vector<int> estado;  // -1 = sin calcular, 0 = seco, 1 = mojado.

int resolver(int x) {
	if (estado[x] != -1) return estado[x];
	if (h[x] <= 0) return estado[x] = 1;
	if (h[x - 1] > h[x] && h[x + 1] < h[x]) return estado[x] = resolver(x + 1);
	if (h[x + 1] > h[x] && h[x - 1] < h[x]) return estado[x] = resolver(x - 1);
	return estado[x] = 0;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int w;
		cin >> w;

		h.assign(w + 2, LINF);  // los extremos quedan como centinelas.
		for (int i = 1; i <= w; ++i) cin >> h[i];
		estado.assign(w + 2, -1);

		int total = 0;
		for (int i = 1; i <= w; ++i) total += resolver(i);
		cout << total << '\n';
	}
	return 0;
}
