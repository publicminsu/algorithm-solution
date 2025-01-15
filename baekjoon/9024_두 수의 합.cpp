#include <iostream>
#include <algorithm>
using namespace std;
int t, n, k, answerDiff, answerCnt;
int v[1000000];

void init()
{
    cin >> n >> k;

    for (int i = 0, num; i < n; ++i)
    {
        cin >> v[i];
    }

    sort(v, v + n);

    answerDiff = 987654321;
}

void updateAnswer(int num1, int num2)
{
    if (num1 == num2)
    {
        return;
    }

    int sum = num1 + num2;
    int diff = abs(k - sum);

    if (diff == answerDiff)
    {
        ++answerCnt;
    }
    else if (diff < answerDiff)
    {
        answerDiff = diff;
        answerCnt = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> t;
    while (t--)
    {
        init();

        for (int index1 = 0; index1 < n - 1; ++index1)
        {
            int num1 = v[index1];
            auto lb = lower_bound(v + index1 + 1, v + n, k - num1);

            int num2 = *lb;
            updateAnswer(num1, num2);

            --lb;
            num2 = *lb;
            updateAnswer(num1, num2);
        }
        cout << answerCnt << "\n";
    }
    return 0;
}