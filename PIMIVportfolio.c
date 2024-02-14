#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


typedef struct
{
    char Login[30];
    char Password[30];
} Usuario;

typedef struct
{
    char nome[10];
    char cpf[15];
    char telefone[13];
    char rua[100];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char complemento[50];
    int  *nascimento;
    char email[100];
    char diagnostico[11];
    char comorbidade[50];
    int opcaoComorbidade;
    char cep[10];
    int idade;

} cadastro;

// FUNÇÃO LOGIN//

int fazerLogin()
{
    Usuario loginCadastrado;
    Usuario tentativa;

    setlocale(LC_ALL, "portuguese");

    strcpy(loginCadastrado.Login, "admin");
    strcpy(loginCadastrado.Password, "123");

    int i;

     telainicial(0);
    for (i = 0; i < 3; i++)
    {
        printf("SEJA BEM-VINDO!\n\n");system("color 0a");
        printf("Digite seu login: ");
        scanf("%s", &tentativa.Login);
        printf("Digite sua senha:");
        scanf("%s", &tentativa.Password);

        if ((strcmp(tentativa.Login, loginCadastrado.Login) == 0) && (strcmp(tentativa.Password, loginCadastrado.Password) == 0))
        {
            printf(">>>>LOGIN REALIZADO COM SUCESSO!>>>>\n");
            return 1;
        }

        else
        {
            printf("USUÁRIO E/OU SENHA INCORRETO(A).TENTE NOVAMENTE.\n");
        }
    }
    return 0;
}

// FUNÇÃO PARA CALCULAR IDADE//

int calculaIdade(int *nascimento)
{
    int hoje[3] = {23, 11, 2022};
    int anos = hoje[2] - nascimento[2] - 1;
    if (hoje[2] == nascimento[2])
        return 0;
    if (hoje[1] > nascimento[1])
        anos++;
    if (hoje[1] == nascimento[1] && hoje[0] >= nascimento[0])
        anos++;
    return anos;
}

int *lerData()
{
    int dia, mes, ano;
    int *data = (int *)malloc(3 * sizeof(int));
    scanf("%d/%d/%d", &dia, &mes, &ano);
    data[0] = dia;
    data[1] = mes;
    data[2] = ano;
    return data;
}

void escreverPessoaNoArquivo(cadastro *pessoa)
{
    printf("\n\n");
    printf("SALVANDO CADASTRO DO(A) PACIENTE %s...\n", pessoa->nome);
    FILE *out_file = fopen("pacientestodos.txt", "a+");
    fprintf(out_file ,"\ Nome: %s",&pessoa->nome);
    fprintf(out_file,"\nCEP: %s",&pessoa->cep);
    fprintf(out_file,"\nIdade: %d",&pessoa->idade);
    fprintf(out_file,"\nComorbidade: %s \n\n",&pessoa->comorbidade);


    if (out_file == NULL)
    {
        printf("N�o consegui abrir arquivo\n");
        exit(-1);
    }
    fseek(out_file, 0, SEEK_END);
    int size = ftell(out_file);

    if (0 == size)
    {
        printf("Arquivo está vazio. Criando cabeçalho\n");
        fprintf(out_file, "nome,cpf,telefone,idade,rua,complemento,bairro,cidade,estado,cep,email,diagnostico,comorbidade,temComorbidade");
    }

    fprintf(out_file, "\n%s,%s,%s,%d,%s,%d,%s,%s,%s,%s,%s,%s,%s,%d",
            pessoa->nome,
            pessoa->cpf,
            pessoa->telefone,
            pessoa->idade,
            pessoa->rua,
            pessoa->complemento,
            pessoa->bairro,
            pessoa->cidade,
            pessoa->estado,
            pessoa->cep,
            pessoa->email,
            pessoa->diagnostico,
            pessoa->comorbidade,
            pessoa->opcaoComorbidade);


}

int cadastrar()
{
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tMODO DE CADASTRO\n");
    printf("\n\n-------------------------------------------------------------------------------------------------------------\n");
    cadastro *pessoa = (cadastro *)malloc(sizeof(cadastro));
    printf("Nome completo: ");
    fflush(stdin);
    scanf("%[^\n]s", &pessoa->nome);
    printf("CPF: ");
    fflush(stdin);
    scanf("%[^\n]s", &pessoa->cpf);
    printf("E-mail: ");
    fflush(stdin);
    scanf("%[^\n]s", &pessoa->email);
    printf("Data de Nascimento: ");
    fflush(stdin);
    pessoa->nascimento = lerData();
    pessoa->idade = calculaIdade(pessoa->nascimento);
    printf("Idade: %d\n", pessoa->idade);
    fflush(stdin);
    printf("Telefone: ");
    fflush(stdin);
    scanf("%[^\n]s", &pessoa->telefone);
    printf("Rua: ");
    fflush(stdin);
    scanf("%s", &pessoa->rua);
    printf("Complemento: ");
    fflush(stdin);
    scanf("%s", &pessoa->complemento);
    printf("Bairro: ");
    fflush(stdin);
    scanf("%s", &pessoa->bairro);
    printf("Cidade: ");
    fflush(stdin);
    scanf("%s", &pessoa->cidade);
    printf("Estado: ");
    fflush(stdin);
    scanf("%s", &pessoa->estado);
    printf("CEP: ");
    fflush(stdin);
    scanf("%s", &pessoa->cep);
    printf("Data do diagnostico: ");
    scanf("%s", &pessoa->diagnostico);
    printf("Comorbidade?(Sim 1/Nao 2): ");
    fflush(stdin);
    scanf("%d", &pessoa->opcaoComorbidade);
    if(pessoa->opcaoComorbidade == 1) {
      printf("Informe a Comorbidade: ");
      fflush(stdin);
      scanf("%[^\n]s", &pessoa->comorbidade);
     if(pessoa->opcaoComorbidade == 1) {
      printf("Grupo de risco. ");
      escreverPessoaNoArquivo(pessoa);
      }
      }

    }




int main()
{
    int fezLogin = fazerLogin();
     if (fezLogin == 0)
         return 1;

     system("cls");

     int opcao;
     while (1)
    {
         printf("\n\n-------------------------------------------------------------------------------------------------------------\n");
         printf("                       ************CADASTRO DE PACIENTES COM COVID-19\n**********");
         printf("\n\n-------------------------------------------------------------------------------------------------------------\n");
         printf("DIGITE...\n\n");
         printf("1- CADASTRAR\n");
         printf("0- SAIR\n");
         scanf("%d", &opcao);
         fflush(stdin);

         system("cls");

         switch (opcao)
         {
         case 1:
             cadastrar();
             break;
         default:
             printf("\n----------------------------------------------------------------------------------------------------------------------\n");
             printf("          ***************************************VOLTE SEMPRE********************");
             printf("\n----------------------------------------------------------------------------------------------------------------------\n");
             return 0;

         }
     }
}
void telainicial(int Cancelar){

    system("color 2f");


    system("cls");
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora
    printf("%d:",data_hora_atual->tm_min);//minuto
    printf("%d\n",data_hora_atual->tm_sec);//segundo
    printf("\nData ........: %d/", data_hora_atual->tm_mday);
    printf("%d/",data_hora_atual->tm_mon+1); //m�s
    printf("%d\n\n",data_hora_atual->tm_year+1900); //ano

    printf("\n                              ************************************************************");
    printf("\n                                        **************** -TELA DE LOGIN- ****************");
    printf("\n                              ************************************************************\n\n");


    return segundos;
}
