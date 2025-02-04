#include <iostream>
using namespace std;
int N;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    while (N--)
    {
        int point = 0, weeks = 0;
        string detail = "";

        cin >> str;

        for (char c : str)
        {
            int value;

            if (c >= '0' && c <= '9')
            {
                value = c - '0';
            }
            else
            {
                value = c - 'A' + 10;
            }

            int prevQuotient = point / 10;

            point += value;

            int quotient = point / 10;

            if (quotient == 4)
            {
                detail = "(weapon)";
                break;
            }
            else if (quotient > 4)
            {
                detail = "(09)";
                break;
            }
            else
            {
                if (prevQuotient != quotient)
                {
                    weeks += quotient;
                }
            }
        }

        cout << weeks << detail << "\n";
    }
    return 0;
}