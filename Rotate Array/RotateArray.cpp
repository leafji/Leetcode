#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int step;
        int length = nums.size();
        for(step = 0; step < k ; step++)
        {
            int temp = nums[length - 1];
            for( int i = length ; i >= 1 ; i--)
            {
                nums[i] = nums[i - 1];
            }
            nums[0] = temp;
        }
    }
    // 采用swap的方法进行
     void rotate_cpy(vector<int>& nums, int k)
    {
       int n = nums.size();
       int begin = 0;
       for (; k = k %n ; n-=k, begin+=k)
       {
            for(int i = 0; i < k; i++)
            swap(nums[i+begin], nums[n-k+i+begin]);
       }
    }
    // memcpy 形式进行复制
    void rotate_copy(int *num, int n, int k)
    {
        k = k % n;
        if (k == 0) return;
        int *temp = new int[n];
        memcpy(temp, num + (n - k), sizeof(int)*k);
        memcpy(temp + k, num, sizeof(int)*(n-k));
        memcpy(num, temp , n*sizeof(int));
        delete[] temp;
    }
};

int main()
{
    int num[2] = {1,2};
    vector<int> v1;
    for (int i = 0; i < 2 ; i++ )
       v1.push_back(num[i]);
    Solution *object = new Solution();
    object->rotate_cpy(v1,1);
    cout << "Solution is :!" << endl;
    //for (int i = 0; i < 2 ; i++ )
     //  v1.push_back(num[i]);
    for (int i = 0 ; i < v1.size() ; i++)
        cout << v1[i] << ",";
    cout << endl;
    return 0;
}
