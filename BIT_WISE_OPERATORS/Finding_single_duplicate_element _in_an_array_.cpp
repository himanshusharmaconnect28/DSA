#include<iostream>
using namespace std;
int find_duplicate(int arr[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= arr[i];
    }
    for (int i = 1; i < n; i++) {
        result ^= i;
    }
    return result;
}
int main() {
    int arr[] = {1, 3, 4, 2, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int duplicate = find_duplicate(arr, n);
    cout<< "The duplicate element is "<< duplicate << endl;
    return 0;
}
