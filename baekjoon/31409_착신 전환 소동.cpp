#include <iostream>
#include <vector>
using namespace std;
int N, cnt;
vector<int> phones;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    phones = vector<int>(N);
    for (int &phone : phones)
    {
        cin >> phone;
    }

    for (int i = 0; i < N; ++i)
    {
        if (phones[i] == i + 1) // 나 자신이 아닌 곳으로 연결
        {
            phones[i] = i + 2;
            ++cnt;
        }
    }

    if (phones[N - 1] == N + 1) // 마지막 값이 범위 초과일 경우 1로 변경
    {
        phones[N - 1] = 1;
    }

    cout << cnt << "\n";
    for (const int &phone : phones)
    {
        cout << phone << " ";
    }

    return 0;
}