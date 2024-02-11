#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, int> um;
int gemCnt, maxCnt, startI, endI;
vector<int> solution(vector<string> gems)
{
    vector<int> answer = vector<int>(2);

    for (const string &gem : gems)
    {
        if (!um[gem]) // 없는 보석이면 보석 개수 증가
        {
            um[gem] = true;
            ++maxCnt;
        }
    }
    um.clear();

    while (true)
    {
        if (gemCnt == maxCnt) // 만약 최대 보석 개수랑 현재 보석 개수가 같다면
        {
            const string &gem = gems[startI++];
            if (--um[gem] == 0) // 만약 지금 뺀 보석이 0개가 된다면
            {
                --gemCnt;
            }
        }
        else
        {
            if (endI == gems.size()) // 뒤를 늘릴 수 없어서 최대 보석 개수에 도달할 수 없는 경우
            {
                break;
            }

            const string &gem = gems[endI++];
            if (um[gem]++ == 0) // 만약 지금 뺀 보석이 0개였다면
            {
                ++gemCnt;
            }
        }
        if (gemCnt == maxCnt) // 최대 보석 개수에 도달했다면
        {
            if ((answer[0] == 0 && answer[1] == 0) || ((endI - startI) - 1 < (answer[1] - answer[0]))) // 처음 최대 보석 개수에 도달했거나 길이가 더 짧다면
            {
                answer = {startI + 1, endI};
            }
        }
    }
    return answer;
}