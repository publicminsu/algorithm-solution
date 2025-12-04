#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, Q;
vector<int> holes;
int holeToIndex[200001];

void initHoles()
{
    cin >> N;
    holes.reserve(N);

    for (int i = 0; i < N; ++i)
    {
        int hole;
        cin >> hole;

        hole += i;

        if (holes.empty() || holes.back() < hole)
        {
            holes.push_back(hole);
            holeToIndex[hole] = i + 1;
        }
    }
}

void processQueries()
{
    cin >> Q;

    while (Q--)
    {
        int acorn;
        cin >> acorn;

        int hole = *lower_bound(holes.begin(), holes.end(), acorn);
        cout << holeToIndex[hole] << " ";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    initHoles();
    processQueries();
    return 0;
}