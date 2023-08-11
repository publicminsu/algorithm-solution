#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
typedef tuple<float, int, string> fis;
int T;
fis students[50];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (true)
    {
        cin >> T;
        if (!T)
            break;
        for (int i = 0; i < T; ++i)
        {
            cin >> get<2>(students[i]);
            cin >> get<0>(students[i]);
            get<1>(students[i]) = -i;
        }
        sort(students, students + T, greater<fis>());
        cout << get<2>(students[0]);
        for (int i = 1; i < T; ++i)
        {
            if (get<0>(students[0]) != get<0>(students[i]))
                break;
            cout << " " << get<2>(students[i]);
        }
        cout << "\n";
    }
    return 0;
}