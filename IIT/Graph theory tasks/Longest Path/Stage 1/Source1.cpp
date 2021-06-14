// Задание: Найти максимальный путь между заданными вершинами вог СС
// Формат входных данных(input.txt):
// На первой строчке единственное число m - количество вершин
// На второй строчке указать два числа k1, k2, таких что k1, k2 <= m
// Следующие строки задают ребра графа
// u v w
// наприм. 5 6 10 (ребро из вершины пять в шесть с весом ребра в 10)
// используем DFS для "развертывания графа" и нахождения всех путей из v1 в v2
// сохраняем длину этого пути
// сохраняем сам путь
// передаем эти значения по ссылке, и сравниваем пути. Если больший, то изменяем, иначе продолжаем
// если не существует пути из v1 в v2 - выводим No Solutions
// вес ребра храним в матрице, чтобы избежать "корявости" с парами
// ИСПОЛЬЗУЕМ ПЕРЕБООООР. сложность порядка (2^(V)*(V + E))(экспоненциальный, потому что перебор)))0)
// краткая суть алгоритма:
/*
* 1. Помечаем все узлы как неотмеченные
* 2. начинаем с начальной вершины и идем по смежным записывая путь
* 3. запоминаем посещенные узлы, чтобы избежать попадания в цикл(именно цикл типа 1-2-3-1-2-3 и так далее, тогда работа не имеет смысла)
* 4. добавляем промежуточные в путь
* 5. Как только достигаем нужной вершины,  сохраняем путь
* 6. Помечаем вершину не отмеченной и удаляем её из пути(рекурсия же ну)
* 7. После посещаем следующую смежную с v1 вершину и начинаем с шага три
*/
#include <iostream> 
#include <fstream>
#include <string>
#include <list> 
#include <vector>
using namespace std;

class Graph
{
    int V; // число вершин
    list<int>* adj; // список смежности
    vector< vector <int> > weights; // используем матрицу весов, чтобы лишний раз не использовать итератор и не модифицировать список смежности
    void FindLongestPathUtility(int v1, int v2, bool visited[], int path[], int index, int& prevPathLen, vector<int>& maxPath); // "модифицированный dfs"
public:
    Graph(int V); // конструктор по бла-бла-бла
    void addEdge(int v, int w, int weight); // добавление ребра в граф
    void FindLongestPath(int v1, int v2); // основная функция для нахождения наибольшего пути между двумя вершинами
    // вообще, с помощью двух функций мы ищем всевозможные пути из v1 в v2 попутно сохраняя путь максимальной (как длину, так и сам путь)
    // после того, как программа отработает входные данные, мы будем иметь максимальный путь

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    weights = vector< vector <int> >(V, vector<int>(V)); // инициализируем матрицу весов размером V на V
}

void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(w); // Add w to v’s list. 
    weights[v][w] = weight; // показываем, что есть ребро между v и w весом weight
}


void Graph::FindLongestPathUtility(int v1, int v2, bool visited[], int path[], int index, int& prevPathLen, vector<int>& maxPath)
{
    visited[v1] = true; // отмечаем вершину  из которой пришли изведанной
    path[index] = v1; // добавляем её в путь(вообще, тут можно использовать вектор, но я захотел устроить утечку памяти))
    index++; // итерируемся дальше по массиву path
    if (v1 == v2) // если дошли до нужной вершины
    {
        int i; // для считывания текущего пути 
        int pathlen = 0; // найденный путь
        for (i = 0; i < index - 1; i++)
        {
            pathlen += weights[path[i]][path[i + 1]]; // высчитываем его
        }
        if (pathlen > prevPathLen) // если найденный путь больше промежуточного максимального
        {
            // сохраняем его и делаем новым промежуточным
            maxPath.clear();
            prevPathLen = pathlen;
            for (int i = 0; i < index; i++)
            {
                maxPath.push_back(path[i]);
            }
        }
    }
    else
    {
        list<int>::iterator i; // если вершина все же не найдена
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i) // то рекурсивно идем по всем вершинам смежным этим
        {
            if (!visited[*i])
            {
                FindLongestPathUtility(*i, v2, visited, path, index, prevPathLen, maxPath);
            }
        }

    }
    index--; // удаляем эту вершину из пути
    visited[v1] = false; // и делаем её непосещенной
}

void Graph::FindLongestPath(int v1, int v2)
{
    bool* visited = new bool[V]; // помечаем все вершнины как не отмеченные
    for (int i = 0; i < V; i++) // 
        visited[i] = false;

    int* path = new int[V]; // переменная для хранения пути (максимальный путь, это когда задействованы очевидно все вершины)

    int index = 0; // переменная, чтобы проходить по массиву path


    int prevPathLen = 0; // функция, которая хранит в себе промежуточное значение длины пути(чтобы найти среди всех максимальный)
    vector<int> maxPath; // вектор, в котором промежуточный максимальный путь
    FindLongestPathUtility(v1, v2, visited, path, index, prevPathLen, maxPath); // используем поиск
    if (prevPathLen == 0) // если результат не изменился, очевидно что пути нет...
    {
        cout << "No solutions.\n";
        return;
    }
    // ну и вывод данных..
    cout << "Largest path from " << v1 + 1 << " to " << v2 + 1 << " is following path:" << endl;
    for (int i = 0; i < maxPath.size() - 1; i++)
    {
        cout << maxPath[i] + 1 << "->";
    }
    cout << maxPath[maxPath.size() - 1] + 1;
    cout << "\t with lenght " << prevPathLen;
}

void TestRunner(int test) // тестирующую функцию нет смысла комментить, полагаю?)
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

    int s, t;
    input >> s; // точка отправления
    input >> t; // точка прибытия

    Graph g(vertixes);
    while (!input.eof())
    {
        int v, u, w;
        input >> v;
        input >> u;
        input >> w;
        g.addEdge(v - 1, u - 1, w);
    }
    input.close();

    g.FindLongestPath(s - 1, t - 1);

    cout << endl;
    cout << endl;
}
int main()
{
    TestRunner(1);
    TestRunner(2);
    TestRunner(3);
    TestRunner(4);
    TestRunner(5);
}
