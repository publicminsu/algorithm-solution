#include <iostream>
using namespace std;

int N, cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        int j = i;

        bool isSeq = true;

        int prevNum = j % 10;
        j /= 10;
        int num = j % 10;
        j /= 10;

        while (j)
        {
            int nextNum = j % 10;
            j /= 10;

            if (prevNum - num != num - nextNum)
            {
                isSeq = false;
            }

            prevNum = num;
            num = nextNum;
        }

        if (isSeq)
        {
            ++cnt;
        }
    }

    cout << cnt;
    return 0;
}