/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*1η Γραπτή Εργασία - Θέμα 1ο*/
/* Απλή Αριθμομηχανή*/


#include <stdio.h>

int main()
{
    char praksi;
    float arithm1, arithm2, apot;

    printf("Apli Arithmomixani\n");                                         /*Εκτυπώνει μια επικεφαλίδα*/
    printf("******************\n");                                         /*Για να κάνει εντύπωση η επικεφαλίδα*/
    printf(" \n");
    printf("Dwse arithmo praksi arithmo\n");                                /*Ζητάει τα δεδομένα*/

    scanf("%f %c %f", &arithm1, &praksi, &arithm2);                         /*διαβάζει τα δεδομένα που δίνει ο χρήστης*/

    if (praksi=='+') {                                                      /*Αν ο χρήστης επιλέξει πρόσθεση*/
        printf("apotelesma = %5.2f\n", apot=arithm1+arithm2);
    }

        else if (praksi=='-') {                                             /*Αν ο χρήστης επιλέξει αφαίρεση*/
            printf("apotelesma = %5.2f\n", apot=arithm1-arithm2);
        }

        else if (praksi=='*') {                                             /*Αν ο χρήστης επιλέξει πολλαπλασιασμό*/
            printf("apotelesma = %5.2f\n", apot=arithm1*arithm2);
        }

        else if (praksi=='/') {                                             /*Αν ο χρήστης επιλέξει διαίρεση*/
                if (arithm2==0)
                    printf("**ERROR** i diairesi me to 0 den orizetai\n");  /*Μήνυμα λάθους σε περιπτωση που ο διαιρέτης είναι 0*/
                else
                    printf("apotelesma = %5.2f\n", apot=arithm1/arithm2);
        }

    else
        printf("**ERROR** i praksi prepei na einai +,-,*,/\n");             /*Μήνυμα λάθους σε περίπτωση που ο χήστης δεν επιλέξει μία από τις επιθυμητές πράξεις*/

    return 0;
}
