#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include <vector>

#include "runtimeexcept.hpp"

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};




template<typename Object>
class MyPriorityQueue
{
private:
	// fill in private member data here
	std::vector<Object> minHeap; // this is only here for use in a stub, you probably want to delete this.


public:

	MyPriorityQueue();

	~MyPriorityQueue();

 	size_t size() const noexcept;

	bool isEmpty() const noexcept;

	void insert(const Object & elem);

	// Note:  no non-const version of this one.  This is on purpose because
	// the interior contents should not be able to be modified due to the
	// heap property.  This isn't true of all priority queues but 
	// for this project, we will do this.
	// min and extractMin should throw PriorityQueueEmptyException if the queue is empty.
	const Object & min() const; 
	
	void extractMin(); 

private:
	int getParentIndex(const int & currIndex) const;
	
	int getLeftIndex(const int & currIndex) const;
	
	int getRightIndex(const int & currIndex) const;
	
	void percolateUp(int index);
	
	void percolateDown(int index);
};

template<typename Object>
MyPriorityQueue<Object>::MyPriorityQueue()
{
	// stub
}

template<typename Object>
MyPriorityQueue<Object>::~MyPriorityQueue()
{
	// stub
}

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return minHeap.size(); // stub
}

template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	return minHeap.empty(); // stub
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
	if(minHeap.empty())
	{
		minHeap.push_back(elem);
		return;
	}
	minHeap.push_back(elem);
	percolateUp(minHeap.size()-1);
}

template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	return minHeap.at(0);
}

template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
	if(minHeap.empty())
	{
		throw RuntimeException("EMPTY PRIORITY QUEUE");
	}
	minHeap.at(0) = minHeap.at(minHeap.size()-1);
	minHeap.pop_back();
	percolateDown(0);
}

template<typename Object>
int MyPriorityQueue<Object>::getParentIndex(const int & currIndex) const
{
	return (currIndex-1) / 2;
}

template<typename Object>
int MyPriorityQueue<Object>::getLeftIndex(const int & currIndex) const
{
	return currIndex * 2 + 1;
}

template<typename Object>
int MyPriorityQueue<Object>::getRightIndex(const int & currIndex) const
{
	return currIndex * 2 + 2;
}

template<typename Object>
void MyPriorityQueue<Object>::percolateUp(int index)
{
	while(0 < index)
	{
		int parentIndex = getParentIndex(index);
		if(minHeap.at(index) < minHeap.at(parentIndex))
		{
			std::swap(minHeap.at(index), minHeap.at(parentIndex));
			index = parentIndex;
		}
		else 
		{
			return;
		}
	}
}

template<typename Object>
void MyPriorityQueue<Object>::percolateDown(int index)
{
	if(isEmpty()) return;
	int childIndex = getLeftIndex(index);
	Object val = minHeap.at(index);
	while(childIndex < minHeap.size())
	{
		Object minVal = val;
		int minIndex = -1;
		for(int i = 0; i < 2 && i + childIndex < minHeap.size(); ++i)
		{
			if(minHeap.at(i + childIndex) < minVal)
			{
				minVal = minHeap.at(i + childIndex);
				minIndex = i + childIndex;
			}
		}
		if(!(minVal < val) && !(val < minVal))
		{
			return;
		}
		else 
		{
			std::swap(minHeap.at(index), minHeap.at(minIndex));
			index = minIndex;
			childIndex = getLeftIndex(childIndex);
		}
	}
}

#endif 
