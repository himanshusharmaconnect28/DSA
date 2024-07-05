#include<iostream>
using namespace std;
int main() {
    int x = 5;
    int y = 3;
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    cout<<"After swapping, x = "<<x<<", y = "<<y<<endl;
    return 0;
}
