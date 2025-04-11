/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2023-07-17 16:18:18
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-11 16:07:30
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
    st.push(-1);
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
     while (st.top() != -1) {
        int height = vec[st.top()];
        st.pop();
        int width = vec.size() - st.top() - 1;
        res = std::max(res, height * width);
    }
    return res;
}


int largestWater(std::vector<int>& arr) {
        //arr.push_back(0);
        int n = arr.size();
        int ans = 0;

        std::stack<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int h = std::min(arr[left], arr[i]) - arr[top];
                int w = i - left - 1;
                ans +=  h * w;
            }
            st.push(i);
        }
        return ans;
}

int main() {
    std::vector<int> arr{ 4, 4, 4, 2, 10, 2, 2, 2,};
    int res = LargestRectangleArea(arr);
    printf("func1:%d\n", res);

    res = largestWater(arr);
    printf("func2:%d\n", res);
    return 1;
}