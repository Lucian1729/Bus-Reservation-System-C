#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAXLINES  10000
#define MAXCHARSPERLINE 2000

int flag=0;
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int tr_no;


void bus();//for list of bus
void booking(char * user_name);//for booking the tickets
int read_number(int tr_no);//for reading the number from the file
void read_name(int tr_no);//for reading the name from the file
void status(char * user_name);//for printing the status by user input
void status_1(int tr_no);//for printing the status while booking ticket
void cancel();
void add_bus();
void man_status();

void account();
void accountcreated();
FILE * fptr;
int i,n;
char str[100];
char fname[200]="r1.txt";
char str1;

typedef struct ticket{
    int bus_number;
    int seat_number[32];
}tick;

typedef struct seatno{
    int numbers[32];
} seat_numbers;

seat_numbers name_number(int booking,char numstr[100]);

struct passed {
    char username[50];
    char password[50];
    char pnumber[50];
    char fname[50];
    int typeaccount;
    tick user_ticket;
};

typedef struct user_details{
    char username[50];
    int typeaccount;
}user;

user login();


void add_bus(){
 char str2[100];
 FILE *fo;
 fo=fopen("r1.txt","a+");
 scanf("%s",&str2);
 fprintf(fo, "%s",str2);
 fclose(fo);
}

void account()
{
    char password[20];
    int passwordlength=0, i, seek = 0;
    char ch;
    FILE *fp, *fo;
    struct passed u1, u2;

    // Opening file to
    // write data of a user
    fp = fopen("username.txt", "ab");
    fo = fopen("username.txt", "rb");

    // Inputs
    system("cls");
    printf("\n\n!!!!!CREATE ACCOUNT!!!!!");

    printf("\n\nFIRST NAME... ");
    scanf("%s", &u1.fname);

    printf("\n\nACCOUNT TYPE- [1]customer or [2]manager... ");
    scanf("%d", &u1.typeaccount);

    printf("\n\nPHONE NUMBER... ");
    scanf("%s", u1.pnumber);

    printf("\n\nUSERNAME... ");
    int user_repeat=0, user_repeat1=0;
    while(user_repeat==0){
        scanf("%s", &u1.username);
        while (fread(&u2, sizeof(u2),1, fo)) {
            if (strcmp(u2.username, u1.username)== 0) {
                printf("\n\nUsername already taken.\nRE-ENTER USERNAME... ");
                user_repeat1=1;
                break;
            }
        }
        if(user_repeat1==0){
            user_repeat=1;
        }
        user_repeat1=0;
        rewind(fo);
    }

    printf("\n\nPASSWORD...8 to 16 characters... ");

    // Taking password in the
    // form of stars
    int pass_loop = 1;
    while(pass_loop){
        for (i = 0; i < 16; i++) {
            ch = getch();
            if (ch != 13) {
                password[i] = ch;
                ch = '*';
                printf("%c", ch);
                passwordlength += 1;
            } else
                break;
        }
        password[i]='\0';
        if(passwordlength>7){
            pass_loop=0;
        }
        else{
            printf("\n\nPassword must be 8 characters or more.\nRE-ENTER PASSWORD...");
        }
        passwordlength=0;
    }

    strcpy(u1.password, password);
    // printf("%s %s", u1.password, password);
    getch();
    // Writing to the file
    fwrite(&u1, sizeof(u1), 1, fp);

    // Closing file
    fclose(fp);
    fclose(fo);

    // Calling another function
    // after successful creation
    // of account
    accountcreated();
}


void accountcreated()
{
    int i;
    char ch;
    system("cls");
    printf(
            "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++) {
        i++;
        i--;
    }


    printf("ACCOUNT CREATED SUCCESSFULLY....");

    printf("Press enter to login");
    getch();
}
 

 
int nlines = 0; 
char ch[100][100]; 
 
