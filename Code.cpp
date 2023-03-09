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

//SUBSET SUM
#include <bits/stdc++.h> 
bool solve(vector<int>&arr,int i,int k,vector<vector<int>>&dp){
    if(k==0)return true;
    if(i==arr.size()){
        return false;
    }
    if(dp[i][k]!=-1)return dp[i][k];
    bool a=false;
    if (arr[i] <= k) {
      a = solve(arr, i + 1, k - arr[i],dp);
    }
      bool b=solve(arr, i + 1, k, dp);
      return dp[i][k]=a|| b;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return solve(arr,0,k,dp);
}
// Tabulation
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    dp[0][arr[0]]=1;
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool a ;
            if(arr[i]<=j){
                a=dp[i-1][j-arr[i]];
            }
            bool b=dp[i-1][j];
            dp[i][j]= a || b;
        }
    }
    return dp[n-1][k];
}

//Kth closest
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>>q;
        for(auto it: points){
            int dis=it[0]*it[0]+it[1]*it[1];
            //cout<<dis<<endl;
            q.push({dis, {it[0], it[1]}});
            if(q.size()>k)q.pop();
        }
        vector<vector<int>>ans;
        while(q.size()>0){
            ans.push_back({q.top().second.first, q.top().second.second});
            q.pop();
        }
        return ans;
    }
};

// Connect n ropes
long long connectRopes(int* arr, int n)
{
    priority_queue<long long,vector<long long>,greater<long long>>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    long long int ans=0;
    while(pq.size()>1){
        long long m=pq.top();
        pq.pop();
        long long n=pq.top();
        pq.pop();
        long long sum=m+n;
        ans+=sum;
        pq.push(sum);
    }
    return ans;
}

//EQUAL SUBSET SUM
class Solution { 
public:
bool change(vector<int>&nums,int sum,int i,vector<vector<int>>&dp){
    if(sum==0) return 1;
    if(i==nums.size()) return 0;
    if(sum<0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool a=change(nums,sum-nums[i],i+1,dp);
    bool b=change(nums,sum,i+1,dp);
    return a|| b;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto i: nums){
            sum+=i;
        }
        if(sum%2!=0) return 0;   
        int s=sum/2;
        vector<vector<int>>dp(nums.size(),vector<int>(s+1,-1));
        bool a=change(nums,s,0,dp);
        return a;
    }
};

// COUNT OF SUBSET AND A GIVEN SUM
//MINIMUM SUBSET SUM DIFFERENCE
#include <bits/stdc++.h> 
bool change(vector<int>&arr,int sum,int i,vector<vector<int>>&dp){
    if(sum==0) return 1;
    if(i==arr.size()) return 0;
    if(sum<0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    int l=change(arr,sum-arr[i],i+1,dp);
    int m=change(arr,sum,i+1,dp);
    return dp[i][sum]=l|| m;
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum=0;
	for(auto i:arr){
        sum+=i;
    }
    vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
    int mini=INT_MAX;
    for(int i=0;i<=sum/2;i++){
        bool l=change(arr,i,0,dp);
        if(l){
            mini=min(mini,abs((sum-i)-i));
        }
    }
    return mini;
}


