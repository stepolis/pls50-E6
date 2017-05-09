/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*1η Γραπτή Εργασία - Θέμα 2ο*/
/* Γεωμετρικοί Υπολογισμοί*/


#include <stdio.h>
#include <math.h>

float perimtetragwnou(float n);
float perimparallilogrammou(float n, float m);
float perimtrigwnou(float n, float m);
float perimkuklou(float n);
int main()
{
    char epilogi;
    float a, b, c, r;

    printf("Gewmetrikoi Ypologismoi\n");
    printf("***********************\n");
    printf(" \n");

    do {
        printf("0. Exodos \n");
        printf("1. Tetragwno \n");
        printf("2. Parallilogrammo \n");
        printf("3. Orthogwnio Trigwno \n");
        printf("4. Kuklos \n");
        printf(" \n");
        printf("Dwse ton arithmo pou antistoixei stin epilogi sou\n");
        scanf(" %c", &epilogi);

        if (epilogi=='1') {
            printf("Dwse tin pleura tou tetragwnou a \n");
            scanf(" %f", &a);
            printf("**H Perimetros tou tetragwnou einai: %5.2f **\n\n\n\n", perimtetragwnou(a));
        }

            else if (epilogi=='2') {
                printf("Dwse tis pleures tou parallilogrammou a kai b \n");
                scanf(" %f %f", &a, &b);
                printf("**H Perimetros tou parallilogrammou einai: %5.2f **\n\n\n\n", perimparallilogrammou(a, b));
            }

            else if (epilogi=='3') {
                printf("Dwse tis duo kathetes pleures tou trigwnou a kai b \n");
                scanf(" %f %f", &a, &b);
                printf("**H Perimetros tou orthogwniou trigwnou einai: %5.2f **\n\n\n\n", perimtrigwnou(a, b));
            }

            else if (epilogi=='4') {
                printf("Dwse tin aktina tou kuklou r \n");
                scanf(" %f", &r);
                printf("**H Perimetros tou kuklou einai: %5.2f **\n\n\n\n", perimkuklou(r));
            }

    }
    while (epilogi!='0');

    return 0;
}

float perimtetragwnou(float n) {
    float perim;

    perim=4*n;

    return perim;
}

float perimparallilogrammou(float n, float m) {
    float perim;

    perim=2*(n+m);

    return perim;
}

float perimtrigwnou(float n, float m) {
    float perim, c;

    c=sqrt(pow(n,2)+pow(m,2));
    perim=n+m+c;

    return perim;
}

float perimkuklou(float n) {
    float perim;

    perim=2*3.14159*n;

    return perim;
}
