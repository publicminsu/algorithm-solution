#include <iostream>
#include <string>
#include <regex>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string sound;
    cin >> sound;
    regex re("((100+1+)|(01)+)+");
    if (regex_match(sound, re))
        cout << "SUBMARINE";
    else
        cout << "NOISE";
    return 0;
}