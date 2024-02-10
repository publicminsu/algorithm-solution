#include <iostream>
using namespace std;
#define LIMIT 7980
#define E_LIMIT 15
#define S_LIMIT 28
#define M_LIMIT 19
int E, S, M, e, s, m;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> E >> S >> M;
    E %= E_LIMIT;
    S %= S_LIMIT;
    M %= M_LIMIT;
    for (int i = 1; i <= LIMIT; ++i)
    {
        e = i % E_LIMIT;
        s = i % S_LIMIT;
        m = i % M_LIMIT;
        if (E == e && S == s && M == m) // 동일할 경우
        {
            cout << i;
            break;
        }
    }
    return 0;
}