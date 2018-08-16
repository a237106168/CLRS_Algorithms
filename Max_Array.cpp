#include<iostream>
#include<vector>

using namespace std;

struct max_array {
	int max;
	int start;
	int end;
};

#ifndef 最大和子数组-分治策略

max_array max_cross_array(vector<int> &nums, int start, int mid, int end) {
	max_array item;

	int sum = 0, left_max = -9999;
	for (int i = mid; i >= 0; i--) {
		sum += nums[i];
		if (sum > left_max) {
			left_max = sum;
			item.start = i;
		}
	}

	sum = 0;
	int  right_max = -9899;
	for (int i = mid + 1; i <= end; i++) {
		sum += nums[i];
		if (sum > right_max) {
			right_max = sum;
			item.end = i;
		}
	}

	if (left_max >= 0 && right_max >= 0) {
		item.max = left_max + right_max;
	}
	else if (left_max >= 0 && right_max <= 0) {
		item.max = left_max;
		item.end = mid;
	}
	else if (left_max <= 0 && right_max >= 0) {
		item.max = right_max;
		item.start = mid + 1;
	}
	else if (left_max <= 0 && right_max <= 0) {
		if (left_max > right_max) {
			item.max = left_max;
			item.end = mid;
		}
		else {
			item.max = right_max;
			item.start = mid + 1;
		}
	}

	return item;
}

max_array max_array_merge(vector<int> &nums, int start, int end) {
	if (start == end) {
		max_array item;
		item.max = nums[start];
		item.start = item.end = start;

		return item;
	}

	max_array item_left, item_right, item_cross;

	item_left = max_array_merge(nums, start, (start + end) / 2);
	item_right = max_array_merge(nums, (start + end) / 2 + 1, end);
	item_cross = max_cross_array(nums, start, (start + end) / 2, end);

	if (item_left.max > item_right.max && item_left.max > item_cross.max)
		return item_left;
	else if (item_left.max < item_right.max && item_right.max > item_cross.max)
		return item_right;
	else
		return item_cross;
}
#endif // !最大和子数组-分治策略

#ifndef 最大和子数组 -O(n)方法

max_array max_array_linear(vector<int> &nums, int start, int end) {
	max_array *item = new max_array[end - start];
	item[start].max = nums[start];
	item[start].start = start;
	item[start].end = start;
	for (int i = start + 1; i <= end; i++) {
		if (item[i - 1].max < 0) {
			item[i].max = nums[i];
			item[i].start = item[i].end = i;
		}
		else {
			item[i].max = nums[i] + item[i - 1].max;
			item[i].start = item[i - 1].start;
			item[i].end = i;
		}
	}

	max_array *max = &item[start];
	for (int i = start + 1; i <= end; i++) {
		if ((*max).max < item[i].max)
			max = &(item[i]);
	}

	return *max;
}
#endif // !最大和子数组 -O(n)方法


void main() {
	vector<int> nums{ 1,2,-7,5,-4,6,-8,6,8,1,-1,8,-5,9,-8,10 };
	max_array max1 = max_array_merge(nums, 0, nums.size() - 1);
	max_array max2 = max_array_linear(nums, 0, nums.size() - 1);

	for (int i = max1.start; i <= max1.end; i++) {
		cout << nums[i] << " ";
	}
	cout << endl;
	cout << "Max of the array: " << max1.max << endl;

	//for (int i = max2.start; i <= max2.end; i++) {
	//	cout << nums[i] << " ";
	//}
	//cout << endl;
	//cout << "Max of the array: " << max2.max << endl;
}