// José Elías Garza Vázquez - A00824494
#include <iostream>
using namespace std;

float merge(int *a, int *b, int start, int end) {
    int middle = (start + end) / 2;
    int i = start, j = start, k = start;
    int temp[200];
    while(i <= middle && j + middle <= end) {
        temp[k++] = (a[i] < b[j] ? a[i++]:b[j++]);
    }
    while(i <= middle) {
        temp[k++] = a[i++];
    }
    while(j + middle <= end) {
        temp[k++] = b[j++];
    }
    return  ((float)temp[middle - 1] + (float)temp[middle]) / 2;
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
        /*
        cout << "Median case " << i + 1 << ": ";
        printf("%.2f", merge1(a, b, 0, 2 * n));
        cout << '\n';
        */
        snprintf(buff, sizeof(buff), "%.2f", merge(a, b, 0, 2 * n));
        out += "Median case " + to_string(i + 1) + ": " + buff + '\n';
    }
    cout << out;

    /*
    input:
        2 5 1 4 7 8 10 2 9 11 14 15 3 3 4 5 1 2 6
    output:
        Median case 1: 8.50
        Median case 2: 3.50
    */

    return 0;
}