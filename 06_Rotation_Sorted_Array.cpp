#include <vector>
#include <iostream>

using namespace std;

//给定一个数组，将数组中的元素向右移动 k 个位置

//找出最小值。
int findMin(std::vector<int>& arr) {
	int res;
	int left = 0;
	int right = arr.size() - 1;
	res = arr[right];
	while(left < right) {
		int mid = left + (right - left) / 2;
		std::cout << "idx:" << left << "-"<< right << std::endl;
		int val = arr[mid];
		if (val > res && val > arr[left]) {
			left = mid;
		} else if (val < res) {
			right = mid;
			res = val;
		} else {
			right --;
		}
	}
	return res;
}

//查找目标值的索引
int findVal(std::vector<int>& arr, int val) {
	int idx = -1;
	int size = arr.size();
	int left = 0;
	int right = size - 1;
	while(left < right) {
		std::cout << "idx:" << left << "-"<< right << std::endl;
		int mid = left + (right - left) / 2;
		if (arr[mid] == val) {
			return mid;
		}
		if (arr[mid] >= arr[left]) {
			if (val < arr[mid] && val > arr[left]) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {
			if (arr[mid] < val && val < arr[right]) {
				left = mid + 1;
			} else {
				right = mid-1;
			}
		}
	}
	return idx;
}


int main() {
	std::vector<int> arr = {6,7,8,9,1,2,3};
	//int res = findMin(arr);
	int res = findVal(arr, 2);
	std::cout << res << std::endl;
	return 0;
}


