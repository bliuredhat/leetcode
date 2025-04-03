/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-03 11:37:53
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-03 16:55:49
 * @Description: 
 */
#include <vector>
#include <iostream>
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

/*
第一、
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
*/
ListNodePtr sum2List(ListNodePtr a, ListNodePtr b) {
    if (a ==nullptr || b == nullptr) {
        return a==nullptr ? b : a;
    }
    int flag = 0;
    ListNodePtr res = a;
    ListNodePtr tmp = new ListNode(-1);
    tmp->next = res;
    while (a != nullptr || b != nullptr) {
        int val_a = a != nullptr ? a->val : 0;
        int val_b = b != nullptr ? b->val : 0;
        int sum = val_a + val_b + flag;
        flag = 0;
        if (sum >= 10 ) {
            flag = 1;
            sum -= 10;
        }
        tmp->next = (a!=nullptr ? a: b);
        tmp->next->val = sum;
        tmp = tmp->next;
        if (a !=nullptr) {
            a = a->next;
        }
        if (b != nullptr) {
            b = b->next;
        }
    }
    if (flag > 0) {
        tmp->next = new ListNode(1);
    }
    return res;
}
/*
int main() {
    std::vector<int> v1{1,2,3,4};
    std::vector<int>::iterator begin = v1.begin();
    for (; begin!= v1.end(); begin++) {
        std::cout << *begin;
    }
    auto l1 = buildList(v1);
    printList(l1);
    std::vector<int> v2{9,9,9,9,9};
    auto l2 = buildList(v2);
    printList(l2);
    auto res = sum2List(l1,l2);
    printList(res);
    return 1;
}
*/

//************line*******

/*
第二、
无重复字符的最长子串；给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
*/
int longestSubString(const std::string& inputStr) {
    if (inputStr.empty()) {
        return 0;
    }
    int res = 0;
    std::unordered_set<char> mid_set;
    mid_set.reserve(inputStr.size());
    int size = inputStr.size();
    int pre =0;
    int next = 0;
    for (; next < size; next ++) {
        char val = inputStr.at(next);
        if (mid_set.find(val) == mid_set.end()) {
            mid_set.insert(val);
        } else {
            while (pre < next) {
                char tmp = inputStr.at(pre ++);
                if (tmp != val) {
                    mid_set.erase(tmp);
                } else {
                    break;
                }
            }
        }
        if (res < mid_set.size()){
            res = mid_set.size();
        }
    }
    return res;
}

int main() {
    std::string example{"pwwkew"};
    std::cout << example << std::endl;
    int res = longestSubString(example);
    std::cout << "len: " << res << std::endl;
    return 1;
}
