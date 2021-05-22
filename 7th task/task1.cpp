#include <iostream>
#include <ctime>
#include <chrono>
#include <numeric>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <iomanip>
#include <thread>
using namespace std;
using namespace chrono;

static int rrand(int rmin, int rmax)
{
    return rand() % (rmax - rmin + 1) + rmin;
}

void Pi_search(unsigned n, unsigned  side, unsigned qside, unsigned   &cnt)
{
    for (int i = 0; i < n; ++i)
    {
    unsigned x = rrand(0, side);
    unsigned y = rrand(0, side);
    if ((x * x + y * y) < qside) ++cnt;
    }

}

int main()
{
    auto start = high_resolution_clock::now();
    srand((unsigned)time(0));
    unsigned x = 300000;
    unsigned cnt = 0;
    unsigned side = 1000;
    unsigned qside = side * side;
    unsigned n = unsigned int(x / 4);
    vector<unsigned int> cnti{ 0, 0, 0, 0 };
    std::vector<std::thread> threads;
    for (unsigned i = 0; i <4; ++i)
    {
    threads.push_back(std::thread(Pi_search, n, side, qside, ref(cnti[i])));
    }
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    cnt = std::accumulate(cnti.begin(), cnti.end(), 0);
    std::cout << double(cnt * 4) / x << "\n";
    auto end = high_resolution_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "time is " << elapsed_ns.count() << " mcs\n";
    return 0;
}
