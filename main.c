#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void listarObras();
void listarTodasAsObras();
void adicionarObra();
void removerObra();

typedef struct TV
{
    int id;
    char titulo [50];
    char sinopse [150];
    unsigned int dataDeLancamento;
    char categoria [15];
} TV;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int acaoPrincipal = 0;

    #ifdef _WIN32
    char limparTela [4] = "cls";
    #endif // _WIN32

    #ifdef linux
    char limparTela [6] = "clear";
    #endif // linux

    while (acaoPrincipal != 9)
    {
        do
        {
            system (limparTela);
            printf ("\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("|Digite (1) para listar obras em progresso                                |\n");
            printf ("|Digite (2) para listar obras completados                                 |\n");
            printf ("|Digite (3) para listar obras pausadas                                    |\n");
            printf ("|Digite (4) para listar obras abandonadas                                 |\n");
            printf ("|Digite (5) para listar obras que se planeja assistir                     |\n");
            printf ("|Digite (6) para listar todas as obras                                    |\n");
            printf ("|Digite (7) para adicionar uma obra                                       |\n");
            printf ("|Digite (8) para remover uma obra                                         |\n");
            printf ("|Digite (9) para sair                                                     |\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("Digite o número que corresponde à ação: ");
            scanf ("%i", &acaoPrincipal);
        }
        while (acaoPrincipal < 1 || acaoPrincipal > 9);

        switch (acaoPrincipal)
        {
        case 1:
            listarObras(limparTela, 1);
            break;
        case 2:
            listarObras(limparTela, 2);
            break;
        case 3:
            listarObras(limparTela, 3);
            break;
        case 4:
            listarObras(limparTela, 4);
            break;
        case 5:
            listarObras(limparTela, 5);
            break;
        case 6:
            listarTodasAsObras(limparTela);
            break;
        case 7:
            adicionarObra(limparTela);
            break;
        case 8:
            removerObra(limparTela);
            break;
        default:
            exit(0);
        }
    }
}

void listarObras (char limparTela [], int operacao)
{

    char localDoArquivo [30];

    switch (operacao)
    {
    case 1:
        strcpy(localDoArquivo, "./arquivos/obrasAssistidas.txt");
        break;
    case 2:
        strcpy(localDoArquivo, "./arquivos/obrasCompletadas.txt");
        break;
    case 3:
        strcpy(localDoArquivo, "./arquivos/obrasPausadas.txt");
        break;
    case 4:
        strcpy(localDoArquivo, "./arquivos/obrasAbandonadas.txt");
        break;
    case 5:
        strcpy(localDoArquivo, "./arquivos/obrasPlanejamento.txt");
        break;
    default:
        return;
    }

    FILE *arquivo = fopen (localDoArquivo, "r");

    if (arquivo == NULL)
    {
        printf("ERRO: Arquivo Inexistente");
        arquivo = fopen (localDoArquivo, "w");
        return;
    }

    char lista [10000];

    while (fgets(lista, 10000, arquivo) != NULL)
    {
        printf ("%s", lista);
    }
    fclose(arquivo);

}
void listarTodasAsObras (char limparTela [])
{

}

void adicionarObra (char limparTela [])
{
    unsigned int operacao;
    char localDoArquivo [30];
    TV show;

    do
    {
        system (limparTela);
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("|Digite (1) para adicionar à lista de obras assistidas                    |\n");
        printf ("|Digite (2) para adicionar à lista de obras completadas                   |\n");
        printf ("|Digite (3) para adicionar à lista de obras pausadas                      |\n");
        printf ("|Digite (4) para adicionar à lista de obras abandonadas                   |\n");
        printf ("|Digite (5) para adicionar à lista de obras em planejamento               |\n");
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &operacao);
    }
    while (operacao < 1 || operacao > 5);

    switch (operacao)
    {
    case 1:
        strcpy(localDoArquivo, "./arquivos/obrasAssistidas.txt");
        break;
    case 2:
        strcpy(localDoArquivo, "./arquivos/obrasCompletadas.txt");
        break;
    case 3:
        strcpy(localDoArquivo, "./arquivos/obrasPausadas.txt");
        break;
    case 4:
        strcpy(localDoArquivo, "./arquivos/obrasAbandonadas.txt");
        break;
    case 5:
        strcpy(localDoArquivo, "./arquivos/obrasPlanejamento.txt");
        break;
    default:
        return;
    }

    FILE *arquivo = fopen (localDoArquivo, "a");

    if (arquivo == NULL)
    {
        printf("ERRO: Arquivo Inexistente");
        arquivo = fopen (localDoArquivo, "w");
        return;
    }

    //show.id = (operationThatReadsFileAndReturnLastID);

    printf ("Type the title: \n");
    scanf ("%[^\n]s", &show.titulo);

    printf ("Type the synopsis: \n");
    scanf ("%[^\n]s", &show.sinopse);

    printf ("Type the aired date: \n");
    scanf ("%u", &show.dataDeLancamento);

    printf ("Type the category: \n");
    scanf ("%[^\n]s", &show.categoria);
}

void removerObra ()
{

}
