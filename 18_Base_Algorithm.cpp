/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-18 12:11:06
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-18 14:56:08
 * @Description: 
 */
#include <vector>
#include <stack>
#include <iostream>
#include <utility>

using namespace std;

//快速排序
void printVec(std::vector<int>& vec) {
    for (auto& val : vec) {
        std::cout << " , " << val;
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& vec, int start, int end) {
    int val = vec[start];
    int left = start;
    int right = end;
    while(left < right) {
        while(left < right && vec[right] > val) {
            right --;
        }
        if (left < right) {
            vec[left] = vec[right];
            left++;
        }
        while(left < right && vec[left] < val) {
            left ++;
        }
        if (left < right) {
            vec[right] = vec[left];
            right--;
        }
    }
    vec[left] = val;
    return left;
}

void quick_sort_handle(std::vector<int>& vec, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = partition(vec, start,  end);
    quick_sort_handle(vec, start, mid-1);
    quick_sort_handle(vec, mid+1, end); 
}

void quicksort(std::vector<int>& vec) {
    quick_sort_handle(vec, 0, vec.size()-1);
}

int main() {
    std::vector<int> vec{8,3,7,1,6,2,7,4, 5};
    printVec(vec);
    quicksort(vec);
    printVec(vec);
}


