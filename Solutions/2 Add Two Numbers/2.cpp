/**
 * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 */
#include <iostream>
#include <ostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // Check for end of list
        bool eol1 = false;
        bool eol2 = false;

        int sum;
        int carry = 0;

        ListNode *sumptr = new ListNode(); // Pointer for current value being summed
        ListNode *output = sumptr;         // Mark the head of the output list

        // Catch some easy cases
        if (!l1 && !l2)
        {
            return NULL;
        }
        if (l1 && !l2)
        {
            return l1;
        }
        if (!l1 && l2)
        {
            return l2;
        }

        while (!eol1 || !eol2)
        {
            // Bring over any carry from previous and reset carry count
            sum = carry;
            carry = 0;

            if (!eol1)
            {
                sum += l1->val;
                // If the next in list is null, then mark end of list
                if (l1->next == nullptr)
                {
                    eol1 = true;
                }
                l1 = l1->next;
            }

            if (!eol2)
            {
                sum += l2->val;
                // If the next in list is null, then mark end of list
                if (l2->next == nullptr)
                {
                    eol2 = true;
                }
                l2 = l2->next;
            }

            // Calculate carry
            if (sum > 9)
            {
                carry = 1;
                sum = sum % 10;
            }

            // Apply sum
            sumptr->val = sum;

            // Add a node if we're not at the end or our last one had a carry
            if (!eol1 || !eol2 || carry > 0)
            {
                // Worth noting that setting next->val = carry doesn't do anything unless it's
                // at the end of the lists since it gets overwritten if we loop
                sumptr->next = new ListNode(carry);
            }
            sumptr = sumptr->next;
        }

        return output;
    }
};