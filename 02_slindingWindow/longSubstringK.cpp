#include <bits/stdc++.h>
using namespace std;

int slide(string s, int target){
    int n = s.size();
    map<char, int> mpp;
    int ans = INT_MIN;
    int k = 0, low = 0, high = 0;
    
    if(target > n) return 0;

    while(high < n){
        if(k <= target){
            if(mpp.find(s[high]) == mpp.end()){
            mpp.insert({s[high], 1});
        }
        else{
            mpp[s[high]]++;
        }
        }

        k = mpp.size();
        if(k == target){
            ans = max(ans, high - low + 1);
            high++;
        }
        else if(k > target){
            if(mpp[s[low]] == 1){
                mpp.erase(s[low]);
            }
            else{
                mpp[s[low]]--;
            }
            low++;
        }
        else{
            high++;
        }
    }
    return ans;
}


int main(){
    string s = "gigglingfigling";
    int target = 4;
    cout << slide(s, target);
}