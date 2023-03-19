#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
int help();
int start();
int score();
int i = 0;
struct play {
    char name[20];
    int score1;
}p[10];

int main()
{

    int choice;
    printf("\t\t        ----------------------------------          \n");
    printf("\t\t                 MINI QUIZ GAME                     \n");
    printf("\t\t        ----------------------------------          \n\n");
    printf("\t\t\t-->Press 1 to start the game\n\t\t\t-->press 2 to see score sheet\n\t\t\t-->press 3 to see game help\n\t\t\t-->Press 0 to exit");
    printf("\n\n\t\t\tEnter your choice:");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        start();
        break;
    case 2:
        score();
        break;
    case 3:
        help();
        break;
    default:
        exit(1);
    }
    return 0;
}

int help()
{
    int choice;
    printf("\n >> There will be a total of 10 questions");
    printf("\n >> You will be given 4 options and you have to press 1, 2 ,3 or 4 for the right option");
    printf("\n >> Each question will carry 5 points");
    printf("\n >> Questions will be asked continuously");
    printf("\n >> After answering the question press enter to continue");
    printf("\n >> There is no negative marking for wrong answer");
    printf("\n\n ************************* BEST OF LUCK *************************\n\n");
    printf("\nContinue playing ? (1 for YES/0 for NO) :");
    scanf("%d", &choice);
    system("cls");
    if (choice == 1)
    {
        start();
    }
    else
    {
        main();
    }
    return 0;
}

int start()
{
    int score = 0, choice;
    char guess;
    printf("ENTER YOUR NAME:");
    scanf("%s", p[i].name);
    system("cls");
    printf("HI %s ALL THE BEST FOR THE QUIZ!!\n", p[i].name);
    printf("\nPRESS ANY KEY TO CONTINUE");
    getch();
    system("cls");
    char questions[][100] = { "Q1. Who invented C Language ?",
                          "Q2.C language was invented in the year ?",
                          "Q3.C is _______ type of programming language ?",
                          "Q4.C language is used in the development of ?",
                          "Q5.C language was invented in which laboratories?",
                          "Q6.C language was invented to develop which Operating System ?",
                          "Q7.C Language is a successor to which language",
                          "Q8.What is the present C Language Standard ?",
                          "Q9.A C program is a combination of ?",
                          "Q10.Single Line Comment // is also called ?" };

    char options[][100] = { "A.Charles Babbage","B.Graham bell","C.Dennis Ritchie","D.Steve Jobs",
                             "A.1972","B.1978","C.1999","D.1990",
                             "A.Functional","B.Procedural","C.Bit level language","D.Object Oriented",
                             "A.Databases","B.Graphic applications","C.Word Processors","D.All of the above",
                             "A.Uniliver Labs","B.IBM Labs","C.AT&T Bell Labs","D.Verizon Labs",
                             "A.Android","B.Linux","C. Ubuntu","D.Unix",
                             "A.B Language","B.D Language","C.BASIC","D.FORTRAN",
                             "A.C99 ISO/IEC 9899:1999","B.C11 ISO/IEC 9899:2011","C.C05 ISO/IEC 9899:2005","D.C10 ISO/IEC 9899:2010",
                             "A.Statements","B.Functions","C.Variables","D.All of the above",
                             "A. C++ Style Comment","B.Java Style Comment","C.PHP Style Comment","D.All the above" };

    char answers[] = { 'C','A','B','D','C','D','A','B','D','D' };
    for (int i = 0; i < 10; i++)
    {
        printf("\n%s", questions[i]);
        for (int j = (i * 4); j < (i * 4) + 4; j++)
        {
            printf("\n%s", options[j]);
        }
        printf("\n\nYour answer=");
        scanf("\n%c", &guess);
        guess = toupper(guess);
        if (guess == answers[i])
        {
            printf("CORRECT!\n");
            score = score + 5;
        }
        else
        {
            printf("\nWRONG! correct answer=%c\n", answers[i]);
        }
        getch();
        system("cls");
    }
    p[i].score1 = score;
    printf("\nNAME:%s\nSCORE=%d/50", p[i].name, p[i].score1);
    if (score > 40)printf("\nRating: * * * * *");
    else if (p[i].score1 > 30 && p[i].score1 <= 40)printf("\nRating: * * * *");
    else if (p[i].score1 > 20 && p[i].score1 <= 30)printf("\nRating: * * * ");
    else if (p[i].score1 > 10 && p[i].score1 <= 20)printf("\nRating: * *");
    else if (p[i].score1 > 0 && p[i].score1 <= 10)printf("\nRating: *");
    else printf("\nRating:NULL");
    i++;
    printf("\n\n-->Press 1 to go back to main menu\n-->Press 0 to exit\n");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {

    case 1:
        main();
        break;
    default:
        exit(1);
    }
    return 0;
}

int score()
{
    int choice, j, k, max;
    struct play temp;
    printf("\n************************** SCORE SHEET ***************************\n\n");
    printf("NAME\t\tSCORE\n");
    for (j = 0; j < i - 1; j++)
    {
        max = j;
        for (k = j + 1; k < i; k++)
        {
            if (p[k].score1 > p[max].score1)
                max = k;
        }
        temp = p[j];
        p[j] = p[max];
        p[max] = temp;
    }
    for (j = 0; j < i; j++)
    {
        printf("%s\t\t%d\n", p[j].name, p[j].score1);
    }
    printf("\n\n-->Press 1 to go back to main menu\n-->Press 0 to exit\n");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        main();
        break;
    default:
        exit(1);
    }
    return 0;
}
