#ifndef ROAD_H
#define ROAD_H
#include <iostream>
using namespace std;

	const int NO_BRIDGE = -1;
class Road
{
private:

	float min_bridge_ = NO_BRIDGE;
	float* bridges_;
	int bridge_phs_size_;
	int bridges_log_size_ = 0;
	int heap_index_;

public:
	Road(int index, int bridge_phs_size);
	void insertBridge(float new_bridge) { bridges_[bridges_log_size_] = new_bridge; bridges_log_size_++; }
	void setHeapIndex(int index) { heap_index_ = index; };
	int getHeapIndex() { return heap_index_; };
	void setMin(float new_min) { min_bridge_ = new_min; };
	float getMin() { return min_bridge_; };
	void setActionsSize(int actions_size) { bridge_phs_size_ = actions_size; };
	void printBridges();

};

#endif // ROAD_H