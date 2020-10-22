/*
RICARDO LÓPEZ CANALES
A01422699
*/



#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX
#define Edge pair<int, int>
#define Graph vector<vector<Edge> >
#define Vertex pair<int,int>  // Distance from source, vertex ID

vector<int> Dijkstra(Graph& G, int source)
{
    vector<int> Dist;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex > > queue;

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

            if(Dist[v] > Dist[u] + w)
            {
                Dist[v] = Dist[u] + w;
                Vertex vtx(Dist[v], v);
                queue.push(vtx);
            }
        }
    }

    return Dist;
}
//        A B C D E
// Dist = 0 5 4 6 7

int main()
{
    int n, nodes, edges, source, w;
    char u, v; vector<char> resp;

    cin >> n;

    for (int x = 0; x < n; ++x){
        Graph G(nodes);
        cin >> nodes >> edges;
        source = 0;

        for (int i = 0; i < edges; i++)
        {
            cin >> u >> v >> w;
            // Edge from u->v
            Edge edge1(v-'A', w);
            G[u-'A'].push_back(edge1);

            // Edge from v->u
            Edge edge2(u-'A', w);
            G[v-'A'].push_back(edge2);
        }

        // We run our algorithm
        vector<int> distances = Dijkstra(G, source);

        int mayor = 0;

        for (int i = 0; i < nodes; ++i)
        {
            if(distances[i]> distances[mayor])
                mayor = i;
        }

        resp.push_back(mayor);
    }

    for (int i = 0; i < resp.size(); ++i)
    {
        char salida = 'A'+ resp[i];
        cout << "Case" << i +1 <<": "<< salida<<endl;
    }
    return 0;
}

/*
5 8 1
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7

2
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
*/

