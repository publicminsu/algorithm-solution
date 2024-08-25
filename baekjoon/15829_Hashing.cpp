#include <iostream>
using namespace std;
#define r 31
#define M 1234567891
using ll = long long;
int L;
ll sr = 1, answer;
string str;
int main()
{
    cin >> L >> str;

    for (const char &c : str)
    {
        answer = (answer + (c - 'a' + 1) * sr) % M;

        sr = (sr * r) % M;
    }

    cout << answer;
    return 0;
}