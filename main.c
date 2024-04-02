//Programa feito de maneira enxuta por ser manuscrito, preservando minhas mãos
//emanu que fez
#include <stdio.h>
#include <locale.h>

struct Funcionario{
    int id;
    char nome[100];
    float salario;
    int quantidade_filhos;
};

void incluirFuncionario(struct Funcionario funcionario[], int *numFuncionarios){
    printf("Informe o nome do funcionário: ");
    fflush(stdin);
    fgets(funcionario[*numFuncionarios].nome, sizeof(funcionario[*numFuncionarios].nome), stdin);
    funcionario[*numFuncionarios].nome[strcspn(funcionario[*numFuncionarios].nome, "\n")] = '\0';
    printf("Informe o salário do funcionário: ");
    scanf("%f", &funcionario[*numFuncionarios].salario);
    printf("Informe a quantidade de filhos: ");
    scanf("%d", &funcionario[*numFuncionarios].quantidade_filhos);
    funcionario[*numFuncionarios].id = *numFuncionarios;
    printf("O funcionário foi cadastrado no ID %d", funcionario[*numFuncionarios].id);
    (*numFuncionarios)++;
}

void eliminarRegistro(struct Funcionario funcionario[], int id_funcionario, int *numFuncionarios)
{
    printf("\n");
    if (id_funcionario > *numFuncionarios || id_funcionario < 1) {
        printf("Funcionário não cadastrado");
    } else {
        for (int i = id_funcionario - 1; i < *numFuncionarios - 1; ++i) {
            funcionario[i] = funcionario[i+1];
        }
        printf("O funcionário foi deletado do sistema.");
    }
    (*numFuncionarios)--;
}

void alterarRegistro(struct Funcionario funcionario[], int id_funcionario, int *numFuncionarios)
{
    int aux_interna;
    printf("\nO que deseja alterar no funcionário %s de ID %d>>>", funcionario[id_funcionario].nome, id_funcionario);
    printf("\n1 - Nome");
    printf("\n2 - Salário");
    printf("\n3 - Quantidade de filhos\n");
    scanf("%d", &aux_interna);

    switch(aux_interna) {
        case 1:
            printf("Digite o novo nome para o funcionário (apenas primeiro nome): ");
            scanf("%s", funcionario[id_funcionario].nome);
            printf("O novo nome agora é %s", funcionario[id_funcionario].nome);
            break;

        case 2:
            printf("Digite o novo salário para o funcionário: ");
            scanf("%f", &funcionario[id_funcionario].salario);
            printf("O novo salário agora é %.2f", funcionario[id_funcionario].salario);
            break;

        case 3:
            printf("Digite a nova quantidade de filhos do funcionário: ");
            scanf("%d", &funcionario[id_funcionario].quantidade_filhos);
            printf("A nova quantidade de filhos agora é %d", funcionario[id_funcionario].quantidade_filhos);
            break;

        default:
            printf("Opção inválida!");
            break;
    }
}

void listarTodosRegistros(struct  Funcionario funcionario[], int *numFuncionarios)
{
    for (int i = 0; i < *numFuncionarios; ++i) {
        printf("\n-----FUNCIONÁRIO ID %d------", funcionario[i].id);
        printf("\n|NOME: %s", funcionario[i].nome);
        printf("\n|SALÁRIO: %.2f", funcionario[i].salario);
        printf("\n|Qtd filhos: %d", funcionario[i].quantidade_filhos);
    }
}

void listarRegistrosMais2Filhos(struct Funcionario funcionario[], int *numFuncionarios)
{
    for (int i = 0; i < *numFuncionarios; ++i) {
        if (funcionario[i].quantidade_filhos > 2){
            printf("\n-----FUNCIONÁRIO ID %d------", funcionario[i].id);
            printf("\n|NOME: %s", funcionario[i].nome);
            printf("\n|SALÁRIO: %.2f", funcionario[i].salario);
            printf("\n|Qtd filhos: %d", funcionario[i].quantidade_filhos);
        }
    }
}

