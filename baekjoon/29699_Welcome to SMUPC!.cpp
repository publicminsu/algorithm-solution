#include <iostream>
using namespace std;

int N;
string WelcomeToSMUPC = "WelcomeToSMUPC";

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;
    --N;
    N %= WelcomeToSMUPC.length();
    cout << WelcomeToSMUPC[N];

    return 0;
}