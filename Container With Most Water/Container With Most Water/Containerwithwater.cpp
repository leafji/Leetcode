#include <iostream>
#include <vector>
using namespace std;
/*
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container,
such that the container contains the most water.
Note: You may not slant the container.
*/
class Solution {
public:
    int maxArea_overlimit(vector<int>& height) {
        int len = height.size();
        int maxArea = min(height[1],height[0]);
        for(int i = 2; i < len ; i++)
        {
            for(int j = 0; j < i; j++)
            {
                int tempArea = (i - j)*min(height[i], height[j]);
                if(tempArea > maxArea)
                    maxArea = tempArea;
            }
        }
        return maxArea;
    }
    // 28ms
    int maxArea(vector<int> &height)
    {
        int maxArea = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            maxArea = max(min(height[left], height[right])*(right - left), maxArea);
            if(height[left] < height[right])
                left += 1;
            else
                right -=1;
        }
        return maxArea;
    }
};
/* similar issue
Given n non-negative integers representing an elevation map where the width of each
bar is 1, compute how much water it is able to trap after raining.
For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution_copy {
public:
    int trap(vector<int>& height)
    {
        int maxHgt = 0;
        int maxId;
        int i;
        for (i = 0 ; i < height.size(); i++)
        {
            if(height[i] > maxHgt)
            {
                maxHgt = height[i];
                maxId = i;
            }
        }
        int hgt = 0;
        int totalarea = 0;
        int pillararea = 0;
        for (i = 0; i < maxId ; i++)
        {
            pillararea += height[i];
            if(height[i] > hgt)
            {
                totalarea += (maxId - i)*(height[i] - hgt);
                hgt = height[i];
            }
        }
        hgt = 0;
        for(i = height.size() - 1; i > maxId ; i--)
        {
            pillararea += height[i];
            if(height[i] > hgt)
            {
                totalarea += (i - maxId)*(height[i] - hgt);
                hgt = height[i];
            }
        }
        return totalarea - pillararea;
    }
};

int main()
{
    Solution_copy *object = new Solution_copy();
    int num[] = {0,1,0,2,1,0,1,3,2,1,2,6,2,3,0,3,8,4,1};
               //0 1 0 2 0 0 0 2 0 0 2 0
    vector<int> v1;
    for (int i = 0; i < sizeof(num)/sizeof(int) ; i++)
        v1.push_back(num[i]);
    cout << "Result is :"<< object->trap(v1) << endl;
    return 0;
}
