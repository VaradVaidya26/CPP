// Binary Search implimentation in C++ (Iterative)
// Time Complexity : O(N)
// Space Complexity : O(1)
#include<bits/stdc++.h>
using namespace std;

// Returns index of item in given array, if it is present
// otherwise returns -1
int binarySearch(int arr[], int l, int r, int item)
{
    while (l <= r) {
        int mid = l + (r - l) / 2;
  
        // if item is at mid
        if (arr[mid] == item)
            return mid;
  
        // If item greater, ignore left half, consider only right half
        if (arr[mid] < item)
            l = mid + 1;
  
        // If item is smaller, ignore right half, consider only left half
        else
            r = mid - 1;
    }
  
    // if we are able to reach here
    // means item wasn't present
    return -1;
}
  
int main()
{
    // array needs to be sorted to impliment binary search
    int arr[] = {3, 5, 7, 9, 12, 15, 16, 18, 19, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    int item = 7;
    
    int position = binarySearch(arr, 0, n - 1, item);
    
    if(position == -1)
        cout << item << " Not Found";
    else
        cout << item << " Found at index " << position;
        
    return 0;
}