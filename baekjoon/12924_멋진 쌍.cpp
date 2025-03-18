#include <iostream>
#include <set>
using namespace std;
int A, B, answer;
set<int> s;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> A >> B;

    if (B <= 10)
    {
        cout << 0;
    }
    else
    {
        int length = 0;

        int i = A;
        int digits = 1;
        while (i >= 10)
        {
            i /= 10;
            ++length;
            digits *= 10;
        }

        for (int i = A; i <= B; ++i)
        {
            s.clear();

            int num = i;

            for (int j = 0; j < length; ++j)
            {
                int unit = num % 10;
                num /= 10;

                num = num + digits * unit;

                if (num > i && num <= B)
                {
                    s.insert(num);
                }
            }

            answer += s.size();
        }

        cout << answer;
    }
    return 0;
}