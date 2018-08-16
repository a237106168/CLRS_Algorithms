#include<iostream>
#include<vector>

using namespace std;

void main() {
	void Quick_Sort(vector<int> &nums, int start, int end);
	vector<int> nums{ 5,45,95,12,3,4,8,6,1,19 };
	Quick_Sort(nums, 0, nums.size() - 1);

	for each (auto v in nums)
	{
		cout << v << " ";
	}
	cout << endl;
}


int partition(vector<int> &nums, int start, int end) {
	int x = nums[end];
	int iter = start;

	for (int i = start; i < end; i++) {
		if (nums[i] <= x) {
			int temp = nums[iter];
			nums[iter] = nums[i];
			nums[i] = temp;
			iter++;
		}
	}

	int temp = nums[iter];
	nums[iter] = nums[end];
	nums[end] = temp;

	return iter;
}

void Quick_Sort(vector<int> &nums, int start, int end) {
	if (nums.size() < 2)
		return;
	if (start < end) {
		int p = partition(nums, start, end);

		Quick_Sort(nums, start, p - 1);
		Quick_Sort(nums, p + 1, end);
	}
}