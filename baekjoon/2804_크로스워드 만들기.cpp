#include <iostream>
using namespace std;

using pii = pair<int, int>;

string A, B;
char map[31][31];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
}

pii FindIndexes()
{
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            if (A[i] == B[j])
            {
                return {i, j};
            }
        }
    }

    return {0, 0};
}

void paintMap()
{
    pii indexes = FindIndexes();

    for (int i = 0; i < A.size(); ++i)
    {
        map[indexes.second][i] = A[i];
    }

    for (int i = 0; i < B.size(); ++i)
    {
        map[i][indexes.first] = B[i];
    }
}

void print()
{
    for (int i = 0; i < B.size(); ++i)
    {
        for (int j = 0; j < A.size(); ++j)
        {
            cout << (map[i][j] ? map[i][j] : '.');
        }
        cout << "\n";
    }
}

int main()
{
    input();
    paintMap();
    print();
    return 0;
}