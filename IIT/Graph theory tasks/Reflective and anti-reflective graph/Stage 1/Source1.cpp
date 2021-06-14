#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int TEST_KOL = 5;

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

		int num = 0;
		for (int i = 0; i < n; i++)
		{
			bool check = false;
			for (int j = 0; j < graph[i].size(); j++)
			{
				if (graph[i][j] == i)
					check = true;
			}
			if (check)
				num++;
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
		if(num==n)
			cout<< "The Graph is reflexive" << endl;
		else if(num == 0)
			cout << "The Graph is anti-reflexive" << endl;
		else if(num<n)
			cout << "The Graph is partially reflexive" << endl;
		in.close();
		system("pause");
		system("cls");
	}
	return 0;
}