#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, M;
    string poke;
    cin >> N >> M;
    vector<string> v(N + 1);
    unordered_map<string, int> um;
    for (int i = 1; i <= N; ++i)
    {
        cin >> poke;
        v[i] = poke;
        um[poke] = i;
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> poke;
        if (poke[0] >= '0' && poke[0] <= '9')
        {
            int pNum = stoi(poke);
            cout << v[pNum] << "\n";
        }
        else
        {
            cout << um[poke] << "\n";
        }
    }
    return 0;
}