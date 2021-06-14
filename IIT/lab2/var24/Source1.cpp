#include <iostream>
#include <vector>
#include<stdio.h>
#include<map>
#include<set>
#include <fstream>
#include <sstream>

using namespace std;

vector<int>used;
vector<int>ans;
vector<vector<int>>v;
int n, m, f, s, after(0);

ifstream input("input.txt", ios::app);
ofstream output("output.txt", ios::app);

void dfs(int x) {

    used[x] = 1;//������ ������, ��������������� �������, 1

    for (int i = 0; i < v[x].size(); ++i) {//���������� ��� ����� � �������(�������)

        int t = v[x][i];

        if (used[t] == 1) {

            after = 1;
            return;

        }
        else if (!used[t])dfs(t);

    }

    used[x] = 2;

}


void top_sort(int x) {
    used[x] = 1;
    for (int i = 0; i < v[x].size(); ++i) {
        int t = v[x][i];
        if (!used[t])
            top_sort(t);
    }
    ans.push_back(x);
}

int main()
{
    input >> n >> m;
    used.resize(n);
    v.resize(n);

    set<pair<int, int>>st;

    for (int i = 0; i < m; ++i) {//��������� ��� ����, ��� ������� �������� �������
        input >> f >> s;//��������� ���� ������ 

        if (f == s)continue;//���� ������ ���� � ��� ��, ����������

        if (st.find(make_pair(f, s)) != st.end())continue;//���� ����� ����� ���� ������ ����� ��� ���������, ����������
        else st.insert(make_pair(f, s));//����� ��������� ���� ������ �� ���������

        v[f - 1].push_back(s - 1);//��������� ����� ����� �������� f � s
    }
    for (int i = 0; i < n; ++i) {//���������� ������
        if (!used[i])
            dfs(i);
        if (after) {
            output << "No"<<endl;
            return 0;
        }
    }
    used.clear();
    used.resize(n);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            top_sort(i);
    }
    output << "Yes" <<endl;
    for (int i = ans.size() - 1; i >= 0; --i)
        output << ans[i] + 1 << " ";


    return 0;
}