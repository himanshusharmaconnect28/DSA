#include<iostream>
using namespace std;
int Possible_Solution (int book_array[], int student_number, int book_number, int mid) {
    int student_count = 1;
    int page_sum = 0;
    for (int i = 0; i < book_number; i++) {
        if (page_sum + book_array[i] <= mid) {
            page_sum += book_array[i];
        }
        else {
            student_count++;
            if (student_count > student_number || book_array[i] > mid) {
                return 0;
            }
            page_sum = book_array[i];
        }
    }
    return 1;
}
int allocate_books (int book_array[], int student_number, int book_number) {
    int sum = 0;
    for (int i = 0; i < book_number; i++) {
        sum = sum + book_array[i];
    }
    int start = 0;
    int end = sum;
    int ans = -1;
    while (start <= end) {
        int mid =  start + (end - start) / 2;
        if (Possible_Solution(book_array, student_number, book_number, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return ans;
}
int main() {
    int book_array[] = {12, 34, 67, 90};
    int book_number = sizeof(book_array) / sizeof(book_array[0]);
    int student_number = 2;
    cout<<"Minimum number of pages that can be allocated are : "<<allocate_books(book_array, student_number, book_number)<<endl;
    return 0;
}
