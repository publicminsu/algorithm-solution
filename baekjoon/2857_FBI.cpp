#include <iostream>
using namespace std;
string str;
bool isFind;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 1; i <= 5; ++i)
    {
        cin >> str;

        if (str.find("FBI") != -1)
        {
            isFind = true;
            cout << i << " ";
        }
    }

    if (!isFind)
    {
        cout << "HE GOT AWAY!";
    }
    return 0;
}