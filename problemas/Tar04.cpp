#include <iostream>

int suma1(int* arr, int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        if(arr[i]%2 != 0)
            sum += arr[i];
    return sum;
}

int suma2(int* arr, int n){
    if(n == 1)
        return (arr[0] % 2 != 0 ? arr[0]:0);
    return (arr[n - 1] % 2 != 0 ? arr[n - 1] + suma2(arr, n - 1):suma2(arr, n - 1));
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6};
    std::cout << suma1(a, 6) << '\n';
    std::cout << suma2(a, 6) << '\n';
}
