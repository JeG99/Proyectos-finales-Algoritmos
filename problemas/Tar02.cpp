#include <iostream>

int onesAndZeros(std::string s, int n){
	int ones = 0, zeros = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == '1'){
			ones++;
		}
		else{
			zeros++;
		}
	}
	return abs(ones - zeros);
}

int main(){
	int n;
	std::string s;
	std::cin >> n >> s;
	std::cout << onesAndZeros(s, n) << '\n';
	return 0;
}