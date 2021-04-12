#include <iostream>
#include <ctime>
#include <set>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std::chrono;

int main()
{

  srand(time(NULL));
  std::vector<int> v;

  std::set <int> st;

  std::cout << "adding random numbers: " << std::endl;
  auto start = high_resolution_clock::now();
    for (int i = 0; i < 10; i++)
    {
        int random = rand() % 10 + 1;
        st.insert(random);
        v.push_back(random);
        std::cout << i + 1 << ") " << random << std::endl;
    }
    auto stop = high_resolution_clock::now();

    for (std::set <int>::iterator it = st.begin(); it != st.end(); it++) {
      std::cout << *it << ' ';
    }

    duration<double> diff = stop - start;
    std::cout << "Duration time for set: " << diff.count() << std::endl;

    std::sort(v.begin(), v.end());

    for (auto elem:v)
    {
      std::cout << elem << ' ';
    }

    auto stop_1 = high_resolution_clock::now();

    duration<double> diff_1 = stop_1 - start;
    std::cout << "Duration time for vector: " << diff_1.count();


  return 0;
}
