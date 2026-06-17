#include <bits/stdc++.h>
using namespace std;

int slide(string s, int target){
    int n = s.size();
    map<char, int> mpp;
    int low = 0, high = 0, len = 0, k = 0;
    char ch;
    int ans = 0;

    

    while(high < n){
        if(mpp.find(s[high]) == mpp.end()){
            mpp.insert({s[high], 1});
        }
        else{
            mpp[s[high]]++;
        }
        len = mpp.size();
        if(len == 1){
            ch = s[high];
            ans = max(ans, mpp[ch]);
        }
        else{
            if(s[low] == ch){
                low = high;
            }
            mpp.erase(s[high]);
            if(k < target){
                mpp[ch]++;
                ans = max(ans, mpp[ch]);
                k++;
            }
            else{ // abort
                mpp.erase(ch);
                mpp.insert({s[low], 1});
                high = low;
                k = 0;
                ch = s[low];
            }
        }
        high++;
    }
    return ans;
}

int main(){
    string s = "abacdef";
    int target = 1;
    
    cout << slide(s, target);
}