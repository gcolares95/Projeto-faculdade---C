#include <stdio.h>

void removeCaixa(int *caixas, int totalCaixas) {
	int i;

	// removendo a primeira caixa do vetor caixas[]
	for(i = 0; i < totalCaixas - 1; i++){
		caixas[i] = caixas[i + 1];
	}
}
// novoVetorAvariadas(caixasAvariadasAux, qntdCaixasAvariadasAux, caixaConsertada);
void novoVetorAvariadas(int *caixasAvariadasAux, int qntdCaixasAvariadasAux, int *caixasAvariadas) {
	int i;
	
	for(i = 0; i < qntdCaixasAvariadasAux; i++) {
		caixasAvariadasAux[i + 1] = caixasAvariadas[i];
	}
	
	// copiar vetorAux para o original
	for(i = 0; i < qntdCaixasAvariadasAux; i++) {
		caixasAvariadas[i] = caixasAvariadasAux[i];
	}
}

void addCaixa(int *vetCaixas, int size, int value) {
	// adicionando a caixa mais apta no vetor caixasParaVenda[]
	vetCaixas[size] = value;
}

void imprimirCaixas(int *vetCaixas, int size) {
	int i = 0;
	
	// printf("Caixas aguardando para serem vendidas: \n", vetCaixas[i]);
	
	for(i = 0; i < size; i++) {
		printf("~~Caixa com identificador: [%d]\n", vetCaixas[i]);
	}
}

int main(void) {	
	
	int totalCaixas;	 				// Total de caixas geradas 
	int i;    	 						// Para usar no for (Repetição)  
	int instrucao;		 					// Instrução a ser seguida
	
	int caixas[5000 + 1];   			// Vetor das caixas a serem vendidas
	int caixasInvertido[5000 + 1];	    // Vetor das caixas invertida
	int caixasInvertidoAux[5000 + 1];   
    int caixasParaVenda[5000 + 1]; 		// Vetor das caixas para venda
    int caixasAvariadas[5000 + 1];      // Vetor das caixas avariadas
    int caixasAvariadasAux[5000 + 1];      
    
    int valorParaVenda;					// Primeiro elemento do vetor caixas[]
    int qntdCaixasParaVenda = 0;        // quantidade de caixas para venda
    int idCaixaAvariada;				// identificador da caixa avariada;
    int qntdCaixasAvariadas = 0;
    int qntdCaixasAvariadasAux = 1;
    int qntdCaixasInvertidoAux = 0;
    int valorCaixaInvertida;             // para inserir caixa consertada na primeira posicao do vetor
    int caixaConsertada;
		
	printf("DIGITE O TOTAL DE CAIXAS DA FAZENDA: ");
	scanf("%d", &totalCaixas);
	
	printf("\n");
	
	// Receber o id das caixas
	for (i = 0; i < totalCaixas; i++) {
		printf("DIGITE O ID DA CAIXA:\n");
		scanf("%d", &caixas[i]);
	}
	
	// Invertendo Vetor de idCaixas
	 for(i = 0; i <= totalCaixas; i++) {
        caixasInvertido[i] = caixas[totalCaixas-i-1];
    }

	printf("\n==========INSTRUCOES==========\n\n");
	printf(" 0  - Enviar a caixa mais apta para a venda.\n");
	printf(" X  - Identificador da caixa que estava a venda, foi avariada\n");
	printf("-1 - A caixa com maior prioridade foi consertada.\n");
	printf("-2 - Impressao das caixas aguardando para serem vendidas.\n");
	printf("-3 - Impressao do identificador de todas as caixas que estao aguardando a correçao.\n\n");
	
    for(i = 0; i <= totalCaixas; i++) {
    
    	printf("\nDIGITE UMA INSTRUCAO ABAIXO: ");
    	scanf("%d", &instrucao);
    
    	printf("\n");
    	
		switch(instrucao)
			{
			case 0:				
				valorParaVenda = caixasInvertido[0];
				
				printf("~~caixa %d enviada para venda :)\n", valorParaVenda);
							
				// remover a caixa mais apta
				removeCaixa(caixasInvertido, totalCaixas); 
				
				// Inserindo caixa mais apta a ser vendida no vetor de caixasParaVenda[]
				addCaixa(caixasParaVenda, qntdCaixasParaVenda, valorParaVenda);
				
				++qntdCaixasParaVenda;
					
				--totalCaixas; // diminuindo o totalCaixas, pois removemos a primeira caixa
			    		
				break;
			case -1:				
				caixaConsertada = caixasAvariadas[0];
				
				printf("~caixa %d consertada.\n", caixaConsertada);
				removeCaixa(caixasAvariadas, qntdCaixasAvariadas); // remove a primeira caixa
					
				// adicioando caixa consertada no inicio do vetor caixasAvariadasAux[]
				caixasAvariadasAux[0] = caixaConsertada; 
				
				++qntdCaixasAvariadasAux;
				
				--qntdCaixasAvariadas;
					
				novoVetorAvariadas(caixasAvariadasAux, qntdCaixasAvariadasAux, caixasInvertido);
		
				break;
			case -2:
				// imprimir caixas aguardando a serem vendidas
				imprimirCaixas(caixasParaVenda, qntdCaixasParaVenda);
				
				break;
			case -3:
				// imprimir caixas avariadas 
				imprimirCaixas(caixasAvariadas, qntdCaixasAvariadas);
				
				break;
			default:	
				printf("~~ A caixa com identificador [%d] foi avariada.\n", instrucao);
				
				removeCaixa(caixasParaVenda, qntdCaixasParaVenda);
				 
				addCaixa(caixasAvariadas, qntdCaixasAvariadas, instrucao);
				
				++qntdCaixasAvariadas;
				--qntdCaixasParaVenda;
		       	break;
		}	
	}  
	
	printf("\n\n");
	
	for(i = 0; i < qntdCaixasInvertidoAux; i++) {
		printf("teste %d\n", caixasInvertidoAux[i]);
	}

	return 0;	
}
