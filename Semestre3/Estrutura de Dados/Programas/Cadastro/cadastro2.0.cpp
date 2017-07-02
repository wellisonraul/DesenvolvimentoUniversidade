#include <stdio.h>
#include <conio.h>
#include <windows.h>  //necess�rio para a fun��o gotoxy - talvez n�o funcione no linux

//cria a estrutura da agenda
struct registro { 
   char nome[60]; 
   char telefone[10]; 
}; 
//-------------------------
struct registro agenda;
FILE *pointer;  //ponteiro que far� referencia ao arquivo texto

//declaracao do escopo das funcoes
void gotoxy(int, int);
void cadastrar(void);
void exibir(void);
void pesquisar(void);
void altera_reg(void);
void exclui_reg(void);
void excluir_tudo(void);
void ordena_reg(void);
//----------------------------------


int main(void){
	char opcao;
	while(opcao !='9'){
		system("cls");
		gotoxy(33,1);  printf("Menu Principal");
		gotoxy(33,2);  printf("--------------");
		gotoxy(29,5);  printf("1 - Cadastra nomes");
		gotoxy(29,7);  printf("2 - Exibe dados");
		gotoxy(29,9);  printf("3 - Pesquisa por nome");
		gotoxy(29,11); printf("4 - Altera campos de registro");
		gotoxy(29,13); printf("5 - Exclui um registro por nome");
		gotoxy(29,15); printf("6 - Apaga todos os registros");
		gotoxy(29,17); printf("7 - Ordena todos os registros por nome"); 
		gotoxy(29,19);  printf("9 - Fim de programa");
		gotoxy(29,22); printf("Escolha uma opcao: ");
		opcao = getche();
		fflush(stdin); // limpa o buffer de memoria para receber os dados dos nomes
		if(opcao!='9')
			switch(opcao){
				case '1':
					cadastrar();
					break;
				case '2':
					exibir();
					break;
				case '3':
					pesquisar();
					break;
				case '4':
					altera_reg();
					break;	
                case '5':
					exclui_reg();
					break;
                case '6':
					excluir_tudo();
					break;
				case '7':
					ordena_reg();
					break;
				case '9': break;
				default: printf("\n\n  Opcao invalida! Tente novamente");
				getche();
			}
	}
}


void gotoxy(int x, int y) {  //cria a fun��o gotoxy, existente no C ANSI, para posicionar o cursor na porcao coluna,linha da tela
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}


void cadastrar(void){
    pointer= fopen("CADASTRO.TXT", "a"); //cria o arquivo ou, caso j� criado, reabre para edicao
	system("cls");
	gotoxy(27,1);  printf("Cadastramento de nomes");
	gotoxy(10,5);  printf("Entre o nome.........: ");
	fflush(stdin);
   	gets(agenda.nome);
	gotoxy(10,8);  printf("Entre o telefone.........: ");
	fflush(stdin);
	gets(agenda.telefone);
    //fprintf() "escreve" (insere) os campos de mem�ria no arquivo, com a separa��o de cada campo por \t
	fprintf(pointer, "%s\t%s\n",agenda.nome, agenda.telefone); 
	//------------------  fim da escrita do novo registro no arquivo -------------------
	fclose(pointer);
	gotoxy(25,24); printf("Tecle ENTER para voltar ao menu");
	getche();
}

void exibir(void){
    char registro[255];
	pointer= fopen("CADASTRO.TXT", "a"); //caso nao exista o arquivo, o mesmo ser� criado
    int linha = 5;
	system("cls");
	gotoxy(27,1);  printf("Apresentacao de registros");
	pointer = fopen("CADASTRO.TXT", "r"); //abre o arquivo apenas para leitura, com fins de exibicao dos dados
	while(fgets(registro,255,pointer)!=NULL){ //faz enquanto nao for fim de arquivo
	    /*****OBSERVA��ES IMPORTANTES SOBRE O sscanf()*****
	     - Essa fun��o le um vetor de strings e guarda cada informa��o armazenada
	     neste vetor em outras vari�veis, seguindo crit�rios de formata��o
	     definidos pelo usu�rio;
	     - Neste cadastro, como colocamos cada campo separado por uma marca de tabula��o,
	     o sscanf() separou cada campo do registro atual, representado pelo vetor registro[255],
	     em uma vari�vel da estrutura de mem�ria da agenda;
	     - Note o c�digo de formata��o %[^\t] para cada campo.  Isso faz com que o sscanf() insira,
	     caractere a caracere, os dados em cada campo at� que a marca de tabula��o (\t) seja
	     encontrada.  Quando isso ocorrer, ele passa para o pr�ximo campo do registro e assim
	     sucessivamente
         fonte de pesquisa: http://en.cppreference.com/w/cpp/io/c/fscanf*/
         
        sscanf(registro, "%[^\t] %[^\t]",&agenda.nome,&agenda.telefone); //separa os campos do registro atual
        fflush(stdin);//limpa o buffer do teclado, preparando o sscanf() para receber o novo resgistro e tratar
        //----------fim da separa��o dos campos no registro corrente------------------------
		
        gotoxy(1,linha); printf("%s\t%s",agenda.nome,agenda.telefone); //exibe os campos
		linha+=1;
		
 	}
	fclose(pointer);
	gotoxy(25,24); printf("Tecle ENTER para voltar ao menu");
	getche();
}

