#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> trees;
int N, answer;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> N;

    trees = vector<int>(N);
    for (int &tree : trees)
    {
        cin >> tree;
    }

    sort(trees.begin(), trees.end(), greater<int>());

    for (int i = 0; i < N; ++i)
    {
        answer = max(answer, trees[i] + i);
    }

    cout << answer + 2; // 1일 시작 + i는 0인 것 보정
    return 0;
}