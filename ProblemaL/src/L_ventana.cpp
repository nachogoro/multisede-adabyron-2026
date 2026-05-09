#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	ll T;
	while (cin >> N >> T) {
		vector<ll> a(N + 3, 0), b(N + 3, 0);
		for (int i = 1; i <= N; ++i) {
			ll x;
			cin >> x;
			a[i] = a[i - 1] + (x > 0 ? x : 0);
			b[i] = b[i - 1] + (x < 0 ? -x : 0);
		}
		a[N + 1] = a[N];
		b[N + 1] = b[N] + T;
		a[N + 2] = a[N + 1] + T;
		b[N + 2] = b[N + 1];

		// next_after_win[i] = índice donde empieza la siguiente partida
		// si la que arranca en i la ganamos; -1 si la pierde el rival.
		// Un solo vector basta: el -1 codifica el resultado "derrota"
		// y los demás valores hacen también de índice de continuación.
		vector<int> next_after_win(N + 3, -1);

		// Dos punteros que solo avanzan: como tanto el índice donde
		// nosotros cruzamos $T$ como el índice donde lo cruza el rival
		// son no decrecientes en i, cada puntero recorre como mucho
		// $N + 2$ posiciones a lo largo de todo el barrido.
		int k_ours = 1, k_rival = 1;
		for (int i = 1; i <= N + 1; ++i) {
			if (k_ours  < i) k_ours  = i;
			while (a[k_ours]  < a[i - 1] + T) ++k_ours;

			if (k_rival < i) k_rival = i;
			while (b[k_rival] < b[i - 1] + T) ++k_rival;

			if (k_ours < k_rival) next_after_win[i] = k_ours + 1;
		}

		vector<int> dp(N + 4, 0);
		for (int i = N + 1; i >= 1; --i) {
			dp[i] = (next_after_win[i] == -1) ? 0
			                                  : 1 + dp[next_after_win[i]];
		}

		int ans = 0;
		for (int i = 1; i <= N + 1; ++i) ans = max(ans, dp[i]);
		cout << ans << '\n';
	}
	return 0;
}
