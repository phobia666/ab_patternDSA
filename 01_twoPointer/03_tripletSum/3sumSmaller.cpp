#include <bits/stdc++.h>
using namespace std;


//support target as positive
void threeSum(vector<int> a, int target){
    vector<vector<int>> ans;
    int len = a.size();
    int sum = 0;
    sort(a.begin(), a.end());
    int elem = a[0];

    for(int i = 0; i < len - 2; i++){
        if(i > 0){
            if(elem == a[i]) continue;
            elem = a[i];
        }

        int right = len - 1;
        int left = i + 1;

        while(left < right){
            sum = a[left] + a[right];
            if(sum == target - a[i]){
                left++;
                right--;
            }
            else if(sum > target - a[i]){
                right--;
            }
            else{
                int rightTemp = right;
                while(left < rightTemp){
                    ans.push_back({a[i], a[left], a[rightTemp]});
                    rightTemp--;
                }
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

int main() {
    vector<int> a = {-1, 1, 2, 0, 3, 4, 1, 5, 7};
    int target = 4;

    threeSum(a, target); 
}