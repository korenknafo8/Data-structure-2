#ifndef HEAP_H
#define HEAP_H
#include "road.h"

class Heap
{
private:
	const int NO_BRIDGE = -1;
	Road*** roads_arr_ptr_;
	int* roads_indexes_;
	int log_size_ = 0;
	int size_;

public:
	Heap(int size, Road*** roads_arr_ptr) { size_ = size; roads_indexes_ = new int[size]; roads_arr_ptr_ = roads_arr_ptr; };
	void setSize(int size) { size_ = size; };
	void insert(int	road_index);
	void fixHeap(int new_road_index);
	void updateRoad(int new_road_index);
	void heapSwap(int father, int son);
	float getMaxVal() { return (*roads_arr_ptr_[roads_indexes_[0]])->getMin(); };
	int getMaxRoad() { return roads_indexes_[0] + 1; };
};

#endif // !HEAP_H