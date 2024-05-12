#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<string> v;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    v = vector<string>(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> v[i];
        string temp;
        for (int j = 0; j < M; ++j)
        {
            temp.push_back(v[i][j]);
            temp.push_back(v[i][j]);
        }
        v[i] = temp;
    }
    for (int i = 0; i < N; ++i)
    {
        string temp;
        cin >> temp;
        if (temp != v[i])
        {
            cout << "Not Eyfa";
            return 0;
        }
    }
    cout << "Eyfa";
    return 0;
}