#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> lanzamientos(vector<long> soldiers, vector<long> beagleBalls, vector<long> accumForces, long n, long q) {
    long index;
    long sum = 0;
    vector<long> ballFrags, temp = beagleBalls;
    vector<long>::iterator upper, lower, i = beagleBalls.begin(), j = accumForces.begin();
    while(i - beagleBalls.begin() < q) {
        int ball = i - beagleBalls.begin() + 1;
        if(*i > accumForces[n - 1]) {
            sum = 0;
            j = accumForces.begin(); 
            ballFrags.push_back(n);
        }
        else {
            sum += *i;
            upper = upper_bound(j, accumForces.end(), sum);
            //lower = lower_bound(j, accumForces.end(), sum);  
            if(*(upper - 1) == sum){
                sum = 0;
                j += upper - accumForces.begin();
            }
            ballFrags.push_back(accumForces.end() - j);
        }
        i++;
        
    }
    return ballFrags;
}

long lanzada(bool b, long n, long power, long accumPower, vector<long> accumForces, vector<long>::iterator &curr, long fpos){
    if(b == true) return 0;
    else{
        vector<long>::iterator upper = upper_bound(curr, accumForces.end(), accumPower);
        if(*(upper - 1) - accumPower == 0){
            curr = upper;
            return curr - accumForces.begin();
        }
    }
}

int main() {
    vector<long> beagleBalls;
    vector<long> soldiers;
    vector<long> accumForces;
    long n, q;
    cin >> n >> q;
    long input, sum = 0;
    for(int i = 0; i < n; i++){
        cin >> input;
        soldiers.push_back(input);
        sum += soldiers[i];
        accumForces.push_back(sum);
    }
    for(int i = 0; i < q; i++){
        cin >> input; 
        beagleBalls.push_back(input);
    }
    vector<long> fallen = lanzamientos(soldiers, beagleBalls, accumForces, n, q);
    for(int i = 0; i < q; i++){
        cout << fallen[i] << ' ';
    }
    cout << '\n';

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
