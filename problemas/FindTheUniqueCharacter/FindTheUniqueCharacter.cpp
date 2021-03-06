// FindTheUniqueCharacter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

//A A B B C
//0 1 2 3 4

//A B B C C
//0 1 2 3 4
//B B C C
//0 1 2 3
// A A B B C
// 0 1 2 3 4

bool compareLeft(string &s, int pos) {
	if (pos == 0) {
		return false;
	}
	if (s[pos - 1] == s[pos]) {
		return true;
	}
	return false;
}
bool compareRight(string &s, int pos) {
	if (pos == s.length() - 1) {
		return false;
	}
	if (s[pos + 1] == s[pos]) {
		return true;
	}
	return false;
}
char findUniqueCharacter(string &s) {
		int l = 0, r = s.length() -1, m;
		while (l <= r) {
			m = (l + r) / 2;
			if (!compareLeft(s, m) && !compareRight(s, m)) {
				break;
			}
			if (m % 2 == 0) {
				if (compareRight(s, m)) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
			else {
				if (compareLeft(s, m)) {
					l = m + 1;
				}
				else {
					r = m - 1;
				}
			}
		}
		return s[m];
}
int main()
{
	string s;
	cin >> s;
	cout << findUniqueCharacter(s) << "\n";

    return 0;
}	