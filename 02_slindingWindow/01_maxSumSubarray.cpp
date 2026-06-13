#include <bits/stdc++.h>
using namespace std;

int slide(vector<int>& a, int k){
    int sum = 0;
    int n = a.size();

    if(k <= n){
        for(int i = 0; i < k; i++){
            sum += a[i];
        }
    }
    else{
        return 0;
    }
    
    

    int low = 0;
    int high = k - 1;
    int res = INT_MIN;

    while(high < n){
        res = max(res, sum);
        low++;
        high++;
        if(high == n){
            break;
        }

        sum = sum - a[low - 1];
        sum = sum + a[high];

    }
    return res;


}


int main(){
    vector<int> a = {1, 0 ,3, 5, 2, 1, 4};
    int k = 3;

    cout << slide(a, k);

}