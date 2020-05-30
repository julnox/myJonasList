#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

void listarObras();
void listarTodasAsObras();
void adicionarObra();
void removerObra();
void checarLocal();

typedef struct TV
{
    char titulo [50];
    char sinopse [150];
    char dataDeLancamento [10];
    char categoria [15];
} TV;

FILE *arquivo;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    #ifdef _WIN32
    char limparTela [4] = "cls";
    #endif // _WIN32

    #ifdef linux
    char limparTela [6] = "clear";
    #endif // linux

    int acaoPrincipal;

    checarLocal ();

    while (acaoPrincipal != 9)
    {
        do
        {
            system ("clear");
            printf ("\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("| Digite (1) para listar obras em progresso                               |\n");
            printf ("| Digite (2) para listar obras completados                                |\n");
            printf ("| Digite (3) para listar obras pausadas                                   |\n");
            printf ("| Digite (4) para listar obras abandonadas                                |\n");
            printf ("| Digite (5) para listar obras que se planeja assistir                    |\n");
            printf ("| Digite (6) para listar todas as obras                                   |\n");
            printf ("| Digite (7) para adicionar uma obra                                      |\n");
            printf ("| Digite (8) para remover uma obra                                        |\n");
            printf ("| Digite (9) para sair                                                    |\n");
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

void checarLocal ()
{
    FILE *arquivo;
    char localDoArquivo [6][40] =
    {
    "./arquivos/obrasAssistidas.txt",
    "./arquivos/obrasCompletadas.txt",
    "./arquivos/obrasPausadas.txt",
    "./arquivos/obrasAbandonadas.txt",
    "./arquivos/obrasPlanejamento.txt",
    "./arquivos/todasAsObras.txt"
    };

    for (int i = 0; i < 6; i++)
    {
        arquivo = fopen (localDoArquivo[i], "w+");
        fclose(arquivo);
    }
}

void listarObras (char limparTela [6], int operacao)
{
    char localDoArquivo [50];
    char lista [1000];
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

    FILE *arquivo;

    arquivo = fopen (localDoArquivo, "r");

    while (fgets(lista, 1000, arquivo) != NULL)
    {
        printf("%s",lista);
    }
    fclose(arquivo);

}

void listarTodasAsObras (char limparTela [])
{
    FILE *arquivo = fopen ("./arquivos/todasAsObras.txt", "r");
    char lista [3000];

    while (fgets(lista, 1000, arquivo) != NULL)
    {
        printf("%s",lista);
    }
    fclose(arquivo);

}

void adicionarObra (char limparTela [])
{
    unsigned int operacao;
    char localDoArquivo [50];
    char titulo [50];
    char sinopse [150];
    char dataDeLancamento [10];
    char categoria [15];

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

    printf ("Digite o título: ");
    scanf ("%[^\n]s", &titulo);
    strcpy(show.titulo, titulo);

    printf ("Digite a sinopse: ");
    scanf ("%[^\n]s", &sinopse);
    strcpy(show.sinopse, sinopse);

    printf ("Digite a data de lançamento: ");
    scanf ("%s", &dataDeLancamento);
    strcpy(show.dataDeLancamento, dataDeLancamento);

    printf ("Digite a categoria: ");
    scanf ("%[^\n]s", &categoria);
    strcpy(show.categoria, categoria);

    fprintf (arquivo, "Título: %s\n Sinopse: %s\n Data de Lançamento: %s\n Categoria: %s\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);
}

void removerObra ()
{

}
