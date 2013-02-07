#include "Functions.hpp"

void insertionSort(std::vector<int>& arr) {
    unsigned int i, j;
	int tmp;

    for (i = 1; i < arr.size(); i++) {
        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;

            j--;
        }
    }
}

long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return (n * factorial(n - 1));
    }
}
