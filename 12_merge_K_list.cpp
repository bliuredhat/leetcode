/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。
示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
*/
#include <vector>
#include <queue>
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

struct Compare {
    bool operator()(ListNodePtr a, ListNodePtr b) {
        return a->val > b->val; //
    }
};

using namespace std;
ListNodePtr mergeKList(std::vector<ListNodePtr> qu_vec) {
    std::priority_queue<ListNodePtr, std::vector<ListNodePtr>, Compare > k_qu;
    for (auto it : qu_vec) {
        if (it != nullptr) {
           k_qu.push(it);  
        } 
    }
    ListNodePtr dumpPtr = new ListNode(-1);
    ListNodePtr tmpPtr = dumpPtr;
    while (!k_qu.empty()) {
        ListNodePtr it = k_qu.top();
        k_qu.pop();
        tmpPtr->next = it;
        tmpPtr = tmpPtr->next;
        if (it->next != nullptr) {
            k_qu.push(it->next);
        }
    }
    ListNodePtr res = dumpPtr->next;
    delete dumpPtr;
    return res;
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
    //lists = [[1,4,5],[1,3,4],[2,6]] 
    std::vector<int> v1{1,4,5};
    ListNodePtr l1 = buildList(v1);
    std::vector<int> v2{1,3,4};
    ListNodePtr l2 = buildList(v2);
    std::vector<int> v3{2,6};
    ListNodePtr l3 = buildList(v3);
    std::vector<ListNodePtr> qu_vec{l1, l2, l3};
    auto* res = mergeKList(qu_vec);
    while(res!=nullptr) {
        std::cout <<"val: " << res->val << std::endl;
        res = res->next;
    }
    return 1;
}