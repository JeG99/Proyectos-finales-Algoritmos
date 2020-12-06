#include <iostream>

void findUnique(std::string s){
	for(int i = 0; i < s.size(); i+=2){
		if((s[i] + s[i + 1]) != 2*s[i]){
			std::cout << s[i] << '\n';
			break;
		}
	}	
}

int main(){
	std::string s = "AACCDD3EEFF";
	findUnique(s);
	std::cout << (s[0] + s[1]) / (2*s[0]) << '\n'; 
	return 0;
}
