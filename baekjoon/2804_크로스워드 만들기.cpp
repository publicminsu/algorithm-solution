#include <iostream>
using namespace std;

string A, B;
char map[31][31];

void input()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;
}

char FindChar()
{
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < B.size(); ++j)
        {
            if (A[i] == B[j])
            {
                return A[i];
            }
        }
    }

    return 'z';
}

int findIndex(const string &word, const char &c)
{
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] == c)
        {
            return i;
        }
    }
    return 0;
}

void paintMap(const char &c)
{
    int aIndex = findIndex(A, c);
    int bIndex = findIndex(B, c);

    for (int i = 0; i < A.size(); ++i)
    {
        map[bIndex][i] = A[i];
    }

    for (int i = 0; i < B.size(); ++i)
    {
        map[i][aIndex] = B[i];
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
    const char &c = FindChar();
    paintMap(c);
    print();
    return 0;
}