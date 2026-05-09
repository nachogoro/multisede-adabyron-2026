#include <bits/stdc++.h>
using namespace std;

// Función phi de Euler: cuenta los enteros en [1, n] coprimos con n.
int phi(int n) {
	int result = n;
	for (int p = 2; (long long)p * p <= n; ++p) {
		if (n % p == 0) {
			while (n % p == 0) n /= p;
			result -= result / p;
		}
	}
	if (n > 1) result -= result / n;
	return result;
}

long long binomial(int n, int k) {
	if (k < 0 || k > n) return 0;
	if (k > n - k) k = n - k;
	long long c = 1;
	for (int i = 0; i < k; ++i)
		c = c * (n - i) / (i + 1);
	return c;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int n = a + b;

		// Aplicamos directamente la fórmula derivada en EXPLICACION.md:
		//   (1/n) · Σ_{k | n, k | a}  φ(k) · C(n/k, a/k)
		long long suma = 0;
		for (int k = 1; k <= n; ++k) {
			if (n % k == 0 && a % k == 0)
				suma += (long long)phi(k) * binomial(n / k, a / k);
		}
		cout << suma / n << '\n';
	}
	return 0;
}
