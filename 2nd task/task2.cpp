#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include <deque>
#include <list>
#include <array>
#include <iterator>
#include <algorithm>

using namespace std;
using namespace chrono;

// шаблон функции для измерения времени сортировки контейнера
template<typename T>
auto measureSortingTime(T container)
{
    auto start = high_resolution_clock::now();
    //TODO: отсортировать контейнер (чтобы работало для vector, array и deque)
    sort(container.begin(), container.end());
    //TODO: вычислить время сортировки и вернуть
    auto stop = high_resolution_clock::now();
    duration<double> diff = stop - start;
    return diff.count();
}

// специализация шаблона для list
template<>
auto measureSortingTime(list<int> container)
{
    auto start = high_resolution_clock::now();
    //TODO: отсортировать list
    container.sort();
    //TODO: вычислить время сортивки и вернуть
    auto stop = high_resolution_clock::now();
    duration<double> diff = stop - start;
    return diff.count();
}


int main()
{
    default_random_engine generator; //генератор случайных чисел
    uniform_int_distribution<int> distribution(0,10000); //равномерное распределение от 0 до 1000
    auto gen = [&distribution, &generator](){
                   return distribution(generator); // лямбда-функция, которая генерирует случайное число
               };

    //можно поэспериментировать с разными размерами контейнеров
    vector<int> v(100000);
    // заполнение вектора случайными числами
    generate(v.begin(), v.end(), gen);
    array<int, 100000> a;
    deque<int> d(100000);
    list<int> l(100000);
    // нам нужно, чтобы все контейнеры были запонены одинаковыми даннными
    // поэтому скопируем данные из вектора в другие контейнеры
    copy (v.begin(), v.end(), a.begin()); //копирование элементов вектора v в массив a
    copy (v.begin(), v.end(), d.begin());
    copy (v.begin(), v.end(), l.begin());
    //sort(v.begin(), v.end()); // сортировка у vector, array и deque
    //l.sort() // сортировка у list

    /* TODO: выполнить функцию measureSortingTime для vector, array и deque
             и определить, какой из контейнеров сортируется быстрее */

    cout << "measureSortingTime для vector: " <<
    measureSortingTime<vector<int>>(v) << '\n';
    cout << "measureSortingTime для array: " <<
    measureSortingTime<array<int, 100000>>(a) << '\n';
    cout << "measureSortingTime для deque: " <<
    measureSortingTime(d) << '\n';
    cout << "measureSortingTime для list: " <<
    measureSortingTime(l) << '\n';

    return 0;
}
