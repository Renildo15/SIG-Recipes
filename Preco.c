///Funções de validaçaõ feita por mim mesmo
int validaReal(int real){
	if(real <= 0){
		return 0;
	}else{
		return 1;
	}
}


int validaCentavo(int centavo){
	if (centavo <= 0 || centavo > 99){
		return 0;
	}else{
		return 1;
	}
	return 0;
}

