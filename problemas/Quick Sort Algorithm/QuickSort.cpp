#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//&function

i moveZeroes(vector<int>& nums) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] < nums[i + 1]) {
			cout << nums[i];
		}
	}
}
int main() {
	vector<int>nums = { 3,4,5,1,2 };
	vector<int>res;
	res = moveZeroes(nums);

}