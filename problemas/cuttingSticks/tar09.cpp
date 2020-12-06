// José Elías Garza Vázquez - A00824494
#include <iostream>
#include <climits>

using namespace std;

#define MAX 50

void calcula(int D[MAX + 2][MAX + 2], int d[], int n, int l) {
   for(int i = 1; i <= n; i++) {
       D[i][i + 1] = 0;// = P[i][i] = 0;
   }

   int j, men, aux;
   for(int diag = 2; diag <= l; diag++){
       for(int i = 0; i <= n + 1 - diag + 1; i++){
           j = i + diag;
           men = INT_MAX;
           for(int k = i + 1; k < j; k++){
               aux = D[i][k] + D[k][j] + d[j] - d[i];
               if (aux < men){
                   men = aux;
                   //menk = k;
               }
           }
           D[i][j] = men;
           //P[i][j] = menk;
       }
   }
}
/*
void recorre(int P[MAX][MAX], int ini, int fin){
    if(P[ini][fin] != 0){
        cout << '(';
        recorre(P, ini, P[ini][fin]);
        cout << ")x(";
        recorre(P, P[ini][fin] + 1, fin);
        cout << ')';
    }
    else{
        char ch = 'A' + ini - 1;
        cout << ch;
    }
}

void despliega(int P[MAX][MAX], int n){
    recorre(P, 1, n);
    cout << '\n';
}
*/
int main(){
  string out = "";
  int l, n;
  int D[MAX + 2][MAX + 2];//, P[MAX][MAX];
  cin >> l >> n;      
	while(l > 0){
      cin >> l >> n;
      if(l > 0) break;
	    int d[n + 2]; // arreglo de cortes

	    d[0] = 0;
	    d[n + 1] = l; // corte en inicio, corte en el final
	    for(int i = 1; i < n+1; i++) {
	        cin >> d[i];
	    }

	    calcula(D, d, n, l);
	    out += "The minimum cutting is " + to_string(D[0][n + 1]) + ".\n"; 
	    //cout << D[0][n + 1] << '\n';
      
	}
	cout << out;
    //despliega(P, n);
}
