#include <iostream>

using namespace std;

int main() {
    int len_arr, elem_val = 1000;
    cout << "Enter n - ";
    cin >> len_arr;
    if (len_arr > 0) {
        int array_num[len_arr*5];
        array_num[0] = elem_val;
        for (int i = 1; i < len_arr*5; i++) {
            elem_val += 100 + i;
            array_num[i] = elem_val;
        }
        for (int i = 0; i < len_arr; i++) {
            for (int j = 0; j < 5/2; j++) {
                swap(array_num[j + 5*i], array_num[5 - j - 1 + 5*i]);
            }
        }
        int che = 0;
        for (int i = 0; i < len_arr; i++) {
            for (int j = 0; j < 5; j++) {
                cout << array_num[che] << " ";
                che++;
            }
            cout << endl;
        }
    }
    else {
        cout << "\nError\n";
    }
    return 0;
}