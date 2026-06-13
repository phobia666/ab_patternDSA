#include <bits/stdc++.h>
using namespace std;

int slide(vector<int>& a, int target){
    int k = 1;
    int n = a.size();
    int sum = 0;


    while(k < n){
        if(k == 1){
            for(int i = 0; i < n; i++){
                if(a[i] >= target){
                    return k;
                }
            }
        }
        else{
            for(int i = 0; i < n - k; i++){
            sum = 0;
            int j = i;
            int cnt = 0;
            while(cnt < k){
                sum += a[j];
                j++;
                cnt++;
            }
            
            if(sum >= target){
                return k;
            }
            
        }
        }
        k++;
    }
    return 0;
}


int main(){
    vector<int> a = {1, 0 ,3, 5, 2, 1, 4};
    int target = 10;

    cout << slide(a, target);
}