#include <iostream>
#include <climits>
using namespace std;
 
// Divide and conquer solution to find the minimum and maximum number in an array
void findMinAndMax(int arr[], int low, int high, int &min, int &max)
{
    // if the array contains only one element
 
    if (low == high)                    // common comparison
    {
        if (max < arr[low]) {           // comparison 1
            max = arr[low];
        }
 
        if (min > arr[high]) {          // comparison 2
            min = arr[high];
        }
 
        return;
    }
 
    // if the array contains only two elements
 
    if (high - low == 1)                // common comparison
    {
        if (arr[low] < arr[high])       // comparison 1
        {
            if (min > arr[low]) {       // comparison 2
                min = arr[low];
            }
 
            if (max < arr[high]) {      // comparison 3
                max = arr[high];
            }
        }
        else {
            if (min > arr[high]) {      // comparison 2
                min = arr[high];
            }
 
            if (max < arr[low]) {       // comparison 3
                max = arr[low];
            }
        }
        return;
    }
 
    // find the middle element
    int mid = (low + high) / 2;
 
    // recur for the left subarray
    findMinAndMax(arr, low, mid, min, max);
 
    // recur for the right subarray
    findMinAndMax(arr, mid + 1, high, min, max);
}
 
int main()
{
    int arr[] = { 7, 2, 9, 3, 1, 6, 7, 8, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // initialize the minimum element by `INFINITY` and the
    // maximum element by `-INFINITY`
    int max = INT_MIN, min = INT_MAX;
 
    findMinAndMax(arr, 0, n - 1, min, max);
 
    cout << "The minimum array element is " << min << endl;
    cout << "The maximum array element is " << max;
 
    return 0;
}
