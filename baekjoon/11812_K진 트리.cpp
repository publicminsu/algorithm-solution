#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll N, x, y;
int K, Q, answer, gapK;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> K >> Q;
    gapK = K - 2; // 보정

    if (K == 1) // 1인 경우에는 한 줄로 됨
    {
        while (Q--)
        {
            cin >> x >> y;
            cout << abs(x - y) << " ";
        }
    }
    else
    {
        while (Q--)
        {
            answer = 0;
            cin >> x >> y;

            while (true)
            {
                if (x == y) // 값이 같다면
                {
                    break;
                }

                if (x > y) // 다를 경우 부모의 값으로 이동
                {
                    x = (x + gapK) / K;
                    ++answer;
                }
                else
                {
                    y = (y + gapK) / K;
                    ++answer;
                }
            }
            cout << answer << "\n";
        }
    }
    return 0;
}