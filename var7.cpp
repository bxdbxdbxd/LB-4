#include <iostream>
#include <vector>
#include <time.h> 
#include <cmath>

using namespace std;

// Генератор случайных чисел ranlux24
class Ranlux24 {
public:
    Ranlux24(unsigned int seed) : seed(seed) {}

    unsigned int operator()() {
        seed = (16807 * seed + 0) % (1 << 24);
        return seed;
    }

private:
    unsigned int seed;
};

// Заполнение массива случайными числами от 1 до 100
void fillArray(vector<int>& array, int size) {
    Ranlux24 rng(time(0)); // Инициализация генератора случайных чисел с текущим временем в качестве начального значения

    for (int i = 0; i < size; i++) {
        array[i] = (rng() % 100) + 1; // Генерация случайного числа от 1 до 100
    }
}

// Расчет критерия хи-квадрат для проверки нормальности распределения
double chiSquareTest(const vector<int>& array, int numBins) {
    // Количество элементов в каждом интервале
    vector<int> expected(numBins, 0);
    vector<int> observed(numBins, 0);

    // Равномерное распределение значений в интервалах
    for (int i = 0; i < numBins; i++) {
        expected[i] = array.size() / numBins;
    }

    // Подсчет количества элементов в каждом интервале
    for (int e : array) {
        int bin = (e - 1) / (100 / numBins);
        observed[bin]++;
    }

    // Расчет критерия хи-квадрат
    double chiSquare = 0.0;
    for (int i = 0; i < numBins; i++) {
        chiSquare += pow((observed[i] - expected[i]), 2) / expected[i];
    }

    return chiSquare;
}

int main() {
    setlocale(LC_ALL, "rus");
    // Размеры массивов
    const int sizes[] = {50, 100, 1000};

    // Количество интервалов для критерия хи-квадрат
    const int numBins = 10;

    for (int size : sizes) {
        // Заполнение массива случайными числами
        vector<int> array(size);
        fillArray(array, size);

        // Расчет критерия хи-квадрат
        double chiSquare = chiSquareTest(array, numBins);

        // Определение значимости критерия хи-квадрат
        double criticalValue = 16.92; // Критическое значение хи-квадрат для 9 степеней свободы и уровня значимости 0,05
        wcout << L"Критерий хи-квадрат для массива размером " << size << ": " << chiSquare << endl;
        if (chiSquare < criticalValue) {
            wcout << L"Гипотеза о нормальном распределении не отвергается." << endl;
        } else {
            wcout << L"Гипотеза о нормальном распределении отвергается." << endl;
        }
        cout << endl;
    }

    return 0;
}
