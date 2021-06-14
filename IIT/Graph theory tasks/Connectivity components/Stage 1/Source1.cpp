#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int search_vertex(vector<vector<int> >& g, int edge, int start)
{
	for (int i = 0; i < g.size(); i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			if (g[i][j] == edge && i != start)return i;
		}
	}
	return -1;
}

const int TEST_KOL = 3;

int main()
{
	for (int test_num = 1; test_num <= TEST_KOL; test_num++)
	{
		ifstream in(to_string(test_num) + ".txt");
		vector<vector<int> > graph;
		int n;
		in >> n;
		for (int i = 0; i < n; i++)
		{
			int k;
			in >> k;
			vector<int> tmp;
			for (int j = 0; j < k; j++)
			{
				int m;
				in >> m;
				tmp.push_back(m);
			}
			graph.push_back(tmp);
		}

		vector<int> visit(n, 0);
		int num = 1;
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == 0)
			{
				queue<int> q;
				q.push(i);
				visit[i] = num;
				while (!q.empty())
				{
					int v = q.front();
					for (int j = 0; j < graph[v].size(); j++)
					{
						int tmp = search_vertex(graph, graph[v][j], v);
						if (visit[tmp] == 0)
						{
							visit[tmp] = num;
							q.push(tmp);
						}
					}
					q.pop();
				}
				num++;
			}
		}
		cout << "TEST #" << test_num << '\n';
		cout << "Graph:\n";
		for (int i = 0; i < n; i++)
		{
			cout << i << "| ";
			for (int j = 0; j < graph[i].size(); j++)
			{
				cout << graph[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 1; i < num; i++)
		{
			cout << "Component #" << i << endl;
			for (int j = 0; j < n; j++)
			{
				if (visit[j] == i)cout << j << ' ';
			}
			cout << "\n\n";
		}
		in.close();
		system("pause");
		system("cls");
	}
	return 0;
}