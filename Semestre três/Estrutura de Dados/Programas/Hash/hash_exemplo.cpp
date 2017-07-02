/* Exemplo conceitual de tabela hash - beta 1                       *
 * Programa que exemplifica o funcionamento da tabela hash          *
 * mostrando a posição alocada, o elemento correspondente, o numero *
 * de colisoes encontradas e o seu tratamento por Encadeamento Ext. *
 * by Denis, Felipe                                                 *
 * OBS: Limitacao deste algoritmo: funciona para um par de colisoes */

 
#include <stdio.h>
#include <conio.h>

int main(void){
   int qte_num, funcao_hash, nr_colisoes=0, pos_elemento=0, indice=0;
   float num;

   printf("Exemplo conceitual de tabela hash - beta 1\n");
   printf("Programa que exemplifica o funcionamento da tabela hash\n");
   printf("mostrando a posicao alocada, o elemento correspondente e\n");
   printf("o numero de colisoes encontradas\n");
   printf("by Denis, Felipe\n\n");
   printf("OBS: Limitacao deste algoritmo: funciona para um par de colisoes\n\n\n");

   printf("Digite a quantidades de numeros a serem informados: ");
   scanf("%d",&qte_num);
   printf("\n\n");
   
   //cria a matriz que receberá o indice e o elemento a ser alocado na tabela hash
   float tabela_hash[qte_num][2]; 
   //------------------------------------------------------------------
   
   for(int linha=0;linha<qte_num;linha++){
      printf("Digite o %do. numero: ",linha+1);
      scanf("%f",&num);
      funcao_hash=(int)num%4; //funcao hash escolhida para indexar o valor digitado
      tabela_hash[linha][0]=funcao_hash;  //a primeira coluna da tabela hash recebe o indice onde o elemento será armazenado
      tabela_hash[linha][1]=num;          //a segunda coluna da tabela hash recebe o numero
   }

   //mostrando todos os elementos inseridos na tabela
   printf("\nListando todos a posicao ocupada (f(x)) e o elemento correspondente\n\n");
   printf("f(x)\tElemento\n");
   for(int linha=0;linha<qte_num;linha++){
      for(int coluna=0;coluna<=1;coluna++){
         printf("%.0f\t",tabela_hash[linha][coluna]);
      }
      printf("\n");
   }
   
   //encontrado o numero de colisoes nas posicoes da tabela hash (simulação baseada no metodo bouble sort)
   printf("\n\nEncontrado o numero de colisoes nas posicoes da tabela hash");
   for(int pivot=0;pivot<qte_num-1;pivot++){
      for(int elemento=pivot+1;elemento<qte_num;elemento++){
         if(tabela_hash[pivot][0] == tabela_hash[elemento][0]){
            nr_colisoes++;
            printf("\n\n%d colisao(oes): indice1 = %d, valor1 = %.2f, indice2 = %d, valor2 = %.2f",nr_colisoes, pivot, tabela_hash[(int)pivot][1], elemento, tabela_hash[(int)elemento][1]);
         }
      }
      nr_colisoes=0;//zera o numero de colisoes, para checar se existem outras colisoes
   }
   
   //tratando as colisões pelo método do encadeamento externo (simulação baseada no metodo bouble sort)
   printf("\n\nTratando as colisoes pelo metodo Encadeamento Externo\n\n");
   for(int pivot=0;pivot<qte_num-1;pivot++){ //fixa o elemento para comparacao com os demais
      for(int elemento=pivot+1;elemento<qte_num;elemento++){ //varre a tabela em busca de um elemento duplicado (em colisao)
         if(tabela_hash[pivot][0] == tabela_hash[elemento][0]){ //se houver colisao (elemento duplicado)...
            printf("%.0f\t %.2f\t %.2f\n",tabela_hash[pivot][0], tabela_hash[pivot][1], tabela_hash[elemento][1]);
            pos_elemento = elemento; //guarda o valor do ultimo elemento a ser utilizado para exibi-lo, caso a ultima posicao nao esteja duplicada
         }
            
      }
      
   }
   getch();
}
