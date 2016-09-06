#include "ListManager.h"

ListManager::ListManager()
{
    //ctor
}

ListManager::ListManager(int *nums, int len)
{
    ListNode* head = NULL;
    for (int i = 0; i < len ; i++)
    {
        ListNode* temp = new ListNode(nums[i]);
        if(head == NULL)
        {
            head = temp;
            mList = head;
        }
        else
        {
            head->next = temp;
            head = head->next;
        }
    }
}

ListManager::~ListManager()
{
    //dtor
}

void ListManager::showList (void)
{
    ListNode* list;
    for (list = mList; list != NULL; list = list->next)
    {   cout << list->val ;
        if (list->next != NULL)
            cout << "->";
    }
    cout << endl;
}
