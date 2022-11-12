#include <bits/stdc++.h>
using namespace std;

void prevGreater(int arr[], int size) {
    stack<int>s;

    s.push(arr[0]);
    cout << "- ";

    for (int i = 1; i < size; i++)
    {
        while (s.empty() == false && s.top() <= arr[i])
            s.pop();
        if (s.empty())
            cout << "- ";
        else
            cout << s.top() << " ";
        s.push(arr[i]);
    }
}

int main()
{
    int arr[] = {30, 50, 20, 15, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    prevGreater(arr, size);
    return 0;
}