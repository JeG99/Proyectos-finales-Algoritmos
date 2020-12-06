#include <iostream>
#include <climits>

using namespace std;

#define MAX 51

void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n) {
   for(int i = 1; i <= n; i++) {
       D[i][i] = P[i][i] = 0;
   }
   int j, men, menk, aux;
   for(int diag = 1; diag <= n - 1; diag++){
       for(int i = 1; i <= n - diag; i++){
           j = i + diag;
           men = INT_MAX;
           for(int k = i; k < j; k++){
               aux = D[i][k] + D[k + 1][j] + d[i - 1]*d[k]*d[j];
               if (aux < men){
                   men = aux;
                   menk = k;
               }
           }
           D[i][j] = men;
           P[i][j] = menk;
       }
   }
}

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

int main(){
    int d[MAX]; // vector de dimensiones

    int D[MAX][MAX], P[MAX][MAX];
    // D: min número de mult escalares de las Mat(i)...Mat(j)
    // P: k que minimiza Mat(i)...Mat(j)
    int n;

    cin >> n;
    for(int i = 0; i <= n; i++) {
        cin >> d[i];
    }
    calcula(D, P, d, n);
    cout << D[1][n] << '\n';
    despliega(P, n);
}
