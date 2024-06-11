#include <iostream>
#include <set>
using namespace std;
set<int> s;
int N, M;
bool isSub(set<int> &a)
{
    if (s.size() < a.size())
    {
        swap(s, a);
    }

    for (const int &i : a)
    {
        if (s.find(i) == s.end())
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0, k; i < N; ++i)
    {
        set<int> a;
        for (int j = 0; j < M; ++j)
        {
            cin >> k;

            if (k)
            {
                a.insert(j);
            }
        }

        if (!isSub(a))
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}