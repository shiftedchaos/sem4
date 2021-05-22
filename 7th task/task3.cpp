#include <iostream>
#include <thread>
#include <string>
#include <future>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;

void myfunction (int i) {  // function:
	std::cout << ' ' << i;
}

template<typename Iterator, typename Func>
void parallelny_for_each(Iterator first, Iterator last, Func f)
{
     unsigned long const length = std::distance(first, last);

     if (!length)
    	 return;

     unsigned long const perthread = 30;
     if (length < (2 * perthread)) {
    	 for_each(first, last, f);
     } else {
    	 Iterator const midle = first + length / 2;
    	 std::future<void> first_half =
    	 std::async(&parallelny_for_each<Iterator, Func>,
    	 first, midle, f);
    	 parallelny_for_each(midle, last, f);
    	 first_half.get();
     }
}

int main(int argc, char **argv)
{
	  std::vector<int> myvector;
	  myvector.push_back(10);
	  myvector.push_back(20);
	  myvector.push_back(30);

	  std::cout << "myvector contains:";
	  parallelny_for_each (myvector.begin(), myvector.end(), myfunction);
	  std::cout << '\n';
}
