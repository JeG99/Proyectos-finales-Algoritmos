// José Elías Garza Vázquez - A00824494
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

void leeArcos (int mat[100][100], int p[100][100], int m) {
	int a, b, c;
	for (int i = 0; i < 100; i++) {
		p[i][i] = mat[i][i] = 0;
		for (int j = i + 1; j < 100; j++) {
			mat[i][j] = mat[j][i] = INT_MAX;
			p[i][j] = p[j][i] = 0;
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
				    max(mat[i][k], mat[k][j]) < mat[i][j]) {
					mat[i][j] = max(mat[i][k], mat[k][j]);
					p[i][j] = k;
				}
			}
		}
	}
}
/*
void checaTrayectoria (int p[100][100], int a, int b) {
	
}
*/
void consulta (int mat[100][100], int p[100][100], int q, string& output, int caseN) {
	output += "Case " + to_string(caseN) + ':';
	int a0, b0;
	vector<int> a;
	vector<int> b;
	for (int i = 1; i <= q; i++){
		cin >> a0 >> b0;
		a.push_back(a0);
		b.push_back(b0);
	}
	for(int j = 0; j < a.size(); j++){
		if (mat[a[j] - 1][b[j] - 1] == INT_MAX){
			output += "\nno path";
		}
		else{
			output += "\n" + to_string(mat[a[j] - 1][b[j] - 1]);
		}
	}
	output += '\n';
}

int main () {
	string out = "";
	int mat[100][100];
	int p[100][100];
	int cases, n, m, q;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		// n - Cant Nodos
		// m - Cant Arcos
		// q - Cant de Consultas
		cin >> n >> m >> q;
		leeArcos (mat, p, m);
		floyd (mat, p, n);
		consulta (mat, p, q, out, i + 1);
	}
	cout << out;
}
/*
2
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
7 6 3
1 2 50
1 3 60
2 4 120
3 6 50
4 6 80
5 7 40
7 5
1 7
2 4
*/