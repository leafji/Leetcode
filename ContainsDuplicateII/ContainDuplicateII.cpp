#include <iostream>
#include <vector>
using namespace std;
/*  II Given an array of integers and an integer k, find out whether there are two distinct
    indices i and j in the array such that nums[i] = nums[j] and the difference between i
    and j is at most k.

    I Given an array of integers, find if the array contains any duplicates. Your function should
    return true if any value appears at least twice in the array, and it should return false if
    every element is distinct.

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        if(nums.size() == 0)
                return false;
        int temp[200000]={0};
        vector<int> diff;
        for(int i = 0 ;i < nums.size(); i++)
        {
            if(temp[100000 + nums[i]] > 0)
            {
                diff.push_back(i + 1 - temp[100000 + nums[i]]);
                temp[100000 + nums[i]] = i + 1;
            }
            else
                temp[100000 + nums[i]] = i + 1;
        }
        for(int i = 0; i < diff.size() ;i++)
        {
            if(diff[i] <= k)
                return true;
        }
        return false;
    }

    bool containsDuplicate(vector<int>& nums)
    {
        int array[1000000] = {0};
        int i = 0;
        if(nums.size() == 0)
            return false;
        for (; i < nums.size() ; i++)
        {
            if (array[nums[i]] == 0)
                array[nums[i]]++;
            else
                return true;
        }
        return false;
    }
};

int main()
{
    Solution *object = new Solution();
    cout << "Hello world!" << endl;
    return 0;
}
