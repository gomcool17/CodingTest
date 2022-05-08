#include <bits/stdc++.h>

using namespace std;

#define SNAKE 100
#define APPLE 200
#define RIGHT 0
#define LEFT 2
#define UP 3
#define DOWN 1
#define INF 987654321

int N, K, L;
vector<pair<int, char>> v;
int re = INF;
int board[100][100];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

struct INFO
{
    int hy, hx, hdir;
    int ty, tx, tdir;
};

int sol()
{
    int re = 0;
    int chang_lo = 0;
    int tail_dir = 0;
    int tail_count = 1;

    INFO info = {0, 0, RIGHT, 0, 0, RIGHT};

    while (1)
    {
        //cout << "re : " << re << "\n";
        re++;
      /*  for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == SNAKE)
                    cout << "S ";
                else if (board[i][j] == APPLE)
                    cout << "A ";
                else
                    cout << "O ";
            }
            cout << "\n";
        }
        cout << "\n\n";*/


        if (info.hdir == RIGHT)
            info.hx++;
        else if (info.hdir == LEFT)
            info.hx--;
        else if (info.hdir == UP)
            info.hy--;
        else
            info.hy++;

        if (info.hx >= 0 && info.hy >= 0 && info.hx < N && info.hy < N)
        {
            if (board[info.hy][info.hx] == APPLE) //사과일때
            {
                board[info.hy][info.hx] = SNAKE;
            }
            else if (board[info.hy][info.hx] == SNAKE) //뱀일때(몸이랑 부딪)
                break;
            else //아무것도 아닐때(꼬리 짧아짐)
            {
                board[info.ty][info.tx] = 0;
                board[info.hy][info.hx] = SNAKE;
               // cout << "tail : " << info.ty << " " << info.tx << "\n";
              //  cout << "head : " << info.hy << " " << info.hx << "\n";
                if (info.tdir == RIGHT)
                    info.tx++;
                else if (info.tdir == LEFT)
                    info.tx--;
                else if (info.tdir == UP)
                    info.ty--;
                else
                    info.ty++;

                if (tail_count == v[tail_dir].first)
                {
                   // cout << "tail_  : " << tail_count << " " << v[tail_dir].first << "\n ";
                    if (v[tail_dir].second == 'D')
                        info.tdir = (info.tdir + 1) % 4;
                    else
                    {
                        info.tdir = (info.tdir + 4 - 1) % 4;
                    }
                   // cout << info.tdir << "\n";
                    tail_dir++;
                }

                tail_count++;
            }
        }
        else // 벽일때
        {
            break;
        }

        if (chang_lo < L)
        {
            if (re == v[chang_lo].first)
            {
               // cout << "chang lo  : " << chang_lo << " " << v[chang_lo].first << "\n ";
                if (v[chang_lo].second == 'D')
                {
                    info.hdir = (info.hdir + 1) % 4;
                   // cout << info.hdir << "\n";
                }
                else
                {
                    info.hdir = (info.hdir + 4 - 1) % 4;
                }

                chang_lo++;
            }
        }
    }

    return re;
}
int main()
{
    cin >> N >> K;

    for (int i = 0; i < K; i++)
    {
        int y, x;
        cin >> y >> x;
        board[y-1][x-1] = APPLE;
    }

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        int n;
        char c;
        cin >> n >> c;
        v.push_back({n, c});
    }

    board[0][0] = SNAKE;
    cout << sol();
}