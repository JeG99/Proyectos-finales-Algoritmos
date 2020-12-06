#include <iostream>

int divisibles1(int inf, int sup){
	int divisibles = 0;
	for(int i = inf; i <= sup; i++){
		if (i % 3 == 0 && i % 5 == 0){
			divisibles++;
		}
	}
	return divisibles;
}

int divisibles2(int inf, int sup){
	int divisibles = 0;
	for(int i = inf; i <= sup; i++){
		if (i % 15 == 0){
			divisibles++;
		}
	}
	return divisibles;
}

int divisibles3(int inf, int sup){
	int divisibles = 0;
	int arranque = inf + (inf % 15 == 0 ? 0 : 15 - inf % 15);
	for(int i = arranque; i <= sup; i += 15){
		divisibles++;
	}
	return divisibles;
}

int divisibles4(int inf, int sup){
	return sup/15 + inf/15 + (inf % 15 == 0 ? 1 : 0);
}

int main(){
	std::cout << divisibles1(0, 30) << '\n';
	std::cout << divisibles2(0, 30) << '\n';
	std::cout << divisibles3(0, 30) << '\n';
	std::cout << divisibles4(0, 30) << '\n';
	return 0;
}