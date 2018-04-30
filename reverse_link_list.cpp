//Reverse a singly linked list.

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {

  if(!head || !head->next)
    return head;

  ListNode* node = head;
  ListNode* newNext = NULL;

  while(node){
    ListNode* next = node->next;
    node->next = newNext;
    newNext = node;
    node = next;
  }

  return newNext;
}

int main(){

  ListNode *one = new ListNode(1);
  ListNode *two = new ListNode(2);
  ListNode *three = new ListNode(3);
  one->next = two;
  two->next = three;

  ListNode* newHead = reverseList(one);
  cout << "Old head" << one->val << endl;
  cout << "New head" << newHead->val;

  return 1;
}
