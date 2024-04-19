#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int f(vector<int>& arr){
    int left = 0, right = arr.size() - 1, mid;
    int maxNumber = INT_MIN;
    while (left <= right){
        mid = left + (right - left) / 2;
        
        if (arr[left] <= arr[right]){
            maxNumber = max(maxNumber, arr[right]);
            break;
        }
        
        if (arr[mid] >= arr[left]){
            maxNumber = max(maxNumber, arr[mid]);
            left = mid + 1;
        }else{
            maxNumber = max(maxNumber, arr[right]);
            right = mid - 1;
        }
    }
    return maxNumber;
}

int main(){
    vector<int> arr = {34, 55, -67, 1, 2 ,3};
    cout << f(arr);
    
    return 0;
}