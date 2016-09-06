#include <iostream>
#include <vector>
#include "ListManager.h"
using namespace std;
/*
Given a linked list, swap every two adjacent nodes and return its head.
For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list,
only nodes itself can be changed.
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* travel = head;
        ListNode* swap1;
        ListNode* swap2;
        ListNode* rtn_head;
        ListNode* connect = NULL;
        if(head == NULL) return NULL;
        if(head->next)
        {
            rtn_head = head->next;
        }
        else
            rtn_head = head;
        while(travel)
        {
            if(travel->next)
            {
                swap1 = travel;
                swap2 = travel->next;
                ListNode* temp = swap2->next;
                swap1->next = temp;
                swap2->next = swap1;
                travel = temp;
                if(connect == NULL)
                {
                    connect = swap1;
                }
                else
                {
                    connect->next = swap2;
                    connect = connect->next->next;
                }
            }
            else
                break;
        }
        return rtn_head;
    }
};

int main()
{
    int nums[] = {1,2,3,4,5,6,7,8,56};
    ListNode* list = NULL;
    ListNode* head;
    ListManager *lmsger = new ListManager(nums, sizeof(nums)/sizeof(int));
    lmsger->showList();
    Solution *object = new Solution();
    lmsger->SetmList(object->swapPairs(lmsger->GetmList()));
    lmsger->showList();
    cout << "Hello world!" << endl;
    return 0;
}
