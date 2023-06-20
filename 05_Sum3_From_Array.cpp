#include <vector>
#include <iostream>

using namespace std;

int get2sum(std::vector<int>& arr, int left,  int right,  int target) {
	int res = 0;
	while(left < right ) {
		while(arr[right] > target) { 
			right -- ;
		}
		if (arr[left] + arr[right] > target) {
			right --;
			continue;
		}
		
		res = res < ( arr[left] + arr[right]) ? ( arr[left] + arr[right]) : res;
		left ++;
	}
	return res;
}



int getTarget(std::vector<int> nums, int target) {
    int res = 0;
	if ( nums.empty()) {
		return res;
	}
	std::sort(nums.begin(), nums.end());
	int size = nums.size();
	for (int idx1=0; idx1 < size-3; idx1 ++) {
		if (nums[idx1] > target || res == target) {
			break;
		}
		int tmp = nums[idx1] + get2sum(nums, idx1 + 1, size - 1,   target - nums[idx1]);
		
		if (res < tmp) {
			res = tmp;
			 std::cout << "candiate:" << nums[idx1] << std::endl;
		}
	}
	return res;
}

//g++ -o 05 05_Sum3_From_Array.cpp -std=c++11

int main() {
	std::vector<int> arr = {1, 10, 3, 20, 5, 30, 7, 40, 9, 49, 11, 60, 13}; 
	int res = getTarget(arr, 99);
	std::cout << res << std::endl;
}



