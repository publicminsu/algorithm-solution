#include <iostream>
using namespace std;
string A, B;

void toLower(string &str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
}

void printEquals()
{
    cout << (A == B ? "true" : "false") << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B;

    if (A == "null")
    {
        cout << "NullPointerException\n"
             << "NullPointerException";
    }
    else
    {
        printEquals();

        if (B == "null")
        {
            cout << "false";
        }
        else
        {
            toLower(A);
            toLower(B);
            printEquals();
        }
    }
    return 0;
}