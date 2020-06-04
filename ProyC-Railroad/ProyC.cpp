// José Elías Garza Vázquez - A00824494 
#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> t1, vector<int> t2, vector<int> ft){
    
    int t1Len = t1.size();
    int t2Len = t2.size();
    bool dp[t1Len + 1][t2Len + 1];

    dp[0][0] = true;
    for(int i = 1; i <= t1Len; i++){
        dp[i][0] = dp[i - 1][0] && ft[i - 1] == t1[i - 1];
    }
    for(int i = 1; i <= t2Len; i++){
        dp[0][i] = dp[0][i - 1] && ft[i - 1] == t2[i - 1];
    }

    for(int i = 1; i <= t1Len; i++){
        for(int j = 1; j <= t2Len; j++){
            dp[i][j] = ((ft[i + j - 1] == t2[j - 1] && dp[i][j - 1]) || (ft[i + j - 1] == t1[i - 1] && dp[i - 1][j]) ? true:false);
        }
    }

    return dp[t1Len][t2Len];
}

int main() {

    string out;
    vector<int> train1, train2, finalTrain;
    int N1 = 1, N2 = 1;
    int car;

    cin >> N1 >> N2;
    while(N1 > 0 || N2 > 0){

        for(int i = 0; i < N1; i++){
            cin >> car;
            train1.push_back(car);
        }
        for(int i = 0; i < N2; i++){
            cin >> car;
            train2.push_back(car);
        }
        for(int i = 0; i< N1 + N2; i++){
            cin >> car;
            finalTrain.push_back(car);
        }

        out += (isPossible(train1, train2, finalTrain) ? "possible\n":"not possible\n");
        
        train1.clear();
        train2.clear();
        finalTrain.clear();

        cin >> N1 >> N2;
    }

    cout << out;
    
    return 0;
/*
3 3
1 2 1
2 1 1
1 2 1 1 2 1
3 3
1 2 1
2 1 2
1 1 1 2 2 2
0 0
possible
not possible
*/
}