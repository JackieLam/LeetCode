#pragma once
#include <vector>
using namespace std;

class SortingSolution
{
public:
	SortingSolution();
	~SortingSolution();
	void quick_sort(vector<int> &nums);
	void heap_sort(vector<int> &nums);
    void merge_sort(vector<int> &nums);

private:
	void max_heapify(vector<int> &nums, int start, int end);
	int partition(vector<int> &nums, int start, int end);
	void qs_recursive(vector<int> &nums, int start, int end);
};