void pesquisar(void){
    char registro[255], nome_pesq[60];  //variavel que guardar� o nome a ser pesquisado
	pointer= fopen("CADASTRO.TXT", "a"); //caso nao exista o arquivo, o mesmo ser� criado
    int linha = 5;
	system("cls");
	gotoxy(27,1);  printf("Pesquisa de registros por nome");
	gotoxy(10,3);  printf("Digite o nome a ser pesquisado: ");
	fflush(stdin);
	gets(nome_pesq);
	pointer = fopen("CADASTRO.TXT", "r"); //abre o arquivo apenas para leitura, com fins de exibicao dos dados
	while(fgets(registro,255,pointer)!=NULL){ //executa a pesquisa por nome at� o final do arquivo
        sscanf(registro, "%[^\t] %[^\t]",&agenda.nome,&agenda.telefone); //separa os campos do registro atual
        fflush(stdin);//limpa o buffer do teclado, preparando o sscanf() para receber o novo resgistro e tratar
        //----------fim da separa��o dos campos no registro corrente------------------------
		/*Rotina de pesquisa por parte do nome digitado:
          Essa rotina abaixo utiliza a fun��o strstr(string completa,substring),
          funcionando assim: no par�metro string completa corresponde, neste contexto,
          ao campo nome do arquivo; o par�metro substring corresponde � string que o usu�rio
          digitou, neste contexto, parte do nome que o usu�rio digitou.  A fun��o, ent�o, 
          compara as duas strings e, se existir ao menos um caractere do nome digitado,
          ela retorna 1-verdadeiro.  Caso contr�rio, restorna 0-falso.  Ex: se o nome da
          pessoa for Ana Claudia e o usu�rio digitar Ana, ele vai mostrar todos os nomes
          que cont�m a palavra Ana, inclusive o Ana Claudia; se o usu�rio digitar Clau, ele
          mostra todos os nomes que cont�m a palavra Clau, independente se no in�cio, meio ou
          fim do campo.
                 */
        if(strstr(strupr(agenda.nome),strupr(nome_pesq))){  //se encontrou parte do nome pesquisado...
        	gotoxy(5,linha); printf("%s\t%s",agenda.nome,agenda.telefone); //mostra o registro associado
		    linha+=1;
        }
		
	}
	fclose(pointer);
	gotoxy(25,24); printf("Tecle ENTER para voltar ao menu");
	getche();
}

