#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<string> us;
int N, M, answer;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;

    while (N--)
    {
        cin >> str;
        us.insert(str);
    }

    while (M--)
    {
        cin >> str;
        if (us.find(str) != us.end()) // 존재한다면
        {
            ++answer;
        }
    }

    cout << answer;
    return 0;
}