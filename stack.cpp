#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

struct stack
{
	int top,*arr,size;
	stack(){
		size = 5;
		top = -1;
		arr  = new int[size];
	}
	void push(int data){
		if(top==size-1){
			cout<<"Stack Overflow\n";
			return;
		}
		arr[++top] = data; 
		
	}
	int pop(){
		if(top==-1)
			return -1;
		return arr[top--]; 
	}
	void display(){
		for(int i=0;i<=top;i++)
			cout<<arr[i]<<" ";
	}
	
	
	
};


int main(int argc, char const *argv[])
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	stack mystack;
	mystack.push(10);
	mystack.push(20);
	mystack.push(30);
	mystack.push(40);
	mystack.push(50);
	


	mystack.display();

	return 0;
}
