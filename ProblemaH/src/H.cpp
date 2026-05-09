#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N, M, S;
	while (cin >> N >> M >> S) {
		int D;
		cin >> D;

		vector<vector<pair<int,int>>> g(N + 1);  // g[u] = lista de (v, peso)
		for (int i = 0; i < M; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}

		const int INF = INT_MAX;
		vector<int> dist(N + 1, INF);
		vector<int> padre(N + 1, -1);
		dist[S] = 0;

		priority_queue<pair<int,int>, vector<pair<int,int>>,
		               greater<pair<int,int>>> pq;
		pq.push({0, S});

		while (!pq.empty()) {
			auto [d, u] = pq.top();
			pq.pop();
			if (d > dist[u]) continue;        // entrada obsoleta
			if (u == D) break;                // ya tenemos la distancia óptima
			for (auto [v, w] : g[u]) {
				int nd = d + w;
				if (nd < dist[v]) {
					dist[v] = nd;
					padre[v] = u;
					pq.push({nd, v});
				}
			}
		}

		// Reconstruimos el camino siguiendo los padres desde D hasta S.
		vector<int> camino;
		for (int u = D; u != -1; u = padre[u]) camino.push_back(u);
		reverse(camino.begin(), camino.end());

		for (size_t i = 0; i < camino.size(); ++i) {
			if (i) cout << ' ';
			cout << camino[i];
		}
		cout << " -> " << dist[D] << '\n';
	}
	return 0;
}
