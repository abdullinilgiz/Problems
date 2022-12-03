
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}

      ListNode(int x) : val(x), next(nullptr) {}

      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* next;
        ListNode* prev = nullptr;
        while(head->next != nullptr){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head->next = prev;
        return head;
    }
};

using namespace std;

int main() {

    Solution sln;

    ListNode node = ListNode(0, nullptr);
    ListNode node1 = ListNode(1, &node);
    ListNode node2 = ListNode(2, &node1);
    ListNode node3 = ListNode(3, &node2);
    ListNode node4 = ListNode(4, &node3);

    ListNode* result = sln.reverseList(&node4);

    return 0;
}
