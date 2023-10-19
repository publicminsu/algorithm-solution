#include <iostream>
#include <string>
#include <map>
using namespace std;
string getExtension(string filename)
{
    int idx = 0;
    string ret;
    for (; idx < filename.length(); ++idx)
        if (filename[idx] == '.')
        {
            ++idx;
            break;
        }
    for (; idx < filename.length(); ++idx)
        ret += filename[idx];
    return ret;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N;
    string filename;
    map<string, int> extensions;
    cin >> N;
    while (N--)
    {
        cin >> filename;
        ++extensions[getExtension(filename)];
    }
    for (auto extension : extensions)
        cout << extension.first << " " << extension.second << "\n";
    return 0;
}