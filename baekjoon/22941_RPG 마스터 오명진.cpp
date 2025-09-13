#include <iostream>
using namespace std;

using ll = long long;

struct Stats
{
    ll hp, atk;

    void input()
    {
        cin >> hp >> atk;
    }
};

Stats hero, enemy;
ll P, S;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    hero.input();
    enemy.input();
    cin >> P >> S;

    ll heroAttackCnt = (enemy.hp + hero.atk - 1) / hero.atk;
    ll enemyRemainHP = enemy.hp - hero.atk * (heroAttackCnt - 1);
    if (enemyRemainHP >= 1 && enemyRemainHP <= P)
    {
        heroAttackCnt = (enemy.hp + S + hero.atk - 1) / hero.atk;
    }

    cout << (hero.hp - enemy.atk * (heroAttackCnt - 1) > 0 ? "Victory!" : "gg");

    return 0;
}