// Leetcode -> 1975 (https://leetcode.com/problems/maximum-matrix-sum/description/)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int row = matrix.size();
        int col = matrix[0].size();
        // count the number of negative values 
        int negativevalues=0;
        // minval is used to find the absolute minimum value in the matrix
        int minval=INT_MAX;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                // this is to count the negative values
                if(matrix[i][j]<0){
                    negativevalues++;
                }
                // find the absolute minimum value in the matrix 
                minval = min(minval,abs(matrix[i][j]));
                // find the sum of all the element in the matrix with their absolute value
                sum+=abs(matrix[i][j]);
            }
        }
    /* if the number of neagative value are even then we can make all negative
     value postive easily just by multipling the number by -1 as mentioned in the question */
        if(negativevalues%2 == 0){
            return sum;
        }
    /*
    if the number of negative value are odd then we left a atleast with a one negative level in the matrix 
    so we convert the minimum number to negative number and we substract the twice of min number from the original sum 
    */
        return (sum-2*minval); 
    }
};
/*
N-> number of row , M-> number of column
Time Complexity->O(N*M)
Space Complexity->O(1)
*/
