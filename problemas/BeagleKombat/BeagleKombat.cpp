#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int getMaxPosibleDamage(vector<pair<char, int>> attacks, int K) {
	int sum = 0;
	priority_queue<pair<char, int>>pQueue;

	for (int i = 0; i < attacks.size() - 1; i++) {
		pQueue.push(attacks[i]);
		if (attacks[i].first != attacks[i + 1].first) {
			int counter = 0;
			while (!pQueue.empty()) {
				if (counter < K) {
					sum += pQueue.top().second;
					counter++;
				}
				pQueue.pop();
			}
		}

	}
	return sum;
}
int main()
{
	int n, k;
	cin >> n;
	cin >> k;

	vector<pair<char, int>> attacks(n);


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		attacks[i].second = num;
	}
	for (int x = 0; x < n; x++) {
		char attack;
		cin >> attack;
		attacks[x].first = attack;
	}
	pair<char, int> eChar;
	eChar.first = '*';
	eChar.second = 0;

	attacks.push_back(eChar);
	cout << getMaxPosibleDamage(attacks, k);
	/*
	for (int i = 0; i < n; i++) {
	cout << attacks[i].first << " - " << attacks[i].second << " " << "\n";
	}
	*/
	return 0;
}