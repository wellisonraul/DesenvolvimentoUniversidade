#include<stdio.h>
#include<stdlib.h>
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
    	printf("Não foi possivel alocar memoria");
    	return 0;
    }
    else{
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = grau_max;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        
		gr->grau = (int*) calloc(nro_vertices,sizeof(int));
        if(gr->grau==NULL){
    		printf("Não foi possivel alocar memoria para o grau!");
    		return 0;
    	}

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        if(gr->arestas==NULL){
    		printf("Não foi possivel alocar memoria para arestas!");
    		return 0;
    	}
        
		for(i=0; i<nro_vertices; i++){
			 gr->arestas[i] = (int*) malloc(grau_max * sizeof(int));
			 if(gr->arestas[i]==NULL){
			 	printf("Não foi possivel alocar memoria para arestas!");
    			return 0;
			 }
		}
           

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            if(gr->pesos==NULL){
            	printf("Não foi possivel alocar memoria para pesos!");
    			return 0;
			}
            
			for(i=0; i<nro_vertices; i++){
				 gr->pesos[i] = (float*) malloc(grau_max * sizeof(float));
				 if(gr->pesos[i]==NULL){
				 	printf("Não foi possivel alocar memoria para pesos!");
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
void buscaLargura_Grafo(Grafo *gr, int ini , int *visitado,int *caminho){

	int i, vert, NumeroV , cont=1 , *fila, InicioF=0 , FinalF = 0;
	//marca vertices como nao visitdos 
	for(i=0; i<gr->nro_vertices; i++) 
		visitado[i]=0;
	//cria fila. visita e insere na fila
	NumeroV = gr-> nro_vertices;
	fila = (int*) malloc(NumeroV * sizeof(int));
	FinalF++ ;
	fila[FinalF]= ini ;
	visitado[ini]=cont ;
	//condição de parada
	while(InicioF != FinalF){
		//pega primeiro da fila
		InicioF=(InicioF+1) % NumeroV ;
		vert= fila[InicioF];
		caminho[cont-1] = vert;
		cont++;
		//visita os vizinhos ainda não visitados e coloca na fila
		for(i=0;i<gr->grau[vert];i++){
			if(!visitado[gr->arestas[vert] [i]]){
				FinalF = (FinalF + 1) % NumeroV ; 
				fila[FinalF]=gr->arestas[vert][i];
				visitado[gr->arestas[vert][i]]=cont;
			}
		}
	}
	
	free(fila);
	for(i=0;i < gr->nro_vertices; i++){
		printf("%d -> %d \n",i,caminho[i]);
	}
}
int main(){
	int eh_digrafo=0 ;
	//exemplo de grafo
	Grafo* gr =cria_Grafo(5,5,0);
	Grafo* gr1 = cria_Grafo(10,10,0);
   	Grafo* gr2 = cria_Grafo(10,10,0);
   	
   	// GRAFO 1
	insereAresta(gr, 0 , 1, eh_digrafo, 0);
	insereAresta(gr, 1 , 3, eh_digrafo, 0);
	insereAresta(gr, 1 , 2, eh_digrafo, 0);
	insereAresta(gr, 2 , 4, eh_digrafo, 0);
	insereAresta(gr, 3 , 0, eh_digrafo, 0);
	insereAresta(gr, 3 , 4, eh_digrafo, 0);
	insereAresta(gr, 4 , 1, eh_digrafo, 0);
	
	 //GRAFO 2 - SEM PESO; DIGRAFO 
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
    
    //GRAFO 3 - SEM PESO; DIGRAFO
    insereAresta(gr2,1,2,eh_digrafo,0);
    insereAresta(gr2,2,5,eh_digrafo,0);
    insereAresta(gr2,2,6,eh_digrafo,0);	
    insereAresta(gr2,2,7,eh_digrafo,0);	
    insereAresta(gr2,1,3,eh_digrafo,0);
    insereAresta(gr2,1,4,eh_digrafo,0);
    insereAresta(gr2,4,8,eh_digrafo,0);
    insereAresta(gr2,4,9,eh_digrafo,0);
    
	int vis[5];
	int caminho[5];
	
	//fazer uma busca no grafo iniciando no vertice 0
	buscaLargura_Grafo(gr1,0,vis,caminho);
	libera_Grafo(gr);
	system("pause");
	return 0 ;
	
	
}

