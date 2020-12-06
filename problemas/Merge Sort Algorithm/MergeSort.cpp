#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
int contComp = 0;
/*
	Luis Felipe Alvarez Sanchez A01194173
*/
void Une(vector<int> &d, int ini, int m, int fin) {
	int i = ini; int j = m + 1; int k = 0;
	int it = ini;
	// i left
	// j right
	//aux array
	vector<int>aux(d.size());

	while ((i <= m ) && (j <= fin)) {
		contComp++;
		if (d[i] < d[j]) {
			aux[k] = d[i];
			i++;
		}
		else {
			aux[k] = d[j];
			j++;
		}
		k++;
	}
	//Add elements remaining from left
	while (i <= m)
	{
		aux[k] = d[i];
		i++;
		k++;
	}
	//Add elements remaining from right
	while (j <= fin)
	{
		aux[k] = d[j];
		j++;
		k++;
	}
	//Copys aux into original array
	i = 0;
	for (it = 0; i <= fin; it++, i++) {
		d[i] = aux[it];
	}
};
//Merge sort function
void MergeSort(vector<int> &d, int ini, int fin) {
	int mitad = 0;
	
	if (ini < fin) {
		mitad = (ini + fin) / 2;
		MergeSort(d,ini, mitad);
		MergeSort(d, mitad + 1, fin);
		Une(d, ini, mitad, fin);
	}

};

int main() {
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i = 0; i<n; i++) {
		cin >> datos[i];
	}
	//Runs recursive function
	MergeSort(datos,0, n - 1);
	/*for (int i = 0; i < datos.size(); i++) {
		cout << datos[i] << "\n";
	}
	*/
	cout << contComp << "\n";
}
