#include <iostream>
#include <climits>

using namespace std;

void leeArcos (int mat[100][100], int p[100][100], int m) {
	int a, b, c;
	for (int i = 0; i < 100; i++) {
		p[i][i] = mat[i][i] = 0;
		for (int j = i + 1; j < 100; j++) {
			mat[i][j] = mat[j][i] = INT_MAX;
			p[i][j] = p[j][i] = -1;
		}
	}
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		mat[a - 1][b - 1] = mat[b - 1][a - 1] = c;
	}
}

void floyd (int mat[100][100], int p[100][100], int n) {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && 
				    mat[i][k] + mat[k][j] < mat[i][j]) {
					mat[i][j] = mat[i][k] + mat[k][j];
					p[i][j] = k;
				}
			}
		}
	}
}

void checaTrayectoria (int p[100][100], int a, int b) {
	if(p[a][b] != -1){
		checaTrayectoria(p, a, p[a][b]);
		cout << (p[a][b] + 1) << '-';
		checaTrayectoria(p, p[a][b], b);
	}
}

void consulta (int mat[100][100], int p[100][100], int q) {
	int a, b;
	for (int i = 1; i <= q; i++){
		cin >> a >> b;
		if (mat[a - 1][b - 1] == INT_MAX){
			cout << "no path" << endl;
		}
		else{
			cout << "Costo: " << mat[a - 1][b - 1] << " Path: " << a << '-';
			checaTrayectoria(p, a - 1, b - 1);
			cout << b << endl;
		}
	}
}

int main () {
	int mat[100][100];
	int p[100][100];
	int n, m, q;
	// n - Cant Nodos
	// m - Cant Arcos
	// q - Cant de Consultas
	cin >> n >> m >> q;
	leeArcos (mat, p, m) ;
	floyd (mat, p, n) ;
	consulta (mat, p, q) ;
}
/*
7 9 3
1 2 50
1 3 60
2 4 120
2 5 90
3 6 50
4 6 80
4 7 70
5 7 40
6 7 140
1 7
2 6
6 2
*/