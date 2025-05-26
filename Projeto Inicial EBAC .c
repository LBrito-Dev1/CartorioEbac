#include <stdio.h> // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>	// biblioteca de aloca��es de texto por regi�o
#include <string.h>	// biblioteca responsavel por cuidar das string 

int registro() // Fun��o responsavel por cadastrar
{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	//inicio cria��o de vari�veis/string
	char arquivo[14];
	char cpf[11];
	char nome[40];
	char cargo[40];
	char data[10];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF: "); // coletando informa��o
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); // responsavel por copiar o valor das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o w significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite a data de admiss�o: ");
	scanf("%s",data);
	
	file = fopen(arquivo, "a");
	fprintf(file,data);
	fclose(file);
	
	system("pause");
}
int consultar()
{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	char cpf[14];
	char conteudo[100];
	
	printf("Digite o CPF: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Arquivo n�o encontrado.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}
int deletar()
{
	char cpf[14];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	system("cls");
	
	if(file == NULL)
	{
		printf("Usu�rio n�o cadastrado no sistema!\n");
		system("pause");
	}
	else
	{
		printf("Usu�rio deletado!\n");
		system("pause");
	}
}
int main()
{
	int opcao=0; // Definindo vari�veis
	 
	while (1)

	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
		printf("Base de Alunos da EBAC\n\n"); // inicio do menu	
		printf("Qual a op��o desejada?\n\n");
		printf("\t1 Registrar\n");
		printf("\t2 Consultar\n");
		printf("\t3 Deletar\n");
		printf ("\t4 Sair do sistema\n\n");
		printf("Op��o: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usu�rio
	
		system("cls"); // limpar o comando
	
		switch(opcao) //inicio da sele��o
		{
			case 1:
			registro();
			break;
			
			case 2: 
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n\n");
			return 0;
			break;
	
			
			default: 
			printf("Essa op��o n�o est� disponivel!\n");
			system("pause");
		} // fim da sele��o
	}			
}

