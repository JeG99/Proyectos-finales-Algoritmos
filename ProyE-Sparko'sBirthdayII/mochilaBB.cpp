#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct node{
	int niv;
	int va;
	int pa;
	int vp;
	vector<bool> inc;
   	bool operator<(const node &otro) const{
        return vp < otro.vp;
    }
};

struct obj{
	int valor, peso, valpeso;
};

// PESO = Peso Mochila
// VOptimo = Valor óptimo
// n = cantidad de objetos.

int PESO;
int vOptimo;
int n;

// Objetos
vector<obj> datos;

// Los objetos que son incluidos para acumular el Voptimo
vector<bool> res;

bool my_cmp(const obj& a, const obj& b)
{
    return a.valpeso > b.valpeso;
}

// i = Nivel
// vpAux = Valor Acumulado Arranque
// pesoAux = Peso Acumulado de Arranque
int calculaVP(int i, int vpAux, int pesoAux){
	int k = i+1;
	while (k < n && pesoAux+datos[k].peso <= PESO){
		vpAux += datos[k].valor;
		pesoAux += datos[k].peso;
		k++;
	}
	if (k < n){
		vpAux += ((PESO-pesoAux)*datos[k].valpeso);
	}
	return vpAux;
}

void BB(){
	vOptimo = 0;
	priority_queue<node> pq;
	node arranque;
	arranque.niv = -1;
	arranque.va = 0;
	arranque.pa = 0;
	arranque.vp = calculaVP(arranque.niv, arranque.va, arranque.pa);
	for (int i=0; i<n; i++){
		arranque.inc.push_back(false);
	}
	pq.push(arranque);
	while(!pq.empty()){
		arranque = pq.top();
		pq.pop();
		if (arranque.va > vOptimo){
			vOptimo = arranque.va;
			res.clear();
			for (int i=0; i<n; i++){
				res.push_back(arranque.inc[i]);
			}
		}
		if (arranque.vp > vOptimo){
			arranque.niv++;
			// No incluyo el sig objeto;
			arranque.vp = calculaVP(arranque.niv, arranque.va, arranque.pa);
			if (arranque.vp > vOptimo && arranque.pa < PESO){
				arranque.inc[arranque.niv] = false;
				pq.push(arranque);
			}
			// Si incluyo al siguiente objeto
			arranque.va += datos[arranque.niv].valor;
			arranque.pa += datos[arranque.niv].peso;
			arranque.vp = calculaVP(arranque.niv, arranque.va, arranque.pa);
			if (arranque.vp > vOptimo && arranque.pa < PESO){
				arranque.inc[arranque.niv] = true;
				pq.push(arranque);
			}
		}

	}
}

int main(){
	int v, p, vp;
	cin >> n >> PESO;
	for (int i=1; i<=n; i++){
		cin >> v >> p;
		vp = v/p;
		obj misDatos;
		misDatos.valor = v;
		misDatos.peso = p;
		misDatos.valpeso = vp;
		datos.push_back(misDatos);
	}
	sort(datos.begin(), datos.end(), my_cmp);
	cout << endl << "Objetos Ordenados:"<<endl;
	for (int i=0; i<n; i++){
		cout << "Obj"<<(i+1)<<": "<<datos[i].valor<< " "<<datos[i].peso<<endl;
	}
	BB();
	cout << endl << "Resultado: " << vOptimo << endl<<"Incluyendo los Obj: ";
	for (int i=0; i<n; i++){
		if (res[i]){
			cout << (i+1) << " ";
		}
	}
	cout << endl;
return 0;
}

/*
4 16
10 5
40 2
50 10
30 5
*/