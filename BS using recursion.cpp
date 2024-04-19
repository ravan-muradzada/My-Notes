#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int binarySearch(vector<int>& arr, int target, int left, int right){
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] > target) return binarySearch(arr, target, left, mid - 1);
    else return binarySearch(arr, target, mid + 1, right);
}

int main(){
    vector<int> arr = {1, 2 ,3, 12, 34, 145};
    int target = 1451;
    
    cout << binarySearch(arr, target, 0, arr.size() - 1);
    
    return 0;
}