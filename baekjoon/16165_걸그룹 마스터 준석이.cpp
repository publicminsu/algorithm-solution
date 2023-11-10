#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N, M;
unordered_map<string, vector<string>> members; // ����� �̸��� �����ϴ� ��
unordered_map<string, string> group;           // �׷��� �̸��� �����ϴ� ��
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
        if (type) // ������ ����
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