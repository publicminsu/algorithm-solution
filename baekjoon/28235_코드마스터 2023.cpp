#include <iostream>
using namespace std;
string str;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> str;
    switch (str[0])
    {
    case 'S':
        cout << "HIGHSCHOOL";
        break;
    case 'C':
        cout << "MASTER";
        break;
    case '2':
        cout << "0611";
        break;
    case 'A':
        cout << "CONTEST";
        break;
    }
    return 0;
}