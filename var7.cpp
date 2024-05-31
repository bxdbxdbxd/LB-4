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

void fillArray(vector<int>& array, int size);
double chiSquareTest(const vector<int>& array, int numBins);


int main() {
    setlocale(LC_ALL, "rus");
    const int sizes[] = {50, 100, 1000};
    const int numBins = 10;

    for (int size : sizes) {
        vector<int> array(size);
        fillArray(array, size);
        double chiSquare = chiSquareTest(array, numBins);

        double criticalValue = 16.92;
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

// Расчет критерия хи-квадрат для проверки нормальности распределения
double chiSquareTest(const vector<int>& array, int numBins) {
    vector<int> expected(numBins, 0);
    vector<int> observed(numBins, 0);
    for (int i = 0; i < numBins; i++) {
        expected[i] = array.size() / numBins;
    }
    for (int e : array) {
        int bin = (e - 1) / (100 / numBins);
        observed[bin]++;
    }
    double chiSquare = 0.0;
    for (int i = 0; i < numBins; i++) {
        chiSquare += pow((observed[i] - expected[i]), 2) / expected[i];
    }

    return chiSquare;
}

void fillArray(vector<int>& array, int size) {
    Ranlux24 rng(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = (rng() % 100) + 1;
    }
}