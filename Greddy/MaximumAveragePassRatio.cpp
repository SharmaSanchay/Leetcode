//Leetcode ->1792(https://leetcode.com/problems/maximum-average-pass-ratio/description/)
class Solution {
public:
    #define P pair<double, int> // Define a pair type with double and int

    // Function to calculate the maximum average pass ratio after adding extra students
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size(); // Number of classes
        priority_queue<P> pq;   // Max heap to store the gain in pass ratio and class index

        // Calculate the initial gain in pass ratio for each class and push it into the priority queue
        for (int i = 0; i < n; i++) {
            double currpr = (double)classes[i][0] / classes[i][1]; // Current pass ratio
            double newpr = (double)(classes[i][0] + 1) / (classes[i][1] + 1); // Pass ratio after adding one student
            double delta = newpr - currpr; // Gain in pass ratio
            pq.push({delta, i}); // Push the gain and index into the priority queue
        }

        // Distribute the extra students
        while (extraStudents--) {
            auto curr = pq.top(); // Get the class with the maximum gain in pass ratio
            pq.pop(); // Remove the top element from the priority queue
            double delta = curr.first; // Gain in pass ratio
            int idx = curr.second; // Index of the class
            classes[idx][0]++; // Increment the number of passes
            classes[idx][1]++; // Increment the number of students

            // Recalculate the gain in pass ratio for the updated class and push it back into the priority queue
            double currpr = (double)classes[idx][0] / classes[idx][1]; // Current pass ratio
            double newpr = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1); // Pass ratio after adding one student
            double deltap = newpr - currpr; // Gain in pass ratio
            pq.push({deltap, idx}); // Push the gain and index back into the priority queue
        }

        double result = 0.0; // Variable to store the total pass ratio

        // Calculate the total pass ratio
        for (int i = 0; i < n; i++) {
            result += (double)classes[i][0] / classes[i][1];
        }

        return result / n; // Return the average pass ratio
    }
};
/*
Time Complexity->O(nlogn+logn)
Space Complexity->O(N)
*/
