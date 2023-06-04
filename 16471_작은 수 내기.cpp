#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, i = 0, j = 0;
    cin >> N;
    vector<int> my(N), enemy(N);
    for (int i = 0; i < N; ++i)
        cin >> my[i];
    for (int i = 0; i < N; ++i)
        cin >> enemy[i];
    sort(my.begin(), my.end());
    sort(enemy.begin(), enemy.end());
    while (true)
    {
        if (my[i] < enemy[j])
            ++i, ++j;
        else
            ++j;
        if (i > N / 2)
        {
            cout << "YES";
            return 0;
        }
        if (i == N || j == N)
            break;
    }
    cout << "NO";
    return 0;
}