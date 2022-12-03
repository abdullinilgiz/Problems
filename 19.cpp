#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 1;
    ListNode* temp = head;
    while(temp->next != nullptr){
        ++count;
        temp = temp->next;
    }
    int index = count - n;
    if (index == 0){
        if (count > 1){
            return head->next;
        } else {
            return nullptr;
        }
    }
    temp = head;
    while(index > 1){
        temp = temp->next;
        --index;
    }

    temp->next = temp->next->next;

    return head;
}

int main() {

    ListNode l1;
    ListNode l2(1, &l1);
    ListNode l3(2, &l2);
    ListNode l4(3, &l3);

    ListNode* head = removeNthFromEnd(&l4, 4);

    cout << " OK";


    return 0;
}