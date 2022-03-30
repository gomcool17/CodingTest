#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct info
{
    int x, y, blankCnt = 0, friendCnt = 0;
    bool operator<(const info &i) const
    {
        if (friendCnt == i.friendCnt)
        {
            if (blankCnt == i.blankCnt)
            {
                if (x == i.x)
                    return y > i.y;
                else
                    return x > i.x;
            }
            else
                return blankCnt < i.blankCnt;
        }
        else
            return friendCnt < i.friendCnt;
    }
};

struct student
{
    int id;
    int love[4];
    int x, y;
};

int manjok[] = {0, 1, 10, 100, 1000};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    cout << (-1  % 4) << "\n";
}