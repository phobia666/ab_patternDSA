#include <bits/stdc++.h>
using namespace std;


//support target as positive
int threeSum(vector<int> a, int target){
    int closeSum = 0;
    int diff = INT_MAX;
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
                return target;
            }
            else if(sum > target - a[i]){
                right--;
            }
            else{
                left++;
            }
            if(sum + a[i] - target < diff){
                diff = sum + a[i] - target;
                closeSum = sum + a[i];
            }
        }
    }
    return closeSum;
}

int main() {
    vector<int> a = {-1, 1, 2, 5, 7};
    int target = 4;

    cout << threeSum(a, target);
}