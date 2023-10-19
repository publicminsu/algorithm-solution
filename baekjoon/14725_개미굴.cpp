#include <iostream>
#include <string>
#include <map>
using namespace std;
struct node
{
    map<string, node *> m; // 맵에 맵을 이어서 트리의 구조를 보이게 된다.
};
node *head;
void print(node *cur, string depth)
{
    for (auto s : cur->m)
    {
        cout << depth + s.first << "\n";
        print(s.second, depth + "--"); // 깊어질수록 층에 대한 표시를 추가한다.
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int N, K;
    string food;
    head = new node;
    cin >> N;
    while (N--)
    {
        cin >> K;
        node *cur = head;
        while (K--)
        {
            cin >> food;
            if (cur->m.find(food) == cur->m.end()) // 없을 시 새로 만든다.
            {
                cur->m[food] = new node;
            }
            cur = cur->m[food]; // 더 깊이 들어간다.
        }
    }
    print(head, "");
    return 0;
}
