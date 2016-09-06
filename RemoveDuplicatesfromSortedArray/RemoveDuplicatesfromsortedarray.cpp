#include <iostream>
#include <vector>
using namespace std;
/*
//removeDuplicates//
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
    Given input array nums = [1,1,2],
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the new length.
// removeElement //
Given an array and a value, remove all instances of that value in place and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.
Example:
 Given input array nums = [3,2,2,3], val = 3
Your function should return length = 2, with the first two elements of nums being 2.
*/
class Solution {
public:
	int removeDuplicates(vector<int>& nums)
	{
	    int pos;
	    int index = 0;
	    if (nums.size() == 0) return 0;
	    for (pos = 1 ; pos < nums.size() ; pos++)
	    {
	        if(nums[pos] != nums[pos - 1])
	        {
	            nums[++index] = nums[pos];
	        }
	    }
	    return index + 1;
	}
	int removeElement(vector<int>& nums, int val)
    {
        int len = nums.size();
        int index = 0;
        if (nums.size() == 0)
            return 0;
        for (int i = 0 ;i < len ;i++)
        {
            if(nums[i] != val)
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main()
{
    Solution *object = new Solution();
    cout << "Hello world!" << endl;
    return 0;
}
