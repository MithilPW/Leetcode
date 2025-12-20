class Solution {
public:
    int getKthlargestElement(vector<int>& nums,int n,int k){
        priority_queue<int , vector<int>,greater<int> > pq;
        //first k element ko process karo

        for(int i=0;i<k;i++){
        int element = nums[i];
        pq.push(element);
        }
        //remaining element ko tabhi insert karenge jab vo root se chotte honge
        for(int i=k;i<n;i++){
        int element = nums[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
            }
        }
        int ans = pq.top();
        return ans;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int rev = getKthlargestElement(nums,n,k);
        return rev;
    }
};