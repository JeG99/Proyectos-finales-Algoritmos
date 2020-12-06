// José Elías Garza Vázquez
// A00824494

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge>>
#define Vertex pair<int, int>  // Distance from source, vertex ID

vector<int> Dijkstra(Graph& G, int source) {
    vector<int> Dist;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> queue;

    Dist.assign(G.size(), INF);
    Dist[source] = 0;

    Vertex vx(0, source);
    queue.push(vx);

    while(!queue.empty())
    {
        int u = queue.top().second;  // Vertex ID
        queue.pop();

        for (int i = 0; i < G[u].size(); i++)
        {
            Edge e = G[u][i];
            int v = e.first;
            int w = e.second;

            if(Dist[v] < Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                Vertex vtx(Dist[v], v);
                queue.push(vtx);
            }
        }
    }

    return Dist;
}

int main() {
	string out = "";
	int cases = 1
	//cin >> cases;
    int nodes, edges, source, u, v, w;
    char U, V;
    Graph G;

    source = 1;
	for(int c = 0; c < cases; c++){

		// Read from stdin
	    cin >> nodes >> edges; //>> source;
	    G.resize(nodes);

	    for (int i = 0; i < edges; i++)
	    {
	        cin >> U >> V >> w;
	        u = U - 64;
	        v = V - 64;
	        // Edge from u->v
	        Edge edge1(v-1, w);
	        G[u-1].push_back(edge1);

	        // Edge from v->u
	        Edge edge2(u-1, w);
	        G[v-1].push_back(edge2);
	    }

	    // We run our algorithm
	    vector<int> distances = Dijkstra(G, source-1);
	    
	    int tempDist = distances[0]; 
	    char tempNode = source + 64;
	    for (int i = 1; i < nodes; i++)
	    {
	        if (i != source-1)
	        {
            	if(distances[i] > tempDist && distances[i] != INF){
            		tempDist = distances[i];
            		tempNode = (char)(i + 65);
            	}
	        }
	    }
	    out += tempNode + ' ' + to_string(tempDist) + '\n';
	    G.clear();
	}
	cout << out;

    return 0;
}
/*
in:
3
5 7
A B 5
A C 4
A D 7
B E 3
C D 2
C E 4
D E 1
4 6
A B 1
A C 1
A D 1
B C 1
B D 1
C D 1
4 6
A B 5
A C 1
A D 7
B C 9
B D 8
C D 6

out:
Case 1: E                                                                                                             
Case 2: B                                                    
Case 3: D 
*/