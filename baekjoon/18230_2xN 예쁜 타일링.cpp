#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, A, B;
int length, index21, index22, sum;
vector<int> tile21, tile22;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N >> A >> B;

    tile21 = vector<int>(A);
    tile22 = vector<int>(B);

    for (int &i : tile21)
    {
        cin >> i;
    }

    for (int &i : tile22)
    {
        cin >> i;
    }

    sort(tile21.begin(), tile21.end(), greater<int>());
    sort(tile22.begin(), tile22.end(), greater<int>());

    for (; index22 < B && length + 2 <= N; ++index22, length += 2)
    {
        sum += tile22[index22];
    }

    for (; index21 < A && length < N; ++index21, ++length)
    {
        sum += tile21[index21];
    }

    for (; index21 + 1 < A && --index22 >= 0 && tile21[index21] + tile21[index21 + 1] > tile22[index22]; index21 += 2)
    {
        sum -= tile22[index22];
        sum += tile21[index21] + tile21[index21 + 1];
    }

    cout << sum;
    return 0;
}