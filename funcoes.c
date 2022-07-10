/*
    As principais funções do programa estão neste arquivo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "funcoes.h"

typedef struct TV
{
    char titulo [50];
    char sinopse [1200];
    char dataDeLancamento [12];
    char categoria [150];
} TV;

char localDoArquivo [35];
char localTodosArq [5][35] =
{
    ".\\arquivos\\obrasEmProgresso.txt",
    ".\\arquivos\\obrasCompletadas.txt",
    ".\\arquivos\\obrasPausadas.txt",
    ".\\arquivos\\obrasAbandonadas.txt",
    ".\\arquivos\\obrasPlanejamento.txt",
};

FILE *arquivo;

//Verifica se os arquivos já existem
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

//Função que seleciona o arquivo correspondente da ação escolhida
void escolherLocalArq (unsigned int acao)
{
    switch (acao)
    {
    case 1:
        strcpy(localDoArquivo, ".\\arquivos\\obrasEmProgresso.txt");
        break;
    case 2:
        strcpy(localDoArquivo, ".\\arquivos\\obrasCompletadas.txt");
        break;
    case 3:
        strcpy(localDoArquivo, ".\\arquivos\\obrasPausadas.txt");
        break;
    case 4:
        strcpy(localDoArquivo, ".\\arquivos\\obrasAbandonadas.txt");
        break;
    default:
        strcpy(localDoArquivo, ".\\arquivos\\obrasPlanejamento.txt");
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

    printf ("Pressione Enter para continuar. . .\n");
    getchar();
    getchar();

}

void listarTodasAsObras ()
{
    char caracter;

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

    printf ("Pressione Enter para continuar. . .\n");
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

    //Tratamento de dados, pois, a função fgets atribui um enter (\n) nos itens digitados pelo usuário,
    //a função strcspn percorre o array e retorna a primeira posição em que o caractere
    //especificado é encontrado, este caractere será substituido por um null terminator (\0)
    show.titulo[strcspn(show.titulo, "\n")] = '\0';
    show.sinopse[strcspn(show.sinopse, "\n")] = '\0';
    show.dataDeLancamento[strcspn(show.dataDeLancamento, "\n")] = '\0';
    show.categoria[strcspn(show.categoria, "\n")] = '\0';


    //Série de loops for para cada item, para identificar se o usuário digitou ';'
    //pois, este caractere poderia quebrar o programa, já que outras funções dependem
    //dele para identificar a separação dos itens de cada campo
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

    //Adiciona no arquivo os itens digitados pelo usuário
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

    char localArqTemp [34] = {".\\arquivos\\arquivoTemporario.txt"};
    char caracter;
    int obraParaDeletar, cont1 = 1, cont2 = 1, contPontoVirgula = 0;

    FILE *arquivoOriginal, *arquivoTemp;

    escolherLocalArq(acaoRemover);

    arquivoOriginal = fopen(localDoArquivo, "r");
    caracter = getc(arquivoOriginal);

    printf ("---------------------------------Remover-------------------------------------\n");

    if (caracter != EOF)
    {
        printf ("Obra número 1:\n");
    }

    while (caracter != EOF)
    {
        //Checa se o caracter é um ';', atribui no lugar dele um backspace '\b',
        //o cursor retorna uma posição e deixa de imprimir o ponto vírgula,
        //Se a condição for verdadeira adiciona um ao contador de ';'
        if (caracter == ';')
        {
            caracter = '\b';
            contPontoVirgula++;
        }
        else
        {
            printf("%c", caracter);
            caracter = getc(arquivoOriginal);
        }

        if (contPontoVirgula == 4)
        {

            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = EOF ou 'T'

            if (caracter == 'T')
            {
                cont1++;
                printf ("\n");
                printf ("\nObra número %i:\n", cont1);
                printf ("%c", caracter);
                caracter = getc(arquivoOriginal);
            }

            else
            {
                printf ("\n");
            }
            contPontoVirgula = 0;
        }
    }

    printf ("---------------------------------Remover-------------------------------------\n");

    rewind(arquivoOriginal);

    do
    {
        printf("\nDigite o número da obra que deseja deletar: ");
        scanf("%d", &obraParaDeletar);
    }
    while (obraParaDeletar < 1 || obraParaDeletar > cont1);

    //Substitue o arquivo temporario se ele existir por um arquivo em branco,
    //caso contrario irá criar um novo arquivo
    arquivoTemp = fopen(localArqTemp, "w");

    caracter = getc(arquivoOriginal);
    contPontoVirgula = 0;

    while (caracter != EOF)
    {
        if (caracter == ';')
        {

            if (cont2 != obraParaDeletar)
            {
                putc(caracter, arquivoTemp);
            }
            contPontoVirgula++;
        }

        else if (cont2 != obraParaDeletar)
        {
            putc(caracter, arquivoTemp);
        }

        if (contPontoVirgula == 4)
        {

            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = \n
            caracter = getc(arquivoOriginal); // caracter = EOF ou 'T'

            if (caracter == 'T')
            {
                cont2++;

                if (cont2 != obraParaDeletar)
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
            contPontoVirgula = 0;
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
    char google [110];

    char comando[10] = {"xdg-open "};

    //URL Estou com sorte:
    //Substituir "term" por titulo da obra separado por hífen
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

    printf ("--------------------------------Pesquisar------------------------------------\n");

    printf ("Digite o nome de uma obra: ");
    getchar();
    fgets (titulo, 50, stdin);

    printf ("--------------------------------Pesquisar------------------------------------\n");

    //Tratamento de dados, pois, a função fgets atribui um enter (\n) nos itens digitados pelo usuário,
    //a função strcspn percorre o array e retorna a primeira posição em que o caractere
    //especificado é encontrado, este caractere será substituido por um null terminator (\0)
    titulo[strcspn(titulo, "\n")] = '\0';

    //Tratamento que substitui espaço por hífen para ser utilizado na URL
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
