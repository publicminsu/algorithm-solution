#include <iostream>
using namespace std;

int N, M;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    cout << (N * 100 >= M ? "Yes" : "No");
    return 0;
}