#include <iostream>
#include <vector>

using namespace std;

int C, P;
vector<int> field;
int result = 0;

int count_row(int n)
{
    int re = 0;

    for (int i = 0; i < field.size() - 1; i++)
    {
        int cnt = 1;

        for (int j = i; j < field.size() - 1; j++)
        {
            if (field[j] == field[j + 1])
            {
                cnt++;
            }
            else
            {
                if (cnt >= n)
                {
                    re += cnt - n + 1;
                }
                i = j;
                break;
            }
        }
    }
    
    return re;
}

int zero_one()
{
    int cnt = 0;
    for (int i = 0; i < field.size() - 2; i++)
    {
        if (field[i] + 1 == field[i + 1])
            cnt++;
    }

    return cnt;
}

int one_zero()
{
    int cnt = 0;
    for (int i = 0; i < field.size() - 2; i++)
    {
        if (field[i] == field[i + 1] + 1)
            cnt++;
    }

    return cnt;
}

void shape1()
{
    result = C;
    result += count_row(4);
    return;
}

void shape2()
{
    result += count_row(2);
    return;
}

void shape3()
{
    int cnt = 0;
    for (int i = 0; i < field.size() - 3; i++)
    {
        if (field[i] == field[i + 1] && field[i + 1] + 1 == field[i + 2])
            cnt++;
    }

    result = cnt + one_zero();
    return;
}

void shape4()
{
    int cnt = 0;
    for (int i = 0; i < field.size() - 3; i++)
    {
        if (field[i] == field[i + 1] + 1  && field[i + 1] == field[i + 2]){
            cnt++;
        }
    }

    result = cnt + zero_one();
    return;
}

void shape5()
{
    result += zero_one() + one_zero() + count_row(3);
   
    int cnt = 0;

    for (int i = 0; i < field.size() - 3; i++)
    {
        if (field[i] - 1 == field[i + 1] && field[i + 1] == field[i + 2] - 1)
            cnt++;
    }
    result += cnt;
    return;
}

void shape6()
{
    result += count_row(3) + count_row(2);

    int cnt = 0;
    for (int i = 0; i < field.size() - 3;i++)
    {
        if(field[i] + 1 == field[i+1] && field[i+1] == field[i+2])
            cnt++;
    }

    for (int i = 0; i < field.size() - 2;i++)
    {
        if(field[i] == field[i+1] + 2)
            cnt++;
    }

    result += cnt;
    return;
}

void shape7()
{
    result += count_row(3) + count_row(2);

    int cnt = 0;
    for (int i = 0; i < field.size() - 3; i++)
    {
        if (field[i] == field[i + 1] && field[i + 1] == field[i + 2] + 1)
            cnt++;
    }

    for (int i = 0; i < field.size() - 2; i++)
    {
        if (field[i] + 2 == field[i + 1])
            cnt++;
    }

    result += cnt;
    return;
}

void solution()
{
    if (P == 1)
        shape1();
    else if (P == 2)
        shape2();
    else if (P == 3)
        shape3();
    else if (P == 4)
        shape4();
    else if (P == 5)
        shape5();
    else if (P == 6)
        shape6();
    else
        shape7();
}

int main()
{
    cin >> C >> P;
    for (int i = 0; i < C; i++)
    {
        int n;
        cin >> n;
        field.push_back(n);
    }
    field.push_back(-1);
    solution();
    cout << result << "\n";
}