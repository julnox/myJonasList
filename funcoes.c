#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myJonasList.h"

FILE *arquivo;

typedef struct TV
{
    char titulo [50];
    char sinopse [150];
    char dataDeLancamento [10];
    char categoria [15];
} TV;

void limparTela ()
{
    #ifdef _WIN32
    char comandoLimparTela [4] = "cls";
    #endif // _WIN32

    #ifdef linux
    char comandoLimparTela [6] = "clear";
    #endif // linux

    system(comandoLimparTela);
}

void checarLocal ()
{
    char localDoArquivo [6][40] =
    {
        "./arquivos/obrasEmProgresso.txt",
        "./arquivos/obrasCompletadas.txt",
        "./arquivos/obrasPausadas.txt",
        "./arquivos/obrasAbandonadas.txt",
        "./arquivos/obrasPlanejamento.txt",
        "./arquivos/todasAsObras.txt"
    };

    for (int i = 0; i < 6; i++)
    {
        arquivo = fopen (localDoArquivo[i], "r");
        if (arquivo == NULL)
        {
            arquivo = fopen (localDoArquivo[i], "w");
            fclose(arquivo);
        }
        else
        {
            fclose(arquivo);
        }
    }
}

void listarObras (int operacao)
{
    char localDoArquivo [35];
    char lista [1000];
    char opcao [27];

    switch (operacao)
    {
    case 1:
        strcpy(localDoArquivo, "./arquivos/obrasEmProgresso.txt");
        strcpy(opcao, "Obras em Progresso");
        break;
    case 2:
        strcpy(localDoArquivo, "./arquivos/obrasCompletadas.txt");
        strcpy(opcao, "Obras Completadas");
        break;
    case 3:
        strcpy(localDoArquivo, "./arquivos/obrasPausadas.txt");
        strcpy(opcao, "Obras Pausadas");
        break;
    case 4:
        strcpy(localDoArquivo, "./arquivos/obrasAbandonadas.txt");
        strcpy(opcao, "Obras Abandonadas");
        break;
    case 5:
        strcpy(localDoArquivo, "./arquivos/obrasPlanejamento.txt");
        strcpy(opcao, "Obras Planeja-se Assistir");
        break;
    default:
        return;
    }

    arquivo = fopen (localDoArquivo, "r");

    limparTela();
    printf ("---------------------Lista de %s------------------------\n", opcao);
    while (fgets(lista, 1000, arquivo) != NULL)
    {
        printf("%s",lista);
    }
    printf ("---------------------Lista de %s------------------------\n", opcao);
    fclose(arquivo);

    getchar();
    getchar();

}

void listarTodasAsObras ()
{
    char lista [3000];
    arquivo = fopen ("./arquivos/todasAsObras.txt", "r");

    limparTela();
    printf ("---------------------Lista de Todas As Obras------------------------\n");
    while (fgets(lista, 1000, arquivo) != NULL)
    {
        printf("%s",lista);
    }
    printf ("---------------------Lista de Todas As Obras------------------------\n");

    fclose(arquivo);
    getchar();
    getchar();

}

void adicionarObra ()
{
    unsigned int operacao;
    char localDoArquivo [35];
    TV show;

    operacao = menuAdicionar();

    switch (operacao)
    {
    case 1:
        strcpy(localDoArquivo, "./arquivos/obrasEmProgresso.txt");
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

    printf ("Digite o título: ");
    scanf ("%[^\n]s", &show.titulo);
    //strcpy(show.titulo, );

    printf ("Digite a sinopse: ");
    scanf ("%[^\n]s", &show.sinopse);
    //strcpy(show.sinopse, scanf("%s"));

    printf ("Digite a data de lançamento: ");
    scanf ("%s", &show.dataDeLancamento);
    //strcpy(show.dataDeLancamento, scanf("%s"));

    printf ("Digite a categoria: ");
    scanf ("%[^\n]s", &show.categoria);
    //strcpy(show.categoria, scanf("%s"));

    arquivo = fopen (localDoArquivo, "a");
    fprintf (arquivo, "\n Título: %s\n Sinopse: %s\n Data de Lançamento: %s\n Categoria: %s\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    arquivo = fopen ("./arquivos/todasAsObras.txt", "a");
    fprintf (arquivo, "\n Título: %s\n Sinopse: %s\n Data de Lançamento: %s\n Categoria: %s\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    printf ("Obra Adicionada com Sucesso!\n");
    getchar();
    getchar();
}

void removerObra ()
{

}

void buscarObra ()
{
    char obra [1][20];
    char google[] = {"https://www.google.com/search?q="};

    //"https://www.google.com/search?q=term&btnI"
    #ifdef _WIN32
    char comando[] = {"start chrome.exe "};
    #endif // _WIN32

    #ifdef linux
    char comando[] = {"firefox "};
    #endif // linux

    printf ("Digite o nome de uma obra: \n");
    scanf("%s", &obra[0]);

    strcat(google, obra);
    strcat(google, "\&btnI");
    strcat(comando, google);
    printf("%s", comando);

    system (comando);
}
