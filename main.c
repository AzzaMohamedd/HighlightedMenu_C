#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#define Extended -32
#define Up 72
#define Down 80
#define Home 71
#define End 79
#define Enter 13
#define Esc 27


void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

struct Employee{
    int id;
    char name[20];
    int age;
    float salary;
    float commission;
    float deduction;
};


struct Employee emp[10];
int count =0; //when delete employee (minus) & when add employee (add)
int cursor=1;//in menu ==>up&down

char arr[8][20] ={"New","Display All","Display By ID","Display By Name","Delete All","Delete By Name","Delete By ID","EXIT"};
char ch; //menu

void Header(){
    //row header in display employees(table shape)
    gotoxy(20,3);
    printf("id");
    gotoxy(30,3);
    printf("name");
    gotoxy(40,3);
    printf("age");
    gotoxy(50,3);
    printf("salary");
    gotoxy(60,3);
    printf("commission");
    gotoxy(80,3);
    printf("deduction");
}
void DisplayMenu(){
    system("cls");
    ch=0;

    for(int i=1 ; i<=8 ; i++){ //Display Menu

            gotoxy(50,10+i);

            if(i==cursor){
                textattr(6);
            }
            else{
                textattr(15);
            }
            printf("%s \n",arr[i-1]);
        }
}

void addForm(){
    gotoxy(5,3);
    printf("id: ");
    gotoxy(50,3);
    printf("name: ");
    gotoxy(5,5);
    printf("age: ");
    gotoxy(50,5);
    printf("salary: ");
    gotoxy(5,7);
    printf("commission: ");
    gotoxy(50,7);
    printf("deduction: ");
}

void AddNewEmp(){
    system("cls");
    addForm();

    gotoxy(9,3);
    scanf("%i",&emp[count].id);
    gotoxy(56,3);
    scanf("%s",emp[count].name);
    gotoxy(10,5);
    scanf("%i",&emp[count].age);
    gotoxy(58,5);
    scanf("%f",&emp[count].salary);
    gotoxy(17,7);
    scanf("%f",&emp[count].commission);
    gotoxy(61,7);
    scanf("%f",&emp[count].deduction);

    count++;

}

void DisplayById(){
    system("cls");
    int empId;
    char cha;

    gotoxy(40,10);
    printf("Employee ID   -->");
    gotoxy(60,10);

    scanf("%i",&empId); //////click double!!!!!!!(fix it) -->must write first then enter then choose enter or esc
    cha=getch();

    switch(cha){
        case Enter://get this employee id

            for(int i=0;i<10;i++){ //loop on array to get this record
                if(empId == emp[i].id){
                    system("cls");
                    Header();//row header

                    //get employee info
                    for(int m=1 ; m<=6 ;m++){
                        if(m==6){ //deduction is longer (just design)
                            gotoxy(80,5);
                        }
                        else{
                            gotoxy(10+10*m,5);
                        }
                        switch(m){
                            case 1:
                                printf("%i",emp[i].id);
                                break;
                            case 2:
                                printf("%s",emp[i].name);
                                break;
                            case 3:
                                printf("%i",emp[i].age);
                                break;
                            case 4:
                                printf("%f",emp[i].salary);
                                break;
                            case 5:
                                printf("%f",emp[i].commission);
                                break;
                            case 6:
                                printf("%f",emp[i].deduction);
                                break;
                        }

                    }
                    break;
                }
                else{
                    system("cls");
                    gotoxy(40,10);
                    printf("There is No Employee with this ID");
                }
            }
            break;
        case Esc: //return to menu
            DisplayMenu();
            break;
    }
    cha=getch();
    switch(cha){
        case Enter:
            DisplayMenu();
            break;
        case Esc:
            DisplayMenu();
            break;
    }

}

void DisplayAllEmp(){
    int cha;
    system("cls");
    //row header
    Header();

    for(int i=1 ; i<=10 ;i++){
        if(emp[i-1].id !=0){
            for(int j=1 ; j<=6 ; j++){
                if(j==6){ //deduction is longer (just design)
                    gotoxy(80,5+i);
                }
                else{
                    gotoxy(10+10*j,5+i);
                }

                switch(j){
                    case 1:
                        printf("%i",emp[i-1].id);
                        break;
                    case 2:
                        printf("%s",emp[i-1].name);
                        break;
                    case 3:
                        printf("%i",emp[i-1].age);
                        break;
                    case 4:
                        printf("%f",emp[i-1].salary);
                        break;
                    case 5:
                        printf("%f",emp[i-1].commission);
                        break;
                    case 6:
                        printf("%f",emp[i-1].deduction);
                        break;
                }

            }
        }


    }
    cha=getch();

    //may Enter or Esc
    switch(cha){
        case Enter:
        case Esc: //return to menu
            DisplayMenu();
            break;
    }
}

void DeleteById(){
    system("cls");
    int empId;
    char cha;

    gotoxy(40,10);
    printf("Employee ID   -->");
    gotoxy(60,10);

    scanf("%i",&empId); //////click double!!!!!!!(fix it) -->must write first then enter then choose enter or esc
    cha=getch();

    //may Enter or Esc
    switch(cha){
        case Enter://delete this employee id
            for(int i=0;i<10;i++){ //loop on array to get this record
                if(empId == emp[i].id){
                    emp[i].id =0;
                    emp[i].name[0]='\0';
                    emp[i].age =0;
                    emp[i].salary =0;
                    emp[i].commission =0;
                    emp[i].deduction =0;

                    count--;
                    DisplayMenu();
                }
            }
            break;
        case Esc: //return to menu
            DisplayMenu();
            break;
    }
}

