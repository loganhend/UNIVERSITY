#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <string>

/// Проверить, является ли граф двусвязным СИ 1.8
/// Проверка производится для неориентированного графа
/// Определение двусвязного графа для неориентированного графа:
/// Двусвязный неориентированный граф — это связный граф, не распадающийся на части при удалении любой вершины (и всех инцидентных ей рёбер). 
/// Значит, для проверки на двусвязность нужно будет проверить две вещи:
/// 1) проверить, является ли граф связным
/// 2) проверить, являются ли все его возможные подграфы связными
/// Алгоритм:
/// 1) проверяем является ли наш исходный граф связным
/// 2) удаляем вершину k, k = (0, V) - где V - кол-во вершин
/// 3) проверяем на связность граф без k вершины
/// 4) меняем k на другое число и возвращаемся в пункт 2.
/// Формат входных данных:
/// первое число - количество вершин в графе
/// следующие строки - описание связей в графе имеют следующий формат:
/// u w e, где u, w - вершины, e - номер ребра, соединяющий эти вершины. прим(1 2 1) - значит, что ребро 1 соединяет вершины 1 и 2
/// 
using namespace std;
class Graph
{
    int V; // количество вершин
    list<int>* ind; // список инцидентности
    void DFS(int s, bool visited[]);
    bool IsSubGraphConnected(int ver); // ver - удаляемая вершина
    bool isConnected();
public:
    bool isBiconnected();
    Graph(int V); // конструктор для графа
    void addEdge(int v, int w, int edgeNum); // функция добавления ребра в граф
};

bool Graph::IsSubGraphConnected(int ver)
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    visited[ver] = true; // помечаем "удаленную вершину" как помеченную, т.е мы не имеем возможности в нее заходить...
    for (int i = 0; i < V; i++)
    {
        if (i != ver) // находим вершину, которая не удалена...
        {
            DFS(i, visited); // запускаем из нее dfs
            break;
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false) // проверяем подграф на связность
            return false;
    }
    return true;
}
bool Graph::isConnected() // проверка на связность исходного графа 
{
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    DFS(0, visited); // вызываем обход в глубину

    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false) // если остались непосещенные вершины
            return false; // граф несвязный
    }
    return true;
}


void Graph::DFS(int u, bool visited[])
{
    visited[u] = true;

    list<int>::iterator i;
    for (i = ind[u].begin(); i != ind[u].end(); ++i) // обход в глубину
    {                                               // посещаем ещё непосещенные вершины, все просто, если посетели все, возвращаемся на вершину назад и ищем смежные дальше, вернулись в исходную или уперлись - конец обхода
        for (int j = 0; j < V; j++)
        {
            if (u == j)
                continue;
            if ((find(ind[j].begin(), ind[j].end(), *i) != ind[j].end()) && !visited[j])
                DFS(j, visited);
        }
    }

}


bool Graph::isBiconnected()
{
    if (!isConnected())
        return false;

    for (int i = 0; i < V; i++)
    {
        if (!IsSubGraphConnected(i)) // проверяем для всех вершин
            return false;
    }
    return true;
}

Graph::Graph(int V)
{
    this->V = V; // количество вершин в графе
    ind = new list<int>[V]; // список инцидентности для графа
}

void Graph::addEdge(int v, int w, int edgeCount)
{
    // записываем данные в список инцидентности
    // каждой вершине записываем, какие ребра ей инциденты
    // ребро одно для двух вершин(очевидно)
    // и поскольку граф неориентированный добавляем для двух вершин...
    ind[v].push_back(edgeCount);
    ind[w].push_back(edgeCount);
}




void TestingSystem(int test)
{
    cout << "Test " << test << endl;
    string testname, line;
    testname = "test" + to_string(test) + ".txt";
    ifstream input(testname, ios::app);

    if (!input.is_open())
    {
        cout << "File is not opened yet!" << endl;
    }

    int vertixes;
    input >> vertixes;// количество вершин

    Graph G(vertixes);

    while (!input.eof())
    {
        int v, u, edgeNum;
        input >> v;
        input >> u;
        input >> edgeNum;
        G.addEdge(v - 1, u - 1, edgeNum - 1);
    }
    input.close();
    if (G.isBiconnected())
        cout << "Biconnected.";
    else
        cout << "Not Biconnected.";
    // формируем подграфы
    cout << endl;
    cout << endl;
}
int main()
{
    for (int i = 1; i <= 5; i++)
        TestingSystem(i);

}

