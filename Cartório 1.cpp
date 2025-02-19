#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região 
#include <string.h> //biblioteca responsavel por amarzenar as strings

int registro()  //função responsavel por cadastrar os usuarios no sistema
{ 
    //inicio da cadastração de variaveis/strings
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
     //final da cadastração de variaveis/strings
     
    printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuario
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
    	printf("Não foi possivel abrir o arquivo, Não localizado! . \n");
	}
    
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("Essas são as informações do usuário:");
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
    	printf("O Usuario não se encontra no sistema!. \n");
    	system("pause");
	}
    
    
    
}


int main()
{
	
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
    {
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	    
	    printf("### Cartório da Ebac ###\n \n"); //inicio do menu
	    printf("Escolha a opção desejada do menu:\n \n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar os nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("\t4 - Sair do Sistema\n\n");
	    printf("Opção: "); //fim do menu

	    scanf("%d" , &opcao); //armazenando a escolha do usuario 
	
	    system("cls"); //responsavel por limpar a tela 
	    
	    switch(opcao) //inicio da seleção 
	    {
	    case 1:
	    registro();	 //chamada de funções
	    break; 
		    
		case 2: 
	    consulta();	
		break;
		    
		case 3:
	    deletar();
		break;
		
		case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    break;
		    
		default:
		printf("Essa opção não está disponivel.\n");
		system("pause"); 
		break;	//fim da seleção
		
		}
	    
	
    }
}	
