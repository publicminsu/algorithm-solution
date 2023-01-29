#include <iostream>
#include <cstring>
using namespace std;
int parent[10001];
int getDepth(int cur)
{
    int cnt = 0;
    while (cur != 0)
    {
        cur = parent[cur];
        ++cnt;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        memset(parent, 0, sizeof(parent));
        int N, p, c;
        cin >> N;
        while (N-- > 1)
        {
            cin >> p >> c;
            parent[c] = p;
        }
        cin >> p >> c;
        int n1 = getDepth(p), n2 = getDepth(c);
        while (n1 != n2)
        {
            if (n1 > n2)
            {
                p = parent[p];
                --n1;
            }
            else
            {
                c = parent[c];
                --n2;
            }
        }
        while (p != c)
        {
            c = parent[c];
            p = parent[p];
        }
        cout << p << "\n";
    }
}