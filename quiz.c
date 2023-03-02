#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
int help();
int start();
int score();
struct play {
    char name[20];
    int score1;
}p;

int main()
{

    int a;
    printf("\t\t        ----------------------------------          \n");
    printf("\t\t                 MINI QUIZ GAME                     \n");
    printf("\t\t        ----------------------------------          \n\n");
    printf("\t\t\t-->Press 1 to start the game\n\t\t\t-->press 2 to see score sheet\n\t\t\t-->press 3 to see game help\n\t\t\t-->Press 0 to exit");
    printf("\n\n\t\t\tEnter your choice:");
    scanf("%d", &a);
    system("cls");
    switch (a)
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
    int b;
    printf("\n >> There will be a total of 10 questions");
    printf("\n >> You will be given 4 options and you have to press 1, 2 ,3 or 4 for the right option");
    printf("\n >> Each question will carry 5 points");
    printf("\n >> Questions will be asked continuously");
    printf("\n >> After answering the question press enter to continue");
    printf("\n >> There is no negative marking for wrong answer");
    printf("\n\n ************************* BEST OF LUCK *************************\n\n");
    printf("\nContinue playing ? (1 for YES/0 for NO) :");
    scanf("%d", &b);
    system("cls");
    if (b == 1)
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
    FILE* fp;
    fp = fopen("play.txt", "a");
    int score = 0, c;
    char guess;
    printf("ENTER YOUR NAME:");
    scanf("%s", p.name);
    system("cls");
    printf("HI %s ALL THE BEST FOR THE QUIZ!!\n", p.name);
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
    p.score1 = score;
    printf("\nNAME:%s\nSCORE=%d/50", p.name, p.score1);
    if (score > 40)printf("\nRating: * * * * *");
    else if (p.score1 > 30 && p.score1 <= 40)printf("\nRating: * * * *");
    else if (p.score1 > 20 && p.score1 <= 30)printf("\nRating: * * * ");
    else if (p.score1 > 10 && p.score1 <= 20)printf("\nRating: * *");
    else if (p.score1 > 0 && p.score1 <= 10)printf("\nRating: *");
    else printf("\nRating:NULL");
    fprintf(fp, "%s\t%d\n", p.name, p.score1);
    fclose(fp);
    printf("\n\n-->Press 1 to go back to main menu\n-->Press 0 to exit\n");
    scanf("%d", &c);
    system("cls");
    switch (c)
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
    int d;
    FILE* fp;
    fp = fopen("play.txt", "r");
    if (fp == NULL)
    {
        printf("\nNo games played yet!\n");
    }
    else
    {
        printf("\n************************** SCORE SHEET ***************************\n\n");
        printf("NAME\t\tSCORE\n");
        while (fscanf(fp, "%s %d", p.name, &p.score1) != EOF)
        {
            printf("%s\t\t%d\n", p.name, p.score1);
        }
        fclose(fp);
    }
    printf("\n\n-->Press 1 to go back to main menu\n-->Press 0 to exit\n");
    scanf("%d", &d);
    system("cls");
    switch (d)
    {
    case 1:
        main();
        break;
    default:
        exit(1);
    }
    return 0;
}



