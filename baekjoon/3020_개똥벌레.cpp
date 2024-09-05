#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> top, bottom;
int N, H, answerLength, answerCount;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> H;

    top = bottom = vector<int>(N / 2);

    for (int i = 0, j; i < N; ++i)
    {
        cin >> j;

        if (i % 2)
        {
            top[i / 2] = H - j;
        }
        else
        {
            bottom[i / 2] = j;
        }
    }

    sort(top.begin(), top.end());
    sort(bottom.begin(), bottom.end());

    answerLength = N;

    for (int i = 0; i < H; ++i)
    {
        int topLength = upper_bound(top.begin(), top.end(), i) - top.begin();
        int bottomLength = N / 2 - (upper_bound(bottom.begin(), bottom.end(), i) - bottom.begin());

        int sum = topLength + bottomLength;

        if (answerLength > sum)
        {
            answerLength = sum;
            answerCount = 1;
        }
        else if (answerLength == sum)
        {
            ++answerCount;
        }
    }

    cout << answerLength << " " << answerCount;
    return 0;
}