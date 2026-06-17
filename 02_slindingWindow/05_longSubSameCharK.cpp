#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& chh){
    int maxCnt = 0;

    for(int i = 0; i < chh.size(); i++){
        maxCnt = max(maxCnt, chh[i]);
    }
    return maxCnt;
}

int slide(string s, int target){
    int n = s.size();
    vector<int> chh(256, 0);
    int low = 0;
    int ans = 0;

    for(int high = 0; high < n; high++){
        chh[s[high]]++;
        int len = high - low + 1;
        int maxCnt = find(chh);
        int diff = len - maxCnt;

        while(diff > target){
            chh[s[low]]--;
            low++;
            len = high - low + 1;
            maxCnt = find(chh);
            diff = len - maxCnt;
        }
        len = high - low + 1;
        ans = max(ans, len); 
    }

    return ans;
}

int main(){
    string s = "cggdgf";
    int target = 1;
    
    cout << slide(s, target);
}