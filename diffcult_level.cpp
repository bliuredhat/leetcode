/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-03 17:07:48
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-07 16:33:31
 * @Description: 
 */
#include <vector>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef ListNode* ListNodePtr;

ListNodePtr buildList(std::vector<int> vec) {
    ListNodePtr res = nullptr;
    if  (vec.empty()) {
        return res;
    }
    ListNodePtr tmpPtr = nullptr;
    for (auto& val : vec) {
        auto* ptr = new ListNode(val);
        if (res == nullptr) {
            res = ptr;
            tmpPtr =res;
        } else {
            tmpPtr->next = ptr;
            tmpPtr = tmpPtr->next;
        }
    }
    return res;
}

void printList(ListNodePtr a) {
    auto* tmp = a;
    while(tmp!=nullptr) {
        std::cout << " , " <<tmp->val;
        tmp = tmp->next;
    }
    std::cout << std::endl;
}

//******************line***********************

/*
1、
中位数
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
*/

int findKIndex(const std::vector<int>& vec1, const std::vector<int> vec2, int k) {
    int size1 = vec1.size();
    int size2 = vec2.size();
    int idx1=0, idx2=0;
    while (true)
    {
        if (idx1 == size1){
            return vec2[idx2+k-1];
        }
        if (idx2 == size2) {
            return vec1[idx1+k-1];
        }
        if (k==1) {
            return std::min(vec1[idx1], vec2[idx2]);   
        }
        int new_idx1 = std::min(idx1 + k/2 -1, size1-1);
        int new_idx2 = std::min(idx2 + k/2 -1, size2-1);
        if (vec1[new_idx1] < vec2[new_idx2]) {
            k -= (new_idx1 - idx1 +1) ;
            idx1 = new_idx1 + 1;
        } else {
            k -= (new_idx2 - idx2 + 1);
            idx2 = new_idx2 +1;
        }
    }    
}

double findMid(const std::vector<int>& vec1, const std::vector<int>vec2) {
    int size1 = vec1.size();
    int size2 = vec2.size();
    if ((size1 + size2) % 2 == 0) {
        int idx1 = (size1 + size2) / 2;
        int idx2 = idx1 + 1;
        int res1 = findKIndex(vec1, vec2, idx1);
        int res2 = findKIndex(vec1, vec2, idx2); 
        std::cout << "res1: " << res1 << ", res2: " << res2 <<std::endl;
        return (res1 + res2)/2.0;
    } else {
        return findKIndex(vec1, vec2, (size1 + size2 + 1 )/2);
    }
}
/*
int main() {
    std::vector<int> vec1{1,2,3,4,5,6}; //6
    std::vector<int> vec2{7,8,9,11,12,13}; //6
    double res = findMid(vec1, vec2);
    std::cout << res << std::endl; 
}
*/

/*
2.
最长有效括号。
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/
int longestValidParentheses(string s) {
    int maxans = 0;
    std::stack<int> stk;
    stk.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();
            if (stk.empty()) {
                stk.push(i);
            } else {
                maxans = max(maxans, i - stk.top());
            }
        }
    }
    return maxans;
}

int main() {
    std::string s = ")()())";
    int res = longestValidParentheses(s);
    std::cout << "res: " << res <<std::endl;
    return 1;
}