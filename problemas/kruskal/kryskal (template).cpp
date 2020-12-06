// https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std; 
  
typedef  pair<int, int> iPair; 
  
struct Graph { 
    // V = Cantidad de Nodos
    // E = Cantidad de Arcos
    int V, E, costMST; 
    vector< pair<int, iPair> > edges; 
  
    Graph(int V, int E){ 
        this->V = V; 
        this->E = E; 
    } 
  
    void addEdge(int u, int v, int w) { 
        edges.push_back({w, {u, v}}); 
    } 
  
    void kruskalMST(); 
}; 
  
// To represent Disjoint Sets 
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    DisjointSets(int n){ 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
        for (int i = 0; i <= n; i++){ 
            rnk[i] = 0; 
            parent[i] = i; 
        } 
    } 
  
    // Find the parent of a node 'u' 
    // Path Compression 
    int find(int u) 
    { 
        /* Make the parent of the nodes in the path 
           from u--> parent[u] point to parent[u] */
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    // Union by rank 
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        /* Make tree with smaller height 
           a subtree of the other tree  */
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else // If rnk[x] <= rnk[y] 
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  

  
void Graph::kruskalMST(){ 
    costMST = 0;
    sort(edges.begin(), edges.end());
    DisjointSets ds(V);
    vector< pair<int, iPair> > :: iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;
        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if( set_u != set_v){
            cout << u << " - " << v << endl;
            costMST += it->first;
            ds.merge(set_u, set_v);
        }
    }
} 
  
int main(){ 
    int V, E;
    cin >> V >> E;
    Graph g(V, E); 
    int a, b, c;
    for (int i=1; i<=E; i++){
        cin >> a >> b >> c;
        g.addEdge(a,b,c);
    }
  
    cout << "Los arcos que componen el MST son:"<<endl; 
    g.kruskalMST();
    cout << "Costo Total del MST es: " << g.costMST<<endl; 
  
    return 0; 
} 

/*
Unidrected Graph
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/
