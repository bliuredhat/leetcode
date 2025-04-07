/*
 * @Author: bo.liu bo.liu@ushow.media
 * @Date: 2025-03-25 16:42:24
 * @LastEditors: bo.liu bo.liu@ushow.media
 * @LastEditTime: 2025-03-25 17:20:40
 * @FilePath: /code_review/09_Copy_Random_List.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <unordered_map>

/*
给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针random，
该指针可以指向链表中的任何节点或空节点。
构造这个链表的深拷贝。深拷贝应该正好由n个全新节点组成，
其中每个新节点的值都设为其应的原节点的值。
新节点的next指针和random指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
复制链表中的指针都不应指向原链表中的节点 。
*/
template <typename T>
struct randomNode
{
  T value;
  randomNode* next;
  randomNode* random;
  randomNode(T val): value(val), next(nullptr), random(nullptr){} 
};

typedef randomNode<int> RandomNode;

RandomNode* copyRandomList(RandomNode* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  RandomNode* origin = head;
  std::unordered_map<RandomNode*, RandomNode*> dataMap;
  RandomNode* dump = new RandomNode(-1);
  RandomNode* tmp = dump;
  while (origin != nullptr)
  {
    tmp->next = new RandomNode(origin->value);
    tmp = tmp->next;
    dataMap[origin] = tmp;
    origin = origin->next;
  }
  origin = head;
  tmp = dump->next;
  while(origin != nullptr) {
    tmp->random = (origin->random != nullptr) ? dataMap[origin] : nullptr;
    origin = origin->next;
  }
  return dump->next;
}

//优化
class Solution {
public:
    std::unordered_map<RandomNode*, RandomNode*> cachedNode;

    RandomNode* copyRandomList(RandomNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (!cachedNode.count(head)) {
            RandomNode* headNew = new Node(head->val);
            cachedNode[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};