void altera_reg(void){
    char registro[255], nome_pesq[60];  //variavel que guardar� o nome do registro a ser alterado
    char op;
    pointer= fopen("CADASTRO.TXT", "a"); //caso nao exista o arquivo, o mesmo ser� criado
    int linha = 5, reg_cont = 1; //reg_cont conta quantos registros existem no arquivo
	pointer= fopen("CADASTRO.TXT", "r"); //abre o arquivo para leitura
    //contando o n�mero de registros do arquivo
	while(fgets(registro,255,pointer)!=NULL){ //executa a pesquisa por nome at� o final do arquivo    
	    reg_cont++;  //conta quantos registros existem no arquivo
    }
    /*cria uma estrutura vetorial com a quantia exata de registros, para armazenar, 
    temporariamente, o conte�do do arquivo e tratar a rotina de altera��o l�gica*/
    struct registro agenda_reg[reg_cont]; 
    //----------------------------------------------------------------------------
    rewind(pointer); //reposiciona o ponteiro no in�cio do arquivo, para iniciar a entrada dos registros na estrutura vetorial
    reg_cont=0;
    while(fgets(registro,255,pointer)!=NULL){ //captura cada registro do arquivo at� EOF
        sscanf(registro, "%[^\t] %[^\t]",&agenda_reg[reg_cont].nome,&agenda_reg[reg_cont].telefone); //separa os campos, copiando-os no registro de mem�ria atual
        fflush(stdin);//limpa o buffer do teclado, preparando o sscanf() para receber o novo resgistro e tratar
        reg_cont++; //incrementa o contator de registros  	    
    }
    //**** Pesqisa do registro a ser alterado, por nome ****
    system("cls");
	gotoxy(27,1);  printf("Pesquisa de registros por nome");
	gotoxy(10,3);  printf("Digite o nome a ser pesquisado para alteracao: ");
	fflush(stdin);
	gets(nome_pesq);
    rewind(pointer); //reposiciona o ponteiro no in�cio do arquivo, para iniciar pesquisa do registro a ser alterado na estrutura vetorial    
    for(int cont=0;cont<reg_cont;cont++){  //varre a estrutura vetorial de registros, procurando o registro a ser alterado logicamete
        if(strstr(strupr(agenda_reg[cont].nome),strupr(nome_pesq))){  //se encontrou parte do nome pesquisado...
             gotoxy(5,linha); printf("%s\t%s",agenda_reg[cont].nome,agenda_reg[cont].telefone); //mostra o registro associado
           	 gotoxy(5,linha+1); printf("Deseja alterar dados desse registro (S/N)? ");
             op = getche();
        	 if(op == 's' || op == 'S'){
               //*** in�cio da rotina de altera��o l�gica do registro na mem�ria ***
               gotoxy(5,10);  printf("Entre o nome (<ENTER> para n�o alterar)......: ");
               fflush(stdin);
   	           gets(agenda.nome);  //guarda o valor digitado no campo da estrutura
   	           if(strlen(agenda.nome)!=0){ //testa se o campo n�o est� vazio.  Caso esteja vazio, n�o altera o conte�do no registro vetorial corrente
                  strcpy(agenda_reg[cont].nome,agenda.nome); //copia o valor alterado do campo da estrutura simples para o campo do registro vetorial corrente
               }
	           gotoxy(5,12);  printf("Entre o telefone (<ENTER> para n�o alterar)..: ");
	           fflush(stdin);
	           gets(agenda.telefone);
	           if(strlen(agenda.telefone)!=0){
                  strcpy(agenda_reg[cont].telefone,agenda.telefone);
                  strcat(agenda_reg[cont].telefone, "\n");  //insere, no final do �ltimo campo (neste caso, o campo "telefone", uma quebra de linha, indicando o fim do registro corrente
               }
	           //**** fim da rotina de altera��o l�gica do registro na mem�ria ****
	           //**** in�cio da rotina de altera��o f�sica do registro na mem�ria ***
               pointer = fopen("CADASTRO.TXT", "w"); //apaga todo o conte�do do arquivo, para copiar, da estrutura vetorial, todos os registros, menos o que deve ser exclu�do
               fflush(pointer);
               rewind(pointer);//garante que o ponteiro fique posicionado no in�cio do arquivo, para a transfer�ncia dos registros, da estrutura vetorial de registros, para o arquivo
               for(int cont=0;cont<reg_cont;cont++){ //varre o vetor de registros, para copiar todos os registros, da estrutura vetorial de registors, para o arquivo
                  fprintf(pointer, "%s\t%s",agenda_reg[cont].nome, agenda_reg[cont].telefone); //copia os campos da estrutura vetorial de registros s para o arquivo
                  fflush(pointer);  //for�a a c�pia do registro corrente, da mem�ria RAM, para o arquivo
               }
               break; //encerra a pesquisa de registros, visto que a altera��o f�sica j� foi conclu�da
               //fim da rotina de altera��o f�sica do regsitro
              }
          }
    }       
    fclose(pointer);
	gotoxy(25,24); printf("Tecle ENTER para voltar ao menu");
	getche();
}

