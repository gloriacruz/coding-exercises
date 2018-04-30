// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long total1 = 0;
        long total2 = 0;

        ListNode* current= l1;
        while(current){
            total1 = total1 * 10 + current->val;
            current = current->next;
        }

        current = l2;
        while(current){
            total2 = total2 * 10 + current->val;
            current = current->next;
        }

        long total = total1 + total2;

        if(total == 0) return new ListNode(0); //return 1 node with value 0

        ListNode* pastDigit = NULL;
        while(total>0){
            int mod = total % 10;
            total = total / 10;
            ListNode* digit = new ListNode(mod);
            if(pastDigit){
                digit->next = pastDigit;
            }
            pastDigit = digit;
        }
        return pastDigit;
    }
};
