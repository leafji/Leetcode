#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
// �ܽ���������㷨���͸��Ӷ�
// ��ռ�ڴ�������㷨:In-place sort ��������ѡ������ð�����򡢶����򡢿�������
// ռ���ڴ���㷨: �鲢���򡢼������򡢻�������Ͱ����
// stable sort����������ð�����򡢹鲢���򡢼������򡢻�������Ͱ����
//unstable sort��ѡ������(5 8 5 2 9)���������򡢶�����
class SortSummary
{
public:
    // �㷨˼��: ����һ�����飬�ó�������ֵ������ĺ��ʵ�λ����ȥ������Ҫ�ƶ���Ԫ���ƶ�
    // ʱ�临�Ӷ�O(n2)
    void Insert_Sort(int *num, int length)
    {
        for (int travel_pos = 1; travel_pos < length ; travel_pos++)
        {
            int insert_pos = 0;
            while(insert_pos < travel_pos && num[insert_pos] < num[travel_pos])
                insert_pos++;
            if(insert_pos < travel_pos)
            {
                int temp = num[travel_pos];
                for(int k = travel_pos; k > insert_pos ; k-- )
                    num[k] = num[k - 1];
                num[insert_pos] = temp;
            }
        }
    }
    //  ��Խ�������Ԫ�أ�С���ȳ�������ĺ����
    // ʱ�临�Ӷ�O(n2)
    void Bubble_Sort(int *num, int length)
    {
        int first_travel;
        int second_travel;
        for (first_travel = 0; first_travel < length ; first_travel++)
        {
            for(second_travel = first_travel + 1; second_travel < length ; second_travel++)
            {
                if(num[second_travel] < num[second_travel - 1])
                {
                    int temp = num[second_travel];
                    num[second_travel] = num[second_travel - 1];
                    num[second_travel - 1] = temp;
                }
            }
        }
    }
    // ʱ�临�Ӷ�O(n2)
    void Selectiont_Sort(int *num, int length)
    {
        int travel_pos = 1;
        for(; travel_pos < length; travel_pos++)
        {
            int minPos;
            int minValue = num[travel_pos - 1];
            for(int k = travel_pos; k < length; k++)
            {
                if(num[k] < minValue)
                {
                    minValue = num[k];
                    minPos = k;
                }
            }
            if(minValue != num[travel_pos - 1])
            {
                int temp = num[minPos];
                num[minPos] = num[travel_pos - 1];
                num[travel_pos - 1] = temp;
            }
        }
    }
    // �鲢����stable sort��Out-place sort  O(nlgn)
    // �Ƚ�������Σ� ����֮���ٺϲ�
    // ʱ�临�Ӷ�O(nlog(n))
    int level = 0;
    void Merge_Sort(int *num, int first, int last)
    {
        if (first + 1 < last)
        {
            int mid = (first + last)/2;
            Merge_Sort(num, first, mid);
            Merge_Sort(num, mid, last);
            Merge(num, first, mid, last);
        }
    }
    // �������Ѿ��ź����е�����ϲ�Ϊһ�����������
    void Merge(int *num, int first, int mid, int last)
    {
        int *mergenum = new int[last - first + 1];
        int mergcnt = 0;
        int indexA = first;
        int indexB = mid;
        while(indexA < mid && indexB < last)
        {
            if (num[indexA] < num[indexB])
            {
                mergenum[mergcnt++] = num[indexA];
                indexA++;
            }
            else
            {
                mergenum[mergcnt++] = num[indexB];
                indexB++;
            }
        }
        while(indexA < mid)
        {
            mergenum[mergcnt++] = num[indexA++];
        }
        while(indexB < last)
        {
            mergenum[mergcnt++] = num[indexB++];
        }
        memcpy(num + first, mergenum, (last - first)*sizeof(int));
        delete[] mergenum;
    }
    // ���������Ƕ�ð�������һ�ָĽ������õ�Ҳ��һ�ַ��ε�˼�롣
    // ʱ�临�Ӷ�O(nlog(n))
    void QuickSort(int *num, int left, int right)
    {
        if (left < right)
        {
            int low = left;
            int high = right;
            int ref_value = num[low];
            while(low < high)
            {
                while(num[high] > ref_value && low < high)
                    high--;
                num[low] = num[high];
                while(num[low] <= ref_value && low < high)
                    low++;
                num[high] = num[low];
            }
            num[low] = ref_value;
            QuickSort(num,left,low - 1);
            QuickSort(num,low + 1, right);
        }
    }
    void ShowSort(int *num, int length)
    {
        for(int i = 0; i < length ; i++)
            cout << num[i] << " ";
        cout << endl;
    }
};


int main()
{
    int nums[] = {8,2,3,7,8,10,4,11,34,23};
    //int nums[] = {2,6,8,3,5,7,9};
    SortSummary *sort = new SortSummary();
    //sort->Selectiont_Sort(nums, sizeof(nums)/sizeof(nums[0]));//sizeof(nums));
    //sort->Merge_Sort(nums, 0,sizeof(nums)/sizeof(nums[0]));
    sort->QuickSort(nums, 0,sizeof(nums)/sizeof(nums[0]));
    sort->ShowSort(nums,sizeof(nums)/sizeof(nums[0]));
    return 0;
}
