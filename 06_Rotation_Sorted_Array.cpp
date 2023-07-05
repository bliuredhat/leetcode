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

int findVal(std::vector<int>& arr) {


}


int main() {
	std::vector<int> arr = {6,7,8,9,1,2,3};
	int res = findMin(arr);
	std::cout << res << std::endl;

}


