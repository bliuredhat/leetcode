/*
 * @Author: bliuredhat@gmail.com
 * @Date: 2023-07-13 17:13:35
 * @LastEditors: bliuredhat@gmail.com
 * @LastEditTime: 2025-04-11 16:42:26
 * @Description: 
 */
#include <iostream>

using namespace std;
/*
   列表操作
*/
//单链表
struct Node
{
   int val;
   Node* next;
   Node(int x): val(x), next(nullptr){}
};

//链表翻转
Node* reverseList(Node* root, Node* end) {
   Node* next = root;
   Node* pre = end->next;
   while(pre != end) {
      Node* tmp = next->next;
      next->next = pre;
      pre = next;
      next = tmp;
   }
   return pre;
}

//k 步骤翻转
Node* reverseKList(Node* head, int k){
   if(!head || !head->next) {
      return head;
   }
   Node dump = Node(-1);
   dump.next = head;
   Node* pre = &dump;
   //Node* next = head->next;
   while(true){
      Node* begin = pre->next;
      Node* end = begin;
      for(int i = 0; i < (k-1) && end != nullptr; i ++) {
         end = end->next;
      }
      if (!end) {
         break;
      }
      pre->next = reverseList(begin, end);
      pre = begin;
      // next = begin->next;
   }
	head = dump.next;
   return dump.next;
}

int main(int argc, const char** argv) {
   Node* head = new Node(0);
   int N = 20;
   Node* next = head;
   for(int val=1; val < 23; val++) {
	std::cout << val << std::endl;
      Node* node = new  Node(val);
      next->next = node;
      next = node;
   }
   next = head;
   while(next) {
      std::cout << next->val << " ";
		next = next->next;
		if(next == nullptr) {
			break;
		}
   }
   std::cout<<std::endl;
   next = reverseKList(head, 4);
   while(next) {
      std::cout << next->val << " ";
      next =next->next;
   }
   return 0;
}









