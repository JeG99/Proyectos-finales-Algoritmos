/*
  Matricula: José Elías Garza Vázquez
  Nombre: A00824494
*/

#include <iostream>
#include <vector>

using namespace std;

string juego(vector<int> &d){
	int turnos = 0;
	for(int i = 1; i < d.size(); i++){
		if(d[i - 1] > d[i]){
			turnos++;
		}
	}
	return (turnos % 2 == 0 ? "PEPE":"BETO");
}

string juegopendejo(vector<int> &d){
	string turno; 
	turno = " "; 
	int n = d.size();
	int nInicial = n;
	while(n > 0){
		turno = (turno == "BETO" ? "PEPE":"BETO"); 
		int mayor = d[0];
		int mayorIndex = 0;	
		for(int i = 0; i < n; i++)
			if(d[i] > mayor){
				mayor = d[i];
				mayorIndex = i;
			}
		n = n - (nInicial - mayorIndex);
		nInicial = n;
	}
	return turno;
}

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
  	cout << juegopendejo(datos) << ' ' << juego(datos) <<endl;
}

/*
Ejemplo 1
4
1 2 4 3

Ejemplo 2
4
1 4 3 2

Ejemplo 3
6
8 10 5 12 13 9

*/