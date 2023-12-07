#include <iostream>
#include <vector>
using namespace std;
int N;
long long ret;
vector<int> stack;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    stack.reserve(N);
    for (int i = 0, h; i < N; ++i)
    {
        cin >> h;
        while (!stack.empty() && stack.back() <= h) // 높거나 같은 빌딩일 경우
        {
            stack.pop_back();
        }
        ret += stack.size(); // 해당 위치를 볼 수 있는 빌딩의 수
        stack.push_back(h);
    }
    cout << ret;
    return 0;
}