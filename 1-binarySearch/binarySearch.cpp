#include <iostream>
#include <vector>
#include <algorithm>

#define NOT_FOUND       -1
#define UNSORTED_INPUT  -2

template<typename T>
class BinarySearch {
private:
    std::vector<T> data;

    int recursiveSearch(const T& target, int first, int last) const {
        if (first > last) {
            return NOT_FOUND;
        }

        int middle = first + (last - first) / 2;

        if (target == data[middle]) {
            return middle;
        } else if (target > data[middle]) {
            return recursiveSearch(target, middle + 1, last);
        } else {
            return recursiveSearch(target, first, middle - 1);
        }
    }

public:
    BinarySearch(const std::vector<T>& inputData) : data(inputData) {}

    int iterative(const T& target) const {
        if (!std::is_sorted(data.begin(), data.end())) {
            std::cerr << "Input must be a sorted vector" << std::endl;
            return UNSORTED_INPUT;
        }

        int first = 0;
        int last = data.size() - 1;

        while (first <= last) {
            int middle = first + (last - first) / 2;

            if (target == data[middle]) {
                return middle;
            } else if (target > data[middle]) {
                first = middle + 1;
            } else {
                last = middle - 1;
            }
        }
        return NOT_FOUND;
    }

    int recursive(const T& target) const {
        if (!std::is_sorted(data.begin(), data.end())) {
            std::cerr << "Input must be a sorted vector" << std::endl;
            return UNSORTED_INPUT;
        }

        return recursiveSearch(target, 0, data.size() - 1);
    }
};

int main() {
    std::vector<int> intData = {1, 2, 3, 10, 20, 30, 100};
    std::vector<std::string> strData = {"ahmd", "hla", "lyla"};

    BinarySearch<int> intSearch(intData);
    BinarySearch<std::string> strSearch(strData);

    std::cout << intSearch.iterative(20) << std::endl;   
    std::cout << intSearch.recursive(20) << std::endl;   

    std::cout << strSearch.iterative("hla") << std::endl;  
    std::cout << strSearch.recursive("hla") << std::endl;  

    return 0;
}