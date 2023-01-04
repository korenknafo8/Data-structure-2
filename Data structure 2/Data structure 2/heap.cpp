#include "heap.h"

void Heap::insert(int road_index)
{
	heapSwap(roads_indexes_[size_ - log_size_ - 1], road_index);
	log_size_++;
	updateRoad(size_ - log_size_ - 1);
}

void Heap::fixHeap(int new_road_index)
{
	int runner = new_road_index, father;
	float father_value, son_value;
	bool is_fixed = false;

	while (runner != 0 && !is_fixed)
	{
		father_value = (*roads_arr_ptr_[roads_indexes_[(runner - 1) / 2]])->getMin();
		son_value = (*roads_arr_ptr_[roads_indexes_[runner]])->getMin();
		if (father_value < son_value && father_value != NO_BRIDGE)
		{
			father = (runner - 1) / 2;
			heapSwap(father, runner);
			runner = father;
		}
		else
			is_fixed = true;
	}
}

void Heap::updateRoad(int new_road_index)
{
	int son, runner = new_road_index;
	float son_val;
	bool is_fixed = false;
	while (!is_fixed)
	{

		son = 2 * runner + 1; //get left son
		if (son <= log_size_)
		{
			son_val = (*roads_arr_ptr_[roads_indexes_[son]])->getMin(); //left son val
			if (son + 1 <= log_size_)
			{
				if (son_val < (*roads_arr_ptr_[roads_indexes_[son + 1]])->getMin()) //right son val compares to left
				{
					son++; //make left son become right son
					son_val = (*roads_arr_ptr_[roads_indexes_[son]])->getMin(); //right son val
				}
			}
			if (son_val > (*roads_arr_ptr_[roads_indexes_[runner]])->getMin()) //son val compares to father val
			{
				heapSwap(son, runner);
				runner = son;
			}
			else
				is_fixed = true;
		}
		else
			is_fixed = true;
	}
}

void Heap::heapSwap(int father, int son)
{
	int temp = roads_indexes_[father];
	roads_indexes_[father] = roads_indexes_[son];
	roads_indexes_[son] = temp;
	(*roads_arr_ptr_[roads_indexes_[father]])->setHeapIndex(son);
	(*roads_arr_ptr_[roads_indexes_[son]])->setHeapIndex(father);
}