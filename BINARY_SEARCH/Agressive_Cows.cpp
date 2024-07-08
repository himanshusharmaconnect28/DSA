#include<iostream>
using namespace std;
void Bubble_Sort (int barn_array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (barn_array[j] > barn_array[j + 1]) {
                int temp = barn_array[j];
                barn_array[j] = barn_array[j + 1];
                barn_array[j + 1] = temp;
            }
        }
    }
}
int Is_Possible(int barn_array[], int cow_number, int mid, int size) {
    int cow_count = 1;
    int last_possition = barn_array[0];
    for (int i = 0; i < size; i++) {
        if (barn_array[i] - last_possition >= mid) {
            cow_count++;
            if (cow_count == cow_number) {
                return 1;
            }
            last_possition = barn_array[i];
        }
    }
    return 0;
}
int Aggressive_Cows (int barn_array[], int cow_number, int size) {
    Bubble_Sort(barn_array, size);
    int start = 0; 
    int end = barn_array[size - 1];
    int ans = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (Is_Possible(barn_array, cow_number, mid, size)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}    
int main() {
    int barn_array[] = {2, 9, 4, 1, 8};
    int cow_number = 3;
    int size = sizeof(barn_array) / sizeof(barn_array[0]);
    int result = Aggressive_Cows (barn_array, cow_number, size);
    cout<<"Maximum minimum distance that should be mantained is : "<<result<<endl;
    return 0;
}
