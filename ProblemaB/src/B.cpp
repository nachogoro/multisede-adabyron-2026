#include <bits/stdc++.h>
using namespace std;

int mod(int a, int n) {
	// Queremos el resultado con el mismo signo que n, no basta %
	return ((a % n) + n) % n;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, rotor_inicial;
	cin >> n >> rotor_inicial;
	cin.ignore();  // descartar el salto de línea tras los dos números

	while (n--) {
		string linea;
		getline(cin, linea);
		int rotor = rotor_inicial;
		for (char& c : linea) {
			if (c >= 'A' && c <= 'Z') {
				// Restamos el rotor (mod 26).
				c = 'A' + mod(c - 'A' - rotor, 26);
				rotor = (rotor + 1) % 26;
			}
		}
		cout << linea << '\n';
	}
	return 0;
}
