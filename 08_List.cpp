/*
 * @Author: bo.liu bo.liu@ushow.media
 * @Date: 2025-03-25 14:42:28
 * @LastEditors: bo.liu bo.liu@ushow.media
 * @LastEditTime: 2025-03-25 15:55:54
 * @FilePath: /code_review/08_List.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
#include <iostream>


template <typename T>
struct listNode  {
  T value;
  listNode* next;
  listNode(T val): value(val), next(nullptr){}
};

typedef listNode<int> ListNode;


//翻转链表
ListNode* reverseList(ListNode* head) {
  if (head ==nullptr || head->next == nullptr) {
    return head;
  }
  ListNode* pre = nullptr;
  ListNode* next = head;
  while (next != nullptr) {
    ListNode* tmp = next->next;
    next->next = pre;
    pre = next;
    next = tmp->next; 
  }
  head = pre;
  return pre;
}

/*链表表示数字； 两链表想加；
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
*/
ListNode* add2List(ListNode* A, ListNode* B) {
  if (A == nullptr || B == nullptr) {
    return A == nullptr ? B : A;
  }
  ListNode* res = new ListNode(0);
  ListNode* tmp = res;
  int carry = 0;
  while(A != nullptr && B != nullptr) {
    tmp->value += carry;
    
    int val = A->value + B->value;
    carry = 0;
    if (val > 10) {
      carry = 1;
      val -= 10;
    }
    tmp->value += val;
    tmp->next = new ListNode(0);
    tmp = tmp->next;
  }
  return res;
}

//合并两个有序链表, 假设升序排练。
ListNode* mergeList(ListNode* A, ListNode* B){
  if (A == nullptr || B == nullptr) {
    return A==nullptr ? B : A;
  }
  ListNode* head = new ListNode(-1);
  ListNode* dump = head;
  while(A!= nullptr && B != nullptr) {
    if (A->value > B->value) {
      head->next = A;
    } else {
      head->next = B;
      B = B->next;
    }
  }

  if (B != nullptr) {
    head->next = B;
  }
  if (A != nullptr) {
    head->next = A;
  }
  return dump->next;
}

//判断是否为循环链表
bool checkCycleList(ListNode* head) {
  if (head ==nullptr || head->next ==nullptr) {
    return false;
  }
  ListNode* lowPtr =head;
  ListNode* fastPtr = lowPtr->next; 
  while (lowPtr != nullptr && fastPtr != nullptr)
  {
    if (lowPtr == fastPtr) {
      return true;
    }
    lowPtr = lowPtr->next;
    if (fastPtr->next == nullptr && fastPtr->next->next) {
      break;
    }
    fastPtr = fastPtr->next->next;
  }
  return false;
}