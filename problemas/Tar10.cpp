//José Elías Garza Vázquez - A00824494

#include <iostream>
using namespace std;

int main(){
    string out = "";
    int mat[11][11];
    int n, r;
    cin >> n;

    for(int k = 0; k < n; k++){  
        cin >> r;
       
        for(int i = 0; i < r; i++)
            for(int j = 0; j < r; j++)
                mat[i][j] = 0;
        
        for(int i = 0; i < r; i++)
            for(int j = 0; j < i + 1; j++)
                cin >> mat[i][j];
            
        for(int i = r - 2; i >= 0; i--)
            for(int j = 0; j < i + 1; j++)
                mat[i][j] += max(mat[i + 1][j], mat[i + 1][j + 1]);
        
        out += to_string(mat[0][0]) + '\n';
    }

    cout << out;
    return 0;
}
