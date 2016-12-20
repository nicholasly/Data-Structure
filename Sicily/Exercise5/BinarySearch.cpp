#include <iostream>
int binSearch(const int s[], const int size, const int target) {
	int high = size - 1, low = 0, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (target > s[mid]) low = mid + 1;
		else if (target < s[mid]) high = mid - 1;
		else {
			while (s[mid] == target) mid++;
			return mid;
		};
	}
	return -1;
}