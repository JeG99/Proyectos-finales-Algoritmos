// ZerosAndOnes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int zerosAndOnes(string s) {
	int one = 0, zero = 0, len = 0, i = 0;
	for (i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			zero++;
		}else {
			one++;
		}
	}
	return (one > zero) ? one-zero : zero-one;
}
int main()
{
	string input;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> input;
	}

	cout << zerosAndOnes(input);

    return 0;
}

