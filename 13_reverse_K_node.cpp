/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2025-04-02 10:49:33
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-02 15:40:18
 * @Description: 
 */
/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef ListNode* ListNodePtr;

/*
方法一：分段反转
*/

std::pair<ListNodePtr, ListNodePtr> reverseList(ListNodePtr head, ListNodePtr tail) {
        ListNode* prev = tail->next;  // 注意连接到下一组的第一个节点
        ListNode* curr = head;
        
        while (prev != tail) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {tail, head};
}

ListNodePtr reverseKNode(ListNodePtr head, int k) {
    if (head ==nullptr || k == 1) {
        return head;
    }
    ListNodePtr next = head;
    for (int id = 0; id < k-1; id ++) {
        next = next->next;
        if (next == nullptr) {
            return head;
        }
    }
    auto pair = reverseList(head, next);
    auto* first = pair.first;
    auto* second = pair.second;
    second->next = reverseKNode(second->next, k);

    return first;
}


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

int main() {
    std::vector<int> vec{1,2,3,4,5};
    auto l1 = buildList(vec);
    auto  res = reverseKNode(l1, 2);
    while(res !=nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
    return 1;
}
