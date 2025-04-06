// Copyright 2021 NNTU-CS
#include <unordered_map>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
        if (arr[i] + arr[j] == value) {
            count++;
        }
    }
}
return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;

while (left < right) {
	int sum = arr[left] + arr[right];
	if (sum == value) {
		count++;
		right--;
	}
	else if (sum < value) {
		left++;
	}
	else {
		right--;
	}
}

return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
std::unordered_map<int, int> num_counter;
for (int i = 0; i < len; ++i) {
    num_counter[arr[i]]++;
}
for (int i = 0; i < len; ++i) {
    int complement = value - arr[i];
    if (num_counter.count(complement)&& complement > arr[i]) {
        count += num_counter[complement];
    }
}
return count;
}
