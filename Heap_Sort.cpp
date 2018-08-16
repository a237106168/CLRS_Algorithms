#include<iostream>
#include<vector>

using namespace std;

void main() {
	void Heap_Sort(vector<int> &);
	vector<int> nums{ 5,45,95,12,3,4,8,6,1,19 };
	Heap_Sort(nums);

	for each (auto v in nums)
	{
		cout << v << " ";
	}
	cout << endl;
}

void Max_Heapify(vector<int> &nums, int i, int heap_size) {
	int l = 2 * i, r = 2 * i + 1;
	int largest;

	if (l <= heap_size && nums[l] > nums[i]) 
		largest = l;
	else 
		largest = i;
	if (r <= heap_size && nums[r] > nums[largest])
		largest = r;

	if (largest != i) {
		int temp = nums[i];
		nums[i] = nums[largest];
		nums[largest] = temp;
		Max_Heapify(nums, largest, heap_size);
	}
}

void Build_Max_Heap(vector<int> &nums) {
	for (int i = nums.size() / 2; i >= 0; i--) 
		Max_Heapify(nums, i, nums.size() - 1);
}

void Heap_Sort(vector<int> &nums) {
	Build_Max_Heap(nums);
	int heap_size = nums.size() - 1;
	for (int i = nums.size()-1; i >= 1; i--) {
		int temp = nums[i];
		nums[i] = nums[0];
		nums[0] = temp;
		heap_size--;
		Max_Heapify(nums, 0, heap_size);
	}
}