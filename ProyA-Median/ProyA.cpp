// Jose Elias Garza Vazquez - A00824494
#include <iostream>
using namespace std;

double median(int* arr, int n){
    return (double)(n % 2 == 0 ? ((arr[(n - 1) / 2] + arr[n / 2]) / 2.0) : arr[n / 2]);
}

double median2Arrays(int* A, int* B, int n){

    // umbral
    if(n == 1){
        return (double)((A[0] + B[0]) / 2.0);
    }
    if(n == 2){
        return (double)((max(A[0], B[0]) + min(A[1], B[1])) / 2.0);
    }
    double Am = median(A, n), Bm = median(B, n);
    if(Am == Bm){
        return Am;
    } 
    
    bool isEven = n % 2 == 0;
    if(Am < Bm) {   
        return (double)(isEven ? (median2Arrays(A + (n / 2 - 1), B, (n - n / 2 + 1))) : (median2Arrays(A + (n / 2), B, n - (n / 2))));       
    } else{
        return (double)(isEven ? (median2Arrays(B + (n / 2 - 1), A, (n - n / 2 + 1))) : (median2Arrays(B + (n / 2), A, n - (n / 2))));
    }

}

int main() {
    string out = "";
    char buff[5];
    int t, n, a[100], b[100];
    cin >> t;
    for(int i = 0; i < t; i++) {
        // input arrays lenght
        cin >> n;
        // input array a
        for(int j1 = 0; j1 < n; j1++) {
            cin >> a[j1];
        }
        // input array b
        for(int j2 = 0; j2 < n; j2++) {
            cin >> b[j2];
        }
        // add output to out string
        snprintf(buff, sizeof(buff), "%.2f", median2Arrays(a, b, n));
        out += "Median case " + to_string(i + 1) + ": " + buff + '\n';
    }
    cout << out;
    return 0;

/*
input:
7 
5 
1 4 7 8 10 
2 9 11 14 15 
3 
3 4 5 
1 2 6 
4 
1 2 3 4 
5 6 7 8
4 
5 6 7 8
1 2 3 4
6 
2 3 5 7 8 56
1 2 3 47 87 100
5
0 2 4 6 8
1 3 5 7 9
4
0 2 4 6
1 3 5 7

output:
Median case 1: 8.50
Median case 2: 3.50
Median case 3: 4.50
Median case 4: 4.50
Median case 4: 6.00
Median case 5: 4.50
Median case 4: 3.50
*/
}