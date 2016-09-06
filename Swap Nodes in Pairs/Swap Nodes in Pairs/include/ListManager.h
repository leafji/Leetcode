#ifndef LISTMANAGER_H
#define LISTMANAGER_H
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(NULL){}
};


class ListManager
{
    public:
        ListManager();
        ListManager(int *nums, int len);
        virtual ~ListManager();
        void showList(void);
        struct ListNode* GetmList(void){return mList;}
        void SetmList(struct ListNode *list) {mList = list;}
        //bool RemoveNode(int number);
    protected:

    private:
        int listNumber;
        struct ListNode* mList;
};

#endif // LISTMANAGER_H
