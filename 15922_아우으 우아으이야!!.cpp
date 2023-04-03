#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, start, end, len = 0, nS, nE;
    cin >> N >> start >> end;
    --N;
    len = end - start;
    while (N--)
    {
        cin >> nS >> nE;
        if (nE <= end)
            continue;
        if (nS < end)
            nS = end;
        end = nE;
        len += nE - nS;
    }
    cout << len;
    return 0;
}