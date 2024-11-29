#include <iostream>
using namespace std;
int N;

string GetBottle(int cnt)
{
    switch (cnt)
    {
    case 0:
        return "no more bottles";
    case 1:
        return "1 bottle";
    default:
        return to_string(cnt) + " bottles";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    for (int i = N; i > 0; --i)
    {
        string bottles = i - 1 == 0 ? "no more" : to_string(i - 1);

        cout << GetBottle(i) << " of beer on the wall, " << GetBottle(i) << " of beer.\n"
             << "Take one down and pass it around, " << GetBottle(i - 1) << " of beer on the wall.\n\n";
    }

    cout << "No more bottles of beer on the wall, no more bottles of beer.\n"
         << "Go to the store and buy some more, " << GetBottle(N) << " of beer on the wall.";
    return 0;
}