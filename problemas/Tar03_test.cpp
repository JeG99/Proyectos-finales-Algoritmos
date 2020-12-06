#include <iostream>

int pow1(int x, int n){
    int r = 1;
    for(int j = 1; j <= n; j++){
        r = r * x;
    }
    return r;
}

int pow2(int x, int n){
    int r = 1;
    while(n > 0){
        if(n % 2 != 0) r *= x;
        x *= x;
        n /= 2;
        std::cout << n << '\n';
    }
    return r;
}

void sumas(int* A, int n){
    
    int** B = new int*[n];
    for(int i = 0; i < n; i++)
        B[i] = new int[n];
    for(int i = 0; i < n; i++){
        B[i][i] = A[i];
        for(int j = i + 1; j < n; j++){
            B[i][j] = B[j][i] = B[i][j - 1] + A[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << B[i][j] << ' ';
        }
        std::cout << '\n';
    }
    for(int i = 0; i < n; i++)
        delete[] B[i];
    delete[] B;
}

int main(){
    /*
    for(int i = 0; i < 16; i+=2)
        std::cout << std::boolalpha << (pow1(2, i) == pow2(2, i)) << '\n';
    */
   
    //std::cout << pow2(2, 17) << '\n' << pow2(2, 16) << '\n';
    int a[] = {1, 2, 3, 4, 5}; 
    sumas(a, 5); 

    return 0;
}
