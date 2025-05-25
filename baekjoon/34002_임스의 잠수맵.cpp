#include <iostream>
using namespace std;

#define FULL_EXP 25000

int A, B, C, S, V, L;
int time, exp;

void useTicket(int &ticketCount, int ticketExp)
{
    --ticketCount;

    exp += ticketExp * 30;
    time += 30;

    if (FULL_EXP < exp)
    {
        time -= (exp - FULL_EXP) / ticketExp;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B >> C >> S >> V >> L;

    exp = L * 100;

    while (exp < FULL_EXP)
    {
        if (V)
        {
            useTicket(V, C);
        }
        else if (S)
        {
            useTicket(S, B);
        }
        else
        {
            ++time;
            exp += A;
        }
    }

    cout << time;
    return 0;
}