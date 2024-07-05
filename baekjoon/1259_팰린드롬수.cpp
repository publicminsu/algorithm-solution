#include <iostream>
using namespace std;
string num;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> num;

        if (num == "0")
        {
            break;
        }

        bool isFind = true;

        for (int i = 0; i < num.size() / 2; ++i)
        {
            if (num[i] != num[num.size() - i - 1])
            {
                isFind = false;
            }
        }

        cout << (isFind ? "yes" : "no") << "\n";
    }

    return 0;
}