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
        else {
            end = mid;
        }
    }
    return start;
}
int Binary_Search(int arr[], int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;    
}
int Find_Position(int arr[], int start, int end, int key, int size) {
    int pivot = Find_Pivot_Index(arr, size);
    if (key >= arr[pivot] && key <= arr[end]) {
        return Binary_Search(arr, pivot, end, key);
    }
    else {
        return Binary_Search(arr, start, pivot - 1, key);
        }
}
int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 1;
    int size = sizeof(arr) / sizeof(arr[0]);
    int position = Find_Position(arr, 0, size - 1, target, size);
    cout<<"The number "<<target<<" is at index : "<<position<<endl;
    return 0;
}
