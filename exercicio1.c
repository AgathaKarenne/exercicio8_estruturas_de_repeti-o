#include <stdio.h>

int main() {
	/*Um cinema possui capacidade de 100 lugares e está sempre com ocupação total. Certo dia, cada espectador respondeu a um questionário, no qual constava:

  - sua idade;

  - sua opinião em relação ao filme, segundo as seguintes notas:*/

  /*Elabore um algoritmo que, lendo estes dados, calcule e imprima:

a quantidade de respostas ótimo;
a diferença percentual entre respostas bom e regular;
a média de idade das pessoas que responderam ruim;
a percentagem de respostas péssimo e a maior idade que utilizou esta opção;
a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim. */

	char lugares = 100;
	char opnião;
	int idade, otimoA = 0, bomB = 0, regularC = 0, ruimD = 0, pessimoE = 0;
	int idadeRuim = 0, maiorIdadeOtimo = 0, maiorIdadeRuim = 0, maiorIdadePessimo = 0;

	/*criar questionario individual*/
	printf("opnião\n");
	printf("A:otimo\n");
	printf("B:bom\n");
	printf("C:regular\n");
	printf("D:ruim\n");
	printf("E:pessimo\n");

	/*constar perguntas do questionario*/
	for (int i = 0; i < lugares; i++) {
		printf("Informe a idade do espectador %d", i);
		scanf("%d", &idade);

		printf("Informe a opinião (A, B, C, D ou E) do espectador %c", i);
		scanf(" %c", &opnião);
	}
	/*trazer a nota do espectador*/
	do {
		fflush(stdin);
		printf("opnião");
		scanf("%c", &opnião);
		/*verificar se a opnião (A, B, C, D ,E) da nota são verdadeiras e se não pode pular o codigo para a media de idade*/
	} while (opnião != otimoA, opnião != bomB, opnião != regularC, opnião != ruimD, opnião != pessimoE);

	/*verificar qual sera a resposta do espectador e tambem se é a idade maior de otimo, ruim e pessimo e repeti-la se necessario*/
	if (opnião == otimoA) {
		otimoA++;
		if (idade >= maiorIdadeOtimo)
			maiorIdadeOtimo = idade;
	}
	else if (opnião == bomB) {
		bomB++;
	}
	else if (opnião == regularC) {
		regularC++;
	}
	else if (opnião == ruimD) {
		ruimD++;
		idadeRuim = maiorIdadeRuim + idade;
		if (idade >= maiorIdadeRuim)
			maiorIdadeRuim = idade;
	}
	else if (opnião == pessimoE) {
		pessimoE++;
		if (idade >= maiorIdadePessimo)
			maiorIdadePessimo = idade;
	}

	/* diferença percentual entre respostas bom e regular */
	int diferencaPercentual = ((int)(bomB - regularC) / bomB) * 100;
	/*quantidadeB - quantidadeC / quantidadeB * lugaresDoCinema */


	/*média de idade das pessoas que responderam ruim*/
	int mediaIdadeRuim = 0;
	if (maiorIdadeRuim > 0) {
		mediaIdadeRuim = (int)idadeRuim / ruimD;
	}

	/*percentagem de respostas péssimo e a maior idade que utilizou esta opção;*/
	int percentagemPessimo = ((int)pessimoE / lugares) * 100;
	/*quantidadeE / lugaresDoCinema * 100*/

	/*diferença de idade entre a maior idade que respondeu ótimo e a maior idade que respondeu ruim.*/
	int diferençaIdade = maiorIdadeOtimo - maiorIdadeRuim;

	/*imprimir*/
	printf("\n\nQuantidade de respostas otimo: %d", otimoA);
	printf("\nDifer. perc. entre respostas bom e regular: %d%%", (bomB - regularC));
	printf("\nMedia de idade das pessoas que responderam ruim: %.2f", (idadeRuim / ruimD));
	printf("\nPercentagem de respostas pessimo: %d%%", pessimoE);
	printf("\nMaior idade que utilizou a opcao pessimo: %d", maiorIdadePessimo);
	printf("\n\nDiferenca de idade entre a maior idade que respondeu");
	printf("\notimo e a maior idade que respondeu ruim: %d", (maiorIdadeOtimo - maiorIdadeRuim));


}
