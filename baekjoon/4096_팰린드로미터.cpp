#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string str;
    while (true)
    {
        cin >> str;
        if (str == "0")
        {
            break;
        }

        int count = 0;
        int size = str.size();
        while (true)
        {
            bool isFind = true;

            for (int i = 0; i < size / 2; ++i)
            {
                if (str[i] != str[size - 1 - i])
                {
                    isFind = false;
                    break;
                }
            }

            if (isFind)
            {
                cout << count << "\n";
                break;
            }

            ++count;
            int num = stoi(str);

            string next = to_string(num + 1);
            str = "";
            for (int i = 0; i < size - next.size(); ++i)
            {
                str.push_back('0');
            }
            str += next;
        }
    }
    return 0;
}