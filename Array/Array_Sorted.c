#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct array{
	int A[10];
	int size;
	int length;
};
void Display(struct array arr) {

	int i;
	for (i = 0; i < arr.length; i++) {
		printf("\t%d", arr.A[i]);
	}
}
//insert element in a sorted array so that resulting array is also sorted
void Insert(struct array* arr, int element) {
	int i = arr->length - 1;
	while (arr->A[i] > element) {
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = element;
	arr->length++;
}
//Check if array is sorted or not
bool Algosort(struct array arr) {
	int i;
	for (i = 0; i < arr.length - 1; i++) {
		if (arr.A[i] > arr.A[i + 1])
			return false;
	}
	return true;
}
void swap(int* x, int* y) {

	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//all negatives on left side
void Negativeonside(struct array* arr) {
	int i = 0, j = arr->length - 1;
	while (i < j) {
		while (arr->A[i] < 0) { i++; }
		while (arr->A[j] >= 0) { j--;}
		if (i < j)
				swap(&arr->A[i], &arr->A[j]);
	}

}
int main() {

	struct array arr = { {-6,3,-8,10,5,-7,-9,14,-4,2}, 15, 10 };
	//Display(arr);
	//printf("\n");
	//Insert(&arr, 12);
	//Display(arr);
	//printf("\n%d", Algosort(arr));
	Negativeonside(&arr);
	Display(arr);
	printf("\n");
	Display(arr);
	
	return 0;
}