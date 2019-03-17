#include "SortingSolution.h"

SortingSolution::SortingSolution()
{
}


SortingSolution::~SortingSolution()
{
}


int SortingSolution::partition(vector<int> &nums, int start, int end) {
    swap(nums[start], nums[end]);
    int pivotIndex = end;
	int pivotValue = nums[pivotIndex];
	int storeIndex = start;
	
	for (int i = start; i < end; ++i) {
		if (nums[i] <= pivotValue) {
			swap(nums[i], nums[storeIndex]);
			storeIndex++;
		}
	}
	swap(nums[storeIndex], nums[pivotIndex]); // Bug

	return storeIndex; // Bug 
}

void SortingSolution::qs_recursive(vector<int> &nums, int start, int end) {
	if (end > start) {
		int pivotIndex = partition(nums, start, end);
		qs_recursive(nums, start, pivotIndex - 1);
		qs_recursive(nums, pivotIndex + 1, end);
	}
}

void SortingSolution::quick_sort(vector<int> &nums) {
	qs_recursive(nums, 0, (int)nums.size() - 1);
}

void SortingSolution::max_heapify(vector<int> &nums, int start, int end) {
	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && nums[son + 1] > nums[son]) // Bug: could not change && order
			son++;
		if (nums[son] > nums[dad]) {
			swap(nums[son], nums[dad]);
			dad = son;
			son = dad * 2 + 1; // while end condition should be decided by this
		}
		else
			return;
	}
}

void SortingSolution::heap_sort(vector<int> &nums) {
	int len = (int)nums.size();
	for (int i = len / 2 - 1; i >= 0; i--) { // Bug: i-- instead of ++
		max_heapify(nums, i, len - 1);

	}
	for (int i = len - 1; i > 0; i--) {
		swap(nums[i], nums[0]);
		max_heapify(nums, 0, i - 1);
	}
}

void SortingSolution::merge_sort(vector<int> &nums) {
    int len = (int)nums.size();
    int *b = (int*)malloc(len * sizeof(int));
    for (int gap = 1; gap < len; gap *= 2) {
        for (int i = 0; i < len - 1; i += gap * 2) { // len - 1?
            int start = i;
            int k = start;
            
            int j = i + gap;
            int endi = min(j-1, len-1);
            int endj = min(j+gap-1, len-1);
            while (i <= endi && j <= endj) {
                if (nums[i] <= nums[j]) b[k++] = nums[i++];
                else b[k++] = nums[j++];
            }
            while (i <= endi) b[k++] = nums[i++];
            while (j <= endj) b[k++] = nums[j++];
            
            for (int idx = start; idx <= endj; idx++) // bug 1. wrong position; 2. idx <= endj
                nums[idx] = b[idx];
            
            i = start;
        }
    }
        
    delete b;
}
