#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca responsavel por amarzenar as strings

int registro()  //fun��o responsavel por cadastrar os usuarios no sistema
{ 
    //inicio da cadastra��o de variaveis/strings
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
     //final da cadastra��o de variaveis/strings
     
    printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usuario
    scanf("%s", cpf);  // %s refere-se a string
    
    strcpy(arquivo, cpf); //responsavel por copiar os valores das strings 
    
    FILE *file; //cria o arquivo no banco de dados do computador 
    file = fopen(arquivo, "w"); //cria o arquivo
    fprintf(file,cpf); //salvo o valor da variavel
    fclose (file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite um nome a ser cadastrado:");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite um sobrenome a ser cadastrado:");
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}
int consulta()
{ 
    setlocale(LC_ALL, "Portuguese");
    
	char cpf[40];
    char conteudo[200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, N�o localizado! . \n");
	}
    
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("Essas s�o as informa��es do usu�rio:");
    	printf("%s", conteudo);
    	printf("\n \n");
    
	}
    
    system("pause");
}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("O Usuario n�o se encontra no sistema!. \n");
    	system("pause");
	}
    
    
    
}


int main()
{
	
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	    
	    printf("### Cart�rio da Ebac ###\n \n"); //inicio do menu
	    printf("Escolha a op��o desejada do menu:\n \n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Op��o: "); //fim do menu

	    scanf("%d" , &opcao); //armazenando a escolha do usuario 
	
	    system("cls"); //responsavel por limpar a tela 
	    
	    switch(opcao) //inicio da sele��o 
	    {
	    case 1:
	    registro();	 //chamada de fun��es
	    break; 
		    
		case 2: 
	    consulta();	
		break;
		    
		case 3:
	    deletar();
		break;
		
		    
		default:
		printf("Essa op��o n�o est� disponivel.\n");
		system("pause"); 
		break;	//fim da sele��o
		
		}
	    
	
    }
}	
