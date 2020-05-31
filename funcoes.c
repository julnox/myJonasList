#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>
#include "myjonaslist.h"

typedef struct TV
{
    char titulo [50];
    char sinopse [150];
    char dataDeLancamento [12];
    char categoria [15];
} TV;

FILE *arquivo;

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

void listarObras (int acaoListar)
{
    char localDoArquivo [35];
    char lista [1000];
    char opcao [27];

    switch (acaoListar)
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
    unsigned int acaoAdicionar;
    char localDoArquivo [35];
    TV show;

    acaoAdicionar = menuAdicionar();

    switch (acaoAdicionar)
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
    getchar();
    fgets (show.titulo, 50, stdin);

    printf ("Digite a sinopse: ");
    fgets (show.sinopse, 150, stdin);

    printf ("Digite a data de lançamento: ");
    fgets (show.dataDeLancamento, 12, stdin);

    printf ("Digite a categoria: ");
    fgets (show.categoria, 15, stdin);

    show.titulo[strcspn(show.titulo, "\n")] = '\0';
    show.sinopse[strcspn(show.sinopse, "\n")] = '\0';
    show.dataDeLancamento[strcspn(show.dataDeLancamento, "\n")] = '\0';
    show.categoria[strcspn(show.categoria, "\n")] = '\0';

    arquivo = fopen (localDoArquivo, "a");
    fprintf (arquivo, "\n Título: %s\n Sinopse: %s\n Data de Lançamento: %s\n Categoria: %s\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    arquivo = fopen ("./arquivos/todasAsObras.txt", "a");
    fprintf (arquivo, "\n Título: %s\n Sinopse: %s\n Data de Lançamento: %s\n Categoria: %s\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    printf ("Obra Adicionada com Sucesso!\n");
    sleep (1);
}

void removerObra ()
{
    unsigned int acaoRemover;

    acaoRemover = menuRemover();

    switch (acaoRemover)
    {

    }
}

void pesquisarObra ()
{
    char titulo [50];
    char google [80];
    char opcao [15];
    unsigned int acaoPesquisar;

    acaoPesquisar = menuPesquisar();

    #ifdef _WIN32
    char comando[19] = {"start chrome.exe "};
    #endif // _WIN32

    #ifdef linux
    char comando[9] = {"firefox "};
    #endif // linux

    //I'm Felling Lucky URL:
    //"https://www.google.com/search?q=term&btnI"

    switch (acaoPesquisar)
    {
    case 1:
        strcpy(google, "\"https://www.google.com/search?q=myanimelist-");
        strcpy(opcao, "Anime");
        break;
    case 2:
        strcpy(google, "\"https://www.google.com/search?q=imdb-");
        strcpy(opcao, "Série/Filme");
        break;
    case 3:
        strcpy(google, "\"https://www.google.com/search?q=");
        strcpy(opcao, "Outros");
        break;
    default:
        return;
    }

    limparTela();
    printf ("---------------------Pesquisar %s------------------------\n", opcao);
    printf ("Digite o nome de uma obra: ");
    getchar();
    fgets (titulo, 50, stdin);
    printf ("---------------------Pesquisar %s------------------------\n", opcao);

    for (int i = 0; i < 50; i++)
    {
        if (titulo[i] == 32)
        {
            titulo[i] = 45;
        }
    }

    strcat(google, titulo);
    strcat(google, "&btnI\"");
    strcat(comando, google);

    printf ("Você será redirecionado para uma página\n");
    sleep (1);

    system (comando);
}
