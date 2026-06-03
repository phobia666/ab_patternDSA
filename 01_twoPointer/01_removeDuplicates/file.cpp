#include <bits/stdc++.h>
using namespace std;


//sorted
//return the number of unique elements
//return the array with unique elements

int uniqueElems(vector<int>& arr, int len){
    int cnt = 1;
    int unique = 0;
    int pointer = 1;

    while(pointer < len){
        if(arr[unique] != arr[pointer]){
            swap(arr[unique + 1], arr[pointer]);
            unique++;
            cnt++;
        }
        pointer++;
    }
    return cnt;
}

int main(){
    vector<int> arr = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4};
    int len = arr.size();
    cout << uniqueElems(arr, len) << endl;

    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

}