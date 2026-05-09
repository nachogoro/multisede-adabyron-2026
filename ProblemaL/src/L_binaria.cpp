#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int N;
	ll T;
	while (cin >> N >> T) {
		// Sumas prefijas separadas para nuestros puntos y los del
		// rival (cada ronda solo afecta a una de las dos).
		vector<ll> a(N + 3, 0), b(N + 3, 0);
		for (int i = 1; i <= N; ++i) {
			ll x;
			cin >> x;
			a[i] = a[i - 1] + (x > 0 ? x : 0);
			b[i] = b[i - 1] + (x < 0 ? -x : 0);
		}

		// Dos centinelas: el primero (N+1) regala T puntos al rival;
		// el segundo (N+2) nos los regala a nosotros. Toda partida que
		// no haya terminado dentro de las N rondas la pierde el rival,
		// y además ambas búsquedas binarias siempre encuentran un
		// índice válido — no hace falta tratar el caso "no se llega".
		a[N + 1] = a[N];
		b[N + 1] = b[N] + T;
		a[N + 2] = a[N + 1] + T;
		b[N + 2] = b[N + 1];

		// dp[i] = máxima racha de partidas seguidas que ganamos si la
		// primera empieza en la ronda i. Vamos rellenando desde el final.
		vector<int> dp(N + 4, 0);
		for (int i = N + 1; i >= 1; --i) {
			ll va = a[i - 1] + T;
			ll vb = b[i - 1] + T;

			// Primer k >= i en el que cada equipo cruzaría el umbral.
			// Las prefijas son no decrecientes, así que basta una
			// búsqueda binaria sobre cada vector.
			int end_ours  = (int)(lower_bound(a.begin() + i,
			                                  a.begin() + N + 3, va) - a.begin());
			int end_rival = (int)(lower_bound(b.begin() + i,
			                                  b.begin() + N + 3, vb) - b.begin());

			if (end_ours < end_rival) {
				// Ganamos en end_ours; la siguiente partida empieza
				// justo después.
				dp[i] = 1 + dp[end_ours + 1];
			} else {
				// El rival gana esta partida, racha rota.
				dp[i] = 0;
			}
		}

		int ans = 0;
		for (int i = 1; i <= N + 1; ++i) ans = max(ans, dp[i]);
		cout << ans << '\n';
	}
	return 0;
}
