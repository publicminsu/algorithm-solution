#include <iostream>
#include <set>
using namespace std;
int N, M, num;
set<int> s;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> num;
        s.insert(num);
    }

    cin >> M;
    while (M--)
    {
        cin >> num;
        cout << (s.find(num) != s.end()) << " ";
    }
    return 0;
}