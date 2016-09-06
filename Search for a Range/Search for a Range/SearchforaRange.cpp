#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> result;
        if (std::binary_search(nums.begin(), nums.end(), target))
        {
            std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounders;
            bounders = std::equal_range(nums.begin(), nums.end(), target);
            result.push_back(bounders.first - nums.begin());
            result.push_back(bounders.second - nums.begin() - 1);
        }
        else
        {
            result.push_back(-1);
            result.push_back(-1);
        }
        return result;
    }
};
int main()
{
    int num[] = {1,2,4,4,6};
    vector<int> result;
    vector<int> v1(num, num + sizeof(num)/sizeof(int));
    Solution *object = new Solution();
    result = object->searchRange(v1, 4);
    cout << "Result is [" << result[0] <<","<<result[1] <<"]" << endl;
    return 0;
}

int var = 1;
int longVarName = 2;
int foobar = 3;
