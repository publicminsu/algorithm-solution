#include <iostream>
#include <string>
using namespace std;
int N;
void recur(int depth, const string &prefix)
{
    cout << prefix << "\"����Լ��� ������?\""
         << "\n";
    if (N != depth)
    {
        cout << prefix << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���."
             << "\n";
        cout << prefix << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���."
             << "\n";
        cout << prefix << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\""
             << "\n";
        recur(depth + 1, prefix + "____");
    }
    else
    {
        cout << prefix << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\""
             << "\n";
    }
    cout << prefix << "��� �亯�Ͽ���."
         << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N;
    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������."
         << "\n";
    recur(0, "");
    return 0;
}