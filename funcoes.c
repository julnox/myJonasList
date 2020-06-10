//Biblioteca padrão para entrada e saida.
#include <stdio.h>
//Biblioteca que possui funções associadas a alocação de memoria, controle de processos e etc.
#include <stdlib.h>
//Biblioteca que possui funções para comparação, atribuição e uso de strings.
#include <string.h>
//Uso da biblioteca para dar uma pausa temporaria.
#include <unistd.h>
//Biblioteca especifica do programa que importa funções incluidas no header.
#include "myjonaslist.h"

//Comando usado para criar um tipo de variavel.
typedef struct TV
{
    //O termo utilizado para identificar um sequencia de caracter.
    char titulo [50];
    char sinopse [1200];
    char dataDeLancamento [12];
    char categoria [150];
} TV;
//Atribuições que pode ser usada por todas as funções.
char localDoArquivo [35];
char localTodosArq [5][35] =
{
    "./arquivos/obrasEmProgresso.txt",
    "./arquivos/obrasCompletadas.txt",
    "./arquivos/obrasPausadas.txt",
    "./arquivos/obrasAbandonadas.txt",
    "./arquivos/obrasPlanejamento.txt",
};
//Comando usado para criação e manipulação de arquivos.
FILE *arquivo;
//Comando para limpar Tela(Linux)e(Windows).
void limparTela ()
{
//Condição para o pre-processamento do programa.
#ifdef _WIN32
    char comandoLimparTela [4] = "cls";
//Fechamento da condição
#endif // _WIN32

#ifdef linux
    char comandoLimparTela [6] = "clear";
#endif // linux
    //Manda um comando para o terminal do sistema.
    system(comandoLimparTela);
}

void checarLocal ()
{
    for (int i = 0; i < 5; i++)
    {
        arquivo = fopen (localTodosArq[i], "r");
        if (arquivo == NULL)
        {
            arquivo = fopen (localTodosArq[i], "w");
            fclose(arquivo);
        }
        else
        {
            fclose(arquivo);
        }
    }
}

void escolherLocalArq (unsigned int acao)
{
    switch (acao)
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
    default:
        strcpy(localDoArquivo, "./arquivos/obrasPlanejamento.txt");
        break;
    }
}

void listarObras (unsigned int acaoListar)
{
    if (acaoListar == 6)
    {
        return;
    }

    char caracter;

    escolherLocalArq(acaoListar);

    arquivo = fopen (localDoArquivo, "r");
    caracter = getc(arquivo);

    limparTela();
    printf ("----------------------------------Listar-------------------------------------\n");

    while (caracter != EOF)
    {
        if (caracter == ';')
        {
            caracter = '\b';
        }
        else
        {
            printf ("%c", caracter);
            caracter = getc(arquivo);
        }
    }

    printf ("----------------------------------Listar-------------------------------------\n");

    fclose(arquivo);

    getchar();
    getchar();

}

void listarTodasAsObras ()
{
    char caracter;

    limparTela();
    printf ("---------------------------Lista de Todas as Obras---------------------------\n");

    for (int i = 0; i < 5; i++)
    {
        arquivo = fopen(localTodosArq[i], "r");
        caracter = getc(arquivo);

        while (caracter != EOF)
        {
            if (caracter == ';')
            {
                caracter = '\b';
            }
            else
            {
                printf ("%c", caracter);
                caracter = getc(arquivo);
            }
        }
        fclose(arquivo);
    }

    printf ("---------------------------Lista de Todas as Obras---------------------------\n");

    getchar();
    getchar();
}

void adicionarObra (unsigned int acaoAdicionar)
{
    if (acaoAdicionar == 6)
    {
        return;
    }

    TV show;

    escolherLocalArq(acaoAdicionar);

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
            show.titulo[i] = ' ';
        }
    }

    for (int i = 0; show.sinopse[i] != '\0'; i++)
    {
        if (show.sinopse[i] == ';')
        {
            show.sinopse[i] = ' ';
        }
    }

    for (int i = 0; show.dataDeLancamento[i] != '\0'; i++)
    {
        if (show.dataDeLancamento[i] == ';')
        {
            show.dataDeLancamento[i] = ' ';
        }
    }

    for (int i = 0; show.categoria[i] != '\0'; i++)
    {
        if (show.categoria[i] == ';')
        {
            show.categoria[i] = ' ';
        }
    }

    arquivo = fopen (localDoArquivo, "a");
    fprintf (arquivo, "Título: %s;\nSinopse: %s;\nData de Lançamento: %s;\nCategoria: %s;\n\n", show.titulo, show.sinopse, show.dataDeLancamento, show.categoria);
    fclose(arquivo);

    printf ("Obra Adicionada com Sucesso!\n");
    sleep (1);
}

