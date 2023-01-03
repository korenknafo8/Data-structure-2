#include "heap.h"

void Heap::insert(int road_index)
{
	roads_indexes_[log_size_] = road_index;
	log_size_++;
}

void Heap::fixHeap()
{
	int runner = log_size_-1, father_value,son_value, father;
	bool is_fixed = false;
	while (runner != 0 && !is_fixed)
	{
		father_value = roads_arr_ptr_[roads_indexes_[(runner - 1) / 2]]->getMin();
		son_value = roads_arr_ptr_[roads_indexes_[runner]]->getMin();
		if (father_value < son_value)
		{
			father = (runner - 1) / 2;
			heapSwap(father, runner);
			runner = father;
		}
		else
			is_fixed = true;
	}
}
void Heap::fixHeapDown(int new_road_index)
{
	int runner = new_road_index, father_value, son_l_value, son_r_value;
	bool is_fixed = false;
	while (!is_fixed)
	{
		if (2*runner+1 <= log_size_)
		{
			son_l_value = roads_arr_ptr_[roads_indexes_[2*runner+1]]->getMin();
			if (2*runner+2 <= log_size_)
			{
				son_r_value = roads_arr_ptr_[roads_indexes_[2*runner+2]]->getMin();
				if (son_l_value > son_r_value)
				{

				}
			}

		}
		
		father_value = roads_arr_ptr_[roads_indexes_[runner]]->getMin();
		if (father_value < son_value)
		{
			father = (runner - 1) / 2;
			heapSwap(father, runner);
			runner = father;
		}
		else
			is_fixed = true;
	}
}
void Heap::heapSwap(int father,int son)
{
	int temp = roads_indexes_[father];
	roads_indexes_[father] = roads_indexes_[son];
	roads_indexes_[son] = temp;
	roads_arr_ptr_[roads_indexes_[father]]->setHeapIndex(son);
	roads_arr_ptr_[roads_indexes_[son]]->setHeapIndex(father);

}
