#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TVShow
{
    int id;
    char title [50];
    char synopsis [150];
    unsigned int airedDate;
    char category [15];
} TVShow;

void listShows();
void listAllShows();
void addShow();
void removeShow();

int main()
{
    int mainAction = 0;

    while (mainAction != 9)
    {
        do
        {
            system("clear");
            printf ("                                       dd         bb              \n");
            printf ("              mm mm mmmm    aa aa      dd   eee   bb      yy   yy \n");
            printf ("              mmm  mm  mm  aa aaa  dddddd ee   e  bbbbbb  yy   yy \n");
            printf ("              mmm  mm  mm aa  aaa dd   dd eeeee   bb   bb  yyyyyy \n");
            printf ("              mmm  mm  mm  aaa aa  dddddd  eeeee  bbbbbb       yy \n");
            printf ("                                                           yyyyy  \n");
            printf ("                        jjj                              \n");
            printf ("                             oooo  nn nnn    aa aa  sss  \n");
            printf ("                        jjj oo  oo nnn  nn  aa aaa s     \n");
            printf ("                        jjj oo  oo nn   nn aa  aaa  sss  \n");
            printf ("                        jjj  oooo  nn   nn  aaa aa     s \n");
            printf ("                      jjjj                          sss  \n");
            printf ("\n");
            printf ("--------------------------------Name--------------------------------\n");
            printf ("|Type (1) to list watching shows                                   |\n");
            printf ("|Type (2) to list completed shows                                  |\n");
            printf ("|Type (3) to list paused shows                                     |\n");
            printf ("|Type (4) to list dropped shows                                    |\n");
            printf ("|Type (5) to list planning to watch shows                          |\n");
            printf ("|Type (6) to list all shows                                        |\n");
            printf ("|Type (7) to add a show                                            |\n");
            printf ("|Type (8) to remove a show                                         |\n");
            printf ("|Type (9) to exit                                                  |\n");
            printf ("--------------------------------Name--------------------------------\n");
            printf ("Type the number corresponding to the action: ");
            scanf ("%i", &mainAction);
        }
        while (mainAction < 1 || mainAction > 7);

        switch (mainAction)
        {
        case 1:
            listShows(1);
            break;
        case 2:
            listShows(2);
            break;
        case 3:
            listShows(3);
            break;
        case 4:
            listShows(4);
            break;
        case 5:
            listShows(5);
            break;
        case 6:
            listAllShows();
            break;
        case 7:
            addShow();
            break;
        case 8:
            removeShow();
            break;
        default:
            exit(0);
        }
    }
}

void listShows (int operation)
{

    char fileLocation [30];

    switch (operation)
    {
    case 1:
        strcpy(fileLocation, "watchingshows.txt");
        break;
    case 2:
        strcpy(fileLocation, "completedshows.txt");
        break;
    case 3:
        strcpy(fileLocation, "pausedshows.txt");
        break;
    case 4:
        strcpy(fileLocation, "droppedshows.txt");
        break;
    case 5:
        strcpy(fileLocation, "planningshows.txt");
        break;
    default:
        return;
    }

    FILE *file = fopen (fileLocation, "r");

    if (file == NULL)
    {
        printf("ERRO: Arquivo Inexistente");
        file = fopen (fileLocation, "w");
        return;
    }

    char list [10000];

    while (fgets(list, 10000, file) != NULL)
    {
        printf ("%s", list);
    }
    fclose(file);

}
void listAllShows ()
{

}

void addShow ()
{
    unsigned int operation;
    char fileLocation [30];
    TVShow show;

    do
    {
        system ("clear");
        printf ("--------------------------------Name----------------------------------\n");
        printf ("|Type (1) to add to watching shows                                   |\n");
        printf ("|Type (2) to add to completed shows                                  |\n");
        printf ("|Type (3) to add to paused shows                                     |\n");
        printf ("|Type (4) to add to dropped shows                                    |\n");
        printf ("|Type (5) to add to planning to watch shows                          |\n");
        printf ("--------------------------------Name----------------------------------\n");
        printf ("Type the number corresponding to the action: ");
        scanf ("%i", &operation);
    }
    while (operation < 1 || operation > 4);

    switch (operation)
    {
    case 1:
        strcpy(fileLocation, "watchingshows.txt");
        break;
    case 2:
        strcpy(fileLocation, "completedshows.txt");
        break;
    case 3:
        strcpy(fileLocation, "pausedshows.txt");
        break;
    case 4:
        strcpy(fileLocation, "droppedshows.txt");
        break;
    case 5:
        strcpy(fileLocation, "planningshows.txt");
        break;
    default:
        return;
    }

    FILE *file = fopen (fileLocation, "a");

    if (file == NULL)
    {
        printf("ERRO: Arquivo Inexistente");
        file = fopen (fileLocation, "w");
        return;
    }

    //show.id = (operationThatReadsFileAndReturnLastID);

    printf ("Type the title: \n");
    scanf ("%[^\n]s", &show.title);

    printf ("Type the synopsis: \n");
    scanf ("%[^\n]s", &show.synopsis);

    printf ("Type the aired date: \n");
    scanf ("%u", &show.airedDate);

    printf ("Type the category: \n");
    scanf ("%[^\n]s", &show.category);

}

void removeShow ()
{

}
