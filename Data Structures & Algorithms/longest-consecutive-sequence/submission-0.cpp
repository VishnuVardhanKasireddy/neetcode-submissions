class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int longest = 0;
        for(int n : nums){
            if(st.find(n-1)==st.end()){
                int len = 1;
                while(st.find(n+len)!=st.end())
                    len++;

                longest = max(len,longest);
            }
        }

        return longest;
    }
};
