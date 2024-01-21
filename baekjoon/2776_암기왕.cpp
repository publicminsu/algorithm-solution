#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
int T, N, M, num;
unordered_set<int> us;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--)
    {
        us.clear();

        cin >> N;
        while (N--)
        {
            cin >> num;
            us.insert(num);
        }

        cin >> M;
        while (M--)
        {
            cin >> num;
            cout << (us.find(num) != us.end()) << "\n"; // 존재하는지 확인
        }
    }

    return 0;
}