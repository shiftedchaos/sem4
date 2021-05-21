#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>

static inline double computeSquare (double x) { return x*x; }

bool isNegative (int i) {return i < 0;}

bool eratosthenesSieve(int currentNumber)
{
    /*
    Describe the function that checks if the number is prime and returns a boolean value.
    This function is based on the "sieve of Eratosthenes" algorithm.
    True - if the number is prime, false - normal.
    */

    // If the number equals to 1 or if it even, return false. And if it equals to 2, return true.
    if (currentNumber == 2 or currentNumber == 3) {
        return true;
    } else if (!(currentNumber % 2) or !(currentNumber % 3) or currentNumber == 1) {
        return false;
    }

    // If the number has the divider from 5 to the root of this number with the second step return false.
    for (int divider = 5; divider <= sqrt(currentNumber); divider += 2) {
        if (!(currentNumber % divider)) {
            return false;
        }
    }

    // In all other situations, return true.
    return true;
}

bool isOdd (int elem)
{
  return elem % 2 == 1;
}

//Task 1

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

  //Task 2

  int num;
  num = count_if(coll.begin(), coll.end(), isOdd);
  std::cout << "Amount of odd elements in coll: " << num << std::endl;

  std::cout << "Minimum: " << *min_element(coll.begin(), coll.end()) <<
  std::endl;
  std::cout << "Maximum: " << *max_element(coll.begin(), coll.end()) <<
  std::endl;

  std::vector<int>::iterator pos;
  pos = find_if(coll.begin(), coll.end(), eratosthenesSieve);
  std::cout << "Just one prime number from coll: " << std::distance(coll.begin(), pos) + 1 << std::endl;

  transform(coll.begin(), coll.end(), coll.begin(), computeSquare);

  std::cout << std::endl;
  for (auto elem: coll)
  {
    std::cout << elem << ' ';
  }
  std::cout << std::endl;

  //Task 3
  int size;
  size = coll.size();
  std::cout << "SIZE: " << size << std::endl;

  std::vector<int> coll2(size);

  std::default_random_engine gen;

  std::uniform_int_distribution<int> dist(-200, 200);
  for (int i = 0; i < size; i++)
  {
        coll2.push_back(dist(gen));
  }
  for( int i = 0; i < size; i++ ) {
      std::cout << coll2[i] << " ";
    }

  std::cout << std::endl;

  int sum_of_elems = 0;
  std::cout << "Sum of elem" << accumulate(coll2.begin(), coll2.end(), 0) <<
  '\n';

  for (size_t i = 0; i < 5; i++)
  {
    coll2[i] = 1;
  }

  std::vector<int> coll3(size);

  std::transform(coll.begin(), coll.end(), coll2.begin(), coll2.end())

/*
  for (size_t i = 0; i < coll3.size(); i++)
  {                                                //use transform here
    coll3[i] = coll2[i] - coll[i];
  }
/*
  for(auto x: coll3)
  {
    std::cout << x << ' ';
  }
*/

  replace_if(coll3.begin(), coll3.end(), isNegative, 0);


  std::vector<int>::iterator index = remove(coll3.begin(), coll3.end(), int(0));
  coll3.erase(coll3.begin() + distance(coll3.begin(), index), coll3.end());
  reverse (coll3.begin(),coll3.end());

  std::cout << "Coll3: ";
  for (auto const &element: coll3)
        std::cout << element << ' ';

  cout << endl << "Top 3:  ";
  nth_element(coll3.begin(),coll3.end()-3, coll3.end());
  copy(coll3.end()-3, coll3.end(), ostream_iterator<int>(cout," "));


  return 0;
}
