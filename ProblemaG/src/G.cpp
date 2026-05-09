#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> hijos;
vector<int> color;  // 0 = blanco, 1 = gris (en este DFS), 2 = negro (cerrado)

bool dfs(int u) {
	color[u] = 1;
	for (int v : hijos[u]) {
		if (color[v] == 1) return true;          // arista hacia atrás: ciclo
		if (color[v] == 0 && dfs(v)) return true;
		// si color[v] == 2 ya está cerrado, podamos
	}
	color[u] = 2;
	return false;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;

		hijos.assign(N + 1, {});
		for (int i = 1; i <= N; ++i) {
			int M;
			cin >> M;
			while (M--) {
				int a;
				cin >> a;
				// Arista del antecesor al descendiente.
				hijos[a].push_back(i);
			}
		}

		color.assign(N + 1, 0);
		bool ciclo = false;
		for (int i = 1; i <= N && !ciclo; ++i) {
			if (color[i] == 0 && dfs(i)) ciclo = true;
		}
		cout << (ciclo ? "NO" : "SI") << '\n';
	}
	return 0;
}
