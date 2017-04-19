#include <iostream>
using namespace std;

//function declaration
void quickSort(int *, int , int);
int divide(int *, int, int);
int main() {
	//sample array in descending order (worst case)
	int arr[] = { 7,6,5,4,3,2,1,0 };
	int size = sizeof(arr) / sizeof(arr[0]);

	
	quickSort(arr, 0, size-1);	
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
	return 0;
}

//defintion of quickSort() 
void quickSort(int *myArr, int start, int end) {
	if (start < end) {
	
	int divideIndex = divide(myArr, start, end);
	//call quickSort() recursively till the divided parts of the array are sorted
	quickSort(myArr, start, divideIndex - 1);
	quickSort(myArr, divideIndex + 1, end);
	}
}

//divide() function which to sort the array with 
//smaller value items to the left of the pivot and 
//larger items to the right
int divide(int *myArr, int start, int end) {
	int divideIndex = start;

	//assign rightmost element as the pivot
	int focus = myArr[end];
	
	//loop to look for elements smaller than the 
	//pivot/focus and swap them to the divide index
	for (int i = start; i < end; i++) {
		if (myArr[i] <= focus) {
			swap(myArr[i], myArr[divideIndex]);
			divideIndex++;
		}
	}
	//swap the last index to the divide index
	swap(myArr[divideIndex], myArr[end]);
	return divideIndex;
}