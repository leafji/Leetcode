#include <iostream>
#include <vector>
using namespace std;
/*
    Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
    Find all unique triplets in the array which gives the sum of zero.
    eg:
    given array S = [-1, 0, 1, 2, -1, -4],
    -4 -1 -1 0 1 2
    A solution set is:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]
*/
class Solution {
public:
    void quicksort(vector<int>& nums, int left, int right)
    {
        if (left < right)
        {
            int low = left;
            int high = right;
            int refvalue = nums[low];
            while(low < high)
            {
                while(nums[high] > refvalue && low < high)
                    high--;
                nums[low] = nums[high];
                while(nums[low] <= refvalue && low < high)
                    low++;
                nums[high] = nums[low];
            }
            nums[low] = refvalue;
            quicksort(nums, left, low - 1);
            quicksort(nums, low + 1, right);
        }
    }
    vector< vector<int> > twoSum(vector<int>& nums, int target)
    {
        quicksort(nums,0, nums.size() - 1);
        vector<vector<int> > result;
        int l = 0;
        int r = nums.size() - 1;
        while(l < r)
        {
            while(nums[l] == nums[l + 1])
                l++;
            while(nums[r] == nums[r - 1])
                r--;
            if(nums[l] + nums[r] == target)
            {
                vector<int> v0;
                v0.push_back(nums[l]);
                v0.push_back(nums[r]);
                result.push_back(v0);
                l++;
                r--;
            }
            else if(nums[l] + nums[r] > target)
            {
                r--;
            }
            else
                l++;
        }
        return result;
    }
    // 3Sum Closest
    /*
    Given an array S of n integers, find three integers in S
    such that the sum is closest to a given number, target.
    Return the sum of the three integers.
    You may assume that each input would have exactly one solution.
    */
    int threeSumClosest(vector<int>& nums, int target)
    {
        int rtn = 9999999;
        int result;
        //if(nums.size() < 3)

        quicksort(nums, 0 , nums.size() - 1);
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1;
            int r = nums.size() - 1;
            // �� a + b + c��ֵ�� �̶�c -> nums[i], nums[l] С nums[r] ��
            int sum = nums[i] + nums[l] + nums[r];
            int delta = sum - target;
            if(delta > 0) //˵�� a + b + c ��ֵ��target��, ��ô�𽥼���nums[r]
            {
                // ��Сnums[r], Ҫô��С����target ���(������)��Ҫô�ﵽ����ʱ�Ƚ�
                while(delta > 0 && --r > l)
                {
                    //r--;
                    sum = nums[i] + nums[l] + nums[r];
                    delta = sum - target;
                }
                if (delta == 0)
                    return target;
                else if(delta < 0)
                {   int d1 = nums[i] + nums[l] + nums[r + 1] - target;
                    int d2 = 0 - delta;
                    rtn = min(rtn,min(d1, d2));
                    if(rtn == d1)
                        result = nums[i] + nums[l] + nums[r + 1];
                    else if(rtn == d2)
                        result = sum;
                }
                else
                {
                    rtn = min(rtn, delta);
                    if(rtn == delta)
                        result = sum;
                }
            }
            else if(delta < 0)
            {
                while(delta < 0 && ++l < r)
                {
                    //l++;
                    sum = nums[i] + nums[l] + nums[r];
                    delta = sum - target;
                }
                if (delta == 0)
                    return target;
                else if(delta > 0)
                {   int d1 = target - (nums[i] + nums[l - 1] + nums[r]);
                    int d2 = delta;
                    rtn = min(rtn,min(d1, d2));
                    if(rtn == d1)
                        result = (nums[i] + nums[l - 1] + nums[r]);
                    else if(rtn == d2)
                        result = sum;
                }
                else
                {
                    rtn = min(rtn, 0 - delta);
                    if(rtn == (0 - delta))
                        result = sum;
                }
            }
            else   // ˵��a + b + c ��ֵ��target��ȣ���ֱ��return 0����
                return target;
        }
        return rtn;
    }

    // sum1 + sum2 = 0 - target  target �������һ������
    vector< vector<int> > threeSum(vector<int>& nums)
    {
        vector<vector<int> > result;
        if(nums.size() < 3) return result;
        quicksort(nums,0, nums.size() - 1);
        for (int i = 0; i < nums.size(); i++)
        {
            while(i > 0 && nums[i] == nums[i - 1])
                i++;
            int target = 0 - nums[i]; // target �����sum1 + sum2 ��ȱ����Ѿ��ҵ�
            int l = i + 1;
            int r = nums.size() - 1;
            while(l < r)
            {
                // �Ѿ��˻�Ϊ2sum ����
                if(nums[l] + nums[r] == target)
                {
                    vector<int> v0;
                    v0.push_back(nums[l]);
                    v0.push_back(nums[r]);
                    v0.push_back(0 - target);
                    result.push_back(v0);
                    l++;
                    r--;
                    while(nums[l] == nums[l - 1] && l < r)
                        l++;
                    while(nums[r] == nums[r + 1] && l < r)
                        r--;
                }
                else if (nums[l] + nums[r] > target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return result;
    }
};

int main()
{
    int num[] = {-1,2,1,-4,7};
    vector<int> v1;
//    vector< vector<int> > rtn;
    int rtn;
    for (int i = 0; i < sizeof(num)/sizeof(num[0]) ; i++ )
       v1.push_back(num[i]);
    Solution *object = new Solution();
    //object->quicksort(v1, 0 , v1.size() - 1);
    rtn = object->threeSumClosest(v1,1);
    cout << "result is " << rtn << endl;
//    cout << "[" << endl;
//    for (int i = 0; i < rtn.size(); i++)
//    {
//        vector<int> tmp = rtn[i];
//        cout << "[";
//        for (int j = 0 ;j < tmp.size(); j++)
//        {
//            cout << tmp[j] << ",";
//        }
//        cout << "]" << endl;
//    }
//    cout << "]" << endl;
    return 0;
}
