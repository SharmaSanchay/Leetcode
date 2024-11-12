// Leetcode -> 2070 (https://leetcode.com/problems/most-beautiful-item-for-each-query/)
class Solution {
public:

    int BinaryBeauty(vector<vector<int>>& items, int queryPrice) {
        int l = 0;
        int r = items.size()-1;

        int mid;
        int maxBeauty = 0;

        while(l <= r) {
            mid = l + (r-l)/2;

            if(items[mid][0] > queryPrice) {
                r = mid-1; //ignore current and right side items. Move to left now.
            } else {
                maxBeauty = max(maxBeauty, items[mid][1]);
                l = mid+1;
            }
        }

        return maxBeauty;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        int m = queries.size();

        vector<int> result(m);

        //step-1 : Sort the array based on price in ascending order
        sort(begin(items), end(items)); //{pricei, beautyi}
        
        // step2:Inserting the max Beauty till that particular item
        int maxBeauty = items[0][1];
        for(int i = 1; i < n; i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }


        for(int i = 0; i < m; i++) {
            int queryPrice = queries[i];
            result[i] = BinaryBeauty(items, queryPrice);
        }

        return result;

    }
};
/*
Time Complexity ->  O(nlogn + n + mlogn)
Space Complexity -> O(1)
*/