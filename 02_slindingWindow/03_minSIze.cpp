#include <bits/stdc++.h>
using namespace std;


int slide(vector<int>& a, int target){
    int n = a.size();
    int high = 0;
    int low = 0;
    int sum = 0;
    int k = 0;
    int res = INT_MAX;

    while(high < n){
        // if(sum < target){
        //     sum += a[high];
        //     high++;
        // }
        // else if(sum >= target){
        //     sum -= a[low];
        //     k = high - low;
        //     res = min(res, k);
        //     low++;

        // }

        sum += a[high];

        while(sum >= target){
            k = high - low + 1;
            res = min(res, k);
            sum -= a[low];
            low++;
        }
        
        high++;

    }
    return res;
}

int main() {
    vector<int> a = {1, 0, 3, 5, 2, 1, 4};
    int target = 10;

    cout << slide(a, target);

}