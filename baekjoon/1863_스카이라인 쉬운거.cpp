#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, ret = 0;
    vector<int> stack;
    cin >> n;
    for (int i = 0, height; i < n; ++i)
    {
        cin >> height >> height;
        if (stack.empty())
            stack.push_back(height);
        else
        {
            if (stack.back() < height)
                stack.push_back(height);
            else
            {
                while (!stack.empty() && stack.back() > height)
                {
                    ++ret;
                    stack.pop_back();
                }
                if ((!stack.empty() && stack.back() != height) || stack.empty())
                    stack.push_back(height);
            }
        }
    }
    while (!stack.empty())
    {
        if (stack.back() != 0)
            ++ret;
        stack.pop_back();
    }
    cout << ret;
    return 0;
}