int ReadLines(char *filename) 
{ 
        FILE *f; 
        int n; 
        char buf[MAXCHARSPERLINE];
        
        if((f = fopen(filename, "r")) == NULL) 
                return fprintf(stderr, "%: can't open for reading\n", filename), -1; 
        for(nlines = 0; fgets(buf, MAXCHARSPERLINE, f) != NULL; nlines++) { 
                n = strlen(buf); 
                if(n <= 0 || buf[n-1] != '\n') 
                        return fprintf(stderr, "%s:%d read partial line, increase MAXCHARSPERLINE\n", filename, nlines+1), -1; 
                buf[n-1] = '\0'; 
                if(nlines >= MAXLINES) 
                        return fprintf(stderr, "%s:%d increase MAXLINES\n", filename, nlines+1), -1; 
                strcpy(ch[nlines], buf); 
        } 
        fclose(f); 
        return nlines; 
} 
int main() {
    if(ReadLines("r1.txt") < 0)
     exit(1);
    int flag1 = 0,k=0;
    user user_detail;
    char user_name[50];
    while (flag1 == 0){
        system("cls");
        printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
        printf("[1] -> login\n[2] -> create account\n");
        int n;
        scanf("%d", &n);
        switch (n) {
            case 1:
                user_detail = login(); 
                flag1=1;
                break;
            case 2:
                account();
                break;
        }
    }
    k=user_detail.typeaccount;
    strcpy(user_name,user_detail.username);
    int num,i;
    if(k==1){
        do{
            system("cls");
            printf("\n\n\n");
            printf("====================================== WELCOME TO BUS RESERVATION SYSTEM ======================================\n\n\n");
            printf("\t\t\t\t\t[1]=> View Bus List\n");
            printf("\n");
            printf("\t\t\t\t\t[2]=> Book Tickets\n");
            printf("\n");
            printf("\t\t\t\t\t[3]=> Cancel Booking\n");
            printf("\n");
            printf("\t\t\t\t\t[4]=> Bus Status Board\n");
            printf("\n");
            printf("\t\t\t\t\t[5]=> Exit\n");
            printf("===============================================================================================================\n\n");
            printf("\t\t\tEnter Your Choice:: ");
            scanf("%d",&num);
            switch(num)
            {
                case 1:
                    bus();//for list of bus
                    break;
                case 2:
                    booking(user_name);//for booking the tickets
                    break;
                case 3:
                    cancel(user_name);
                    break;
                case 4:
                    status(user_name);
                    break;
            }
            getch();
        }while(num != 5);
    }
    else{
        do{
            system("cls");
            printf("\n\n\n%d",k+1);
            printf("====================================== WELCOME TO BUS MANAGEMENTSYSTEM ======================================\n\n\n");
            printf("\t\t\t\t\t[1]=> View Bus List\n");
            printf("\n");
            printf("\t\t\t\t\t[2]=> Bus Status Board\n");
            printf("\n");
            printf("\t\t\t\t\t[3]=> Add Buses in the Depo\n");
            printf("\n");
            printf("\t\t\t\t\t[4]=> Exit\n");
            printf("===============================================================================================================\n\n");
            printf("\t\t\tEnter Your Choice:: ");
            scanf("%d",&num);
            switch(num)
            {
                case 1:
                    bus();//for list of bus
                    break;
                case 2:
                    man_status();
                    break;
                case 3:
                    printf("\n\n\nEnter the name of the Bus :");
                    add_bus();
                    break;
            }
            getch();
        }while(num != 5);
    }
    system("CLS");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\tThank You For Using This System\t\t\t\t\t\t\n");
    printf("\t----------------------------------------------------------------------------------------------------------\n");
    getch();
    return 0;
}



void bus()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    for(int i=0;i<15;i++){
        if(ch[i][0]=='\0'){
            break;
        }
    printf("\t\t\t\t\t[%d]  =>  %s\n",i+1,ch[i]);
    printf("\n");
    }
}

