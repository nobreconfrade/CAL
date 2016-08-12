#include <iostream>
int fib(int n){
	int resposta = 1, ult = 1, penult = 1;
	if (n == 0 || n == 1)
		return 1;
	else{
		for(int i = 2 ; i <= n ; i++){
			resposta = ult + penult;
			penult = ult;
			ult = resposta;
		}
		return resposta;
	}
}

int main(){
	int pos;
	std::cout<<"Escolha uma posicao do Fibonacci:\n";
	std::cin>>pos;
	std::cout<<"O numero é:"<<fib(pos)<<"\n";
	return 0;
}