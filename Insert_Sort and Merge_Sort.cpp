#include<iostream>
#include<vector>
using namespace std;

void main()
{
	void insertion_sort(vector<int> &, bool ascending = true);
	void merge_sort(vector<int> & nums, int begin, int end, bool ascending = true);

	//test
	vector<int> nums = { 5, 7, 19, 4, 3, 27, 9, 10, 12, 56, 1 };
	for each (auto p in nums)
		cout << p << " ";
	cout << endl;

	insertion_sort(nums);
	for each (auto p in nums)
		cout << p << " ";
	cout << endl;

	vector<int> nums1 = { 5, 7, 19, 4, 3, 27, 9, 10, 12, 56, 1 };
	merge_sort(nums1, 0, nums1.size() - 1, false);
	for each (auto p in nums1)
		cout << p << " ";
	cout << endl;
}


#ifndef insertion_sort	//default: ascending

void insertion_sort(vector<int> & nums, bool ascending = true)
{
	for (int i = 1; i < nums.size(); i++)
		for (int j = 0; j < i; j++)
			if (ascending)
			{
				if (nums[i] < nums[j])
				{
					nums.insert(nums.begin() + j, nums[i]);
					nums.erase(nums.begin() + i + 1);
				}
			}
			else
			{
				if (nums[i] > nums[j])
				{
					nums.insert(nums.begin() + j, nums[i]);
					nums.erase(nums.begin() + i + 1);
				}
			}
}
#endif // !insertion_sort


#ifndef merge_sort	//default: ascending

void merge(vector<int> & nums, int begin, int mid, int end, bool ascending = true) {
	vector<int> R_nums, L_nums;
	for (int i = begin; i <= mid; i++)
		L_nums.push_back(nums[i]);
	for (int j = mid + 1; j <= end; j++)
		R_nums.push_back(nums[j]);
	if (ascending)
	{
		L_nums.push_back(9999);
		R_nums.push_back(9999);
	}
	else
	{
		L_nums.push_back(-9999);
		R_nums.push_back(-9999);
	}

	int i = 0, j = 0;
	for (int m = begin; m <= end; m++)
	{
		if (ascending)
			if (L_nums[i] <= R_nums[j])
			{
				nums[m] = L_nums[i];
				i++;
			}
			else
			{
				nums[m] = R_nums[j];
				j++;
			}
		else
			if (L_nums[i] >= R_nums[j])
			{
				nums[m] = L_nums[i];
				i++;
			}
			else
			{
				nums[m] = R_nums[j];
				j++;
			}
	}
}

void merge_sort(vector<int> & nums, int begin, int end, bool ascending = true)
{
	if (begin < end)
	{
		merge_sort(nums, begin, (end + begin) / 2, ascending);
		merge_sort(nums, (end + begin) / 2 + 1, end, ascending);
		merge(nums, begin, (end + begin) / 2, end, ascending);
	}
}

#endif // !merge_sort
