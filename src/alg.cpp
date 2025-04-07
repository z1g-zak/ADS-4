// Copyright 2021 NNTU-CS
#include <unordered_map>
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int fl = 0, point = len - 1;
  for (int i = 0; i < len - 1; ++i) {
    int j = point;
    while (i < j) {
      int sum = arr[i] + arr[j];
      if (sum == value) {
        count++;
        if (fl == 1) {
          point = j;
          fl = 0;
        }
      } else if (sum < value) {
        break;
      } else {
        fl = 1;
      }
      j--;
    }
  }
  return count;
}
int BinarySearch(int* arr, int left, int right, int value) {
  int first = -1, _left = left, _right = right;
  while (_left <= _right) {
    int mid = _left + (_right - _left) / 2;
    if (arr[mid] >= value) {
      _right = mid - 1;
      if (arr[mid] == value) first = mid;
    } else {
      _left = mid + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  _left = first;
  _right = right;
  while (_left <= _right) {
    int mid = _left + (_right - _left) / 2;
    if (arr[mid] <= value) {
      _left = mid + 1;
      if (arr[mid] == value) last = mid;
    } else {
      _right = mid - 1;
    }
  }
  return last - first + 1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    count += BinarySearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return count;
}
