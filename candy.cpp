class Solution {
public:
    int candy(vector<int>& rating) {
        if(rating.size() ==1){
            return 1;
        }
        vector<int>candies(rating.size(),1);
        // traversing left to right
        for(int i=1;i<rating.size();i++){
            if(rating[i-1] < rating[i]){
                candies[i] = candies[i-1] + 1;
            }
        }
        //  traversing right to left
        for(int i=rating.size()-2;i>=0;i--){
            if(rating[i] >  rating[i+1]){
                cout<<"i am talking about"<<i<<endl;
                candies[i] = max(candies[i] ,candies[i+1]+1);
            }
        }
        // traversing in both direction we said neighbour so neighbour is on right and left also 
        int total_candies=0;
        for(int i=0;i<candies.size();i++){
            total_candies+=candies[i];
        }
        return total_candies;
    }
};