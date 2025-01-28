#include<bits/stdc++.h>

using namespace std;

vector<int> calculatePrefixSum(vector<int>& nums){
    int n=nums.size();
    vector<int> prefixSum(n,0);
    prefixSum[0]=max(nums[0],0);

    for(int i=1;i<n;i++){
        prefixSum[i]=max({prefixSum[i-1]+nums[i],nums[i],0});
    }

    return prefixSum;
}
vector<int> calculateSuffixSum(vector<int>& nums){
    int n=nums.size();
    vector<int> suffixSum(n,0);
    suffixSum[n-1]=max({nums[n-1],0});

    for(int i=n-2;i>=0;i--){
        suffixSum[i]=max({suffixSum[i+1]+nums[i],nums[i],0});
    }

    return suffixSum;
}
int maxTwoNonOverlappingSubarraysum(vector<int>& nums){
    int n=nums.size();
    if(n==0)
        return 0;
    
    vector<int> prefixSum=calculatePrefixSum(nums);  // this will give, at any any index i , maximum subarray sum that ends at i(0->i)
    vector<int> suffixSum=calculateSuffixSum(nums);  // this will give , at any index i, maximum sum subarray sum that starts at i(i->n)

    vector<int> maxPrefixSum(n,0);  // this will give , at any index i , maximum sum subarray from 0 to i, that doesn't means it should end at index i.
    maxPrefixSum[0]=prefixSum[0];
    for(int i=1;i<n;i++){
        maxPrefixSum[i]=max(maxPrefixSum[i-1],prefixSum[i]);
    }
    

    vector<int> maxSuffixSum(n,0); // this will give , at any index i , maximum sum subarray from i to n, that doesn't means it should start from index i.
    maxSuffixSum[n-1]=suffixSum[n-1];
    for(int i=n-2;i>=0;i--){
        maxSuffixSum[i]=max(maxSuffixSum[i+1],suffixSum[i]);
    }


    // maximum sum of 2 non-overlapping subarrays
    int maxSum=0;
    for(int i=0;i<n-1;i++){
        maxSum=max(maxSum,maxPrefixSum[i]+maxSuffixSum[i+1]);
    }

    return maxSum;

}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<"Maximum sum of 2 non-overlapping subarrays : "<<maxTwoNonOverlappingSubarraysum(nums)<<endl;
    return 0;
}