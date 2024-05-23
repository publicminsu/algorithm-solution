#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> choice;
map<string, int> m;
int N, answer;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    choice = vector<int>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        m[str] = i;
    }
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        choice[i] = m[str];
    }

    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (choice[i] < choice[j])
            {
                ++answer;
            }
        }
    }

    cout << answer << "/" << (N * (N - 1) / 2);
    return 0;
}