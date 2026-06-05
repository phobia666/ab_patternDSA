#include <bits/stdc++.h>
using namespace std;

void threeSum(vector<int> a, int len){
    vector<vector<int>> ans;
    int left = 1; 
    int right = len - 1;

    for(int i = 0; i < len - 2; i++){
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
    vector<int> a = {-1, -1, 0, 1, 2, 4};
    int len = a.size();
    threeSum(a, len);
}