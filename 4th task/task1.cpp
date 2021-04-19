#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int amount;

  std::vector<int> coll = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << "Input amount of elements that you wand to add to your coll." << std::endl;
  std::cin >> amount;
  for (size_t i = 0; i < amount; i++)
  {
    int a;

    std::cin >> a;
    coll.push_back(a);
  }

  random_shuffle (coll.begin(), coll.end());
  for (auto elem: coll)
  {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  coll.erase( unique( coll.begin(), coll.end() ), coll.end() );

  for (auto elem: coll)
  {
    std::cout << elem << ' ';
  }
}
