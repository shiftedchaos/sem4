#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main()
{
    default_random_engine gen; //генератор случайных чисел
    //равномерное распределение от 0 до 10.0
    uniform_real_distribution<double> dist(0.0,10.0);
    cout << "TASK 1\n";
    vector<double> v1;
    for (size_t i = 0; i < 30; i++)
    {
      v1.push_back(dist(gen));
      cout << "size: " << v1.size() << " , capacity: " << v1.capacity() << endl;
    }

    //1. Определим, как меняется емкость вектора при добавлении элементов

    //TODO: в цикле от 0 до N (N пусть, к примеру, равно 30 или какому-нибудь другому числу)
    //TODO: добавляем случайное число в вектор
    /*TODO: смотрим размер вектора (функция size) и емкость (функция capacity)
            определяем, в какие моменты вектор увеличивает емкость и во вколько раз */
    cout << "TASK 2\n";
    vector<int> v2;
    v2.reserve(7);
    for (size_t i = 0; i < 30; i++)
    {
      v2.push_back(dist(gen));
      cout << "size: " << v2.size() << " , capacity: " << v2.capacity() << endl;
    }

    /*2. Определим, как меняется емкость вектора при добавлении элементов, если установлена
         начальная емкость */

    // TODO: задаем начальную емкость вектора (функция reserve)
    /* TODO: в цикле добавляем элементы так же, как и в предыдущем пункте,
             определяем, как меняется емкость */

    return 0;
}
