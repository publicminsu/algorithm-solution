#include <iostream>
#include <algorithm>
using namespace std;
using pic = pair<int, char>;

pic chocolates[5];
char htckg[] = {'H', 'T', 'C', 'K', 'G'};
int M, prevSum;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 0; i < 5; ++i)
    {
        pic &chocolate = chocolates[i];
        cin >> chocolate.first;
        chocolate.first = -chocolate.first;
        chocolate.second = htckg[i];

        prevSum -= chocolate.first;
    }

    cin >> M;

    while (M--)
    {
        for (int i = 0, j; i < 5; ++i)
        {
            cin >> j;

            for (int k = 0; k < 5; ++k)
            {
                pic &chocolate = chocolates[k];
                if (chocolate.second == htckg[i])
                {
                    chocolate.first += j;
                    break;
                }
            }
        }

        sort(chocolates, chocolates + 5);

        int one = prevSum % 10;

        if (one == 0 || one == 1)
        {
            one = 10;
        }

        int sum = 0;
        string str = "";
        for (int i = 0; i < 5; ++i)
        {
            const pic &chocolate = chocolates[i];

            sum -= chocolate.first;

            if (chocolate.first)
            {
                str += chocolate.second;
            }
        }

        prevSum = sum;

        if (str.empty())
        {
            str = "NULL";
        }

        string sumStr = "";

        while (sum)
        {
            sumStr = to_string(sum % one) + sumStr;
            sum /= one;
        }

        if (sumStr.empty())
        {
            sumStr = "0";
        }

        cout << sumStr << "7H\n"
             << str << "\n";
    }
    return 0;
}