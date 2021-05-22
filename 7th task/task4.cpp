#include <iostream>
#include <ctime>
#include <thread>
#include <random>
#include <algorithm>
#include <execution>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    vector<int> vec = { 1, 10, 2, 9, 3, 8 };
    vector<int>::iterator it;

    auto start = chrono::high_resolution_clock::now();
    sort(execution::par, vec.begin(), vec.end());
    auto end = chrono::high_resolution_clock::now();
    cout << "parallel: " << chrono::duration<float>(end - start).count() << endl;

    auto rng = default_random_engine{};
    shuffle(begin(vec), end(vec), rng);

    auto start = chrono::high_resolution_clock::now();
    sort(execution::seq, vec.begin(), vec.end());
    auto end = chrono::high_resolution_clock::now();
    cout << "straight: " << chrono::duration<float>(end - start).count() << endl;

    auto rng = default_random_engine{};
    shuffle(begin(vec), end(vec), rng);

    uto start = chrono::high_resolution_clock::now();
    it = count(execution::par, vec.begin(), vec.end(), 10);
    auto end = chrono::high_resolution_clock::now();
    cout << "parallel: " << chrono::duration<float>(end - start).count() << endl;

    auto start = chrono::high_resolution_clock::now();
    it = count(execution::seq, vec.begin(), vec.end(), 10);
    auto end = chrono::high_resolution_clock::now();
    cout << "straight: " << chrono::duration<float>(end - start).count() << endl;

    auto start = chrono::high_resolution_clock::now();
    it = find(execution::par, vec.begin(), vec.end(), 10);
    auto end = chrono::high_resolution_clock::now();
    cout << "parallel: " << chrono::duration<float>(end - start).count() << endl;

    auto start = chrono::high_resolution_clock::now();
    it = find(execution::seq, vec.begin(), vec.end(), 10);
    auto end = chrono::high_resolution_clock::now();
    cout << "straight: " << chrono::duration<float>(end - start).count() << endl;
    
    return 0;
}
