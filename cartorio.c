#include <stdio.h> //bibblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () //função responsável por cadastrar usuário no sistema
{
	// inicio criação de váriaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];	
   // final da criação de váriaveis/string	
   
   printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
   scanf("%s", cpf); //%s refere-se a string
   
   strcpy(arquivo, cpf); //responsável por copiar os valores das strings
   
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
	
	// inicio criação de váriaveis/string
	char cpf[40];
	char conteudo[200];
	// final da criação de váriaveis/string	
	
	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r"); //abrir e ler o arquivo Ready
	
	if(file == NULL)	
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
	printf("\nEssas são as informações do usuário: \n");
	printf("%s",conteudo);
	printf("\n\n");
    }
	fclose(file);
	system("pause");
	
}

int deletar ()
{
	// inicio criação de váriaveis/string
	char cpf[40];
	// final da criação de váriaveis/string	
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando informações do usuário
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");	
	}
	fclose(file);
}


int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls"); //responsável por limpar a tela
	
	
	    setlocale(LC_ALL, "PORTUGUESE"); //Definindo a linguagem 
	
	    printf ("### Cartório da EBAC ###\n\n"); //inicio do menu
	    printf ("Escolha a opção desejada do menu:\n\n");
	    printf ("\t1 - Registrar Nomes\n");
	    printf ("\t2 - Consultar Nomes\n");
	    printf ("\t3 - Deletar Nomes\n");
	    printf ("\t4 - Sair do sistema\n\n");
	    printf ("Opção: "); //fim do menu

        scanf("%d", &opcao); //armazenando a escolha do usuário
    
        system("cls");
        
        switch(opcao)
        {
        	case 1:
        	registro (); //chamada de funções
    	    break;
    	    
    	    case 2:
    	    consulta (); //chamada de funções
		    break;
		    
		    case 3:
		    deletar (); //chamada de funções
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema!\n\n");
		    return 0;
			break;
					    
		    default:
		    printf("Essa opção não está disponível!\n");
		    system("pause");
		    break;
		    
		} //fim da seleção
    
    }
}
