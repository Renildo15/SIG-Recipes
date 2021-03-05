/// adaptado de @flgorgoni,2021
int bissexto(int ano) {
  if ((ano % 4 == 0) && (ano % 100 != 0)) {
    return 1;
  } else if (ano % 400 == 0) {
    return 1;
  } else {
    return 0;
  }
}
int validacao (int dia, int mes, int ano){
	int maiorDia;
// Recebe uma data no formato (dia, mes, ano) e valida a mesma
// Retorna 1 se a data é válida ou 0 caso contrário
	if (ano < 2021 || mes < 1 || mes > 12)
		return 0;
	if (mes == 2) {
		if (bissexto(ano)) 
		maiorDia = 29;
		else
		maiorDia = 28;
	} else if (mes == 4 || mes == 6 || 
				mes == 9 || mes == 11) {
				maiorDia = 30;
	} else
		maiorDia = 31;

	if (dia < 1 || dia > maiorDia)
		return 0;

	return 1;
}
