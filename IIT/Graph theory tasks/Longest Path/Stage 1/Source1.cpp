// �������: ����� ������������ ���� ����� ��������� ��������� ��� ��
// ������ ������� ������(input.txt):
// �� ������ ������� ������������ ����� m - ���������� ������
// �� ������ ������� ������� ��� ����� k1, k2, ����� ��� k1, k2 <= m
// ��������� ������ ������ ����� �����
// u v w
// ������. 5 6 10 (����� �� ������� ���� � ����� � ����� ����� � 10)
// ���������� DFS ��� "������������� �����" � ���������� ���� ����� �� v1 � v2
// ��������� ����� ����� ����
// ��������� ��� ����
// �������� ��� �������� �� ������, � ���������� ����. ���� �������, �� ��������, ����� ����������
// ���� �� ���������� ���� �� v1 � v2 - ������� No Solutions
// ��� ����� ������ � �������, ����� �������� "���������" � ������
// ���������� ����������. ��������� ������� (2^(V)*(V + E))(����������������, ������ ��� �������)))0)
// ������� ���� ���������:
/*
* 1. �������� ��� ���� ��� ������������
* 2. �������� � ��������� ������� � ���� �� ������� ��������� ����
* 3. ���������� ���������� ����, ����� �������� ��������� � ����(������ ���� ���� 1-2-3-1-2-3 � ��� �����, ����� ������ �� ����� ������)
* 4. ��������� ������������� � ����
* 5. ��� ������ ��������� ������ �������,  ��������� ����
* 6. �������� ������� �� ���������� � ������� � �� ����(�������� �� ��)
* 7. ����� �������� ��������� ������� � v1 ������� � �������� � ���� ���
*/
#include <iostream> 
#include <fstream>
#include <string>
#include <list> 
#include <vector>
using namespace std;

class Graph
{
    int V; // ����� ������
    list<int>* adj; // ������ ���������
    vector< vector <int> > weights; // ���������� ������� �����, ����� ������ ��� �� ������������ �������� � �� �������������� ������ ���������
    void FindLongestPathUtility(int v1, int v2, bool visited[], int path[], int index, int& prevPathLen, vector<int>& maxPath); // "���������������� dfs"
public:
    Graph(int V); // ����������� �� ���-���-���
    void addEdge(int v, int w, int weight); // ���������� ����� � ����
    void FindLongestPath(int v1, int v2); // �������� ������� ��� ���������� ����������� ���� ����� ����� ���������
    // ������, � ������� ���� ������� �� ���� ������������ ���� �� v1 � v2 ������� �������� ���� ������������ (��� �����, ��� � ��� ����)
    // ����� ����, ��� ��������� ���������� ������� ������, �� ����� ����� ������������ ����

};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    weights = vector< vector <int> >(V, vector<int>(V)); // �������������� ������� ����� �������� V �� V
}

void Graph::addEdge(int v, int w, int weight)
{
    adj[v].push_back(w); // Add w to v�s list. 
    weights[v][w] = weight; // ����������, ��� ���� ����� ����� v � w ����� weight
}


void Graph::FindLongestPathUtility(int v1, int v2, bool visited[], int path[], int index, int& prevPathLen, vector<int>& maxPath)
{
    visited[v1] = true; // �������� �������  �� ������� ������ ����������
    path[index] = v1; // ��������� � � ����(������, ��� ����� ������������ ������, �� � ������� �������� ������ ������))
    index++; // ����������� ������ �� ������� path
    if (v1 == v2) // ���� ����� �� ������ �������
    {
        int i; // ��� ���������� �������� ���� 
        int pathlen = 0; // ��������� ����
        for (i = 0; i < index - 1; i++)
        {
            pathlen += weights[path[i]][path[i + 1]]; // ����������� ���
        }
        if (pathlen > prevPathLen) // ���� ��������� ���� ������ �������������� �������������
        {
            // ��������� ��� � ������ ����� �������������
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
        list<int>::iterator i; // ���� ������� ��� �� �� �������
        for (i = adj[v1].begin(); i != adj[v1].end(); ++i) // �� ���������� ���� �� ���� �������� ������� ����
        {
            if (!visited[*i])
            {
                FindLongestPathUtility(*i, v2, visited, path, index, prevPathLen, maxPath);
            }
        }

    }
    index--; // ������� ��� ������� �� ����
    visited[v1] = false; // � ������ � ������������
}

void Graph::FindLongestPath(int v1, int v2)
{
    bool* visited = new bool[V]; // �������� ��� �������� ��� �� ����������
    for (int i = 0; i < V; i++) // 
        visited[i] = false;

    int* path = new int[V]; // ���������� ��� �������� ���� (������������ ����, ��� ����� ������������� �������� ��� �������)

    int index = 0; // ����������, ����� ��������� �� ������� path


    int prevPathLen = 0; // �������, ������� ������ � ���� ������������� �������� ����� ����(����� ����� ����� ���� ������������)
    vector<int> maxPath; // ������, � ������� ������������� ������������ ����
    FindLongestPathUtility(v1, v2, visited, path, index, prevPathLen, maxPath); // ���������� �����
    if (prevPathLen == 0) // ���� ��������� �� ���������, �������� ��� ���� ���...
    {
        cout << "No solutions.\n";
        return;
    }
    // �� � ����� ������..
    cout << "Largest path from " << v1 + 1 << " to " << v2 + 1 << " is following path:" << endl;
    for (int i = 0; i < maxPath.size() - 1; i++)
    {
        cout << maxPath[i] + 1 << "->";
    }
    cout << maxPath[maxPath.size() - 1] + 1;
    cout << "\t with lenght " << prevPathLen;
}

void TestRunner(int test) // ����������� ������� ��� ������ ����������, �������?)
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
    input >> vertixes;// ���������� ������

    int s, t;
    input >> s; // ����� �����������
    input >> t; // ����� ��������

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
