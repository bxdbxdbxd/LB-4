#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    int len_arr = 15, sum_posit = 0, sum_negat = 0, qua_posit = 0, qua_negat = 0;
    int array_of_num[15], mx_num = -100, mn_num = 100, ind_mn, ind_mx;
    ranlux24 engine; // Инициализация генератора Ranlux24
    uniform_int_distribution<int> dist(-100, 100);

    for (int i = 0; i < len_arr; i++) {
        array_of_num[i] = dist(engine);
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
    cout << "\nArithmetic mean of positive  " << sum_posit / qua_posit << "\nArithmetic mean of negative  " << sum_negat / qua_negat << endl;
    sort(array_of_num, array_of_num + len_arr, greater<int>());

    for (int i = 0; i < len_arr; i++) {
        cout << array_of_num[i] << " ";
    }
    return 0;
}