void DeleteAllEmps(){

    system("cls");
    gotoxy(40,10);
    printf("Are you sure to delete All Employees?");
    gotoxy(45,12);
    printf("yes= Enter \t No= Esc");

    ch=getch();
    //may Enter or Esc
    switch(ch){
        case Enter://delete All
            for(int i=0;i<10;i++){ //loop on array to get this record
                emp[i].id =0;
                emp[i].name[0]='\0';
                emp[i].age =0;
                emp[i].salary =0;
                emp[i].commission =0;
                emp[i].deduction =0;

                count--;
                DisplayMenu();
            }
            break;
        case Esc: //return to menu
            DisplayMenu();
            break;
    }
}

void DeleteByName(){
    system("cls");
    char empName[20];
    char cha;

    gotoxy(40,10);
    printf("Employee Name   -->");
    gotoxy(60,10);

    scanf("%s",empName); //////click double!!!!!!!(fix it) -->must write first then enter then choose enter or esc
    cha=getch();

    //may Enter or Esc
    switch(cha){
        case Enter://delete this employee with name
            for(int i=0;i<10;i++){ //loop on array to get this record
                if(strcmp(empName , emp[i].name)==0){//delete record
                    emp[i].id =0;
                    emp[i].name[0]='\0';
                    emp[i].age =0;
                    emp[i].salary =0;
                    emp[i].commission =0;
                    emp[i].deduction =0;

                    count--;
                    DisplayMenu();
                }
            }
            break;
        case Esc: //return to menu
            DisplayMenu();
            break;
    }
}

void DisplayByName(){
    system("cls");
    int cha,ch;
    char empName[20];

    gotoxy(40,10);
    printf("Employee Name   -->");
    gotoxy(60,10);

    scanf("%s",&empName); //////click double!!!!!!!(fix it) -->must write first then enter then choose enter or esc
    cha=getch();

    switch(cha){
        case Enter://show this employee with name

            for(int i=0;i<10;i++){ //loop on array to get this record
                if(strcmp(empName , emp[i].name)==0){//show record
                    system("cls");
                    Header();
                    for(int j=1 ; j<=6 ; j++){
                        switch(j){
                            case 1:
                                gotoxy(10+10*j,5);
                                printf("%i",emp[i].id);
                                break;
                            case 2:
                                gotoxy(10+10*j,5);
                                printf("%s",emp[i].name);
                                break;
                            case 3:
                                gotoxy(10+10*j,5);
                                printf("%i",emp[i].age);
                                break;
                            case 4:
                                gotoxy(10+10*j,5);
                                printf("%f",emp[i].salary);
                                break;
                            case 5:
                                gotoxy(10+10*j,5);
                                printf("%f",emp[i].commission);
                                break;
                            case 6:
                                gotoxy(80,5);
                                printf("%f",emp[i].deduction);
                                break;


                        }
                    }
                break;
                }

                else{
                    system("cls");
                    gotoxy(40,10);
                    printf("There is No Employee with this Name");
                }
            }

            break;
        case Esc: //return to menu
            DisplayMenu();
            break;
    }

    ch=getch();

    //may Enter or Esc
    switch(ch){
        case Enter:
        case Esc: //return to menu
            DisplayMenu();
            break;
    }


}

int main()
{
    //Task 3 ==> 10 employees with highlighted menu


    do{
        DisplayMenu();

        textattr(15); //when step on 8 and choose Esc -> the long message become yellow

        ch=getch();

        switch(ch){
        case Extended: //Extended ==> up,down,home,end
            ch=getch();
            switch(ch){
                case Down:
                    cursor++;
                    if(cursor>8){
                        cursor=1;
                    }
                    break;
                case Up:
                    cursor--;
                    if(cursor<1){
                        cursor=8;
                    }
                    break;
                case Home:
                    cursor=1;
                    break;
                case End:
                    cursor=8;
                    break;
            }
        break;
        case Enter: //Normal --> enter
            switch(cursor){
                case 1: //Enter on New
                    if(count<10){ //array have less than 10
                        AddNewEmp();
                    }
                    else{ //there is no more space in array
                        textattr(5); // New button's color become red --> Try It
                    }
                    break;
                case 2: //enter on Display All
                    DisplayAllEmp();
                    break;
                case 3: //enter on Display By ID
                    DisplayById();
                    break;
                case 4: //enter on Display By Name
                    DisplayByName();
                    break;
                case 5: //enter on Delete All
                    DeleteAllEmps();
                    break;
                case 6: //enter on Delete By Name
                    DeleteByName();
                    break;
                case 7: //enter on Delete By ID
                    DeleteById();
                    break;
                case 8: //enter on Exit
                    ch=27;
                    break;

            }
        break;
        }

    }
    while(ch!=27); //not equal Esc


    system("cls");
    gotoxy(50,10);
    printf("Do you want to exit?\n");
    gotoxy(48,12);
    printf("yes= Enter \t  No= Esc");
    char yOn =getch();
    switch(yOn){
        //yes or no
        case Enter:
            break;
        case Esc:
            DisplayMenu();
            break;
    }


    return 0;
}
