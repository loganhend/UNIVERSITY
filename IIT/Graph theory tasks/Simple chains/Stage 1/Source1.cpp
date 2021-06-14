#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;
vector < vector<pair<int, int> > > g;
vector<int> visit;
int L;

void dfs(int v, int length, string path)
{
	visit[v] = 1;
	if (length == L) cout << path << endl;
	for (int i = 0; i < g[v].size(); i++)
	{
		int t = g[v][i].first;
		if (visit[t] == 0)
			dfs(t, length + g[v][i].second, path + "->" + to_string(t));
	}
	visit[v] = 0;
}

const int TEST_KOL = 5;

int main()
{
	for (int test_num = 1; test_num <= TEST_KOL; test_num++)
	{
		ifstream in(to_string(test_num) + ".txt");
		int n;
		in >> n >> L;
		visit.resize(n, 0);
		g.resize(0);
		for (int i = 0; i < n; i++)
		{
			vector < pair<int, int> > tmp;
			int m; in >> m;
			for (int j = 0; j < m; j++)
			{
				pair<int, int> p;
				in >> p.first >> p.second;
				tmp.push_back(p);
			}
			g.push_back(tmp);
		}

		cout << "TEST #" << test_num << endl;
		cout << "LENGTH " << L << endl;
		for (int i = 0; i < g.size(); i++)
		{
			cout << i << "| ";
			for (int j = 0; j < g[i].size(); j++)
			{
				cout << "(" << g[i][j].first << ", " << g[i][j].second << ") ";
			}
			cout << '\n';
		}
		cout << "\n";
		for (int i = 0; i < g.size(); i++)
		{
			string path = to_string(i);
			dfs(i, 0, path);
		}
		system("pause");
		system("cls");
	}
	return 0;
}