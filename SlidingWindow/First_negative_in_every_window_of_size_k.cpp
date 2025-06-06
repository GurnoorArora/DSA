//https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
//The problem was- an array is given and an integer K is given, K is the size of the window, in every K sized window we had to find the first negative number and store it in a vector which to be returned. In Case, if a negative number is not present in the window then 0 is to be pushed to the vector
//Example-arr[] = [-8, 2, 3, -6, 10] , k = 2
//Output: [-8, 0, -6, -6]
/*
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.
*/

/*Approach-
Clearly this is a sliding window question that too the size of the window is fixed

so the main idea is to slide the K sized window and in each window we need to extract the first negative number, So we need to think in a way that without iterating in each K sized window and then finding what's the negative number(this is a bit redundant) because
for example if the example was like 1 2 -4 3 2 -1 and K=3 then for the window 1 2 -4 the the first negative value would be -4 and similarly for the window 2 3 -4 (-4 is the first negative) -4 3 2 (again -4) so we dont really should check all three times only to end up as having
-4. So what would be the possibly an optimal approach

//Okay let's think in order and then we'll build up on it
//what we really need to do is dont let go of the negative number if it could be the first negative number in order windows too //this is the crux idea so that would mean we should store that number right? okay this would be the first clue
//now when a number possibly cant be the first negative number in some other window(see if it was the first negative in first window for sure if its there in other window that number will be the first negative in that too)
//it wont be the first negative for the other window if we let go of the number while sliding the window(okay this is the second clue)
//also the negative number which is stored first will be the first to go out also while sliding the window(so this hints me to use a  QUEUE)
//so we set our standard sliding window template that goes like:
  while(end<size)
  {
    //some calculation
    //if(windw==K)
    {
      //store the result
    }

    //move the window
  }

  here the calculation part would be storing the negative numbers we encounter while expanding the window

  and if the window expanded till k now we check the first element of the queue that is out first negative number and hence we store it
  //now the part should we let go of this negative number? okay that depends on if the slided window excludes that number or not that means we move our begin pointer if begin pointer in the previous window was the first negative number which we stored, if we
  //move the window that element would go out right so we will remove it from the queue.
  //now it might also be possible that the queue is empty that would mean there is no negative number in the window in that case we'll push 0 in our result vector

  That's it

*/

//code-
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int begin=0;//starting pointer
        int end=0;//ending pointer
        int n=arr.size();//size of the array
        vector<int> result;//this is the result to be returned
        queue<int> q;
        while(end<n)
        {
            //calculation(to check if the number is negative we would add it in the queue)
            if(arr[end]<0)
            {
                q.push(arr[end]);
            }
            
            //now we check if the window size hits k
            if(end-begin+1==k)
            {
                if(!q.size())
                {
                    result.push_back(0);
                    
                }
                else
                {
                    result.push_back(q.front()); 
                     if(q.front()==arr[begin]) q.pop();
                }
            
                
               
                begin++;
                
            }
            end++;
        }
        return result;
        
    }
};
