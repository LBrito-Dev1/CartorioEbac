#include <stdio.h> // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h>	// biblioteca de alocações de texto por região
#include <string.h>	// biblioteca responsavel por cuidar das string 

int registro() // Função responsavel por cadastrar
{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	//inicio criação de variáveis/string
	char arquivo[14];
	char cpf[11];
	char nome[40];
	char cargo[40];
	char data[10];
	//final da criação de variáveis/string
	
	printf("Digite o CPF: "); // coletando informação
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
	
	printf("Digite a data de admissão: ");
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
		printf("Arquivo não encontrado.\n");
	}
	
	while(fgets(conteudo, 100, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("Usuário não cadastrado no sistema!\n");
		system("pause");
	}
	else
	{
		printf("Usuário deletado!\n");
		system("pause");
	}
}
int main()
{
	int opcao=0; // Definindo variáveis
	 
	while (1)

	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
		printf("Base de Alunos da EBAC\n\n"); // inicio do menu	
		printf("Qual a opção desejada?\n\n");
		printf("\t1 Registrar\n");
		printf("\t2 Consultar\n");
		printf("\t3 Deletar\n");
		printf ("\t4 Sair do sistema\n\n");
		printf("Opção: "); // fim do menu
	
		scanf("%d", &opcao); // armazenando a escolha do usuário
	
		system("cls"); // limpar o comando
	
		switch(opcao) //inicio da seleção
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
			printf("Essa opção não está disponivel!\n");
			system("pause");
		} // fim da seleção
	}			
}

