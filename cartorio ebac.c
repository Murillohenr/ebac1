#include <stdio.h> //biblioteca de cominicacoa de usuario
#include <stdlib.h>//biblioteca de alacocao de espaco de memoria
#include <locale.h>//biblioteca de alacacoes de texto por regiao
#include <string.h>//biblioTECA responsavel por cuidar das string

int registro()
{
	//inicio das criacoes das variaveis,strings
	char arquivo[40];
	char cpf [40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das criacoes das string
	
	printf("digite o cpf a ser cadastrado:");//coletando o cpf do usuario
	scanf("%s",cpf);//%s refere-se a strings
	
	
	strcpy(arquivo,cpf);//responsavel por copiar os valores da string
	
	FILE *file;//criar arquivo
	file = fopen(arquivo,"w");//cria o arquivo e o "w"significa escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	
	file = fopen(arquivo,"a");//abrir o arquivo
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");//nome a ser cadastrado do usuario
	scanf("%s",nome);//%s refere-se a strings
	
	
	file = fopen(arquivo,"a");//abrir aquivo 
	fprintf(file,nome);//salvar o valor da variavel
	fclose(file);//fecha arquivo
	
	file = fopen(arquivo,"a");//abrir arquivo 
	fprintf(file,",");
	fclose(file);
	
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
		
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);


	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file =fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");


}
int consulta()//consulta do usuario 
{
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado:\n");//cpf a ser consultado
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)//quando o arquivo nao e encontrado
	{
		printf("nao foi possivel abrir o arquivo cpf nao localizado! \n");
		
	}
	while(fgets (conteudo, 200, file ) != NULL )//
	
	{
		printf("\nEssas sao as informacoes do usuario:\n\n");
		printf("%s",conteudo);
		printf("\n\n");
	}
		system("pause");
}

int deletar()//deletar o usuario 
{
	char cpf [40];
	
	printf("digite o cpf do usuario a ser deletado. \n");//cpf a ser deletado
	scanf("%s",cpf);
	
	remove(cpf);
	FILE *file;
	file = fopen(cpf,"r");

	
	if (file == NULL)
	
	{
	printf("usuario deletado com sucesso:\n");
	printf("volte ao menu:\n");
	system("pause");	
	}
	
	
}

int main( )
{
	int opcao=0;//defenindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
			system("cls");
			
			setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
			printf("###cartorio da ebac###\n\n");
			printf("cadastro de usuarios\n\n");
			printf("\t1 - registrar nomes\n\n");
			printf("\t2 - consultar nomes\n\n");
			printf("\t3 - deletar nomes\n\n");//fim do menu
			printf("\t4 -sair do sistema\n\n");
			printf("opcao");
		
			scanf("%d" , &opcao);//armazenando a escolha do usuario
		
			system("cls");//responsavel por limpa a tela
	
	switch(opcao)//inicio do menu
{

	
			case 1:
			registro();//chamadas de funcoes 'registro'
			break;
		
			case 2:
			consulta();//chamadas de funcoes 'consultar'
			break;
			
			case 3:
			deletar();//chamads funcoes 'deletar'
			break;
			
			case 4:
			printf("\t -###obrigado por utilizar o sistema### \n\n");
			return 0;
			break;
		
			
			default:
			printf("essa opcao nao esta disponivel");//fim da selecao 	
			system("pause");	
			break;
			//fim do programa
}

		
}

}
