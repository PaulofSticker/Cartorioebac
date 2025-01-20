#include <stdio.h> //biblioteca de comunicacao
#include <stdlib.h> //biblioteca de alocacao de espaco
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> // biblioteca responsavel por cuidar da strings

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria arquivo
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao localizado! \n");
	}
	
	while(fgets(conteudo,200, file) != NULL)
	{
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuario nao se encontra no sistema!. \n");
		system("pause");
				
	}		
}

int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");

		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartorio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opcao desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar os nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
		printf("Opcao: "); //fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuario
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro();
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
			printf("Opcao invalida!\n");
			system("pause");
			break;	
		}
	
		}
	
	
	
	
}
