#include <iostream>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string mascot;
    int N, K;
    cin >> N >> mascot >> K;
    if (mascot == "annyong") // 마스코트 확인
    {
        if (!(K & 1)) // 짝수라면
        {
            K += 1;
        }
    }
    else
    {
        if (K & 1) // 홀수라면
        {
            K += 1;
        }
    }
    if (K > N)
    {
        K -= 2;
    }
    cout << K;
}
