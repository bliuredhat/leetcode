/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2023-07-17 16:18:18
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-11 11:38:55
 * @Description: 
 */
#include <vector>
#include <stack>
#include <iostream>

int LargestRectangleArea(const std::vector<int>& vec) {
    int res = 0;
    if (vec.empty()) {
        return res;
    }
    std::stack<int> st;
    int size = vec.size();
    for(int idx=0; idx < size; idx++) {
        int val = vec[idx];
        while (!st.empty() && val < vec[st.top()]) {
            int height = vec[st.top()];
            int weith = idx - st.top();
            res = std::max(res, height* weith);
            st.pop();
        }
        st.push(idx);
    }
    return res;
}


int maxAreaV2(std::vector<int>& arr) {
        arr.push_back(0);
        int n = arr.size();
        int ans = 0;

        std::stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int top = st.top();
                int h = arr[top];
                int w = i - top;
                ans = std::max(ans, h * w);
                st.pop();
                if (st.empty()) {
                    break;
                }
            }
            st.push(i);
        }
        return ans;
}

int main() {
    std::vector<int> arr{ 4, 1, 2, 3, 15, 6};
    int res = LargestRectangleArea(arr);
    printf("func1:%d\n", res);

    res = maxAreaV2(arr);
    printf("func2:%d\n", res);

    return 1;
}