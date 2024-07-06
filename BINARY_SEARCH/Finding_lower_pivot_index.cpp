#include<iostream>
using namespace std;
int Find_Pivot_Index(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] > arr[mid + 1]) {
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return start;
}
int main() {
    int arr[] = {8, 10, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int pivot_index = Find_Pivot_Index(arr, size);
    cout << "The pivot element is at index: " << pivot_index << endl;
    cout << "The pivot element is: " << arr[pivot_index] << endl;
    return 0;
}
