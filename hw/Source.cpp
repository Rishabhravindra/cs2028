#include <iostream>
void merge(int*, int*, int, int*, int);
void mergeSort(int *, int);
using namespace std;
int main() {

	//replace this with your random no. arr
	int arr[] = { 2,4,1,6,8,5,3,7};  

	//calculate array size
	int size = sizeof(arr) / sizeof(arr[0]);

	//call mergeSort()
	mergeSort(arr, size);

	//output
	for (int i = 0; i < size; i++) {
		cout << arr[i]<<"\n";
	}
	return 0;
}

//function definition of merge()
void merge(int *myArr, int *left, int numL, int *right ,int numR ) {
	// i and j are used as indexes for left and right resp.
	// k is used as a tracker index for the main array
	int i = 0,
		j = 0,
		k = 0;

	//while loop to execute till all elements of either left or right array are compared
	while (i<numL && j<numR) {
		//compare the elements of left with right and 
		// assign the lower value to myArray
		if (left[i] < right[j]) {
			myArr[k] = left[i];
			i ++;
		}
		else {
			myArr[k] = right[j];
			j ++;
		}
		k++;
	}

	//After all values in left or right are compared,
	//we compare for the remaining values in the other array
	while (i<numL) {
		myArr[k] = left[i];
		i ++;
		k ++;
	}
	while (j<numR) {
		myArr[k] = right[j];
		j ++;
		k ++;
	}
}

//function definiton for mergeSort array
void mergeSort(int *myArr, int size) {
	
	//return the element if array size is 1
	if (size < 2) return;

	//determine midpoint of the array	
	int mid = size / 2;
	
	//declare arrays left and right to hold the two sections of the parent array
	int *left = new int [mid];
	int *right = new int[size - mid];
	
	//loop to insert values in left 
	for (int i = 0; i < mid; i++) {
		left[i] = myArr[i];
	}
	
	//loop to insert values in right
	for (int i = mid; i < size; i++) {
		right[i-mid] = myArr[i];
	}

	//call the mergeSort() function recursively to sort the sub arrays, left and right
	mergeSort(left, mid);
	mergeSort(right, size -mid);

	//once the main array has been broken 
	//down into the smallest possible sub-arrays,
	//call the merge function
	merge(myArr, left, mid, right, size - mid);

	//free up memory, after the arrays are merged
	delete(left);
	delete(right);
}