void somaSalarios(struct Funcionario funcionario[], int *numFuncionarios)
{
    float aux_interna = 0;
    for (int i = 0; i < *numFuncionarios; ++i) {
        aux_interna += funcionario[i].salario;
    }

    printf("A soma de todos os salários é igual a: %.2f", aux_interna);
}

void retornarMaiorSalario(struct Funcionario funcionario[], int *numFuncionarios)
{
    float maiorSalario = funcionario[0].salario;
    int id = funcionario[0].id;

    for (int i = 1; i < *numFuncionarios; i++) {
        if (funcionario[i].salario > maiorSalario) {
            maiorSalario = funcionario[i].salario;
            id = funcionario[i].id;
        }
    }

    printf("O maior salário é do funcionário de ID %d, com a bagatela de: %.2f\n", id, maiorSalario);
}

void retornarMenorSalario(struct Funcionario funcionario[], int *numFuncionarios)
{
    float menorSalario = funcionario[0].salario;
    int id = funcionario[0].id;

    for (int i = 1; i > *numFuncionarios; i++) {
        if (funcionario[i].salario > menorSalario) {
            menorSalario = funcionario[i].salario;
            id = funcionario[i].id;
        }
    }

    printf("O menor salário é do funcionário de ID %d, com a bagatela de: %.2f\n", id, menorSalario);
}

void aumentarSalariosMenorQue1000(struct Funcionario funcionario[], int *numFuncionarios)
{
    for (int i = 0; i < *numFuncionarios; ++i) {
        if(funcionario[i].salario < 1000)
        {
            float santigo = funcionario[i].salario;
            funcionario[i].salario += funcionario[i].salario * 10 / 100;
            printf("O funcionário de ID %d teve seu salario aumentado em 10%%, passando de %.2f para %.2f\n", funcionario[i].id, santigo, funcionario[i].salario);

        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct Funcionario funcionario[100];
    int a = 1, numFuncionarios = 0, id_funcionario;
    do
    {
        fflush(stdin);
        printf("\nDigite a opção que você deseja executar: ");
        printf("\n1 - Eliminar um registro");
        printf("\n2 - Alterar um registro");
        printf("\n3 - Incluir um registro");
        printf("\n4 - Listar todos os registros");
        printf("\n5 - Listar apenas os registros que possuam funcionários com mais de 2 filhos");
        printf("\n6 - Retornar a soma de todos os salários da empresa");
        printf("\n7 - Retornar o maior salário");
        printf("\n8 - Retornar o menor salário");
        printf("\n9 - Aumentar o salário dos funcionários que possuem salário abaixo de R$1000,00 em 10%%");
        printf("\n10 - Encerrar o programa\n");
        scanf("%d", &a);

        switch(a) {
            case 1:
                printf("\nDigite o ID do funcionário que deseja eliminar: ");
                scanf("%d", &id_funcionario);
                eliminarRegistro(funcionario, id_funcionario, &numFuncionarios);
                fflush(stdin);
                break;

            case 2:
                printf("\nDigite o ID do funcionário que deseja alterar: ");
                scanf("%d", &id_funcionario);
                alterarRegistro(funcionario, id_funcionario, &numFuncionarios);
                fflush(stdin);
                break;

            case 3:
                incluirFuncionario(funcionario, &numFuncionarios);
                fflush(stdin);
                break;

            case 4:
                listarTodosRegistros(funcionario, &numFuncionarios);
                fflush(stdin);
                break;

            case 5:
                listarRegistrosMais2Filhos(funcionario, &numFuncionarios);
                fflush(stdin);
                break;

            case 6:
                somaSalarios(funcionario, &numFuncionarios);
                break;

            case 7:
                retornarMaiorSalario(funcionario, &numFuncionarios);
                break;

            case 8:
                retornarMenorSalario(funcionario, &numFuncionarios);
                break;

            case 9:
                aumentarSalariosMenorQue1000(funcionario, &numFuncionarios);
                break;

            case 10:
                printf("Obrigado por utilizar o programa");
                break;

            default:
                printf("Opção inválida!");
                break;
        }


    }while(a != 10);

    return 0;
}
