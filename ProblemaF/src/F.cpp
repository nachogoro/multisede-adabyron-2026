#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Dinic para flujo máximo con capacidades enteras (long long).
struct Dinic {
	struct Edge { int to, rev; ll cap; };
	vector<vector<Edge>> g;
	vector<int> level, iter;
	int n;

	Dinic(int n_) : g(n_), level(n_), iter(n_), n(n_) {}

	void add_edge(int u, int v, ll c) {
		g[u].push_back({v, (int)g[v].size(), c});
		g[v].push_back({u, (int)g[u].size() - 1, 0});
	}

	bool bfs(int s, int t) {
		fill(level.begin(), level.end(), -1);
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto &e : g[u]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[u] + 1;
					q.push(e.to);
				}
			}
		}
		return level[t] >= 0;
	}

	ll dfs(int u, int t, ll f) {
		if (u == t) return f;
		for (int &i = iter[u]; i < (int)g[u].size(); ++i) {
			auto &e = g[u][i];
			if (e.cap > 0 && level[e.to] == level[u] + 1) {
				ll d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					g[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	ll max_flow(int s, int t) {
		ll flow = 0;
		while (bfs(s, t)) {
			fill(iter.begin(), iter.end(), 0);
			while (ll f = dfs(s, t, LLONG_MAX)) flow += f;
		}
		return flow;
	}
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int T, M;
	while (cin >> T >> M && (T || M)) {
		vector<ll> c(T);
		for (auto &x : c) cin >> x;

		vector<vector<int>> conoce(M);
		vector<int> num_musicos(T, 0);

		for (int j = 0; j < M; ++j) {
			int n;
			cin >> n;
			conoce[j].resize(n);
			for (auto &x : conoce[j]) {
				cin >> x;
				--x;
				++num_musicos[x];
			}
		}

		// Si algún instrumento con partes pendientes no tiene a nadie
		// que lo sepa tocar, no hay forma de grabarlo.
		bool imposible = false;
		ll total_c = 0;
		for (int i = 0; i < T; ++i) {
			if (c[i] > 0 && num_musicos[i] == 0) imposible = true;
			total_c += c[i];
		}
		if (imposible) {
			cout << "IMPOSIBLE\n";
			continue;
		}

		// Para R tomas dadas, el problema es factible si el flujo
		// máximo de la red bipartita iguala el total de partes.
		auto factible = [&](ll R) {
			int S = 0, sumidero = M + T + 1;
			Dinic d(M + T + 2);
			for (int j = 0; j < M; ++j) {
				d.add_edge(S, j + 1, R);
				for (int i : conoce[j])
					d.add_edge(j + 1, M + 1 + i, R);
			}
			for (int i = 0; i < T; ++i)
				d.add_edge(M + 1 + i, sumidero, c[i]);
			return d.max_flow(S, sumidero) == total_c;
		};

		// Búsqueda binaria sobre el número de tomas. La cota superior
		// total_c es trivial: una parte por toma siempre cabe.
		ll lo = 1, hi = total_c;
		while (lo < hi) {
			ll mid = (lo + hi) / 2;
			if (factible(mid)) hi = mid;
			else lo = mid + 1;
		}
		cout << lo << '\n';
	}
	return 0;
}
