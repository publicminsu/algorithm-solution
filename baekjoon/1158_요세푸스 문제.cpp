#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K, i = 1, j = 0, cnt = 0;
    cin >> N >> K;
    vector<bool> visted(N + 1);
    cout << "<";
    while (true)
    {
        if (!visted[i])
        {
            ++j;
            if (j == K)
            {
                visted[i] = true;
                j = 0;
                ++cnt;
                if (cnt == N)
                    break;
                cout << i << ", ";
            }
        }
        ++i;
        if (i == N + 1)
            i = 1;
    }
    cout << i << ">";
    return 0;
}