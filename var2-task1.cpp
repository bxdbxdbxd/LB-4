#include <iostream>

using namespace std;

int main() {
    int len_arr = 15, sum_posit = 0, sum_negat = 0, qua_posit = 0, qua_negat = 0;
    int array_of_num[15], mx_num = -100, mn_num = 100, ind_mn, ind_mx;
    for (int i = 0; i < len_arr; i++) {
        array_of_num[i] = rand() % (100 + 100 + 1) - 100;
        if (array_of_num[i] < 0) {
            sum_negat += array_of_num[i];
            qua_negat += 1;
            if (mn_num > array_of_num[i]) {
                mn_num = array_of_num[i];
                ind_mn = i;
            }
        }
        if (array_of_num[i] > 0) {
            sum_posit += array_of_num[i];
            qua_posit += 1;
            if (mx_num < array_of_num[i]) {
                mx_num = array_of_num[i];
                ind_mx = i;
            }
        }
    }
    for (int i = 0; i < len_arr; i++) {
        cout << array_of_num[i] << " ";
    }
    swap(array_of_num[ind_mx], array_of_num[ind_mn]);
    cout << "\n";
    for (int i = 0; i < len_arr; i++) {
        cout << array_of_num[i] << " ";
    }
    cout << "\n" << sum_posit / qua_posit << "+" << sum_negat / qua_negat << "-";
    return 0;
}