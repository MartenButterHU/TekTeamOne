#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "hwlib.hpp"

template<typename T, unsigned int SIZE>
class Queue
{
private:
	unsigned volatile int head_counter = 0;
	unsigned volatile int tail_counter = 0;
	T queue[SIZE];
	
	unsigned int addModular(int counter, int add){return (counter + 1) % SIZE;}
public:
	Queue(){};
	void enqueue(T item){
		if(addModular(head_counter,1) != tail_counter){
			queue[head_counter] = item;
			head_counter = addModular(head_counter,1);
		}
		else{
			hwlib::cout << "QueueException: QueueOverlow\n";
		}
	}
	
	
	T dequeue(){
		if(head_counter != tail_counter){
			unsigned int ret = tail_counter;
			tail_counter = addModular(tail_counter,1);
			return queue[ret];
		}
		else{
			hwlib::cout << "QueueException: EmptyQueue\n";
			return 0;
		}
	}
	
	T peek(){return queue[tail_counter];}

};

#endif // QUEUE_HPP