void removerObra (unsigned int acaoRemover)
{
    if (acaoRemover == 6)
    {
        return;
    }

    char localArqTemp [34] = {"./arquivos/arquivoTemporario.txt"};
    char caracter;
    int obraParaDeletar, cont = 1, cont2 = 1, contPV = 0;

    FILE *arquivoOriginal, *arquivoTemp;

    escolherLocalArq(acaoRemover);

    arquivoOriginal = fopen(localDoArquivo, "r");
    caracter = getc(arquivoOriginal);

    limparTela();
    printf ("---------------------------------Remover-------------------------------------\n");

    if (caracter != EOF)
    {
        printf ("Obra número 1:\n");
    }

    while (caracter != EOF)
    {
        if (caracter == ';')
        {
            caracter = '\b';
            contPV++;
        }
        else if (caracter != EOF)
        {
            printf("%c", caracter);
            caracter = getc(arquivoOriginal);
        }
        if (contPV == 4)
        {
            caracter = getc(arquivoOriginal);
            caracter = getc(arquivoOriginal);
            caracter = getc(arquivoOriginal);

            if (caracter == 'T')
            {
                cont2++;
                printf ("\n");
                printf ("\nObra número %i:\n", cont2);
                printf ("%c", caracter);
                caracter = getc(arquivoOriginal);
            }
            contPV = 0;
        }
    }

    printf ("---------------------------------Remover-------------------------------------\n");

    rewind(arquivoOriginal);

    do
    {
        printf("\nDigite o número da obra que deseja deletar: ");
        scanf("%d", &obraParaDeletar);
    }
    while (obraParaDeletar < 1 || obraParaDeletar > cont2);

    arquivoTemp = fopen(localArqTemp, "w");
    caracter = getc(arquivoOriginal);
    contPV = 0;

    while (caracter != EOF)
    {
        if (caracter == ';')
        {
            if (cont != obraParaDeletar)
            {
                putc(caracter, arquivoTemp);
            }
            contPV++;
        }
        else if (cont != obraParaDeletar && caracter != EOF)
        {
            putc(caracter, arquivoTemp);
        }
        if (contPV == 4)
        {
            caracter = getc(arquivoOriginal);
            caracter = getc(arquivoOriginal);
            caracter = getc(arquivoOriginal);
            if (caracter == 'T')
            {
                cont++;
                if (cont != obraParaDeletar)
                {
                    putc ('\n', arquivoTemp);
                    putc ('\n', arquivoTemp);
                    putc(caracter, arquivoTemp);
                }
            }
            else
            {
                putc ('\n', arquivoTemp);
                putc ('\n', arquivoTemp);
            }
            contPV = 0;
        }
        caracter = getc(arquivoOriginal);
    }

    remove(localDoArquivo);
    rename(localArqTemp, localDoArquivo);

    fclose(arquivoOriginal);
    fclose(arquivoTemp);
}

void pesquisarObra (unsigned int acaoPesquisar)
{
    if (acaoPesquisar == 4)
    {
        return;
    }

    char titulo [50];
    char google [80];

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
        break;
    case 2:
        strcpy(google, "\"https://www.google.com/search?q=imdb-");
        break;
    case 3:
        strcpy(google, "\"https://www.google.com/search?q=");
        break;
    default:
        return;
    }

    limparTela();
    printf ("--------------------------------Pesquisar------------------------------------\n");

    printf ("Digite o nome de uma obra: ");
    getchar();
    fgets (titulo, 50, stdin);

    printf ("--------------------------------Pesquisar------------------------------------\n");

    titulo[strcspn(titulo, "\n")] = '\0';

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

    //printf ("Comando : %s\n", comando);

    printf ("Você será redirecionado para uma página\n");
    sleep (1);

    system (comando);
}
