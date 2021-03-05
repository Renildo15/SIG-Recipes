float ValidaQuant(float quant){
	if (quant < 0){
		return 0;
	}else if (quant == 0.000){
		return 0;
	}else{
		return 1;
	}
	return 1;
}