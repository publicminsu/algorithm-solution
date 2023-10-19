#include <iostream>
#include <string>
using namespace std;

string origin;
int titleStart, titleEnd, pStart, pEnd, nextStart;
string makeP(string p)
{
    string temp = "";
    bool spaceFlag = true;
    for (int i = 0; i < p.length(); ++i)
    {
        if (p[i] == '<')
        {
            i = p.find('>', i);
            continue;
        }

        if (p[i] != ' ') // 공백이 아니면 더해준다
        {
            spaceFlag = false;
            temp += p[i];
        }
        else
        {
            if (spaceFlag)
                continue;
            spaceFlag = true;
            temp += p[i];
        }
    }
    return temp;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    getline(cin, origin);
    origin = origin.substr(6, origin.length() - 13); // main 제거
    while (true)
    {
        titleStart = 0;
        titleStart = origin.find("\"", titleStart);
        ++titleStart;
        titleEnd = origin.find("\"", titleStart);
        cout << "title : " << origin.substr(titleStart, titleEnd - titleStart) << "\n";
        origin = origin.substr(titleEnd);
        nextStart = origin.find("title=", titleEnd);
        pEnd = 0;
        while (true)
        {
            pStart = origin.find("<p>", pEnd);
            if (pStart == -1 || (nextStart != -1 && pStart > nextStart))
                break;
            pStart += 3;
            pEnd = origin.find("</p>", pStart);
            cout << makeP(origin.substr(pStart, pEnd - pStart)) << "\n";
        }
        if (nextStart == -1)
            break;
        origin = origin.substr(nextStart);
    }
    return 0;
}