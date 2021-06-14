#include<iostream>
#include<vector>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include <string>
#include<map>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include<fstream>
#include<sstream>
using namespace std;

void printSolution(const vector<int>& sol)
{
    cout << "Answer: ";
    if (sol.size() != 0) {
        cout << "Dominant Vertexes:";
        for (int i = 0; i < sol.size(); i++)
            cout << sol[i] << " ";
    }
    else
    {
        cout << "No Dominant Vertexes";
    }
}

void VertexSearch(vector<vector<int>>& a)
{
    vector<int> solution;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].size() == (a.size() - 1))
            solution.push_back(i + 1);
    }
    printSolution(solution);
}

vector<vector<int>> GetTestingTable(int test)
{
    int n, link,j;
    string testname,line;
    testname = "test" + to_string(test) + ".txt";
    ifstream input(testname, ios::app);

    if (!input.is_open())
    {
        cout << "File is not opened" << endl;
    }
    getline(input, line);
    istringstream text_stream(line);
    text_stream >> n;

    vector<vector<int>> aa;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        getline(input, line);
        istringstream text_stream(line);

        while (text_stream >> j)
        {
            a.push_back(j);
        }
        aa.push_back(a);
        a.clear();
    }
    return aa;
}

void TestRunner(int test)
{
    int size;
    cout << "Test " << test << endl;
    vector<vector<int>> a = GetTestingTable(test);

    cout << "Table: " << endl;
    cout << "Vertexes:" << a.size() << endl;

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    VertexSearch(a);

    cout << endl;
    cout << endl;
}

// Test
int main()

{
    TestRunner(1);
    TestRunner(2);
    TestRunner(3);
    TestRunner(4);
    TestRunner(5);

    return 0;
}
