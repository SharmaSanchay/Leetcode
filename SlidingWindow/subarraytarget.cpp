#include<iostream>
#include<vector>
using namespace std;
vector<int>MaxSubarray(vector<int>&arr,int S){
    int n = arr.size();
    int e=0,s=0; // making two pointer intially both are standing on the 0 index;
    int currsum=0;//this variable holds the current sum till now we get intially 0
    while(e<n){
        currsum+=arr[e];
        while(currsum>S){   
            // if we get the current sum more the S then there is no point to go beyond that because the sum will inceease as all the numbers are postive
            currsum-=arr[s];
            s++;
        }
        if(currsum == S){
            // if we the subarray whose sum equal to the S
            return {s+1,e+1};
        }
        e++;
    }
    return {-1,-1};

}
int main(){
    vector<int>arr{1, 2, 3, 7, 5};
    int S=12;
}