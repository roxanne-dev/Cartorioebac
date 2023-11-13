#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro () //função responsáel por registrar os usuários no sistema
{
	//início da criação de variáveis/strings
	char arquivo[40]; //comando para salvar até 40 caracteres
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis/strings
	printf ("Digite o cpf a ser cadastrado:\n"); //coletando informação do usuário
	scanf ("%s",cpf); //o percent s dá o comando para salvar as strings 
	
	strcpy (arquivo,cpf); //responsável por copiar os valores das strings - puxando do CPF para o arquivo
	
	FILE *file; // cria o arquivo na nossa pasta
	file = fopen (arquivo,"w"); //cria o arquivo e o "w" significa escrever
	fprintf (file,cpf); //salva o valor da variável, o mesmo printf mas ao invés de mostrar para o usuário, envia para o file
	fclose (file); //fecha o arquivo, como no switch case, precisa fechar o arquivo
	
	file = fopen (arquivo, "a"); //a de atualização 
	fprintf (file, ", "); //Para ter uma vírgula depois do nome e ficar mais legível 
	fclose (file);
	
	
	printf ("Digite o nome a ser cadastrado:\n");
	scanf ("%s",nome);   
	
	file = fopen (arquivo,"a"); 
	fprintf (file, nome); 
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file, ", "); 
	fclose (file);
	
	
	printf ("Digite o sobrenome a ser cadastrado:\n");
	scanf ("%s",sobrenome);  
	
	file = fopen (arquivo,"a"); 
	fprintf (file, sobrenome); 
	fclose (file);
	
	file = fopen (arquivo,"a");
	fprintf (file, ", ");
	fclose (file);
	
		printf ("Digite o cargo a ser cadastrado:\n");
	scanf ("%s",cargo);  
	
	file = fopen (arquivo,"a"); 
	fprintf (file,cargo); 
	fclose (file);
		printf("\n\nO usuário foi cadastrado com sucesso!\n\n");
		printf("\n\nObrigada por escolher Roxy Developer!\n");
	
	system ("pause");
}

int consulta ()
{
	setlocale (LC_ALL,"portuguese");
	
	char cpf[40];
	char conteudo[200];
	 
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE*file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL);
	{	
		printf("\nEessas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n\n\n\n");
		printf("Obrigada por escolher Roxy Developer!\n");
	}

	system ("pause");
}

int deletar ()

{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:\n");
	scanf ("%s",cpf);
	
	remove(cpf); //automaticamente já deleta dentro da pasta designada
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);

	
	if(file == NULL)
	{
		printf ("\nCPF não cadastrado!\n");
		printf("\n\nObrigada por escolher Roxy Developer!\n");
		system ("pause");
	}
	
}

int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;

	for(laco=1;laco=1;)
	{
		
		system ("cls");
		
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem
		
		printf ("### CARTÓRIO DA EBAC ###\n\n"); //início do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t1 - Registrar nomes \n");
		printf ("\t2 - Consultar nomes \n");
		printf ("\t3 - Deletar nomes \n");
		printf ("\t4 - Sair do sistema \n\n"); 
		printf ("Opção: "); //fim do menu
	
		scanf ("%d" , &opcao); //armazenando a escolha do usuário
	
		system ("cls"); //responsável por limpar a tela
		
		switch (opcao) //início da seleção
		{
			case 1:
			registro (); //chamada de funções
			break;
			
			case 2:
			consulta ();
			break;
			
			case 3:
			deletar ();
			break;
		
			case 4:
			printf("obrigado por usar o nosso sistema!\n");
			return 0;
			break;
			
			
			default:
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
		}//fim de seleções
	}
}
