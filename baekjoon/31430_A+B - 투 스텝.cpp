#include <iostream>
using namespace std;
int T;
using ll = long long;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> T;

    if (T == 1)
    {
        ll A, B;
        cin >> A >> B;

        ll sum = A + B;

        string str = "";

        do
        {
            str += 'a' + sum % 26;

            sum /= 26;
        } while (sum);

        for (int i = str.size(); i < 13; ++i)
        {
            str += "a";
        }

        cout << str;
    }
    else
    {
        string str;

        cin >> str;

        ll sum = 0;
        ll temp = 1;

        for (int i = 0; i < 13; ++i, temp *= 26)
        {
            sum += temp * (str[i] - 'a');
        }

        cout << sum;
    }
    return 0;
}