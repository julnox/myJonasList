#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myjonaslist.h"

typedef struct TV
{
    char titulo [50];
    char sinopse [1200];
    char dataDeLancamento [12];
    char categoria [150];
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
    char localDoArquivo [5][35] =
    {
        "./arquivos/obrasEmProgresso.txt",
        "./arquivos/obrasCompletadas.txt",
        "./arquivos/obrasPausadas.txt",
        "./arquivos/obrasAbandonadas.txt",
        "./arquivos/obrasPlanejamento.txt",
    };

    for (int i = 0; i < 5; i++)
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
    char ch;
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

    ch = getc(arquivo);
    limparTela();
    printf ("---------------------Lista de %s------------------------\n", opcao);
    while (ch != EOF)
    {
        if (ch == ';')
        {
            ch = '\b';
            printf ("\n");
        }

        else if (ch == '\n')
        {
            printf ("\n");
        }

        printf("%c", ch);
        ch = getc(arquivo);
    }
    printf ("---------------------Lista de %s------------------------\n", opcao);
    fclose(arquivo);

    getchar();
    getchar();

}

void listarTodasAsObras ()
{
    char localDoArquivo [5][35] =
    {
        "./arquivos/obrasEmProgresso.txt",
        "./arquivos/obrasCompletadas.txt",
        "./arquivos/obrasPausadas.txt",
        "./arquivos/obrasAbandonadas.txt",
        "./arquivos/obrasPlanejamento.txt",
    };
    char ch;
    limparTela();
    printf ("-------------------------Lista de Todas as Obras-------------------------\n");
    for (int i = 0; i < 5; i++)
    {
        arquivo = fopen(localDoArquivo[i], "r");
        ch = getc(arquivo);

        while (ch != EOF)
        {
            if (ch == ';')
            {
                ch = '\b';
                printf ("\n");
            }
            else if (ch == '\n')
            {
                printf ("\n");
            }
            printf("%c", ch);
            ch = getc(arquivo);
        }
        fclose(arquivo);
    }
    printf ("-------------------------Lista de Todas as Obras-------------------------\n");
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

    printf ("Digite o título (50 caracteres): ");
    getchar();
    fgets (show.titulo, 50, stdin);

    printf ("Digite a sinopse (1200 caracteres): ");
    fgets (show.sinopse, 1200, stdin);

    printf ("Digite a data de lançamento (12 caracteres): ");
    fgets (show.dataDeLancamento, 12, stdin);

    printf ("Digite as categorias separadas por vírgula (150 caracteres): ");
    fgets (show.categoria, 150, stdin);

    show.titulo[strcspn(show.titulo, "\n")] = '\0';
    show.sinopse[strcspn(show.sinopse, "\n")] = '\0';
    show.dataDeLancamento[strcspn(show.dataDeLancamento, "\n")] = '\0';
    show.categoria[strcspn(show.categoria, "\n")] = '\0';

    for (int i = 0; show.titulo[i] != '\0'; i++)
    {
        if (show.titulo[i] == ';')
        {
            show.titulo[i] = '\0';
        }
    }

    for (int i = 0; show.sinopse[i] != '\0'; i++)
    {
        if (show.sinopse[i] == ';')
        {
            show.sinopse[i] = '\0';
        }
    }

    for (int i = 0; show.dataDeLancamento[i] != '\0'; i++)
    {
        if (show.dataDeLancamento[i] == ';')
        {
            show.dataDeLancamento[i] = '\0';
        }
    }

    for (int i = 0; show.categoria[i] != '\0'; i++)
    {
        if (show.categoria[i] == ';')
        {
            show.categoria[i] = '\0';
        }
    }

    arquivo = fopen (localDoArquivo, "a");
    fprintf (arquivo, "Título: %s;Sinopse: %s;Data de Lançamento: %s;Categoria: %s\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    printf ("Obra Adicionada com Sucesso!\n");
    sleep (1);
}

void removerObra ()
{
    unsigned int acaoRemover;
    char localDoArquivo [35];
    char localArqTemp [34] = {"./arquivos/arquivoTemporario.txt"};
    char ch;
    int linhaParaDeletar, temp = 1, cont = 1;
    FILE *arquivoOriginal, *arquivoTemp;

    acaoRemover = menuRemover();

    switch (acaoRemover)
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

    arquivoOriginal = fopen(localDoArquivo, "r");

    ch = getc(arquivoOriginal);
    limparTela();

    printf ("--------------------------Remover-------------------------------\n");

    if (ch != EOF)
    {
        printf ("1:\n ");
    }

    while (ch != EOF)
    {
        if (ch == '\n')
        {
            printf ("\n\n");
            ch = getc(arquivoOriginal);
            if (ch == 'T')
            {
                cont++;
                printf ("%i:\n%c", cont, ch);
                ch = getc(arquivoOriginal);
            }
        }
        else if (ch == ';')
        {
            ch = '\b';
            printf("\n");
        }
        else if (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(arquivoOriginal);
        }
    }
    printf ("\n--------------------------Remover-------------------------------\n");

    rewind(arquivoOriginal);

    do
    {
        printf("\nDigite o número da obra que deseja deletar:");
        scanf("%d", &linhaParaDeletar);
    }
    while (linhaParaDeletar < 1 || linhaParaDeletar > cont);

    arquivoTemp = fopen(localArqTemp, "w");

    ch = getc(arquivoOriginal);

    while (ch != EOF)
    {
        if (ch == '\n')
        {
            putc(ch, arquivoTemp);
            temp++;
        }
        else if (temp != linhaParaDeletar && ch != EOF)
        {
            putc(ch, arquivoTemp);
        }
        ch = getc(arquivoOriginal);
    }
    remove(localDoArquivo);
    rename(localArqTemp, localDoArquivo);

    fclose(arquivoOriginal);
    fclose(arquivoTemp);
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
    char comando[15] = {"google-chrome "};
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

    for (int i = 0; titulo[i] != '\0'; i++)
    {
        if (titulo[i] == ' ')
        {
            titulo[i] = '-';
        }
    }

    strcat(google, titulo);
    strcat(google, "&btnI\"");
    strcat(comando, google);

    printf ("Comando : %s\n", comando);

    printf ("Você será redirecionado para uma página\n");
    sleep (1);

    system (comando);
}
