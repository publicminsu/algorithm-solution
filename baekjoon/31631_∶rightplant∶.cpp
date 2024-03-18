#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> H;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;

    H.reserve(N);
    H.push_back(1);
    H.push_back(2);

    for (int i = 2; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            ++H[j];
        }
        int index = (i % 4);
        if (index % 2 == 0)
        {
            index = (i >> 1);
        }
        else if (index == 1)
        {
            index = (i - 1) >> 1;
        }
        else
        {
            index = ((i - 1) >> 1) + 1;
        }
        H.insert(H.begin() + index, 1);
    }

    for (int i : H)
    {
        cout << i << " ";
    }
    return 0;
}