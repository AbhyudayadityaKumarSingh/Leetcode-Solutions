class Solution {
public:
     typedef pair<int,int> P ;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P , vector<P> , greater<P>> pq ;
        map <int,int> mp ;
        for(int &x : nums) {
            mp[x] ++ ;
        }
        for(auto &it : mp) {
            pq.push({it.second,it.first});
            if(pq.size() > k) pq.pop() ;
        }
        vector<int> ans ;
        while(!pq.empty()) {
            int ele = pq.top().second ;
            pq.pop() ;
            ans.push_back(ele) ;
        }
        return ans ;
    }
};