#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

void mainmenu(void);
void customer(void);
void osnack(void);
void cdetails(void);
void aboutproject(void);


int main()
{
    mainmenu();
    return 0;
}
    int choice;
    int again;
    int quantity;
    double total = 0;

void mainmenu(void)
{
    system("cls");// clean the terminal
    printf("\t____________________________________________________\n");
    printf("\t\t\tWELCOME TO SNACK ORDRING SYSTEM\n");
    printf("\t1. CUSTOMER SECTION-->\n\t2. ABOUT THE PROJECT-->\n\t3. EXIT-->\n\n\n\tEnter your choice--> ");

    int select;
    scanf("%d", &select);
    if(select == 1)
    {
        customer();
    }
    else if(select == 2)
    {
       aboutproject();

        //Using "getch can be particularly helpful for implementing menu navigation in console applications because it allows
        //the program to capture user input immediately and act on it without requiring the user to press Enter. This creates a
        //more responsive and intuitive user experience when navigating menus.

        if(getch())
            mainmenu();
    }
    else if(select == 3)
    {
        system("cls");
        printf("\n\n\n");
        printf("\t_________________________________________________\n");
        printf("\t\t\tTHANK YOU\n");
        printf("\t\tFeeling Hungry? time to snack!\n");
        printf("\t__________________________________________________\n");
        exit(0);
    }
}
void customer(void)
{
    system("cls");
    printf("\t__________________________________________________\n");
    printf("\tYou are about to-->\n\t1. Order Snack\n\t2. View Order\n\t3. Back to main menu\n\n\n\tEnter Your Choice--> ");

    int c;
    scanf("%d", &c);

    int load;
    for(load = 0; load <= 5000; load++)
    {

        printf("\r\tLoading: %d%%", (load * 100) / 5000);
        fflush(stdout);
        usleep(-0.5);
    }
    printf("\nLoading complete.\n");

    if(c == 1)
    {
        system("cls");
        osnack();
    }
    else if(c == 2)
    {
        /*
    The main purpose of pointers in file handling in C
    is to manage file operations efficiently and flexibly.
    A file pointer stores the current position of a read or
    write within a file. All operations within the file are
     made with reference to the pointer.
        */

        FILE *vorder;
        char v;
        vorder = fopen("order.txt", "r");
        while((v = fgetc(vorder)) != EOF)
        {
            printf("%c", v);
        }
        if(getch())
        mainmenu();
    }
    else if(c == 3)
    {
        system("cls");
        mainmenu();
    }
    else
    {
        printf("\tWrong input! Kindly input the correct option...\n\n");
        customer();
    }
}

void osnack(void)
{
    printf("\t__________________________________________________\n");
    printf("\t\tSNACK MENU\n");
    printf("\t__________________________________________________\n");
    printf("\t\tINPUT NUMBER FOR SELECTED MENU\n\n\t#1 Fries\t50.00\n\t#2 Burger\t70.00\n\n\t#3 Back to Main Menu\n\tEnter Your choice-->");

    char s;
    FILE *snakmenu;

    snakmenu = fopen("menu.txt", "rt");
    while ((s = getc(snakmenu)) != EOF) // to read from the first character to the end
    {
        printf("%c", s);
    }
    fclose(snakmenu);
    printf("\n\nInput Customer Order: ");
    printf("\n\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Quantity: ");
        scanf("%d", &quantity);
        total = 50 * (quantity) + total;// because the the 70 is the quantity multiply by his order

        printf("\n");
        printf("\tPress 1 To Order Again: \n\tPress 2 To Get Your Total: \n\n\nENTER YOUR CHOICE-->");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2) //  next time ordering
        printf("Your Total Amount Is: %.2f\n\n", total);

        int totl = total;
        FILE *ttl;
        ttl = fopen("order.txt", "a");
        fprintf(ttl, "\nGrand Total: %d\n", totl);
        fclose(ttl);

        cdetails();
    }
    else if(choice == 2)
    {
        {
        printf("Quantity: ");
        scanf("%d", &quantity);
        total = 70 * (quantity) + total;// because the the 70 is the quantity multiply by his order

        printf("\n");
        printf("\tPress 1 To Order Again: \n\tPress 2 To Get Your Total: \n\n\nENTER YOUR CHOICE-->");
        scanf("%d", &again);
        printf("\n");
        if (again == 1)
        {
            printf("\n\n");
            osnack();
        }
        else if (again == 2) //  next time ordering
        printf("Your Total Amount Is: %.2f\n\n", total);

        int totl = total;
        FILE *ttl;
        ttl = fopen("order.txt", "a");
        fprintf(ttl, "\nGrand Total: %d\n", totl);
        fclose(ttl);

        cdetails();
        }
    }
    else if(choice == 3)
    {
        system("cls");
        customer();
    }
    else
    {
        printf("\tWrong input! Kindly input the correct option...\n\n");
        if(getch())
        osnack();

    }

}
void cdetails(void)// customer details including first name second name ...
{
    char fname[20];
    char lname[20];
    long long int phone;

    printf("\tInput Customer Details\n");
    printf("First Name: ");
    scanf("%s", &fname);
    printf("Last Name: ");
    scanf("%s", &lname);
    printf("Phone: ");
    scanf("%lld", &phone);
    printf("\n\n");
    printf("Your Details Entered Are--> \n");
    FILE *cust;
    cust = fopen("order.txt", "a");
    fprintf(cust, "Order by: %s %s\nPhone Number: %lld\n", fname, lname, phone);
    fclose(cust);
      printf("-->First Name: %s\n-->Last Name: %s\n-->Phone: %lld\n", fname, lname, phone);
    printf("\n\n\n");
    printf("\t__________________________________________________\n");
    printf("\t\tYour Order will be in 5 minutess..\n");
    printf("\t\tTHANK YOU...\n");
    printf("\t__________________________________________________\n");
    printf("Press Any Back to Main Menu\n\n\n");
    if(getch())
    mainmenu();
}
void aboutproject(void)
{
    system("cls");
    printf("\n\n\n");
    printf("\tThis is C Mini Project.. may this tutorial will help you...!");
    if(getch())
    mainmenu();
}
