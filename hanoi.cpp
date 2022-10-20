#include <iostream>
#include <iomanip>
#include <stack>
#include <cmath>

using namespace std;
bool stp;
int plt, mov, i, proc;
stack<int> abc[3]; // 0=A,1=B,2=C
stack<int> t;

void stack_out()
{
    if (proc <= mov)
    {
        proc++;
        for (int i = 0; i < 3; i++)
        {
            int o = 0;
            cout << "Tower" << (char)('1' + i) << ":";
            while (!abc[i].empty())
            {
                t.push(abc[i].top());
                abc[i].pop();
            }
            while (!t.empty()) // temp save and reverse output
            {
                if (o == 0)
                {
                    cout << t.top();
                    o++;
                }
                else
                {
                    cout << " " << t.top();
                }
                abc[i].push(t.top());
                t.pop();
            }
            cout << "\n";
        }
        if (proc != mov + 1)
        {
            cout << "\n";
        }
    }
    else
    {
        stp = false;
    }
}

void HanoiTower(int no, char src, char des, char tmp, bool ok)
{
    ok = stp;

    if (no != 0 && ok)
    {
        HanoiTower(no - 1, src, tmp, des, ok);

        abc[des - '1'].push(abc[src - '1'].top());
        abc[src - '1'].pop();
        stack_out();

        HanoiTower(no - 1, tmp, des, src, ok);
    }
}

int main()
{
    cin >> plt &&plt != 0;
    mov = (int)pow(2, plt) - 1;
    proc = 0;
    stp = 1;
    for (i = 0; i < 3; i++)
    {
        while (!abc[i].empty())
        {
            abc[i].pop();
        }
    }

    for (i = plt; i > 0; i--)
    {
        abc[0].push(i);
    }

    stack_out();
    HanoiTower(plt, '1', '3', '2', stp);
}