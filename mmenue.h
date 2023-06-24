#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

struct books{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
}b;

struct student{
    int id;
    char sName[50];
    char sSemester[50];
    int sID;
    char bookName[50];
    char date[12];
}s;

FILE *fp;

void mmenue(){

    int ch;

    while(1){
        system("cls");
        printf("\n\n \t\t******************* Main MENU *******************\n");
        printf("\n \t\t 1.Add Book\n");
        printf("\t\t 2.Books List\n");
        printf("\t\t 3.Remove Book\n");
        printf("\t\t 4.Issue Book\n");
        printf("\t\t 5.Issued Book List\n");
        printf("\t\t 0.Exit\n\n");
        printf("\n \t\t Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
            addBook();
            break;

        case 2:
            booksList();
            break;

        case 3:
            del();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            issueList();
            break;

        default:
            printf("Invalid Choice...\n\n");

        }
        printf("Press Any Key To Continue...");
        getch();
    }

    return;
}


void addBook(){
    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("books.txt", "ab");

    printf("\n \t\t Enter book id: ");
    scanf("%d", &b.id);

    printf("\n \t\t Enter book name: ");
    fflush(stdin);
    gets(b.bookName);

    printf("\n \t\t Enter author name: ");
    fflush(stdin);
    gets(b.authorName);

    printf("\n \t\t Book Added Successfully");

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);
}


void booksList(){

    system("cls");
    printf("\n \t\t ******************* Available Books *******************\n\n");
    printf("%-10s %-30s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");

    fp = fopen("books.txt", "rb");
    while(fread(&b, sizeof(b), 1, fp) == 1){
        printf("%-10d %-30s %-20s %s\n", b.id, b.bookName, b.authorName, b.date);
    }

    fclose(fp);
}

void del(){
    int id, f=0;
    system("cls");
    printf("\n \t\t ******************* Remove Books *******************\n\n");
    printf("\n \t\t Enter Book id to remove: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("books.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&b, sizeof(b), 1, fp) == 1){
        if(id == b.id){
            f=1;
        }else{
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if(f==1){
        printf("\n\n \t\t Deleted Successfully.");
    }else{
        printf("\n\n \t\t Record Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

}


void issueBook(){

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon+1, tm.tm_year + 1900);
    strcpy(s.date, myDate);

    int f=0;

    system("cls");
    printf("\n \t\t ******************* Issue Books *******************\n\n");

    printf("\n \t\t Enter Book id to issue: ");
    scanf("%d", &s.id);

    //Check if we have book of given id
    fp = fopen("books.txt", "rb");

    while(fread(&b, sizeof(b), 1, fp) == 1){
        if(b.id == s.id){
            strcpy(s.bookName, b.bookName);
            f=1;
            break;
        }
    }

    if(f==0){
        printf("\n \t\tNo book found with this id\n");
        printf("\n \t\tPlease try again...\n\n");
        return;
    }

    fp = fopen("issue.txt", "ab");

    printf("\n \t\t Enter Student Name: ");
    fflush(stdin);
    gets(s.sName);

    printf("\n \t\t Enter Student Semester: ");
    fflush(stdin);
    gets(s.sSemester);

    printf("\n \t\t Enter Student ID: ");
    scanf("%d", &s.sID);

    printf("\n \t\tBook Issued Successfully\n\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void issueList(){
    system("cls");
    printf("\n \t\t ******************* Book Issue List *******************\n\n");

    printf("%-10s %-30s %-20s %-10s %-30s %s\n\n", "Book ID", "Name", "Semester", "ID", "Book Name", "Date");

    fp = fopen("issue.txt", "rb");
    while(fread(&s, sizeof(s), 1, fp) == 1){
        printf("%-10d %-30s %-20s %-10d %-30s %s\n", s.id, s.sName, s.sSemester, s.sID, s.bookName, s.date);
    }

    fclose(fp);
}
