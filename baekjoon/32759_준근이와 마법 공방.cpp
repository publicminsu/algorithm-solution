#include <iostream>
using namespace std;
#define p 1000000007
using ll = long long;
int N, M;
ll maxA = -100000, secondMaxA, candidateA;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    for (int i = 0, ai; i < M; ++i)
    {
        cin >> ai;

        if (ai >= maxA)
        {
            secondMaxA = maxA;
            maxA = ai;
        }
        else if (secondMaxA < ai)
        {
            secondMaxA = ai;
        }
    }

    while (N--)
    {
        candidateA = maxA + secondMaxA;

        if (maxA <= candidateA)
        {
            secondMaxA = maxA;
            maxA = candidateA;
        }
        else if (secondMaxA < candidateA)
        {
            secondMaxA = candidateA;
        }

        maxA %= p;
        secondMaxA %= p;
    }

    cout << ((candidateA + p) % p);
    return 0;
}