void exclui_reg(void){
    char registro[255], nome_pesq[60];  //variavel que guardar� o nome do registro a ser exclu�do
    char op;
    pointer= fopen("CADASTRO.TXT", "a"); //caso nao exista o arquivo, o mesmo ser� criado
    int linha = 5, reg_cont = 1, reg_del=0; //reg_cont conta quantos registros existem no arquivo; reg_del guarda o n�mero do registro a ser exclu�do
	pointer= fopen("CADASTRO.TXT", "r"); //abre o arquivo para leitura
    //contando o n�mero de registros do arquivo
	while(fgets(registro,255,pointer)!=NULL){ //executa a pesquisa por nome at� o final do arquivo    
	    reg_cont++;  //conta quantos registros existem no arquivo
    }
    /*cria uma estrutura vetorial com a quantia exata de registros, para armazenar, 
    temporariamente, o conte�do do arquivo e tratar a rotina de exclus�o l�gica*/
    struct registro agenda_reg[reg_cont]; 
    //----------------------------------------------------------------------------
    rewind(pointer); //reposiciona o ponteiro no in�cio do arquivo, para iniciar a entrada dos registros na estrutura vetorial
    reg_cont=0;
    while(fgets(registro,255,pointer)!=NULL){ //executa a pesquisa por nome at� o final do arquivo
        sscanf(registro, "%[^\t] %[^\t]",&agenda_reg[reg_cont].nome,&agenda_reg[reg_cont].telefone); //separa os campos do registro atual
        fflush(stdin);//limpa o buffer do teclado, preparando o sscanf() para receber o novo resgistro e tratar
        reg_cont++;   	    
    }
    
    system("cls");
	gotoxy(27,1);  printf("Pesquisa de registros por nome");
	gotoxy(10,3);  printf("Digite o nome a ser pesquisado: ");
	fflush(stdin);
	gets(nome_pesq);
    rewind(pointer); //reposiciona o ponteiro no in�cio do arquivo, para iniciar pesquisa do registro a ser exclu�do na estrutura vetorial    
    for(int cont=0;cont<reg_cont;cont++){
        if(strstr(strupr(agenda_reg[cont].nome),strupr(nome_pesq))){  //se encontrou parte do nome pesquisado...
             gotoxy(5,linha); printf("%s\t%s",agenda_reg[cont].nome,agenda_reg[cont].telefone); //mostra o registro associado
           	 gotoxy(5,linha+1); printf("Deseja excluir esse registro (S/N)? ");
             op = getche();
        	 if(op == 's' || op == 'S'){
               //in�cio da rotina de exclus�o f�sica do registro no arquivo
               pointer = fopen("CADASTRO.TXT", "w"); //apaga todo o conte�do do arquivo, para copiar, da estrutura vetorial, todos os registros, menos o que deve ser exclu�do
               fflush(pointer);
               reg_del = cont; //guarda o n�mero do registro vetorial a ser apagado do arquivo
               rewind(pointer);//garante que o ponteiro fique posicionado no in�cio do arquivo, para a transfer�ncia dos registros n�o deletados
               for(int cont=0;cont<reg_cont;cont++){ //varre o vetor de registros, para copiar todos os registros menos o escolhido para dele��o
                  if(cont!=reg_del){  //se o registro corrente n�o for o deletado...
                     fprintf(pointer, "%s\t%s",agenda_reg[cont].nome, agenda_reg[cont].telefone); //copie os campos do vetor de registros para o arquivo
                     fflush(pointer);  //for�a a c�pia do registro corrente, da mem�ria RAM, para o arquivo
                  }
               }
               break; //encerra a pesquisa de registros, visto que a dele��o f�sica j� foi conclu�da
               //fim da rotina de exclus�o f�sica do regsitro
              }
          }
    }       
    fclose(pointer);
	gotoxy(25,24); printf("Tecle ENTER para voltar ao menu");
	getche();
}

void excluir_tudo(void){
    char op;
    system("cls");
	gotoxy(5,1);  printf("ATENCAO!!! DESEJA REALMENTE APAGAR TODOS OS DADOS DO ARQUIVO (S/N)?");
	op = getche();
	if(op == 'S' || op == 's'){
        pointer= fopen("CADASTRO.TXT", "w");   //recria o arquivo
        fclose(pointer);
        gotoxy(25,20); printf("Todos os dados foram apagados!");
        
    }else{
        gotoxy(25,20); printf("Dados nao apagados!");  
    }
    gotoxy(25,24); printf("Tecle ENTER para voltar ao menu");
    getche();

}

void ordena_reg(void){
  /*Rotina a ser desenvolvida.  Dica: utilize a l�gica empregada na rotina de altera��o
    copiando todo os campos do arquivo para a estrutura vetorial de registros na memoria;
    depois, ordene a estrutura vetorial pelo campo nome, n�o esquecendo de copiar todos os 
    campos do nome que foi ordenado para a nova posi��o de ordenamento;
    depois, apague fisicamente todo o arquivo (cl�usula "w") e copie todo os registros da 
    estrutura vetorial de registros, da mem�ria, para o arquivo. */
}
