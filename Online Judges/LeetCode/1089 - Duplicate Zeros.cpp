class Solution 
{
    public:
        void duplicateZeros(vector<int>& arr) {
            int n = arr.size();
            int fast = 0;
            int slow = 0;
            for(; slow < n; slow++)
            {
                if(arr[slow] == 0)
                {
                    if(fast == n-1)
                    {
                        arr[fast] = 0;
                        fast--;
                        slow--;
                        break;
                    }
                    fast++;
                }
                if(fast == n-1)
                {
                    break;
                }
                fast++;
            }

            while(slow>=0)
            {
                if(arr[slow] == 0)
                {
                    arr[fast--] = 0;
                }
                arr[fast--] = arr[slow--];
            }
        }
};
