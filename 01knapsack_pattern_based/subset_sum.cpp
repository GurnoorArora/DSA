class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        bool dp[201][10001];
        
        //intializing with the dp array
        int rows=arr.size();
        int cols=sum+1;
        
        for(int i=0;i<=rows;i++)
        {
            for(int j=0;j<=cols;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j]=true;
                }
                //for the first row 
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(i!=0 && j==0)
                {
                    dp[i][j]=true;
                }
                else
                {
                    //core dp logic 
                    //checking if the arr[i] is less than j
                    if(arr[i-1]<=j)
                    {
                        //its feasible
                        if(dp[i-1][j-arr[i-1]]==true || dp[i-1][j])
                        {
                            dp[i][j]=true;
                        }
                        else
                        {
                            dp[i][j]=false;
                        }
                    }
                    else
                    {
                        //not feasible
                        dp[i][j]=dp[i-1][j];
                        
                    }
                }
            }
        }
        return dp[arr.size()][sum];
        
    }
};
