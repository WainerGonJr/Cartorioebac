#include <stdio.h> //bibblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro () //fun��o respons�vel por cadastrar usu�rio no sistema
{
	// inicio cria��o de v�riaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];	
   // final da cria��o de v�riaveis/string	
   
   printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
   scanf("%s", cpf); //%s refere-se a string
   
   strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
   
   FILE *file; //cria o arquivo
   file = fopen(arquivo,"w"); //cria arquivo e o W signnifica escrever
   fprintf(file,cpf); //salva o valor
   fclose(file); //fecha o arquivo
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o nome a ser cadastrado: ");
   scanf("%s", nome);
   
   file = fopen(arquivo,"a");
   fprintf(file, nome);
   fclose(file);
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo,"a");
   fprintf(file, sobrenome);
   fclose(file);
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado: ");
   scanf("%s",cargo);
   
   file = fopen(arquivo,"a");
   fprintf(file,cargo);
   fclose(file);
   
   system("pause"); 
      
}

int consulta ()
{
	setlocale(LC_ALL, "PORTUGUESE"); //Definindo a linguagem
	
	// inicio cria��o de v�riaveis/string
	char cpf[40];
	char conteudo[200];
	// final da cria��o de v�riaveis/string	
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir e ler o arquivo Ready
	
	if(file == NULL)	
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas s�o as informa��es do usu�rio: \n");
	printf("%s",conteudo);
	printf("\n\n");
    }
	fclose(file);
	system("pause");
	
}

int deletar ()
{
	// inicio cria��o de v�riaveis/string
	char cpf[40];
	// final da cria��o de v�riaveis/string	
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando informa��es do usu�rio
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");	
	}
	fclose(file);
}


int main ()
{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //respons�vel por limpar a tela
	
	
	    setlocale(LC_ALL, "PORTUGUESE"); //Definindo a linguagem 
	
	    printf ("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf ("Escolha a op��o desejada do menu:\n\n");
	    printf ("\t1 - Registrar Nomes\n");
	    printf ("\t2 - Consultar Nomes\n");
	    printf ("\t3 - Deletar Nomes\n");
	    printf ("\t4 - Sair do sistema\n\n");
	    printf ("Op��o: "); //fim do menu

        scanf("%d", &opcao); //armazenando a escolha do usu�rio
    
        system("cls");
        
        switch(opcao)
        {
        	case 1:
        	registro (); //chamada de fun��es
    	    break;
    	    
    	    case 2:
    	    consulta (); //chamada de fun��es
		    break;
		    
		    case 3:
		    deletar (); //chamada de fun��es
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n\n");
		    return 0;
			break;
					    
		    default:
		    printf("Essa op��o n�o est� dispon�vel!\n");
		    system("pause");
		    break;
		    
		} //fim da sele��o
    
    }
}
