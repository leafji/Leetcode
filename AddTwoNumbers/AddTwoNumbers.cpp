#include <iostream>
#include <vector>
using namespace std;
/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

struct ListNode
{
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* sum = NULL;
        ListNode* headsum;
        int sumpernode;
        int overbit = 0;
        while(l1 != NULL || l2 != NULL || overbit)  // 这个条件比较重要
        {
            int num1 = l1?l1->val:0;
            int num2 = l2?l2->val:0;
            sumpernode = num1 + num2 + overbit;
            if (sumpernode > 9)
            {
                sumpernode %= 10;
                overbit = 1;
            }
            else
                overbit = 0;
            ListNode *nodetemp = new ListNode(sumpernode);
            if (sum == NULL)
            {
                sum = nodetemp;
                headsum = sum;
            }
            else
            {
                 sum->next = nodetemp;
                 sum = sum->next;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return headsum;
    }
};
int main()
{
    int list1[] = {0};
    int list2[] = {5,6,4};
    ListNode *head1 = new ListNode(0);
    ListNode *l1 = head1;
    ListNode *head2 = new ListNode(5);
    ListNode *l2 = head2;
    for(int i = 1; i < sizeof(list1)/sizeof(int); i++)
    {
        ListNode *temp = new ListNode(list1[i]);
        head1->next = temp;
        head1 = head1->next;
    }
    for(int i = 1; i < sizeof(list2)/sizeof(int); i++)
    {
        ListNode *temp = new ListNode(list2[i]);
        head2->next = temp;
        head2 = head2->next;
    }
    Solution *object = new Solution();
    ListNode *result, *list;
    result = object->addTwoNumbers(l1, l2);
    for (list = result; list != NULL; list = list->next)
    {   cout << list->val ;
        if (list->next != NULL)
            cout << "->";
    }
    cout << endl;
    cout << "Hello world!" << endl;
    return 0;
}
