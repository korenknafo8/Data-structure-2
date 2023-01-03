#ifdef ROAD_H

#endif // ROAD_H

class Road 
{
private:
	float min_bridge_;
	int arr_size_;
	float* bridges_;
	int heap_index_;

public:
	void setHeapIndex(int index) { heap_index_ = index; };
	void setMin(int min) { min_bridge_ = min; };
	float getMin() { return min_bridge_; };
	void setArrSize(int size) { arr_size_ = size; };



};
