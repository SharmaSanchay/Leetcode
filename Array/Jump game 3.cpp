// Problem link -> https://leetcode.com/problems/jump-game-iii/description/
//Apporach 1: DFS( visited array)
class Solution {
public:
    int n;
    bool solve(vector<int>&arr,int start,vector<bool>&visited){
        if(start>=n || start < 0){
            return false;
        }
        if(visited[start]){
            return false;
        }
        visited[start] = true;
        if(arr[start] == 0){
            return true;
        }
        return solve(arr,start+arr[start] , visited) ||  solve(arr,start-arr[start],visited);
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vector<bool>visited(n,false);
        return solve(arr,start,visited);
    }
};
//Approach 2: DFS( without visited array inplace visit)
class Solution {
public:
    int n;
    bool solve(vector<int>&arr,int start){
        if(start>=n || start < 0 || arr[start] == -1){
            return false;
        }
        if(arr[start] == 0){
            return true;
        }

        int temp = arr[start];
        arr[start] = -1;
        return solve(arr,start+temp ) ||  solve(arr,start-temp);
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        return solve(arr,start);
    }
};
