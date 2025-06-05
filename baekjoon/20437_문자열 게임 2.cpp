#include <iostream>
#include <queue>

using namespace std;

int T, K;
string str;
queue<int> indexes[26];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 26; ++i)
        {
            while (!indexes[i].empty())
            {
                indexes[i].pop();
            }
        }

        cin >> str >> K;

        int lenMin = 10001, lenMax = -1;

        for (int i = 0; i < str.size(); ++i)
        {
            int alp = str[i] - 'a';

            indexes[alp].push(i);

            if (indexes[alp].size() >= K)
            {
                int idx = indexes[alp].front();
                indexes[alp].pop();

                int len = i - idx + 1;

                lenMax = max(len, lenMax);
                lenMin = min(len, lenMin);
            }
        }

        if (lenMax == -1)
        {
            cout << -1;
        }
        else
        {
            cout << lenMin << " " << lenMax;
        }

        cout << "\n";
    }

    return 0;
}