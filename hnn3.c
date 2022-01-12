#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)  {
// This function uses binary search to look for the element in an array and returns the index of the element. If the element is not located in the array, the function will return -1	
	
	if (l <= r) {
		int m = 1 + (r - 1) / 2;
	
		// check if the element is located in the middle index of the array
		if (arr[m] == x) {
			return m;
		}
		
		// check if the element is smaller than the middle index of the array, then search the left half of the array
		if (arr[m] > x) {
			return binarySearch(arr, l, m - 1, x);
		}
		
		// check if the element is larger than the middle element of the array, then search the right half of the array
		if (arr[m] < x) {
			return binarySearch(arr, m + 1, r, x);
		}
	}
	// if element is not found in the array, then return -1
	return -1;
}

int main(void) {
	int arr[] = {2, 3, 4, 10, 40};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 4;
	int result = binarySearch(arr, 0, n - 1, x);
	(result == -1)? printf("Element is not found in array.")
		      : printf("Element is found at index %d", result);
	
	return 0;
}
