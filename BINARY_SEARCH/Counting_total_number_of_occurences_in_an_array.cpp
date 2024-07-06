#include<iostream>
using namespace std;
int Find_First_Occurence (int arr[], int start, int end, int target) {
    int result = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
            end = mid - 1;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return result;
}
int Find_Last_Occurence (int arr[], int start, int end, int target) {
    int result = 0;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            result = mid;
            start = mid + 1;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return result;
}
int main() {
    int arr[] = {1, 2, 3, 3, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    int first_occurence = Find_First_Occurence(arr, 0, size - 1, target);
    int last_occurence = Find_Last_Occurence(arr, 0, size - 1, 3);
    cout<<"Total number of times number "<<target<<" has appeared is : " <<last_occurence - first_occurence + 1<<endl;
    return 0;
}
