#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o 
#include <string.h> //biblioteca respons�veu por cuidar das string 

int registro() //Fun��o responsavel por cadastrar os usu�rios no sistema
{
	//Inicio de cria��o de vari�veis/string 
	char arquivo[40];	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //Coletendo informa��o do usu�rio 
	scanf("%s", cpf); //%s refere-se as string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //Salva o valor da variaveu 
	fclose(file); //Fecha o arquivo 
	
	file = fopen(arquivo ,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo ,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo ,"a");
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
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
        printf("Digite o CPF a ser consultado: ");
        scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado! .\n");
	}

    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��o do usu�rio");
    	printf("%s", conteudo);
    	printf("\n\n");
	}

        system("pause");

}

int deletar()
{
	    
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); 
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! .\n");
		system("pause");
		
	}
	    
	    
	    
}

int main()
    {
	int opcao=0; //definindo vari�veis 
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	    printf("escolha a op��o desejada do menu:\n\n");
	    printf("\t1 Registrar nomes\n");
	    printf("\t2 Consultar nomes\n");
	    printf("\t3 Deletar nomes\n"); //fim do menu 
	    printf("\t4 Sair do sistema\n\n");
	    printf("Este software pertence ao aluno Eduardo Maciel.\n");
	    printf("Op��o:");
	    
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	    
	
	    system("cls"); //Responsavel por limpar a tela
	    
	    
	    switch(opcao) //Inicio da sele��o do menu
		{
			case 1:
			registro(); //Chamada de fun��es 
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
			printf("Essa op��o n�o est� disponivel!\n");
     	    system("pause");
			break;	
	       }
	    }
	} 
