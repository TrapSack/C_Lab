#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>

struct AMPInfo {
    int connections           = 0;
    int floors                = 0;
    int height                = 0;
    int lengthToCloset        = 0;
    float priceToProject      = 0;
    float totalLengthOfCabel  = 0;
    float priceToApplications = 0;
    float totalPrice          = 0;
    char contactInfo[100]     = "The AMP company \n adress: Minsk city, Gikalo street \n";

    const double priceForMeter        =  1.5;
    const int priceForConnectionPoint =  1;
    const int priceForConnector       =  1;
    const int priceForCloset          =  143;
    const int priceForCanal           =  20;
    
    void SumTotalPrice() {
        this->totalLengthOfCabel = this->height*this->floors*this->lengthToCloset*this->connections;
        priceToApplications = this->connections*(priceForConnectionPoint+2*priceForConnector)*this->floors+this->floors*priceForCloset;
        int temp = this->totalLengthOfCabel*priceForMeter+priceToApplications;
        this->priceToProject = temp*0.3;
        this->totalPrice = priceToProject+temp;
    }
};
int checkNum(int a) {

    if(a>9) {
        char tens = a/10 + '0';
        char nums = a%10 + '0';

        if(((tens >= '0') && (tens <= '9')) && ((nums >= '0') && (nums <= '9'))){
            return 1;
        } else return 0;
    } else if (a >= 0) {
        char b = a + '0';
        if ((b >= '0') && (b <= '9')) {
            return 1;
        } else return 0;
    } else {
        return 0;
    }
}
void showMenu(AMPInfo element);
void showMenuWithoutInfo(AMPInfo element);
void addInfo(AMPInfo element)
{
    system("CLS");

    while(true) {
    rewind(stdin);
    printf("Connections:");
    scanf("%df \n", &element.connections);
    if(checkNum(element.connections)==1) {
        break;
      } else {
        printf("wrong type\n");
      }
    }

    while(true) {
    rewind(stdin);
    printf("Floors:");
    scanf("%df \n", &element.floors);
    if(checkNum(element.floors)==1) {
        break;
      } else {
        printf("wrong type\n");
      }
    }

    while(true) {
    rewind(stdin);

    printf("Height:");
    scanf("%df \n", &element.height);

    if(checkNum(element.height)==1) {
        break;
      } else {
        printf("wrong type\n");
      }
    }

    while(true) {
    rewind(stdin);
    printf("Length to closet:");
    scanf("%df \n", &element.lengthToCloset);
    if(checkNum(element.lengthToCloset)==1) {
        break;
      } else {
        printf("wrong type\n");
      }
    }


    printf("Space to continue \n");
    int f;
    if(( f = getch()) == (int)' ') {
    showMenu(element);
    }
}

void showContact(AMPInfo element) {
    system("CLS");
    printf("%s", element.contactInfo);
    printf("Space to continue \n");
    int f;
    if(( f = getch()) == (int)' ') {
    showMenu(element);
    }
}

void showInfo(AMPInfo element) {
    system("CLS");
    element.SumTotalPrice();

    printf("Price to project:");
    printf("%.2f",element.priceToProject);
    printf("\n");

    printf("Total length:");
    printf("%.2f",element.totalLengthOfCabel);
    printf("\n");

    printf("Price for applications:");
    printf("%.2f",element.priceToApplications);
    printf("\n");

    printf("Total:");
    printf("%.2f",element.totalPrice);
    printf("\n");

    printf("Any key to continue \n");
    int f;
    if(( f = getch()) == (int)' ') {
    showMenu(element);
    }
}

void showMenuWithoutInfo(AMPInfo element) {
    system("CLS");
    int choice;

    printf("1.Add info \n2.Contact\n 3.Exit\n");
    scanf("%d",&choice);

    switch (choice) {
    case 1: addInfo(element) ;break;
    case 2: showContact(element);
    case 3: exit(1);
    default:break;
    }
}
void showMenu(AMPInfo element) {
    system("CLS");
    int choice;

    printf("1.Add info \n2.Show info \n3.Contact\n 4.Exit\n");
    scanf("%d",&choice);

    switch (choice) {
    case 1: addInfo(element) ;break;
    case 2: showInfo(element);break;
    case 3: showContact(element);
    case 4: exit(1);
    default:break;
    }
}

int main() {
    AMPInfo element;
showMenuWithoutInfo(element);
}
