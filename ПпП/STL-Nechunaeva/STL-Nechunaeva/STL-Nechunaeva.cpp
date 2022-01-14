/*
Задача:
Коэффициенты многочлена 𝑛-ой степени 𝑃 𝑥 = 𝑎(𝑛)*𝑥^𝑛 + 𝑎(𝑛−1)*𝑥^(𝑛−1) + ⋯ + 𝑎1𝑥 + 𝑎0 задаются парами (𝑖, 𝑎(𝑖)),
где 𝑖 – показатель степени для коэффициента 𝑎(𝑖). Даны два многочлена P(x) и Q(x) степеней m и n соответственно.
Найти коэффициенты многочлена, равного произведению многочленов P(x) и Q(x).

Предмет: ПпП
Автор: Нечунаева А.И.
Дата: 08.12.2021
Вариант: 11

*/


#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    // coefs before multiplying by powers of A
    vector<double> a = { 1,2,1 };

    // make polynomial coefs vector
    double A = 1;
    const int as = a.size();
    int ap = 1;
    for (int ai = 0; ai < as; ++ai) {
        a[ai] *= ap;
        ap *= A;
    }

    vector<double> b = { 1,3,3,1 };
    const int bs = b.size();

    // result vector
    vector<double> c(as + bs - 1, 0);

    // multiply vectors
    for (int ai = 0; ai < as; ++ai)
        for (int bi = 0; bi < bs; ++bi) {
            c[ai + bi] += a[ai] * b[bi];
        }

    for (int cn : c)
        cout << cn << ' ';
    return 0;
}


