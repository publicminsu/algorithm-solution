#include <iostream>
#include <vector>
using namespace std;
int n;
vector<bool> isUsed;
vector<int> powerOf2s, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;

    answer = vector<int>(n + 1);

    isUsed = vector<bool>(n + 1);
    isUsed[0] = true;

    for (int i = 2; i <= 2 * n; i *= 2)
    {
        powerOf2s.push_back(i);
    }

    for (int i = n; i > 0; --i)
    {
        for (int j = powerOf2s.size() - 1; j >= 0; --j)
        {
            int value = powerOf2s[j] - i;

            if (value <= 0 || value > n || isUsed[value])
            {
                continue;
            }

            isUsed[value] = true;
            answer[i] = value;
            break;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << answer[i] << "\n";
    }
    return 0;
}