#include <iostream>

using namespace std;

#define INF 987654321

int N;
int nums[50], answer = INF;

bool check(int a, int b)
{
    for (int i = 1; i < N; ++i)
    {
        if (nums[i] != nums[i - 1] * a + b)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    bool isAllSame = true;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
        isAllSame &= nums[0] == nums[i];
    }

    if (N == 1)
    {
        cout << "A";
        return 0;
    }

    if (isAllSame)
    {
        cout << nums[0];
        return 0;
    }

    for (int a = -200; a <= 200; ++a)
    {
        int num0a = nums[0] * a;
        int b = nums[1] - num0a;

        if (check(a, b))
        {
            if (answer != INF)
            {
                cout << "A";
                return 0;
            }
            answer = nums[N - 1] * a + b;
        }
    }

    if (answer != INF)
    {
        cout << answer;
    }
    else
    {
        cout << "B";
    }
    return 0;
}