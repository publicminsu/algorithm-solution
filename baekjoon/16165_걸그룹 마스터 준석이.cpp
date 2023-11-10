#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N, M;
unordered_map<string, vector<string>> members; // 멤버의 이름을 저장하는 곳
unordered_map<string, string> group;           // 그룹의 이름을 저장하는 곳
void init()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string groupName, memberName;
        int memberNum;

        cin >> groupName >> memberNum;
        while (memberNum--)
        {
            cin >> memberName;
            members[groupName].push_back(memberName);
            group[memberName] = groupName;
        }

        sort(members[groupName].begin(), members[groupName].end());
    }
}
void quiz()
{
    while (M--)
    {
        string name;
        int type;
        cin >> name >> type;
        if (type) // 퀴즈의 종류
        {
            cout << group[name] << "\n";
        }
        else
        {
            for (string member : members[name])
            {
                cout << member << "\n";
            }
        }
    }
}
int main()
{
    init();
    quiz();
    return 0;
}