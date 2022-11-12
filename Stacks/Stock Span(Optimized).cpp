#include <bits/stdc++.h>
using namespace std;

void stockSpan(int arr[], int size) {

    stack<int> s;
    s.push(0);
    cout << 1 << " ";

    for (int i = 1; i < size; i++)
    {
        while (s.empty() == false && arr[s.top()] <= arr[i])
        {
            s.pop();
        }
        int span = s.empty() ? i + 1 : i - s.top();
        cout << span << " ";
        s.push(i);
    }
}

int main()
{
    int arr[] = {100, 20, 30, 60, 38, 36, 32, 55, 80, 50, 120};
    int size = sizeof(arr) / sizeof(arr[0]);
    stockSpan(arr, size);
    return 0;
}