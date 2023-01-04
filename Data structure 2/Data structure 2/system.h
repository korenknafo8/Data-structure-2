#ifndef SYSTEM_H
#define SYSTEM_H

#include "road.h"
#include "heap.h"

class System
{
private:
	const int NO_BRIDGE = -1;
	int roads_size_;
	int actions_size_;
	Road** roads_;
	Heap heap_;

public:
	System(int roads_size, int actions_size);
	void AddBridge(float height, int road);
	int WhichRoad(float height);
	void print(int road) { roads_[road - 1]->printBridges(); };
};

#endif // !SYSTEM_H
