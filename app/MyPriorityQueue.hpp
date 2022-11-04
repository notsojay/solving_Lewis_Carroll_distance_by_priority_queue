#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

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
	Object o; // this is only here for use in a stub, you probably want to delete this.


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
	return 500; // stub
}

template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	return true; // stub
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
	// stub
}

template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	return o; // terrible idea, don't actually do this.
}

template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
	// stub
}


#endif 
