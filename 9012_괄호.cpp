#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        string line, output = "YES";
        cin >> line;
        for (char c : line)
        {
            if (c == '(')
                count++;
            else
            {
                count--;
                if (count < 0)
                {
                    output = "NO";
                    break;
                }
            }
        }
        if (count > 0)
            output = "NO";
        cout << output << '\n';
        
    }
    return 0;
}