// Jose Elias Garza Vazquez - A00824494
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lanzamientos(vector<long long> soldiers, vector<long long> beagleBalls, vector<long long> accumForces, long long n, long long q) {
    long long sum = 0;
    vector<long long> ballFrags;
    vector<long long>::iterator upper, i = beagleBalls.begin();
    
    // O(q log n)
    while(i - beagleBalls.begin() < q) { // O(q)

        sum += *i; //O(1)
        upper = upper_bound(accumForces.begin(), accumForces.end(), sum); // O(log n)
        
        if((upper - accumForces.begin() - 1) == (n - 1) || sum == 0) { // O(1)
            upper = accumForces.begin();
            sum = 0;
            cout << n << '\n';
        }
        else if(*(upper - 1) > sum) { // O(1)
            upper--;
        }
        else { // O(1)
            cout << n - (upper - accumForces.begin()) << '\n';
        }

        i++; // O(1)

    }
}

int main() {
    vector<long long> beagleBalls;
    vector<long long> soldiers;
    vector<long long> accumForces;
    long long n, q;
    cin >> n >> q;
    long long input, sum = 0;
    for(long long i = 0; i < n; i++) {
        cin >> input;
        soldiers.push_back(input);
        sum += soldiers[i];
        accumForces.push_back(sum);
    }
    for(long long i = 0; i < q; i++) {
        cin >> input; 
        beagleBalls.push_back(input);
    }
    lanzamientos(soldiers, beagleBalls, accumForces, n, q);

    return 0;
    
/*
Input:
5 5
1 2 1 2 1
3 10 1 1 1
Output:
3
5
4
4
3
*/
}
