#include<stdio.h>
#include<stdlib.h>

typedef struct grafo Grafo;
// Struct para meu grafo.
struct grafo{
	int eh_ponderado,nro_vertices,grau_max;
	int** arestas;
	float** pesos;
	int* grau;
	
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

void comparacaoGulosa(Grafo* gr , int vetorH[] ,int origem , int destino, int* visitado, int* caminho){
	int i,aux =0,menor=2000,teste=0,id=0;
	for(i=0;i<gr->nro_vertices;i++){
		visitado[i]=0 ; //marcando todos como n visitados 
	}
	caminho[id++]=origem; // mostrando a origem no caminho
	visitado[origem]=1;  // marcando origem como visitado
	while (origem != destino){ //teste p saber se ja chegou no destino
	
		for(i=0 ; i<gr->grau[origem];i++){  //grau do valor do vertice origem
		
			if(menor > vetorH[gr->arestas[origem][i]] && visitado[gr->arestas[origem][i]] != 1){ //teste se eh menor e nao visitado
				teste++;  // identifica que tem vizinhos 
				menor=  vetorH[gr->arestas[origem][i]]; // substitui pelo menor "valor" 
				aux= gr->arestas[origem][i];  // Qual o menor visinho pra ir 
			}
			
		}	
		
		if(teste==0){ 
			visitado[origem]=1; 
			origem = caminho[id-2];
			caminho[id++] = origem;
			aux=0;
			menor=2750;
		}else{
			visitado[aux]=1 ;
			origem=aux;
			caminho[id++] = aux;
			aux=0;
			menor=2750;
			teste=0;	
		}
		
	}

}


int main(){
	int eh_digrafo = 0,i;
    Grafo* gr1 = cria_Grafo(8,8,1);
    int vetorH[8]={18,16,10,13,12,10,5,0};
	
    // GRAFO HEURISTICA
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

	
	int vis[8];
	int caminho[8];
	comparacaoGulosa(gr1,vetorH,0,7,vis,caminho);
	for(i=0;i<gr1->nro_vertices;i++){
		printf("|%d|",caminho[i]);
	}	

	libera_Grafo(gr);
	
	return 0;
}
