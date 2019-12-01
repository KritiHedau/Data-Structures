#include<stdio.h>
#include<stdlib.h>

struct Array {
	int* A;
	int size;
	int length;
};
void Display(struct Array arr) {
	int i;
	for (i = 0; i < arr.length; i++) {
		printf("\t%d", arr.A[i]);
	}
}

void Append(struct Array* arr, int x) {

	if (arr->length < arr->size)
		arr->A[arr->length++] = x;

}

void Insert(struct Array* arr, int value, int index) {

	int i;
	if (index >= 0 && index <= arr->length) {
		for (i = arr->length; i > index; i--) {
			arr->A[i] = arr->A[i - 1];
		}
		arr->A[i] = value;
		arr->length++;
	}
}

void Delete(struct Array* arr, int index) {

	int x, i;
	if (index >= 0 && index < arr->length) {
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++) {
			arr->A[i] = arr->A[i + 1];
		}

		arr->length--;
	}
}

int main()
{
	struct Array arr;
	int n, i, value, index;
	
	printf("Enter size of array:");
	scanf_s("%d", &arr.size);
	printf("Enter number of elements you want to enter:");
	scanf_s("%d", &n);
	arr.A = (int*)malloc(arr.size * sizeof(int));
	arr.length = n;

	printf("Enter elements in array:");
	for (i = 0; i < arr.length; i++) {
		scanf_s("\t%d", &arr.A[i]);
	}
	printf("Enter the value to insert and index to insert in:");
	scanf_s("%d%d", &value, &index);

	Append(&arr, 6);
	//Display(arr);
	Insert(&arr, value, index);
	Display(arr);
	Delete(&arr, index);
	printf("\n");
	Display(arr);

	return 0;
}
