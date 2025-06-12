#include <iostream>
using namespace std;

using ll = long long;

int N;
ll sum;
int numberOfClothes[100000];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> numberOfClothes[i];
        sum += numberOfClothes[i];
    }

    bool isHappy = true;

    if (sum != 1)
    {
        for (int i = 0; i < N; ++i)
        {
            if (sum < numberOfClothes[i] * 2)
            {
                isHappy = false;
                break;
            }
        }
    }

    cout << (isHappy ? "Happy" : "Unhappy");
    return 0;
}