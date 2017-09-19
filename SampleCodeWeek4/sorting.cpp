#include <iostream>
using namespace std;

void merge(int data[], int firstHalf, int secondHalf)
{
	int copied = 0, copiedFirst = 0, copiedSecond = 0, i = 0;

	int *temp = new int[firstHalf + secondHalf];

	while ((copiedFirst < firstHalf) & (copiedSecond < secondHalf)) {
		if (data[copiedFirst] < (data + firstHalf)[copiedSecond]) {
			temp[copied++] = data[copiedFirst++];
		}
		else {
			temp[copied++] = (data + firstHalf)[copiedSecond++];
		}
	}

	while (copiedFirst < firstHalf) {
		temp[copied++] = data[copiedFirst++];
	}

	while (copiedSecond < secondHalf) {
		temp[copied++] = (data + firstHalf)[copiedSecond++];
	}

	for (i = 0; i < firstHalf + secondHalf; i++) {
		data[i] = temp[i];
	}

	delete[] temp;
}

void mergeSort(int data[], int size)
{
	int firstHalf, secondHalf;

	if (size > 1) {
		firstHalf = size / 2;
		secondHalf = size - firstHalf;

		mergeSort(data, firstHalf);
		mergeSort((data + firstHalf), secondHalf);

		merge(data, firstHalf, secondHalf);
	}
}

void selectionSort(int data[], int size)
{
	int largest = 0, indxLargest;

	if (size == 0) {
		return;
	}

	for (int i = size - 1; i > 0; i--) {
		largest = data[0];
		indxLargest = 0;

		for (int j = 1; j <= i; j++) {
			if (data[j] > largest) {
				largest = data[j];
				indxLargest = j;
			}
		}

		if (i != indxLargest) {
			int tmp = data[i];
			data[i] = data[indxLargest];
			data[indxLargest] = tmp;
		}
	}
}



int main()
{
	int data[10] = { 20, 25, 35, 19, 42, 5 };

	cout << "Unsorted Data" << endl;

	for (int i = 0; i < 6; i++) {
		cout << data[i] << endl;
	}

	selectionSort(data, 6);

	cout << "Sorted Data" << endl;

	for (int i = 0; i < 6; i++) {
		cout << data[i] << endl;
	}

	system("pause");
	return 0;
}

