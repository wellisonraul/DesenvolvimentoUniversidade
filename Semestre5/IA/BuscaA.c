#include<stdio.h>
#include<stdlib.h>

typedef struct grafo Grafo;
// Struct para meu grafo.
struct grafo{
	int eh_ponderado,nro_vertices,grau_max;
	int** arestas;
	float** pesos;
	int* grau;
	float* heuristica;
	
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
	Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));
        
        gr->heuristica = (float*) malloc(nro_vertices*sizeof(float));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
        }

    }
    return gr;
}

void libera_Grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->heuristica);
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

void insereHeuristica(Grafo* gr, float *heuristica){	
	int i;
	for(i=0;i<gr->nro_vertices;i++) gr->heuristica[i] = heuristica[i];
}


void buscaGulosaA(Grafo *gr,int ini, int dest, int *caminho, int *visitado){
	int i,achou=1,cont=0,tVizinhos=0; // Achou váriavel de controle para fim do while, cont para aumentar de acordo com a inserção do caminho. 
	float menor=2000; 
	
	for(i=0; i<gr->nro_vertices ; i++) visitado[i] = 0;
	
	caminho[cont] = ini; // Inseri o valor na primeira posição do caminho. 
	visitado[ini] = 1; // Marca o valor inicial como visitado. 
	
	while(achou){
		tVizinhos = 0; // Variável relacionada a quantidade de vizinhos que um vertice tem, caso não haja vizinhos ela permanece em zero. 
		ini = caminho[cont++]; // Inseri o valor de inicio que é atulizada a cada laço no vetor caminho.
		printf("|%d| -> ",ini); //Imprimi caminho para que saia o resultado na tela do usuário
		
		
		for(i=0;i<gr->grau[ini];i++){ // Pecorre a quantidades de vizinhos que um vertice tenha
				if(visitado[gr->arestas[ini][i]]==0){ // Analisa se o vizinho desse vertice já foi visitado
					tVizinhos++; // Incrementa, informando que este vertice possui pelo menos um ou mais vizinhos
					if((gr->pesos[ini][i] + gr->heuristica[gr->arestas[ini][i]] ) < menor) { // Analisa somando o valor da arestas + heuristica.
						menor = gr->pesos[ini][i] + gr->heuristica[gr->arestas[ini][i]]; // o valor menor recebe o menor nó, caso haja dois valores indenticos irá para o primeiro.
						caminho[cont] = gr->arestas[ini][i]; //Inseri o menor valor no caminho
					}
					
					if(gr->arestas[ini][i]==dest){ // Testa se é o fim do algoritmo 
						caminho[cont]=dest; // Se for o fim coloque o fim no caminho
						printf("|%d|",dest); // Imprima o fim 
						achou=0; // Coloque achou como zero e pare o While
					}
				}
		}
		
		if(tVizinhos==0 && achou==1){ //Caso não haja mais vizinhos e o mesmo entre em um loop. 
			visitado[ini] = 1; // Inseri o valor atual que não tem vizinhso como 1.
			ini = caminho[cont-2]; // Volta para o valor antes do atual
			caminho[cont++] = ini; // Inseri novamente o valor antes do atual no caminho
			menor = 2000; // menor é setado como o máximo do int - esse valor escolhido aleartorio 
		}else{
			visitado[ini] = 1; // O valor recebe 1 como visitado
			menor = 2000;	// Menor é setado como o máximo do int. 
		}	
	}
}

int main(){
	int eh_digrafo = 0;
    Grafo* gr = cria_Grafo(5, 5, 0);
    Grafo* gr1 = cria_Grafo(8,8,1);
    Grafo* gr2 = cria_Grafo(20,20,1);
    
	// GRAFO INICIAL - GRAFO 1
    insereAresta(gr, 0, 1, eh_digrafo, 0);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    insereAresta(gr, 4, 1, eh_digrafo, 0);
    
    // GRAFO DA HEURISTICA - GRAFO HEURISTICA
	insereAresta(gr1,0,1,eh_digrafo,8);
	insereAresta(gr1,0,2,eh_digrafo,10);
	insereAresta(gr1,0,3,eh_digrafo,5);
	insereAresta(gr1,0,5,eh_digrafo,20);
	insereAresta(gr1,1,2,eh_digrafo,6);
	insereAresta(gr1,1,4,eh_digrafo,7);
	insereAresta(gr1,2,3,eh_digrafo,8);
	insereAresta(gr1,2,4,eh_digrafo,10);
	insereAresta(gr1,2,6,eh_digrafo,4);
	insereAresta(gr1,4,5,eh_digrafo,3);
	insereAresta(gr1,5,6,eh_digrafo,7);
	insereAresta(gr1,5,7,eh_digrafo,24);
	insereAresta(gr1,6,7,eh_digrafo,7);
	
	// GRAFO DA AULA - GRAFO ROMÊNIA
	insereAresta(gr2,0,16,eh_digrafo,118);
	insereAresta(gr2,0,15,eh_digrafo,140);
	insereAresta(gr2,0,19,eh_digrafo,75);
	insereAresta(gr2,16,9,eh_digrafo,111);
	insereAresta(gr2,9,10,eh_digrafo,70);
	insereAresta(gr2,10,3,eh_digrafo,75);
	insereAresta(gr2,3,2,eh_digrafo,120);
	insereAresta(gr2,2,13,eh_digrafo,138);
	insereAresta(gr2,2,14,eh_digrafo,146);
	insereAresta(gr2,15,14,eh_digrafo,80);
	insereAresta(gr2,15,5,eh_digrafo,99);
	insereAresta(gr2,15,12,eh_digrafo,151);
	insereAresta(gr2,12,19,eh_digrafo,75);
	insereAresta(gr2,14,13,eh_digrafo,97);
	insereAresta(gr2,13,1,eh_digrafo,101);
	insereAresta(gr2,5,1,eh_digrafo,211);
	insereAresta(gr2,1,6,eh_digrafo,90);
	insereAresta(gr2,1,17,eh_digrafo,85);
	insereAresta(gr2,17,7,eh_digrafo,98);
	insereAresta(gr2,7,4,eh_digrafo,86);
	insereAresta(gr2,17,18,eh_digrafo,142);
	insereAresta(gr2,18,8,eh_digrafo,92);
	insereAresta(gr2,8,11,eh_digrafo,87);
	/* ARAD = 0
		BUCHA 1
		CRAIOVA 2
		DOBRETA 3
		EFORIE 4
		FAGARAS 5
		GIU 6
		HIR 7
		IASI 8
		LUGOJ 9
		MEHADIA 10
		NEAMT 11
		ORADEA 12
		PITESTI 13
		RIMNICU 14
		SIBIU 15
		TIMISONA 16
		URZI 17 
		VASLUI 18 
		ZERIND 19
		*/
	
 
	float h[8]={18,16,10,13,12,10,5,0},	h1[20]={366,0,160,242,161,176,77,151,226,244,241,234,380,10,193,253,329,80,199,374};
	insereHeuristica(gr1,h);
	insereHeuristica(gr2,h1);
	
		
	int vis[20];
	int caminho[20];
	int i;
	
	
	buscaGulosaA(gr2,19,1,caminho,vis);
	
	libera_Grafo(gr);
	
	return 0;
}

