#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


int LCS(string s1, string s2) {
	int n = s2.size();
	int m = s1.size();
	int matrix[m + 1][n + 1];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			matrix[i][j] = 0;
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	return matrix[m][n];
}
int main()
{
	int numCases;
	cin >> numCases;
	string s1, s2;
	vector<int> ans;
	while (numCases != 0) {
		cin >> s1 >> s2;
		ans.push_back(LCS(s1, s2));
		numCases--;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << "Case " << i + 1 << ": " << ans[i] << "\n";
	}
	return 0;
}

