#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <cstring>
# define INF 0x3f3f3f3f

using namespace std;

class Graph
{
    int V;
    list< pair<int, int> >* adj;

	public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    vector<int> bfs (int s);

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}



vector<int> Graph::bfs(int s) {

    vector<int> dist(V, INF);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (pair <int, int> u : adj[v]) {
		int vert = u.first;
		int weight = u.second;
            if (dist[vert] > dist[v] + weight) {
                dist[vert] = dist[v] + weight;
                q.push(vert);
            }
        }
    }

    return dist;
}



int main(int argc, char* argv[]) {

std::ifstream file("input.txt");

int vertexes, edges, sellers, start, finish;
int seller_city, sell_price;
int city1, city2, weight;
int answer = INF;

list< pair<int, int> > sell_cities;

vector<int> dist, dist_finish;

file >> vertexes >> edges >> sellers;
file >> start >> finish;

Graph g(vertexes);
for (int i = 0; i < sellers; i++) {
		file >> seller_city >> sell_price;
		sell_cities.push_back(make_pair(seller_city, sell_price));
	}

for (int i = 0; i < edges; i++) {
        file >> city1 >> city2 >> weight;
        g.addEdge( city1 - 1, city2 - 1, weight);
}
dist = g.bfs(start-1);
dist_finish = g.bfs(finish-1);

for (pair <int, int> x : sell_cities) {
	int city_number = x.first - 1;
	int cost = x.second;
	int total_weight = dist[city_number] + cost + dist_finish[city_number];
	if (answer > total_weight) answer = total_weight;

}
ofstream output_file("output.txt");
output_file << answer;
output_file.close();

}

