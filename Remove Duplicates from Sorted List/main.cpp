#include <iostream>
#include "ListManager.h"
using namespace std;

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
