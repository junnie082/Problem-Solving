#include <stdio.h>

int binarySearch(int arr[], int start, int end, int num){
	int mid = ( start + end ) / 2; 

	if (arr[mid] ==  num) {
		return mid;
	}
	if (arr[mid] > num) {
		end = mid - 1;
		binarySearch(arr, start, end, num);
	} else if (arr[mid] < num) {
		start = mid + 1;
		binarySearch(arr, start, end, num); 
	} 

}

int main()
{
	int arr[10] = {3, 6, 7, 10, 15, 78, 89, 99, 100, 200};
	
	printf("%d\n", binarySearch(arr, 0, 9, 10));
}