#include <iostream>

using namespace std;

int N;
int re = 0;

void rotate(int n, int arr[][20])
{
    int tmp[20][20];

    while (n--)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                tmp[i][j] = arr[N - 1 - j][i];
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                arr[i][j] = tmp[i][j];
            }
        }
    }
}

void copy_array(int arr[][20], int copy[][20])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            copy[i][j] = arr[i][j];

    return;
}

void match_array(int arr[][20])
{
    for (int j = 0; j < N; j++) // X
    {
        for (int i = 0; i < N; i++) // Y
        {
            if (arr[i][j] == 0)
                continue;
            else
            {
                int n = arr[i][j];
                for (int k = i + 1; k < N; k++)
                {
                    if (arr[k][j] == 0)
                        continue;
                    if (arr[k][j] == n)
                    {
                        arr[i][j] *= 2;
                        arr[k][j] = 0;
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i][j] == 0)
            {
                for (int k = i; k < N; k++)
                {
                    if (arr[k][j] != 0)
                    {
                        arr[i][j] = arr[k][j];
                        arr[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }

    return;
}

void sol(int cnt, int arr[][20])
{
    if (cnt >= 5)
    {
        int m = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                m = max(m, arr[i][j]);
            }
        }

        
        re = max(re, m);
       
        return;
    }

    int copy[20][20];
    copy_array(arr, copy);
    match_array(copy);
    sol(cnt + 1, copy);
    copy_array(arr, copy);

    //왼쪽

    rotate(1, copy); // 90도 회전
    match_array(copy);
    rotate(3, copy); // 원래 틀로 돌아가기
    sol(cnt + 1, copy);
    copy_array(arr, copy);

    //아래
    rotate(2, copy); // 90도 회전
    match_array(copy);
    rotate(2, copy); // 원래 틀로 돌아가기
    sol(cnt + 1, copy);
    copy_array(arr, copy);

    //오른쪽
    rotate(3, copy); // 90도 회전
    match_array(copy);
    rotate(1, copy); // 원래 틀로 돌아가기
    sol(cnt + 1, copy);
    copy_array(arr, copy);
}

int main()
{
    cin >> N;
    int arr[20][20];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    sol(0, arr);

    cout << re << "\n";
}