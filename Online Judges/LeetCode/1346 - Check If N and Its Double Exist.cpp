class Solution
{
    public:
        bool checkIfExist(vector<int>& arr) 
        {
            unordered_map<int,int> Map;
            for(int num:arr)
            {
                if(Map.count(2*num) || (num%2==0 && Map.count(num/2)))
                {
                    return true;
                }
                Map[num]++;
            }
            return false;
        }
}