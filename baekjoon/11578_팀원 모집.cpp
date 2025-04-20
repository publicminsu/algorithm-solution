#include <iostream>
using namespace std;

#define INF 11

int N, M, fullBit, answer = INF;
int students[10];

void init()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> M;

    fullBit = (1 << N) - 1;

    for (int i = 0, O, P; i < M; ++i)
    {
        cin >> O;

        while (O--)
        {
            cin >> P;
            students[i] |= 1 << (P - 1);
        }
    }
}

void comb(int index, int bit, int cnt)
{
    if (bit == fullBit)
    {
        answer = min(answer, cnt);
        return;
    }

    if (index == M)
    {
        return;
    }

    comb(index + 1, bit, cnt);

    bit |= students[index];

    comb(index + 1, bit, cnt + 1);
}

int main()
{
    init();
    comb(0, 0, 0);

    if (answer == INF)
    {
        answer = -1;
    }

    cout << answer;
    return 0;
}