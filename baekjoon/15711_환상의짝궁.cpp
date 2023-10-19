#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define MaxN 2000000 // 2*10^12*2의 제곱근
using namespace std;
typedef unsigned long long ull;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    vector<int> prime;
    bool isPrime[MaxN + 1];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for (ull i = 2; i <= MaxN; ++i)
    {
        if (isPrime[i])
        {
            prime.push_back(i);
            for (ull j = i * i; j <= MaxN; j += i) // i의 배수들은 소수가 아니다.
            {
                isPrime[j] = false;
            }
        }
    }
    while (T--)
    {
        bool isAble = true;
        ull A, B, sum;
        cin >> A >> B;
        sum = A + B;
        if (sum <= 3) // 3 이하는 소수 + 소수가 불가능하다.
        {
            isAble = false;
        }
        else if ((sum & 1) == 0) // 골드 바흐 추측으로 2 이상의 짝수는 소수 + 소수가 가능하다.
        {
            isAble = true;
        }
        else // 2보다 큰 홀수에서 가능한 것은 2 + 소수의 모양이다.
        {
            sum -= 2;
            for (int p : prime)
            {
                if (sum == p) // 합-2와 소수가 같으면 탈출하면 된다.
                {
                    break;
                }
                if (sum % p == 0) // 소수로 나눠지면 소수가 아니다.
                {
                    isAble = false;
                    break;
                }
            }
        }
        cout << (isAble ? "YES" : "NO") << '\n';
    }
}
