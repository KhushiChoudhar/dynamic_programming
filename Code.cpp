// Knapsack Problem
#include <bits/stdc++.h> 
int solve(vector<int> weight, vector<int> value, int n, int maxWeight,int i,vector<vector<int>>&dp){
	if(maxWeight==0)return 0;
	if(i>=n)return 0;
	if(dp[maxWeight][i]!=-1)return dp[maxWeight][i]; 
	int a=0;
        if (weight[i] <= maxWeight) {
          a = value[i] + solve(weight, value, n, maxWeight - weight[i], i + 1,dp);
          int b = solve(weight, value, n, maxWeight, i + 1,dp);
		  return dp[maxWeight][i]=max(a,b);
        } else {
          return dp[maxWeight][i]=solve(weight, value, n, maxWeight, i + 1,dp);
        }
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(maxWeight+1,vector<int>(n,-1));
	return solve(weight,value,n,maxWeight,0,dp);
}
