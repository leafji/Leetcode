#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
// 总结各种排序算法，和复杂度
// 不占内存的排序算法:In-place sort 插入排序、选择排序、冒泡排序、堆排序、快速排序
// 占用内存的算法: 归并排序、计数排序、基数排序、桶排序
// stable sort：插入排序、冒泡排序、归并排序、计数排序、基数排序、桶排序。
//unstable sort：选择排序(5 8 5 2 9)、快速排序、堆排序。
class SortSummary
{
public:
    // 算法思想: 遍历一遍数组，拿出遍历的值，插入的合适的位置中去，将需要移动的元素移动
    // 时间复杂度O(n2)
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
    //  逐对交换两个元素，小的先出来，大的后出来
    // 时间复杂度O(n2)
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
    // 时间复杂度O(n2)
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
    // 归并排序stable sort、Out-place sort  O(nlgn)
    // 先将数组分治， 分治之后再合并
    // 时间复杂度O(nlog(n))
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
    // 将两个已经排好序列的数组合并为一个有序的数组
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
    // 快速排序是对冒泡排序的一种改进，采用的也是一种分治的思想。
    // 时间复杂度O(nlog(n))
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
