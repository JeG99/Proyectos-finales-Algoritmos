// José Elías Garza Vázquez - A00824494
#include <iostream>  
#include <algorithm>
using namespace std; 
  
int longestCommonSubsequence(string str1, string str2, int n1, int n2) {
    int dp[n1 + 1][n2 + 1];  

    for (int i = 0; i <= n1; i++) {
        for (int j = 0; j <= n2; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            
        }
    }
          
    return dp[n1][n2];
}
  
int main() {

    string s1, s2, out = "";
    int n;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s1 >> s2;
        out += "Case " + to_string(i + 1) + ": " + to_string(longestCommonSubsequence(s1, s2, s1.length(), s2.length())) + '\n';  
    }

    cout << out;
    
    return 0;  

/*
2
AAAAAAABBAAB
ABAABBAB
XMJYAUZ
MZJAWXU
*/
} 