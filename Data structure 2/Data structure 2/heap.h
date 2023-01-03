#ifndef HEAP_H
#include "road.h"

class Heap
{
private:
	Road** roads_arr_ptr_;
	int* roads_indexes_;
	int log_size_;
	

public:
	void insert(int	road_index);
	
	void fixHeap();
	void fixHeapDown(int new_road_index);
	float getMax() { return roads_arr_ptr_[roads_indexes_[0]]->getMin(); };
	void heapSwap(int father, int son);
	

};

#endif // !HEAP_H
