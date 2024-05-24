class Solution 
{
    public:
        bool validMountainArray(vector<int>& arr) 
        {
            bool mountainTop = false;
            
            for(int i=1; i<arr.size()-1; i++)
            {
                if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
                    return false;
                if(arr[i-1] == arr[i] || arr[i] == arr[i+1])
                    return false;
                if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
                {
                    mountainTop = true;
                }
            }
            return mountainTop;
        }
};