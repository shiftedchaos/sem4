#include <iostream>
#include <Windows.h>
#include <thread>
#include <vector>
#include <algorithm>
#include <future>
#include <iostream>
#include <numeric>
#include <stdlib.h>
#include <math.h>
#include <chrono>
using namespace std;
using namespace chrono;

template<typename Iterator, typename T>
struct accumulate_block
{
	void operator()(Iterator first, Iterator last, T& result)
	{
		result = std::accumulate(first, last, result);
	}
};


template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init, unsigned long const num_threads)
{
	unsigned long const length = std::distance(first, last);
	if (!length)
		return init;
	unsigned long const block_size = length / num_threads;
	std::vector<T> results(num_threads);
	std::vector<std::thread> threads(num_threads - 1);
	Iterator block_start = first;
	for (unsigned long i = 0; i < (num_threads - 1); ++i)
	{
		Iterator block_end = block_start;
		std::advance(block_end, block_size);
		threads[i] = std::thread(accumulate_block<Iterator, T>(), block_start, block_end, std::ref(results[i]));
		block_start = block_end;
	}

	accumulate_block<Iterator, T>() (block_start, last, results[num_threads - 1]);

	std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
	return
		std::accumulate(results.begin(), results.end(), init);
};

int main(void)
{
	vector < int > v(100);
	iota(v.begin(), v.end(), 1);
	float x;
	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
	SelectObject(hDC, Pen);
	MoveToEx(hDC, 10, 0, NULL);
	LineTo(hDC, 10, 260);
	MoveToEx(hDC, 0, 250, NULL);
	LineTo(hDC, 200, 250);
	auto s = high_resolution_clock::now();
	parallel_accumulate(v.begin(), v.end(), 0, 1);
	auto e = high_resolution_clock::now();
	auto oldtime = std::chrono::duration_cast<std::chrono::microseconds>(e - s);
	for (unsigned long i = 2; i < 15; i++)
	{
		auto start = high_resolution_clock::now();
		parallel_accumulate(v.begin(), v.end(), 0, i);
		auto end = high_resolution_clock::now();
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		MoveToEx(hDC, 10 * (i - 1) + 10, -0.2 * oldtime.count() + 250, NULL);
		LineTo(hDC, 10 * i + 10, -0.2 * elapsed_ns.count() + 250);
		oldtime = elapsed_ns;
	}
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
	return 0;
}
