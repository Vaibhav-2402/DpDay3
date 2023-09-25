#include<limits.h>
int solveRec(int n, int x, int y, int z, vector<int> &dp) {
    //base case
    if( n == 0){
        return 0;
    }

    if(n < 0)
        return INT_MIN;
    
    if(dp[n] != -1)
        return dp[n];

    int a = solveRec(n-x, x, y, z, dp) + 1;
    int b = solveRec(n-y, x, y, z, dp) + 1;
    int c = solveRec(n-z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b,c));
    return dp[n];
}

int solveTab(int n, int x, int y, int z) {
    vector<int> dp(n+1, -1);

    dp[0] = 0;

    for(int i = 1; i <= n; i++) {
        if(i-x >= 0 && dp[i-x] != -1)
            dp[i] = max(dp[i], 1+dp[i-x]);

        if(i-y >= 0 && dp[i-y] != -1)
            dp[i] = max(dp[i], 1+dp[i-y]);

        if(i-z >= 0 && dp[i-z] != -1)
            dp[i] = max(dp[i], 1+dp[i-z]);
    }
    if(dp[n] < 0)
        return 0;
    else 
        return dp[n];
}

int cutSegments(int n, int x, int y, int z) {
    //vector<int> dp(n+1, -1);
	//int ans = solveRec(n, x, y, z, dp);

    /*if(ans < 0)
        return 0;
    else 
        return ans;*/

    int ans = solveTab(n , x, y, z);
    return ans;
}