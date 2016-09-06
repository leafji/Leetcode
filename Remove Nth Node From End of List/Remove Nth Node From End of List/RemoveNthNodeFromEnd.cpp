#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 * Remove the nth node from the end of listNode
 *
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* delfirst = head;
        ListNode* delsecond = new ListNode(0);
        if (n == 0)
            return head;
        delsecond->next = head;
        while(delfirst->next != NULL)
        {
            if (n != 1)
            {
                n--;
                delfirst = delfirst->next;
            }
            else
            {
                delfirst = delfirst->next;
                delsecond = delsecond->next;
            }
        }
        if(delsecond->next == head)  // n equal list.size
            return head->next;
        else
            delsecond->next = delsecond->next->next;
        return head;
    }

};

int main()
{
    int nums[] = {1,2,3,4,5};
    ListNode *head= new ListNode(1);
    ListNode *list = head;
    for(int i = 1; i < sizeof(nums)/sizeof(int); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        list->next = temp;
        list = list->next;
    }
    Solution *object = new Solution();
    ListNode *result;
    result = object->removeNthFromEnd(head, 0);
    for (list = result; list != NULL; list = list->next)
    {   cout << list->val ;
        if (list->next != NULL)
            cout << "->";
    }
    cout << endl;

    cout << "Hello world!" << endl;
    return 0;
}
