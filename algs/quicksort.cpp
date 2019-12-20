#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::swap;
using std::vector;


int partitionOne(vector<int>& nums, int start, int end) {
	int pivot = nums[end];
	int partitionIndex = start;
	for (int index = start; index < end; ++index) {
		if (nums[index] <= pivot) {
			swap(nums[index], nums[partitionIndex]);
			++partitionIndex;
		}
	}
	swap(nums[partitionIndex], nums[end]);
	return partitionIndex;
} // partition()

int partitionTwo(vector<int>&nums, int start, int end) {
	int pivot = end;
	while (true) {
		while (nums[start] < nums[pivot]) {
			++start;
		}
		while (start < end && nums[end - 1] >= nums[pivot]) {
			--end;
		}
		if (start >= end) {
			break;
		}
		swap(nums[start], nums[end - 1]);
	}
	swap(nums[start], nums[pivot]);
	return start;
}

void quick_sort(vector<int>& nums, int start, int end) {
	if (start < end) {
		int partitionIndex = partitionOne(nums, start, end);
		quick_sort(nums, start, partitionIndex - 1);	
		quick_sort(nums, partitionIndex + 1, end);

	}
} // quick_sort()

int main() {
	vector<int> nums = { 4, 1, 5, 2, 53, 54, 12, 63, 654, 531, 5, 9, 234, 1};
	
	quick_sort(nums, 0, nums.size() - 1);

	for (int num : nums) {
		cout << num << ' ';
	} // for
	cout << '\n';
	return 0;
} // main()
