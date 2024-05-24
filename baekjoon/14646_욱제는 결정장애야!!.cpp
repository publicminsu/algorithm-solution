#include <iostream>
#include <vector>
using namespace std;
vector<int> visited;
int N, answer, cnt;
int main()
{
    cin >> N;
    visited = vector<int>(N + 1);

    for (int i = 0, j; i < N * 2; ++i)
    {
        cin >> j;

        if (++visited[j] == 1)
        {
            answer = max(answer, ++cnt);
        }
        else if (visited[j] == 2)
        {
            --cnt;
        }
    }

    cout << answer;
    return 0;
}