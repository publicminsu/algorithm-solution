#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int T, n, k;
string str;
map<string, int> m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;

        m.clear();

        while (n--)
        {
            string buffer;
            int upperCount = 0;
            cin >> str;
            for (const char &c : str)
            {
                if (c >= 'a')
                {
                    buffer += c;
                }
                else
                {
                    buffer += (c + 32);
                    ++upperCount;
                }
            }

            sort(buffer.begin(), buffer.end());

            buffer += to_string(upperCount);

            ++m[buffer];
        }

        int sum = 0;
        for (auto p : m)
        {
            int cnt = p.second;
            sum += (cnt * (cnt - 1)) / 2;
        }
        cout << sum << "\n";
    }
    return 0;
}