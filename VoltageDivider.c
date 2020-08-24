#include "resistor.h"
void Menu();
void InsertResistance(float *r);
void ResistanceMenu();

int main(int argx, const char **argv)
{
    char op;
    char op1 = 'n';
    float r1;
    float r2;
    float vin;
    float vo;

    do
    {
        Menu();
        printf("Select option: \n");
        scanf("%c", &op);
        switch (op)
        {
        case '1':
        {
            printf("Insert vin: \n");
            scanf("%f", &vin);
            printf("Insert R1: \n");
            InsertResistance(&r1);
            printf("Insert R2: \n");
            InsertResistance(&r2);
            vo = (vin * (r2)) / ((r1) + (r2));
            printf("Your output voltage vo is: %f v\n", vo);
        }
        break;

        case '2':
        {
            printf("Insert vo: \n");
            scanf("%f", &vo);
            printf("Insert R1: \n");
            InsertResistance(&r1);
            printf("Insert R2: \n");
            InsertResistance(&r2);
            vin = (vo * (r1 + r2)) / (r2);
            printf("Your input voltage vin is: %f v\n", vin);
        }
        break;

        case '3':
        {
            printf("Insert vo: \n");
            scanf("%f", &vo);
            printf("Insert vin: \n");
            scanf(" %f", &vin);
            printf("Insert R1: \n");
            InsertResistance(&r1);
            r2 = (vo * r1) / (vin - vo);
            printf("Your r2 vin is: %f Ohms\n", r2);
        }
        break;

        case '4':
        printf("Insert vo: \n");
            scanf("%f", &vo);
            printf("Insert vin: \n");
            scanf(" %f", &vin);
            printf("Insert R2: \n");
            InsertResistance(&r2);
            r1 = (vo * r2) / (vin - vo);
            printf("Your r1 vin is: %f Ohms\n", r2);
            break;

        default:
            printf("Bye!\n");
            break;
        }
        printf("wnat to continue? (y/n): \n");
        scanf(" %c", &op1);
    } while (op1 == 'y');

    return 0;
}

void Menu()
{
    printf("---------Main Menu---------\n");
    printf("1) I have two resistance value, Vin. I want Vo\n");
    printf("2) I have two resistance value, Vo. I want Vin\n");
    printf("3) I have R1, Vin, Vo i want R2\n");
    printf("4) I have R2, Vin, Vo i want R1\n");
    printf("0) Quit\n");
}

void ResistanceMenu()
{
    printf("---------Resistance Menu---------\n");
    printf("1) I know the value\n");
    printf("2) I have the color code\n");
    printf("0) Going back\n");
    printf("Select Option: \n");
}

void InsertResistance(float *r)
{
    char op;
    ResistanceMenu();
    scanf(" %c", &op);
    switch (op)
    {
    case '1':
    {
        double value;
        printf("insert resistance value: ");
        scanf("%lf", &value);
        *r = stablishValue(1, value, 0, 0, 0, 0);
    }
    break;
    case '2':
        break;

    default:
        break;
    }
}