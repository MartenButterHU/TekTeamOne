#ifndef STACK_HPP
#define STACK_HPP
template<typename T, volatile unsigned int SIZE>
class Stack
{
private:
	T stack[SIZE];
	volatile unsigned int stack_pointer = 0;
public:
	Stack();
	T pop(){return stack[--stack_pointer];}
	void push(T item){stack[stack_pointer++] = item;}
	T peek(){return stack[stack_pointer - 1];}

};

#endif // STACK_HPP
