#include <iostream>
#include <string>
#include <vector>
using namespace std;
string word, temp;
int ret = 0, sum = 0;
bool isMinus = false;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> word;
    temp = "";
    for (char c : word)
    {
        if (('0' <= c) && (c <= '9'))
        {
            if (temp == "" && c == '0')
                continue;
            temp += c;
        }
        else
        {
            if (isMinus)
            {
                sum -= stoi(temp);
                if (c == '-')
                {
                    ret += sum;
                    sum = 0;
                }
            }
            else
            {
                ret += stoi(temp);
            }
            temp = "";
            if (c == '-' || (isMinus && c == '+'))
                isMinus = true;
            else
                isMinus = false;
        }
    }
    if (isMinus)
    {
        sum -= stoi(temp);
        ret += sum;
    }
    else
    {
        ret += stoi(temp);
    }
    cout << ret;
    return 0;
}