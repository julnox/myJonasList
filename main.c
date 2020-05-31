#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>

void checarLocal();
void listarObras();
void listarTodasAsObras();
void adicionarObra();
void removerObra();
void buscarObra();

typedef struct TV
{
    char titulo [50];
    char sinopse [150];
    char dataDeLancamento [10];
    char categoria [15];
} TV;

int main()
{
    int acaoPrincipal;

    #ifdef _WIN32
    char limparTela [4] = "cls";
    #endif // _WIN32

    #ifdef linux
    char limparTela [6] = "clear";
    #endif // linux

    setlocale(LC_ALL, "Portuguese");

    checarLocal ();

    while (acaoPrincipal != 10)
    {
        do
        {
            system (limparTela);
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
            printf ("| Digite (9) para buscar uma obra                                         |\n");
            printf ("| Digite (10) para sair                                                   |\n");
            printf ("--------------------------------MyJonasList--------------------------------\n");
            printf ("Digite o número que corresponde à ação: ");
            scanf ("%i", &acaoPrincipal);

        }
        while (acaoPrincipal < 1 || acaoPrincipal > 10);

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
        case 9:
            buscarObra(limparTela);
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

void listarTodasAsObras (char limparTela [])
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

void adicionarObra (char limparTela [])
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
