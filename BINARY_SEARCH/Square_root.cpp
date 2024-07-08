#include<iostream>
using namespace std;
int Find_Integer_Part (int n) {
    int start = 0;
    int end = n;
    long long int ans = 0;
    while (start <= end) {
        long long int mid = start + (end - start) / 2;
        long long int square = mid * mid;
        if (square == n) {
            return mid;
        }
        else if (square < n) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}
double Find_Precision (int n, int precision, int integer_ans) {
    double factor = 1;
    double ans = integer_ans;
    for (int i = 0; i < precision; i++) {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor) {
            ans = j;
        }
    }
    return ans;
}
int main() {
    int n = 17;
    int precision = 3;
    int integer_ans = Find_Integer_Part (n);
    double correct_ans = Find_Precision(n, precision, integer_ans);
    cout<<"The square root of "<<n<<" is : "<<correct_ans;
    return 0;
}
