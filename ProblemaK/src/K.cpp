#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int N;
		cin >> N;
		bool dias[7] = {false};
		for (int i = 0; i < N; ++i) {
			int a;
			cin >> a;
			dias[a % 7] = true;
		}
		int distintos = 0;
		for (int i = 0; i < 7; ++i) if (dias[i]) ++distintos;
		if (distintos == 7) cout << "LINEA\n";
		else cout << distintos << '\n';
	}
	return 0;
}
