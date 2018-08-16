#include<vector>
#include<iostream>

using namespace std;

void main(){
	vector<int> nums{ 5,45,95,12,3,4,8,6,1,19 };
	int max = 0;
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] > max)
			max = nums[i];

	vector<int> Count_Sort(vector<int> &nums, const int& max);
	vector<int> results(Count_Sort(nums, max));

	for each (auto v in results)
	{
		cout << v << " ";
	}
	cout << endl;
}

vector<int> Count_Sort(vector<int> &nums, const int& max) {
	vector<int> C(max + 1);
	vector<int> B(nums.size());

	for (int i = 0; i < nums.size(); i++) 
		C[nums[i]] = C[nums[i]] + 1;

	for (int i = 1; i <= max; i++)
		C[i] = C[i] + C[i - 1];

	for (int i = nums.size() - 1; i >= 0; i--) {
		B[C[nums[i]] - 1] = nums[i];
		C[nums[i]]--;
	}

	return B;
}