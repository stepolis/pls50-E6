/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*1η Γραπτή Εργασία - Θέμα 3ο*/
/* Δυαδική Αναπαράσταση Αριθμού*/


#include <stdio.h>


int main() {
    const int d=2;
    int upo;
    long ake, dia;

    printf("Diadiki Anaparastasi Arithmou \n");
    printf("***************************** \n\n");

    do {
        printf("Dwse enan thetiko akeraio arithmo: \n");
        printf(" \n");
        scanf(" %ld", &ake);
        if (ake<0) printf("**ERROR** o arithmos pou edwses den einai thetikos!! \n");
    }
    while (ake<0);

    printf("\nH Antistrofi Diadiki Anaparastasi tou %ld einai: ", ake);

    while (ake!=0) {
        upo = ake%d;
        dia = (upo==0) ? putchar('0') : putchar('1');
        ake = ake/d;
    }

    printf(" \n");

    return 0;
}
