#include<iostream>
#include<vector>
using namespace std;
string  firstnonrepeating(string str){
    vector<int>mp(52,0); // as there are only 26 lowercase alphabet and 26 uppercase alphabets
    int n = str.size();
    // storing  the frequency of each character in the string 
    for(int i=0;i<n;i++){
        //first 0 to 25 blocks are for the storing the frequency of the lowercase and next blocks are for the uppercase
       if(islower(str[i])){
        mp[str[i]-'a']++;
       }else{
        mp[str[i]-'A'+26]++;
       }
    }
    //again traversing the string and the aim is if the any character frequency is 1 if yes we return that particular character.
    for(int i=0;i<n;i++){
        // first checking is it is lowercase and if  yes then check its freequency is it is 1 or same for the uppercase
        if((islower(str[i]) && mp[str[i]-'a'] == 1) || (isupper(str[i]) && mp[str[i] -'A'+26] ==1)){
           // below statment written because we have to return the string not character.
           string ans(1, str[i]);
           return ans;
        }
    }
    return "none";
}
int main(){
    string str = "aabbcddeff";
    cout<<firstnonrepeating(str)<<endl;
}
