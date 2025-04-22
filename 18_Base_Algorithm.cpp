/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-18 12:11:06
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-18 16:37:12
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

//堆排序
void head_adjust(std::vector<int>& vec, int root, int size){
    int val = vec[root];
    int children = 2* root +1;
    for(; children < size; children = children*2+1) {
        if (children+1 < size && vec[children] < vec[children+1]) {
            children += 1;
        }
        if (vec[children] > val) {
            std::swap(vec[children], val);
        } else {
            break;
        }
    }
    vec[root] = val;
}

void heapSort(std::vector<int>& vec) {
    int size = vec.size() ;
    for (int root=size/2; root >= 0; root--) {
        head_adjust(vec, root, size);
    }
    for (int idx=size-1; idx >= 0; idx--) {
        std::swap(vec[0], vec[idx]);
        head_adjust(vec, 0, idx);
    }
}

int main() {
    std::vector<int> vec{8,3,7,1,6,2,7,4, 5};
    printVec(vec);
    std::cout << "快速排序：" << std::endl;
    quicksort(vec);
    printVec(vec);
    std::cout << "堆排序：" <<std::endl;
    std::vector<int> vec1{8,3,7,1,6,2,7,4, 5};
    heapSort(vec);
    printVec(vec);
}


