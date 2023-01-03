#ifndef SYSTEM_H

#include "road.h"
#include "heap.h"

class System
{

private:
	const int UN_INITIALIZED = -1;
	int roads_size_;
	Road* roads_;
	int actions_size_ = UN_INITIALIZED;
	Heap heap_;


public:
	System(int roads_size);
	void AddBridge(int road, float height);


};

#endif // !SYSTEM_H
