#include <bits/stdc++.h>
using namespace std;

int shortSlide(vector<int>& a, int target){
    int n = a.size();
    int low = 0, high = 0, sum = 0;
    int res = INT_MAX;

    while(high < n){
        sum += a[high];

        while(sum > target){
            int len = high - low + 1;
            res = min(res, len);
            if(len == 1) break;
            sum -= a[low];
            low++;
        }
        high++;
    }
    return res;
}



int main() {
    vector<int> a = {30, 10, 20, 20, 60};
    int target = 50;
    cout << shortSlide(a, target);
}