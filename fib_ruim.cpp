#include <iostream>
int fib(int n){
	if (n == 0 || n == 1)
		return 1;
	return fib(n-1) + fib(n-2);
}
int main(){
	int pos;
	std::cout<<"Escolha uma posicao do Fibonacci:\n";
	std::cin>>pos;
	std::cout<<"O numero é:"<<fib(pos)<<"\n";
	return 0;
}