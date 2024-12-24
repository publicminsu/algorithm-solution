#include <iostream>
using namespace std;
int score;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> score;
    score /= 10;
    if (score >= 9)
    {
        cout << "A";
    }
    else if (score >= 8)
    {
        cout << "B";
    }
    else if (score >= 7)
    {
        cout << "C";
    }
    else if (score >= 6)
    {
        cout << "D";
    }
    else
    {
        cout << "F";
    }
    return 0;
}