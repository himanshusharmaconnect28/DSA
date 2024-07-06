#include<iostream>
using namespace std;
int Find_Peak_Index(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while(start < end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] < arr[mid + 1]) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return start;
}
int main() {
    int arr[] = {0, 2, 5, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int peak_index = Find_Peak_Index(arr, size);
    cout<<"The peak element is : "<<arr[peak_index]<<endl;
    return 0;
}
