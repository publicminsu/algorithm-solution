#include <iostream>
using namespace std;

int N;
string T;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;

    cout << (T.front() == 'A' && T.back() == 'B' ? "Yes" : "No");
    return 0;
}