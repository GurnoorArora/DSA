class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //this would sort the array
        int n=nums.size();
        vector<vector<int>> result;
    for(int  i=0;i<n-1;i++)
    {
        //skipping the dupes 
        if (i>0 && nums[i]==nums[i-1]) continue;
        int target=-1*nums[i];
        //so we have found the target 

        int left=i+1;
        int right=n-1;
        while(left<right)
        {
            
            if(nums[left]+nums[right]==target)
            {
                result.push_back({nums[left],nums[i],nums[right]});
                while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;

            }

           else if(nums[left]+nums[right]>target)
            {
                right--;
            }
            else{
                left++;
            }
            
           

        }
    }

    return result;



        
    }
};
