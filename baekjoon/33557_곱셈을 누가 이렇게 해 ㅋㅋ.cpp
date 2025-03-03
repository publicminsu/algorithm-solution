#include <iostream>
using namespace std;
using ll = long long;

int T;
ll A, B;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;

    while (T--)
    {
        cin >> A >> B;

        string result = to_string(A * B);

        string wrongResult = "";

        while (A && B)
        {
            wrongResult = to_string((A % 10) * (B % 10)) + wrongResult;
            A /= 10;
            B /= 10;
        }

        while (A)
        {
            wrongResult = to_string(A % 10) + wrongResult;
            A /= 10;
        }

        while (B)
        {
            wrongResult = to_string(B % 10) + wrongResult;
            B /= 10;
        }

        cout << (result == wrongResult) << "\n";
    }
    return 0;
}