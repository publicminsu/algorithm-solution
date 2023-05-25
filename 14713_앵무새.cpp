#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;
vector<queue<string>> bird;
vector<string> write;
int N;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cin.ignore();
    bird = vector<queue<string>>(N, queue<string>());
    for (int i = 0; i <= N; ++i)
    {
        string j, k;
        getline(cin, j);
        stringstream ss(j);
        while (getline(ss, k, ' '))
        {
            if (i != N)
                bird[i].push(k);
            else
                write.push_back(k);
        }
    }
    for (string w : write)
    {
        bool isCorr = false;
        for (int i = 0; i < N; ++i)
        {
            if (bird[i].empty())
                continue;
            if (bird[i].front() == w)
            {
                bird[i].pop();
                isCorr = true;
                break;
            }
        }
        if (!isCorr)
        {
            cout << "Impossible";
            return 0;
        }
    }
    for (int i = 0; i < N; ++i)
        if (!bird[i].empty())
        {
            cout << "Impossible";
            return 0;
        }
    cout << "Possible";
    return 0;
}