void booking(char* user_name)
{

    int i=0;
    char numstr[100];
    FILE *fp, *fo;
    fp = fopen("tickets.txt", "ab");
    fo = fopen("username.txt", "rb");
    struct passed u1, u2;
    seat_numbers seats;

    while (fread(&u2, sizeof(u2),1, fo)) {
        if (strcmp(u2.username, user_name) == 0) {
            u1 = u2;
            break;
        }
    }


    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for entering train number
    bus();//for seeing train least
    printf("Enter the Bus number:--->");
    scanf("%d",&tr_no);
    u1.user_ticket.bus_number=tr_no;
    system("cls");
    printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");//for selecting coach
    printf("Your Bus Number is %d ********** %s",tr_no,ch[tr_no-1]);
    status_1(tr_no);

    FILE *f1, *fopen();//for reading the seats from the user.
    char str1[80]="32",str2[4],str3[4];
    int seat1,seat2,booking=0;

    if(tr_no == 1)
    {
        f1 = fopen("tr1.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }else if(tr_no == 2)
    {
        f1 = fopen("tr2.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }else if(tr_no == 3)
    {
        f1 = fopen("tr3.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 4)
    {
        f1 = fopen("tr4.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 5)
    {
        f1 = fopen("tr5.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }else if(tr_no == 6)
    {
        f1 = fopen("tr6.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 7)
    {
        f1 = fopen("tr7.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 8)
    {
        f1 = fopen("tr8.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }else if(tr_no == 9)
    {
        f1 = fopen("tr9.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 10)
    {
        f1 = fopen("tr10.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 11)
    {
        f1 = fopen("tr11.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }else if(tr_no == 12)
    {
        f1 = fopen("tr12.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 13)
    {
        f1 = fopen("tr13.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    else if(tr_no == 14)
    {
        f1 = fopen("tr14.txt","r+");
        fgets(str1,80,f1);
        fclose(f1);
    }
    seat1=atoi(str1);//covert the string into number
    if(seat1 <= 0)
    {
        printf("There is no blank seat in this bus ");
    }else
    {
        printf("\n\n\n\t\t\t\tAvailable Seats:------>%d\n",seat1);
        printf("\n\t\t\t\tNumber of Tickets:----->");
        scanf("%d",&booking);
        printf("\n");

        seat1=seat1-booking;
        itoa(tr_no,numstr,10);
        seats = name_number(booking,numstr);
        int seatslist[32];
        for(int j=0;j<32;j++){
            u1.user_ticket.seat_number[j]=seats.numbers[j];
            seatslist[j]=seats.numbers[j];
        }
        fwrite(&u1, sizeof(u1), 1, fp);
        fclose(fp);
        fclose(fo);
        printf("\n\t\t\t\tThe Total booking amount is %d",200*booking);
        printf("\n=========================================== TICKET ============================================\n\n\n");
        printf("Bus Number--->%d\n", tr_no);
        printf("Seat Numbers--->");
        for(int seat_no=0;seat_no<32;seat_no++){
            if(seatslist[seat_no]==1){
                printf("\n%d", seat_no);
            }
        }
        itoa(seat1, str1, 10);
//for reading the seats from the user.
        if(tr_no == 1)
        {
            f1 = fopen("tr1.txt","w");
            fputs(str1,f1);
            fclose(f1);
        }
        else if(tr_no == 2)
        {
            f1 = fopen("tr2.txt","w");
            fputs(str1,f1);
            fclose(f1);
        }
        else if(tr_no == 3)
        {
            f1 = fopen("tr3.txt","w");
            fputs(str1,f1);
            fclose(f1);
        }
        else if(tr_no == 4)
        {
            f1 = fopen("tr4.txt","w");
            fputs(str1,f1);
            fclose(f1);
        }
        else if(tr_no == 5)
        {
            f1 = fopen("tr5.txt","w");
            fputs(str1,f1);
            fclose(f1);
        }
    }
}


seat_numbers name_number(int booking,char numstr[100])
{
    char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
    int number;
    seat_numbers seats;
    FILE *a,*b;
    int i=0;
    strcat(numstr,".txt");
    strcat(tempstr1,numstr);
    strcat(tempstr2,numstr);
    a = fopen(tempstr1,"a");//for open the file to write the name in the file
    b = fopen(tempstr2,"a");//for open the file for writing the number in the file
    for(int i=0;i<32;i++){
            (seats.numbers)[i]=0;
    }
    for(i=0; i<booking; i++)//for entering the person name and seat number in the file
    {
        printf("============================Enter the details for ticket no %d============================\n\n\n",i+1);
        printf("\t\t\t\tEnter the seat number:--->");
        scanf("%d",&number);
        for(int j=0;j<32;j++){
            if(j==number){
                (seats.numbers)[j]=1;
            }
        }
        printf("\t\t\t\tEnter the name of person:--->");
        scanf("%s",name[number-1]);
        printf("\n======================================================================================================\n\n");
        printf("\n");
        itoa(number, tempstr, 10);
        fprintf(a,"%s ",name[number-1]);
        fprintf(b,"%s ",tempstr);

    }
    fclose(a);
    fclose(b);
    return seats;
}



int read_number(int tr_no)//for putting the numeric value in the array
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(tr_no,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");//for open the file to write the name in the file
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {   
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int tr_no)//for putting the numeric value in the array
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(tr_no,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");//for open the file to write the name in the file
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status(char * user_name)
{   FILE* fo;
    fo = fopen("tickets.txt", "rb");
    struct passed u1, u2;
    while (fread(&u2, sizeof(u2),1, fo)) {
        if (strcmp(u2.username, user_name) == 0) {
            u1 = u2;
            break;
        }
    }
    system("cls");
    printf("=========================================== WELCOME TO STATUS BOARD ============================================\n\n\n");
    printf("\n\n\n\n[1]=>Check ticket\n\n[2]=>Check Buses for seats\n\nEnter your choice:");
    int cho;
    scanf("%d", &cho);
    if(cho==2) {
        printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
        int i, tr_no, index = 0, j;
        printf("Enter the number of bus:---->");
        scanf("%d", &tr_no);
        j = read_number(tr_no);
        read_name(tr_no);
        printf("____________________________________________________________________________________________________________________\n");
        printf("                                      Bus.no-->%d---->%s                                                            \n",
               tr_no, ch[tr_no - 1]);
        printf("____________________________________________________________________________________________________________________\n");
        char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty "};
        for (i = 0; i < j; i++) {
            strcpy(tempname[num1[i]], "Booked");
        }
        for (i = 0; i < 8; i++) {
            printf("\t\t\t\t");
            for (j = 0; j < 4; j++) {
                printf("%d.%s\t", index + 1, tempname[index + 1]);
                index++;
            }
            printf("\n");
        }
    }
    if(cho==1){
        printf("=========================================== TICKET ============================================\n\n\n");
        printf("Bus Number--->%d\n", u1.user_ticket.bus_number);
        printf("Seat Numbers--->");
        for(int seat_no=0;seat_no<32;seat_no++){
            if(u1.user_ticket.seat_number[seat_no]==1){
                printf("\n%d", seat_no);
            }
        }
    }
}

void man_status(){
     printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
        int i, tr_no, index = 0, j;
        printf("Enter the number of bus:---->");
        scanf("%d", &tr_no);
        j = read_number(tr_no);
        read_name(tr_no);
        printf("____________________________________________________________________________________________________________________\n");
        printf("                                      Bus.no-->%d---->%s                                                            \n",
               tr_no, ch[tr_no - 1]);
        printf("____________________________________________________________________________________________________________________\n");
        char tempname[33][10] = {"Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ", "Empty ",
                                 "Empty "};
        for (i = 0; i < j; i++) {
            strcpy(tempname[num1[i]], "Booked");
        }
        for (i = 0; i < 8; i++) {
            printf("\t\t\t\t");
            for (j = 0; j < 4; j++) {
                printf("%d.%s\t", index + 1, tempname[index + 1]);
                index++;
            }
            printf("\n");
        }
}
void status_1(int tr_no)
{
    printf("Your Bus Number is %d ********** %s",tr_no,ch[tr_no-1]);
    system("cls");
printf("=========================================== BUS RESERVATION SYSTEM ============================================\n\n\n");
    int i,index=0,j;
    j=read_number(tr_no);
    read_name(tr_no);
    char tempname[33][10]={"Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty ","Empty "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],"Booked");
    }
    for(i=0; i<8; i++)
    {
        printf("\t\t\t\t");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancel()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("Enter the bus number:---->");
 scanf("%d",&tr_no);
 itoa(tr_no,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(tr_no);
 read_name(tr_no);
 status_1(tr_no);
 printf("Enter the seat number:--->");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("======================================================================================================\n");
 printf("\t\t\t\tYour 200 rupees has been Returned\t\t\t\n");
    printf("======================================================================================================\n");
}


user login()
{
    int a=0,i=0;
    char uname[20],c=' ';
    char pword[16],code[10];
    struct passed u1;
    FILE *fp;
    fp = fopen("username.txt","rb");
    do
    {
        system("cls");

        printf("\n  =========================  LOGIN FORM  =========================  ");
        printf(" \n                       ENTER USERNAME:-");
        scanf("%s", &uname);
        printf(" \n                       ENTER PASSWORD:-");
        while(i<16)
        {
            pword[i]=getch();
            c=pword[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pword[i]='\0';
        //char code=pword;
        i=0;
        //scanf("%s",&pword);
        int login_status=0;
        while (fread(&u1, sizeof(u1),1, fp)) {
            //  printf("%s %s %s %s", u1.password, pword, u1.username, uname);
            if (strcmp(uname, u1.username)== 0) {
                if(strcmp(pword, u1.password)==0)
                {   login_status=1;
                    printf("  \n\n\n       WELCOME TO OUR SYSTEM !!!! LOGIN IS SUCCESSFUL");
                    printf("\n\n\n\t\t\t\tPress any key to continue...");
                    getch();//holds the screen
                    break;
                }
            }
        }rewind(fp);

        if(login_status==0){
            printf("\n        SORRY !!!!  LOGIN IS UNSUCCESSFUL");
            a++;

            getch();//holds the screen
        }
        else{
            break;
        }
    }
    while(a<=3);
    if (a>3)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");
        getch();
        exit(0);

    }
    system("cls");
    user user1;
    user1.typeaccount= u1.typeaccount;
    strcpy(user1.username, u1.username);
    fclose(fp);
    return user1;
}
