//Leetcode -> 200 (https://leetcode.com/problems/number-of-islands)
class Solution {
public:
    int m, n; // Dimensions of the grid

    // Depth-First Search (DFS) function to explore the island
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Base case: Check for out of bounds or water ('0') cells
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '1') {
            return;
        }
        
        grid[i][j] = '$'; // Mark the current cell as visited by setting it to '$'
        
        // Recursively visit all adjacent cells (up, down, left, right)
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    // Function to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); // Number of rows
        n = grid[0].size(); // Number of columns
        int island = 0; // Counter for number of islands

        // Iterate through each cell in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') { // If the cell is land ('1')
                    dfs(grid, i, j); // Perform DFS to mark all connected land
                    island += 1; // Increment the island count
                }
            }
        }

        return island; // Return the total number of islands
    }
};
/*
Time Complexity->O(N*M)
Space Complexity->O(N*M)
*/
