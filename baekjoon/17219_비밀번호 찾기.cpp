#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int N, M;
    cin >> N >> M;
    unordered_map<string, string> um;

    while (N--) // unordered_map에 기록
    {
        string site, password;
        cin >> site >> password;
        um[site] = password;
    }

    while (M--) // 사이트에 맞는 비밀번호 출력
    {
        string site;
        cin >> site;
        cout << um[site] << "\n";
    }
    return 0;
}