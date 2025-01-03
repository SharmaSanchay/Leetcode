//Leetcode-> 451(https://leetcode.com/problems/sort-characters-by-frequency/description/)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for (char str : s) {
            // first we make a map which store the occurance and character
            mpp[str]++;
        }
        // map holds the character and their occurance but not in the increasing so to do this we pushed onto the priority queue
        // which holds the character and occurance in the decreasing format
        priority_queue<pair<int, char>> pq;
        for (auto val : mpp) {
            pq.push({val.second, val.first});
        }
        string str = "";
        while (!pq.empty()) {
            pair<int, char> temp = pq.top();
            int checker = temp.first;
            // one more loop is because we have to add the character occurance how many time they occured in strng(s);
            while (checker) {
                str += temp.second;
                checker--;
            }
            pq.pop();
        }
       return str;
    }
};
/*
Time Complexity->O(NlogN)
Space Complexity->O(N)
*/









