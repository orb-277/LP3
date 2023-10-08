#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSackRec(int W, int wt[], int val[], int n,int dp[][1001]) 
    { 
       if(n == 0 || W == 0){
           return 0;
       }
       if(dp[n][W] != -1){
           return dp[n][W];
       }
       if(wt[n-1] <= W){
           
          dp[n][W] = std::max(val[n-1]+knapSackRec(W-wt[n-1],wt,val,n-1,dp),knapSackRec(W,wt,val,n-1,dp));
          return dp[n][W];
       }
       else{
           dp[n][W] = knapSackRec(W,wt,val,n-1,dp);
           return dp[n][W];
       }
    }
    int knapSack(int W, int wt[], int val[], int n)
{
    // double pointer to declare the
    // table dynamically
    int  dp[1001][1001];
    

 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i+1][j+1] = -1;
    return knapSackRec(W, wt, val, n, dp);
}
};

int main() {
    int n; // Number of items
    cin >> n;

    int W; // Maximum weight capacity of the knapsack
    cin >> W;

    int wt[n]; // Array to store the weights of the items
    int val[n]; // Array to store the values of the items

    // Input weights of the items

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    // Input values of the items


    Solution obj;

    // Calculate the maximum value using knapsack
    int maxValue = obj.knapSack(W, wt, val, n);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
