#include <iostream>
#include <array>
#include <stack>
#include <algorithm>

int main()
{
    std::array<int, 7> arr = {3, 0, 2, 0, 4, 0, 5};
    std::stack<size_t> index;

    int total_v = 0;
    for(size_t i = 0; i < arr.size(); i++)
    {
        while(!index.empty() && (arr[index.top()] < arr[i] ))
        {
            int pop_height = arr[index.top()];
            index.pop();
            if(index.empty()) break;

            int distance = i - index.top() - 1;
            int min_height = std::min(arr[index.top()], arr[i]) - pop_height;
            total_v += distance*min_height;
        }
        index.push(i);
    }
    std::cout << total_v << std::endl;
    return 0;
}
