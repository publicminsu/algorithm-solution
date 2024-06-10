#include <iostream>
using namespace std;
string library, label;
int f, c, w;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    while (true)
    {
        cin >> library >> f;

        if (library == "#")
        {
            break;
        }

        cout << library << " Library\n";

        cin >> c;

        for (int i = 1; i <= c; ++i)
        {
            cin >> w >> label;

            cout << "Book " << i << " ";
            cout << (f * label.length() + 2 <= w ? "horizontal" : "vertical") << "\n";
        }
    }
    return 0;
}