#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct{
    char fname[100];
    char lname[20];
    char username[20];
    char password[20];
}login;
void registe(){
    FILE *log;
    log=fopen("login12.txt","w");
    login l;


    printf("\n \t\t Enter Your first name: ");
    scanf("%s",l.fname);
    printf("\n \t\t Enter Your last name: ");
    scanf("%s",l.lname);

    printf("\n \t\t Enter Your User ID: ");
    scanf("%s",l.username);
    printf("\n \t\t Enter Your password: ");
    scanf("%s",l.password);
    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("\n \t\t Now login with your User ID and Password ");
    printf("\n \t\t press any key to continue....... ");

    getch();
    system("cls");
  pass();


}

void pass(){
    char username[200];
    char password [200];
     FILE *log;
    log=fopen("login12.txt","r");
    login l;
    printf("\n \t\t Enter Your User ID: ");
    scanf("%s",&username);
    printf("\n \t\t Enter Your password: ");
    scanf("%s",&password);

    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
             {
                 printf("\n \t\t Login Succesful ");
                 break;

             }
             else{

            printf("\n \t\t Please enter correct User ID and password ");
            pass();
            break;

             }



        }


        fclose(log);

    }














