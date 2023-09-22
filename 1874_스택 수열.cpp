#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, num = 1, k;
    cin >> n;
    vector<int> stack;
    vector<char> ret;
    for (int i = 1; i <= n; ++i)
    {
        cin >> k;
        if (num <= k)
        {
            while (num <= k)
            {
                stack.push_back(num++);
                ret.push_back('+');
            }
            stack.pop_back();
            ret.push_back('-');
        }
        else
        {
            if (stack.empty() || stack.back() < k)
            {
                cout << "NO";
                return 0;
            }
            while (!stack.empty() && stack.back() >= k)
            {
                stack.pop_back();
                ret.push_back('-');
            }
        }
    }
    for (char c : ret)
        cout << c << "\n";
    return 0;
}