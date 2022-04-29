/*
Given a sorted linked list, delete all duplicates such that each element appear only once. For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
// LeetCode, Remove Duplicates from Sorted List 
typedef struct {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(nullptr){}
}  ListNode;

class Solution {
public:
      ListNode *deleteDuplicates(ListNode *head) {
          if (head == nullptr) return nullptr;
          for (ListNode *prev = head, *cur = head->next; cur; cur = prev->next) {
              if (prev->val == cur->val) {
                  prev->next = cur->next;
                  delete cur;
              } else {
                 prev = cur; 
                }
            }
          return head;
      }
};

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5. Given 1->1->1->2->3, return 2->3.
*/
class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (head == nullptr) return head;
            ListNode dummy(INT_MIN);
            dummy.next = head;
            ListNode *prev = &dummy, *cur = head; 
            while (cur != nullptr) {
                bool duplicated = false;
                while (cur->next != nullptr && cur->val == cur->next->val) {
                    duplicated = true;
                    ListNode *temp = cur;
                    cur = cur->next;
                    delete temp;
                }
                if (duplicated) { 
                    ListNode *temp = cur;
                    cur = cur->next;
                    delete temp;
                    continue;
                }
                prev->next = cur;
                prev = prev->next;
                cur = cur->next;
            }
            prev->next = cur;
            return dummy.next;
        } 
};
