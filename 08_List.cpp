/*
 * @Author: bo.liu bo.liu@ushow.media
 * @Date: 2025-03-25 14:42:28
 * @LastEditors: bo.liu bo.liu@ushow.media
 * @LastEditTime: 2025-03-25 15:05:03
 * @FilePath: /code_review/08_List.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * 
 */
#include <iostream>


template <typename T>
struct listNode  {
  T value;
  listNode* next;
};

typedef listNode<int> ListNode;

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