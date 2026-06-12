#include <bits/stdc++.h>
using namespace std;

void threeSum(vector<int> a, int len){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    int elem = a[0];

    for(int i = 0; i < len - 2; i++){
        int left = i + 1;
        int right = len - 1;
        if(i > 0) {
            
            if(elem == a[i]){
                continue;
            }
            
        }

        while(left < right){
            if(a[left] + a[right] == -a[i]){
                ans.push_back({a[i], a[left], a[right]});
                left++;
                right--;
                
                while(left < len - 1 &&(a[left] == a[left - 1])) left++;
                while(right > 0 &&(a[right] == a[right + 1])) right--;
            }
            else if(a[left] + a[right] > -a[i]){
                right--;
            }
            else{
                left++;
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < 3; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> a = {-1,0,1,2,-1,-4};

    int len = a.size();
    threeSum(a, len);
}