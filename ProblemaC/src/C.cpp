#include <bits/stdc++.h>
using namespace std;

const int LINF = INT_MAX;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int w;
		cin >> w;

		// Centinelas en 0 y w+1: aseguran que en los bordes del jardín
		// la regla "fuera la altura es mayor" se cumple sin casos
		// especiales.
		vector<int> h(w + 2);
		h[0] = LINF;
		h[w + 1] = LINF;

		vector<bool> mojada(w + 2, false);
		queue<int> q;

		for (int i = 1; i <= w; ++i) {
			cin >> h[i];
			if (h[i] <= 0) {
				mojada[i] = true;
				q.push(i);
			}
		}

		// BFS hacia atrás desde las celdas con agua: propagamos la
		// humedad a los vecinos que rodarían hacia la celda actual.
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			// El vecino izquierdo x-1 rueda hacia x si h[x] < h[x-1] < h[x-2].
			int l = x - 1;
			if (l >= 1 && !mojada[l] && h[l] > h[x] && h[l - 1] > h[l]) {
				mojada[l] = true;
				q.push(l);
			}

			// Simétrico por la derecha.
			int r = x + 1;
			if (r <= w && !mojada[r] && h[r] > h[x] && h[r + 1] > h[r]) {
				mojada[r] = true;
				q.push(r);
			}
		}

		int total = 0;
		for (int i = 1; i <= w; ++i) if (mojada[i]) ++total;
		cout << total << '\n';
	}
	return 0;
}
