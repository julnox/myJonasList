#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myJonasList.h"

void checarLocal ()
{
    FILE *arquivo;
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

void listarObras (char limparTela [6], int operacao)
{
    char localDoArquivo [35];
    char lista [1000];
    char opcao [27];
    FILE *arquivo;

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

    system (limparTela);
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

void listarTodasAsObras (char limparTela [6])
{
    char lista [3000];
    FILE *arquivo = fopen ("./arquivos/todasAsObras.txt", "r");

    system (limparTela);

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

void adicionarObra (char limparTela [6])
{
    unsigned int operacao;
    char localDoArquivo [35];
    FILE *arquivo;
    TV show;

    do
    {
        system (limparTela);
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("| Digite (1) para adicionar à lista de obras em progresso                 |\n");
        printf ("| Digite (2) para adicionar à lista de obras completadas                  |\n");
        printf ("| Digite (3) para adicionar à lista de obras pausadas                     |\n");
        printf ("| Digite (4) para adicionar à lista de obras abandonadas                  |\n");
        printf ("| Digite (5) para adicionar à lista de obras em planejamento              |\n");
        printf ("--------------------------------Adicionar----------------------------------\n");
        printf ("Digite o número correspondente à ação: ");
        scanf ("%i", &operacao);
    }
    while (operacao < 1 || operacao > 5);

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

void removerObra (char limparTela [6])
{

}

void buscarObra (char limparTela [6])
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
