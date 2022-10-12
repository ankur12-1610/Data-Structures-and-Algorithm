#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int left, int right, int key)
{
   while(left<=right)
   {
     int mid=left + (right - left) / 2;
     if (a[mid] < key)
     {
         left=mid+1;
     }
     else if (a[mid] > key)
     {
         right=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;                //key not found
 }

int main() {

    int n;
    cout << "Enter the number of elements in the array: " << "\n";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: " << "\n";

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int k;
    cout << "Enter the key element to be searched for in the array: " << "\n";
    cin >> k;
    
    sort(arr, arr+n);
    cout << binarySearch(arr,0,n-1,k) << "\n";
    
}
