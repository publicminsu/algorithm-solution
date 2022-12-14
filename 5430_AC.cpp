#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    string deq[100001];
    while (T--)
    {
        string p, arrSTR, num = "", output;
        bool isTurn = false;
        int n, start = 0, end = 0;
        cin >> p >> n;
        cin.ignore();
        getline(cin, arrSTR);
        for (char c : arrSTR)
        {
            if (c == ',' || c == ']')
            {
                deq[end++] = num;
                num = "";
            }
            else if (48 <= c && 57 >= c)
            {
                num += c;
            }
        }
        for (char c : p)
        {
            if (c == 'R')
                isTurn = !isTurn;
            else
            {
                n--;
                if (isTurn)
                    --end;
                else
                    ++start;
            }
        }
        if (n < 0)
        {
            output = "error";
        }
        else
        {
            output = "[";
            int s = isTurn ? end - 1 : start;
            int e = isTurn ? start - 1 : end;
            int plus = isTurn ? -1 : 1;
            while (s != e)
            {
                output += deq[s];
                s += plus;
                if (s == e)
                    break;
                output += ",";
            }
            output += "]";
        }
        cout << output << "\n";
    }
    return 0;
}