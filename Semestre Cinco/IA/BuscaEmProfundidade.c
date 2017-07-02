#include<stdio.h>
#include<stdlib.h>

int cont2 = 0;
float cPesos = 0; 

// Struct para meu grafo.
typedef struct grafo Grafo;

struct grafo{
	int eh_ponderado,nro_vertices,grau_max;
	int** arestas;
	float** pesos;
	int* grau;
	
};

Grafo* cria_Grafo(int nro_vertices, int grau_max, int eh_ponderado){
	Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr==NULL){
    	printf("N�o foi possivel alocar memoria");
    	return 0;
    }
    else{
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        
		gr->grau = (int*) calloc(nro_vertices,sizeof(int));
        if(gr->grau==NULL){
    		printf("N�o foi possivel alocar memoria para o grau!");
    		return 0;
    	}

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        if(gr->arestas==NULL){
    		printf("N�o foi possivel alocar memoria para arestas!");
    		return 0;
    	}
        
		for(i=0; i<nro_vertices; i++){
			 gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));
			 if(gr->arestas[i]==NULL){
			 	printf("N�o foi possivel alocar memoria para arestas!");
    			return 0;
			 }
		}
           

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            if(gr->pesos==NULL){
            	printf("N�o foi possivel alocar memoria para pesos!");
    			return 0;
			}
            
			for(i=0; i<nro_vertices; i++){
				 gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
				 if(gr->pesos[i]==NULL){
				 	printf("N�o foi possivel alocar memoria para pesos!");
    				return 0;
				 }
			}  
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
    if(orig < 0 || orig >= gr->nro_vertices){
    	 return 0;
	}
    if(dest < 0 || dest >= gr->nro_vertices){
    	return 0;
	}
	
    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado) {
    	gr->pesos[orig][dest] = peso;
	}
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont, int *caminho){
    int i;
    visitado[ini] = cont; // Informa que o valor ini j� foi visitado 
    for(i=0; i<gr->grau[ini]; i++){ // Recebe o grau que cada vertice  cont�m 
        if(!visitado[gr->arestas[ini][i]]){ // Procura vizinhos que contenham 
        	caminho[cont2] = gr->arestas[ini][i]; // inseri um novo valor como caminho
        	cont2++; // Incrementa cont
        	if(gr->eh_ponderado==1) cPesos += gr->pesos[ini][gr->arestas[ini][i]]; // Caso seja ponderado calcula o peso
            buscaProfundidade(gr,gr->arestas[ini][i],visitado,cont+1,caminho); // Chama novamente busca em profundidade.
        }
    }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado, int *caminho){
    int i, cont = 1; 
    for(i=0; i< gr->nro_vertices; i++){
    	visitado[i] = 0; // Zera o vetor visitado
    	caminho[i] = -1; // Inicia caminho como -1
	}
    
	caminho[cont2++]= ini; // Inseri o inicio no vetor caminho
    buscaProfundidade(gr,ini,visitado,cont, caminho); //Chama a fun��o busca em profundidade
 
	for(i=0; i < gr->nro_vertices ; i++){
		if(caminho[i]!=-1) printf("%d -> %d\n",i,caminho[i]); // Imprimi o caminho
	}
}

int main(){
	// Criando um grafo. 
	int eh_digrafo = 0;
    Grafo* gr = cria_Grafo(5, 5, 0);
    Grafo* gr1 = cria_Grafo(10,10,0);
   	Grafo* gr2 = cria_Grafo(10,10,0);
	
	//GRAFO 1
	insereAresta(gr, 0, 1, eh_digrafo, 0);
    insereAresta(gr, 1, 3, eh_digrafo, 0);
    insereAresta(gr, 1, 2, eh_digrafo, 0);
    insereAresta(gr, 2, 4, eh_digrafo, 0);
    insereAresta(gr, 3, 0, eh_digrafo, 0);
    insereAresta(gr, 3, 4, eh_digrafo, 0);
    insereAresta(gr, 4, 1, eh_digrafo, 0);
    
    //GRAFO 2
    insereAresta(gr1,1,2,eh_digrafo,0);
	insereAresta(gr1,2,6,eh_digrafo,0);
	insereAresta(gr1,6,3,eh_digrafo,0);
	insereAresta(gr1,3,1,eh_digrafo,0);
	insereAresta(gr1,2,7,eh_digrafo,0);
	insereAresta(gr1,7,8,eh_digrafo,0);
	insereAresta(gr1,8,4,eh_digrafo,0);
	insereAresta(gr1,4,5,eh_digrafo,0);
    insereAresta(gr1,5,9,eh_digrafo,0);
    insereAresta(gr1,5,1,eh_digrafo,0);
    insereAresta(gr1,4,1,eh_digrafo,0);
    insereAresta(gr1,7,4,eh_digrafo,0);
    
    //GRAFO 3
    insereAresta(gr2,1,2,eh_digrafo,0);
    insereAresta(gr2,2,5,eh_digrafo,0);
    insereAresta(gr2,2,6,eh_digrafo,0);	
    insereAresta(gr2,2,7,eh_digrafo,0);	
    insereAresta(gr2,1,3,eh_digrafo,0);
    insereAresta(gr2,1,4,eh_digrafo,0);
    insereAresta(gr2,4,8,eh_digrafo,0);
    insereAresta(gr2,4,9,eh_digrafo,0);
	
	int vis[10];
	int caminho[10];

	buscaProfundidade_Grafo(gr2,1,vis,caminho);	
	

	return 0;
}
