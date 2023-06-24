#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include "heading.h"
#include"login.h"
#include"mmenue.h"



void heading();
void registe();
void pass();
void mmenue();
void addBook();
void booksList();
void del();
void issueBook();
void issueList();



int main(void)
{
   heading();

   int choice;


   printf("\n \t\t Press '1' for registration ");
   printf("\n \t\t Press '2' for login ");
    scanf("%d",&choice);


    if(choice==1)
    {
        system("cls");
        registe();
    }


    else if(choice==2)
   {
       system("cls");
       pass();

   }



   mmenue();

    return 0;
}


