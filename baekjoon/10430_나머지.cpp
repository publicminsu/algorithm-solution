#include <iostream>
using namespace std;

int A, B, C;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> A >> B >> C;
    cout << (A + B) % C << "\n"
         << ((A % C) + (B % C)) % C << "\n"
         << (A * B) % C << "\n"
         << ((A % C) * (B % C)) % C;
    return 0;
}