#include <iostream>
#include <string>
#include <list>
#include <fstream>
using namespace std;

/// <summary>
/// (1) Ациклический граф в ориентированном графе СИ
/// Граф является ациклическим, если в нем не содержится циклов
/// Задача сводится к обнаружению такого цикла, если цикл отсутствует, граф ациклический, иначе нет.
/// Краткое описание алгоритма:
/// Обход в глубину преобразует граф в дерево.
/// Мы будем искать такой лист дерева, что от него можно отправиться в его предок
/// Если такой лист существует, то граф не является ациклическим
/// Запускаем обход для всех вершин
/// И если мы каким-то образом возвращаемся в уже посещенную вершину(смотрим по массиву recurStack), то фиксируем цикл
/// </summary>
class Graph
{
    int V; // кол-во вершин
    list<int>* adj; // список смежности
    bool isCyclicUtility(int v, bool visited[], bool* recurStack); // используется в iscycle

public:
    Graph(int V); // создание графа
    void addEdge(int v, int w); // добавление ребра в граф
    bool isCyclic(); // функция сообщающая о наличии цикла в графе
};

bool Graph::isCyclicUtility(int v, bool visited[], bool* recurStack)
{
    if (visited[v] == false) // если вершина помечена как непосещенная
    {
        visited[v] = true; // помечаем её как посещенную в графе
        recurStack[v] = true; // отслеживаем её
    }

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (!visited[*i] && isCyclicUtility(*i, visited, recurStack)) // проверяем смежную данной вершину, если мы сможем вернуться в текущую вершину, то граф циклический
            return true; // если ещё подробнее, если мы посещаем как бы непосещенную вершину, но он
        else if (recurStack[*i]) 
            return true;
    }
    recurStack[v] = false; // снимаем метку для рекурсии
    return false; // показываем, что не смогли вернуться в нее
}

Graph::Graph(int V) // конструктор по умолчанию для графа
{
    this->V = V; // количество вершин
    adj = new list<int>[V]; // создаем список смежности на V элементом
}

void Graph::addEdge(int v, int w) // ребро из вершины v в w
{
    adj[v].push_back(w); // т.е можно попасть из v в w
}

bool Graph::isCyclic()
{
    bool* visited = new bool[V]; // для отметки посещенных вершин
    bool* recStack = new bool[V]; // для отслеживания вершин
    for (int i = 0; i < V; i++)
    {
        visited[i] = false; // помечаем все как непосещенные
        recStack[i] = false;
    }

    for (int i = 0; i < V; i++)
    {
        if (isCyclicUtility(i, visited, recStack)) // если этот обход в глубину возвращает истину для хоть одной вершины
            return true; // обозначем что существует цикл
    }
    return false; // иначе цикла не существует
}

void TestingSystem(int test)
{
    cout << "Test " << test << endl;
    string testname, line;
    testname = "test" + to_string(test) + ".txt";
    ifstream input(testname, ios::app);

    if (!input.is_open())
    {
        cout << "File is not opened" << endl;
    }

    int vertixes;
    input >> vertixes;// количество вершин

    Graph g(vertixes);
    while (!input.eof())
    {
        int v, u;
        input >> v;
        input >> u;
        g.addEdge(v - 1, u - 1);
    }
    input.close();
    if (g.isCyclic())
        cout << "Cyclic";
    else
        cout << "Acyclic";

    cout << endl;
    cout << endl;
}
int main()
{
    for (int i = 1; i <= 5; i++)
        TestingSystem(i);
}


