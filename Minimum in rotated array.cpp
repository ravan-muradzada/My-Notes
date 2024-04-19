#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int min(int a, int b){
    return (a > b)? b: a;
}
int f(vector<int>& arr){
    int left = 0, right = arr.size() - 1, mid;
    int minNumber = INT_MAX;
    while (left <= right){
        mid = left + (right - left) / 2;
        
        if (arr[left] <= arr[right]){
            minNumber = min(minNumber, arr[left]);
            break;
        }
        
        if (arr[mid] >= arr[left]){
            minNumber = min(minNumber, arr[left]);
            left = mid + 1;
        }else{
            minNumber = min(minNumber, arr[mid]);
            right = mid - 1;
        }
    }
    return minNumber;
}

int main(){
    vector<int> arr = {34, 55, -67, 1, 2 ,3};
    cout << f(arr);
    
    
    

    return 0;
}