#include <iostream>
#include <cmath>
using namespace std;

void merge(int *arr, int start, int end){
    int middle = (start + end) / 2;
    int i = start, j = middle + 1, k = start;
    int temp[200];
    while(i <= middle && j <= end){
        temp[k++] = (arr[i] < arr[j] ? arr[i++]:arr[j++]);
    }
    while(i <= middle){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(int index = 0; index < end; index++){
        arr[index] = temp[index];
    }
}

float round(float var){ 
    float value = (int)(var * 100 + .5); 
    return (float)value / 100; 
}

float merge1(int *a, int *b, int start, int end){
    int middle = (start + end) / 2;
    int i = start, j = start, k = start;
    int temp[200];
    while(i <= middle && j + middle <= end){
        temp[k++] = (a[i] < b[j] ? a[i++]:b[j++]);
    }
    while(i <= middle){
        temp[k++] = a[i++];
    }
    while(j + middle <= end){
        temp[k++] = b[j++];
    }
    return  ((float)temp[middle - 1] + (float)temp[middle]) /2;
}

void sort(int *arr, int start, int end){
    if(start == end){
        return;
    }
    // calculate middle point
    int middle = (start + end) / 2;

    // recursively sort the subarrays
    sort(arr, start, middle); // left subarray
    sort(arr, middle + 1, end); // right subarray
    
    // merge the two divided parts
    merge(arr, start, end);
} 

int main(){ 
    string out = ""; 
    int t, n, a[100], b[100];
    cin >> t;
    for(int i = 0; i < t; i++){
        // input arrays lenght     
        cin >> n;

        // input array a
        for(int j1 = 0; j1 < n; j1++){
            cin >> a[j1];
        }
        // input array b
        for(int j2 = 0; j2 < n; j2++){
            cin >> b[j2];
        }

        cout << "Median case " << i + 1 << ": ";
        printf("%.2f", merge1(a, b, 0, 2 * n)); 
        cout << '\n';
    }
     
    /* 
    input:
        2 5 1 4 7 8 10 2 9 11 14 15 3 3 4 5 1 2 6
    output:
        Median case 1: 8.50
        Median case 2: 3.50
    */
    return 0;
}
