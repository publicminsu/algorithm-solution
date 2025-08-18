#include <iostream>
#include <stack>
using namespace std;

int N;
stack<char> st;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    cin.ignore();

    while (N--)
    {
        string str;
        getline(cin, str);

        for (char c : str)
        {
            if (c == ' ')
            {
                while (!st.empty())
                {
                    cout << st.top();
                    st.pop();
                }

                cout << c;
            }
            else
            {
                st.push(c);
            }
        }

        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }

        cout << "\n";
    }
    return 0;
}