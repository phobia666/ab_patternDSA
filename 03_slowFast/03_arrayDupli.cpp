#include <bits/stdc++.h>
using namespace std;

int Dupli(vector<int> a){
    int n = a.size();
    bool isCycle = false;

    int slow = 0, fast = 0;

    while(fast < n && a[fast] < n){
        slow = a[slow];
        fast = a[a[fast]];
        if(a[slow] == a[fast]){
            isCycle = true;
            break;
        }
    }

    if(isCycle){
        slow = 0;
        while(slow != fast){
            slow = a[slow];
            fast = a[fast];
        }
        return slow;
    }
    else{
        return NULL;
    }
}

int main(){
    vector<int> a = {1, 4, 2, 3, 4};
    cout << Dupli(a);
}