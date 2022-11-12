// Binary Search implimentation in C++ (Recursive)
// Time Complexity : O(N)
// Space Complexity : O(1)
// Auxiliary Space Complexity : O(N) due to function call stack
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int array[], int left, int right, int item){
    
    if (right >= left){
        
        // calculation of new mid
        int mid = left + (right - left)/2;

        // returns position where found
        if (array[mid] == item)
            return mid+1;
        
        // goes to recursive calls in left half
        if (array[mid] > item)
            return binarySearch(array, left, mid-1, item);
    
        // goes to recursive calls in right half
        else
            return binarySearch(array, mid+1, right, item);
    }
    // if element is not found we return -1
    else
       return -1;
}
int main(){
 
    int array[10] = {3, 5, 7, 9, 12, 15, 16, 18, 19, 22};
    int item = 15;
   
    int position = binarySearch(array, 0, 10, item);

    if(position == -1)
        cout<<"Not Found";
    else
        cout<<"We found the item "<< item <<" at position "<< position;
}