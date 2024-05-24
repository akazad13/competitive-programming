class Solution
{
    public:
        int removeDuplicates(vector<int>& nums)
        {
            int lastVal = -200;
            int i = 0;
            for(int j = 0; j < nums.nums.size(); j++)
            {
                if(nums[j] != lastVal)
                {
                    nums[i++] = nums[j];
                    lastVal = nums[j];
                }
            }
            return i;
        }
};