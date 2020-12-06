#include <iostream>

// T(1) = 3                 n = 1
// T(n) = T(n - 1) + 3      n > 1 
int mayorA100(int mat[4][4], int n, int m){
    int line = 0;
    for(int i = 0; i < m; i++){
        line += (mat[n - 1][i] > 100 ? 1:0);
    }
    if (n == 1){
        return line;
    }
    return line + mayorA100(mat, n - 1, m); 
}

int main(){
    int mat[4][4] = {{1, 2, 3, 1000},
                     {5, 6, 7, 8},
                     {9, 10, 11, 200},
                     {13, 14, 15, 16}};
    std::cout << mayorA100(mat, 4, 4) << '\n';
}
