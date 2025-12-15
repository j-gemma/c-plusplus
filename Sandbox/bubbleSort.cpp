#include "bubbleSort.h"


int bubbleSort(int arr[], int size) {

	for (int j{}; j + 1 < size; ++j) {
		[[maybe_unused]]bool swap{ false };
		for (int k{}; k + 1 < size - j; ++k) {
			if (arr[k] > arr[k + 1]) {
				std::swap(arr[k], arr[k + 1]);
				swap = true;
			}
		}
		if (!swap) return j + 1;
	}
	return size;
}

void printArray(int arr[], int size) {

	std::cout << "Sorted array: (";

	for (int i{}; i < size - 1; ++i) {
		std::cout << std::format("{}, ", arr[i]);
	}

	std::cout << std::format("{})\n", arr[size - 1]);

	return;

}

int runBubbleSort() {

	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	int size{ std::size(array) };

	int numLoops{ bubbleSort(array, size) };
	printArray(array, size);
	std::cout << std::format("Early termination on iteration {}.\n", numLoops);
	return  0;

}