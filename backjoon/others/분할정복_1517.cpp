//https://www.acmicpc.net/problem/1517
//분학정복
#include <iostream>
using namespace std;
#define ll long long

const ll MN = 5000001;
ll num[MN];
ll arr[MN];
ll N;

ll divid(int start, int end) {
    if(start == end) return 0;
    
    int mid = (start + end) / 2;
    ll answer = divid(start, mid) + divid(mid+1,end);
    int idx = 0;
    int i = start, j = mid+1;
    while(i <= mid || j <= end) {
        if(i <= mid && (j > end || num[i] <= num[j])) {
            arr[idx++] = num[i++];
        }
        else {
            answer += (mid - i + 1);
            arr[idx++] = num[j++];
        }
    }
    for(int i=start; i <= end; i++) num[i] = arr[i-start];
    return answer;
}
int main() {
    cin >> N;
    for(int i=0;i<N;i++) cin >> num[i];
    cout << divid(0,N-1);
}



/*
#include <iostream>

#include <vector>

using namespace std;

#define MAX_N 500001

int n;

vector<int> numbers;

int arr2[MAX_N];

long long navigate(int start, int end)
{

    if (start == end)
        return 0;

    int mid = (start + end) / 2;
   
    long long answer = navigate(start, mid) + navigate(mid + 1, end);
     cout << "1 : " << start << " " << end << " " << mid << "\n";
    int i = start, j = mid + 1;

    int idx = 0;

    while (i <= mid || j <= end)
    {
        cout << "2 : " << i << " " << j << " " << idx << "\n";
        if (i <= mid && ((j > end) || numbers[i] <= numbers[j]))
        {
            cout << "c\n";
            arr2[idx++] = numbers[i++];
        }
        else
        {
            cout << "d\n";
            answer += (mid - i + 1) * 1LL;
            arr2[idx++] = numbers[j++];
        }
        cout << "3 : ";
            for(int ii=0;ii<n;ii++) cout << arr2[ii] << " ";
            cout << "\n"; 
    }

    for (int i = start; i <= end; i++)
    {
        numbers[i] = arr2[i - start];
    }
    cout << "4 : ";
            for(int ii=0;ii<n;ii++) cout << numbers[ii] << " ";
            cout << "\n"; 
    return answer;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {

        int temp;
        cin >> temp;

        numbers.push_back(temp);
    }

    long long answer = navigate(0, n - 1);

    cout << answer;

    return 0;
} 

*/