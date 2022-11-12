// Time Complexity is : O(n^2)
// Space Complexity is : O(1)
#include <bits/stdc++.h>
using namespace std;

void stockSpan(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        int curr_span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
            curr_span++;
        cout << curr_span << " ";
    }
}

int main()
{
    int arr[] = {12, 14, 15, 7, 15, 17, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    stockSpan(arr, size);
    return 0;
}