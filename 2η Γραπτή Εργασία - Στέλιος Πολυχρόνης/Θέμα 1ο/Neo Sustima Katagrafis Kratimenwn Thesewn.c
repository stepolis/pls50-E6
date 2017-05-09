/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*2η Γραπτή Εργασία - Θέμα 1ο*/
/*Νεο Σύστημα Καταγραφής Κρατημένων Θέσεων*/

#include <stdio.h>
#include <stdlib.h>

FILE *fin, *fout;                                                           /*ορισμός αρχείων εισόδου και εξόδου*/
char onoma[20], epitheto[40], til[11], pinakida[8];                         /*ορισμός πινάκων χαρακτήρων*/
int num[10];                                                                /*ορισμός πίνακα ακεραίων*/
int i, n, m, k, N, upo, kratisi, epilogi, epilogi2, arithm;                 /*ορισμός ακέραιων μεταβλητών*/
int sunolokenwn, sunolokratimenwn, j, z, a, b, c, seires;                   /*ορισμός ακέραιων μεταβλητών*/

struct epivatis {                                                           /*ορισμός struct epivatis με πεδία:  */
    char onomateponimo[40];                                                 /*έναν πίνακα χαρακτήρων 40 θέσεων για το ονοματεπώνυμο*/
    unsigned short tilefono[10];                                            /*έναν πίνακα unsigned short 10 θέσεων για το τηλέφωνο*/
    unsigned int arithmosthesis;                                            /*μια μεταβλητή unsigned int για τον αριθμό θέσης του επιβάτη*/
} theseis[53];                                                              /*ορισμός ενός πίνακα 53 θέσεων τύπου struct epivatis*/

/*προδήλωση συναρτησεων που καλούντε στο πρόγραμμα*/
void anoigma();
void plithoskenwn();
int kratisithesis(int x);
int anazitisithesis(int y);
int akurwsithesis(int l);
void lista();
void kleisimo();

/*αρχή της main*/
void main()
{
    for (i=0; i<53; i++) {                                                  /*αρχικοποίηση του πίνακα θέσεων με τον κενό χαρακτήρα για το   */
        strcpy (theseis[i].onomateponimo, "\0");                            /*ονοματεπώνυμο και το τηλέφωνο και αντιστοίχηση κάθε θέσης του */
        theseis[i].tilefono[0]=0;                                           /*πίνακα με τον αριθμό της αντίστοιχης θέσης του λεωφορείου*/
        theseis[i].arithmosthesis=i+1;
    }

    anoigma();                                                              /*καλεί την συνάρτηση anoigma*/

    do {                                                                    /*βασικός βρόγχος do-while του προγραμματος που εκτελείται μεχρι να επιλέξει ο χρηστης 0.Exodos*/
            printf("\n\n Lista Epilogwn: \n");                              /*λίστα επιλογών για τον χρήστη*/
            printf(" --------------- \n\n");
            printf(" 1. Emfanisi Kenwn Thesewn \n");
            printf(" 2. Kratisi Sugkekrimenis Thesis \n");
            printf(" 3. Anazitisi Kratimenis Thesis \n");
            printf(" 4. Akurwsi Kratisis Thesis \n");
            printf(" 5. Lista Kratimenwn Thesewn \n");
            printf(" 0. Exodos \n\n");
            printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n"); /*ζηταει την επιλογή του χρηστη*/
            scanf(" %d", &epilogi);                                         /*διαβάζει την επιλογή*/
            printf("\n");

            if (epilogi==1) {                                               /*αν η επιλογή είναι 1*/
                plithoskenwn();                                             /*καλεί την συνάρτηση plithoskenwn*/
            }
            else if (epilogi==2){                                           /*αν η επιλογή είναι 2*/
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis na kratiseis: \n");     /*ζηταει τον αριθμό της θεσης για κράτηση*/
                    scanf(" %d", &kratisi);                                 /*διαβαζει τον αριθμο θεσης που δινει ο χρήστης*/
                    kratisithesis(kratisi);                                 /*καλεί την συνάρτηση kratisithesis αναθετωντας της την τιμη της kratisi*/
                }
                while (a==1);                                               /*ο βρογχος do-while εκτελείται όσο η συναρτηση kratisithesis επιστρέφει την τιμή a=1*/
            }
            else if (epilogi==3) {                                          /*αν η επιλογή είναι 3*/
                do {
                    printf("\n\nH Anazitisi Kratimenis Thesis, Theleis na ginei me vasi: \n\n");    /*ζητάει από τον χρήστη να επιλέξει αν η αναζητηση θα γίνει:  */
                    printf("1) to onomateponimo tou epivati? \n");                                  /*με βαση το ονοματεπώνυμο ή το τηλέφωνο  */
                    printf("2) to tilefono tou epivati? \n\n");
                    printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n");
                    scanf(" %d", &epilogi2);                                /*διαβαζει την επιλογή του χρήστη*/
                    anazitisithesis(epilogi2);                              /*καλεί την συνάρτηση anazitisithesis αναθετωντας της την τιμή της epilogi2*/
                }
                while (b==1);                                               /*ο βρογχος do-while εκτελείται όσο η συναρτηση anazitisithesis επιστρέφει την τιμή b=1*/
            }
            else if (epilogi==4){                                           /*αν η επιλογή είναι 4*/
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis na akurwseis: \n");     /*ζηταει τον αριθμό της θεσης για ακύρωση*/
                    scanf(" %d", &kratisi);                                 /*διαβαζει τον αριθμο θεσης που δινει ο χρήστης*/
                    akurwsithesis(kratisi);                                 /*καλεί την συνάρτηση akurwsithesis αναθετωντας της την τιμή της kratisi*/
                }
                while (c==1);                                               /*ο βρογχος do-while εκτελείται όσο η συναρτηση akurwsithesis επιστρέφει την τιμή c=1*/
            }
            else if (epilogi==5) {                                          /*αν η επιλογή είναι 5*/
                lista();                                                    /*καλεί την συνάρτηση lista*/
            }
            else if (epilogi==0) {                                          /*αν η επιλογή είναι 0*/
                kleisimo();                                                 /*καλεί την συνάρτηση kleisimo*/
            }
            else if (epilogi!=0 || epilogi!=1 || epilogi!=2 || epilogi!=3 || epilogi!=4 || epilogi!=5) {
                printf("H epilogi sou den einai egkuri!! \n");
            }
    }
    while (epilogi!=0);
}


void anoigma() {                                                            /*ορισμός της συνάρτησης anoigma τύπου void*/
    fin=fopen("bus.txt", "r");                                              /*ανοιγει το αρχείο εισόδου bus.txt για αναγνωση*/
    if (fin==NULL) {                                                        /*ελεγχει αν υπάρχει λάθος στο ανοιγμα του αρχείου*/
        printf("**ERROR sto anoigma tou arxeiou!** \n");
        exit(1);
    }
    else {
        printf("Neo Sustima Katagrafis Thesewn Lewforeiou \n");
        printf("***************************************** \n\n");
        fscanf(fin, " %s %d", pinakida, &arithm);                           /*διαβαζει από το αρχείο την πινακιδα και τον αριθμό θέσεων του λεωφορείου και τα τυπωνει στην οθόνη*/
        printf("Lewforeio me Pinakida Kukloforias: %s \n", pinakida);
        printf("Sunolikos Arithmos Thesewn: %d \n", arithm);

    }
    N=(arithm-5)/4;
    upo=(arithm-5)%4;
    if (arithm>53 || N<0 || upo!=0) {                                       /*ελέγχει αν ο αριθμος θέσεων είναι επιτρεπτός*/
        printf("**ERROR me ton arithmo twn thesewn tou lewforeiou** \n");
        exit(1);
    }
    while (!feof(fin)) {                                                    /*σαρώνει το αρχείο εισόδου μεχρι το τέλος του και:   */
        epitheto[0]='\0';
        onoma[0]='\0';
        til[0]='\0';
        fscanf(fin, " %s %s %d %s", epitheto, onoma, &n, til);              /*διαβαζει από το αρχείο το επίθετο, το όνομα, τον αριθμό θέσης και το τηλεφωνο του επιβάτη*/
        strcat(epitheto, " ");                                              /*μετά το επίθετο προσθετει το κενό*/
        strcat(epitheto, onoma);                                            /*μετά το επίθετο και το κενό προσθέτει το όνομα*/
        strcpy(theseis[n-1].onomateponimo, epitheto);                       /*αντιγράφει και τα τρεία στο πεδίο ονοματεπώνυμο του πίνακα theseis, στη θέση του πίνακα που αντιστοιχεί στη θέση του επιβάτη*/
        m=0;
        for (i=0; til[i]>='0' && til[i]<='9'; i++) {                        /*μετατρέπει έναν-εναν τους χαρακτήρες του πίνακα χαρακτήρων til σε ακεραίους για να περαστούν στο πεδίο tilefono του struct*/
            m=(til[i]-'0');
            theseis[n-1].tilefono[i]=m;                                     /*αντιγράφει το τηλέφωνο στο πεδίο τηλέφωνο του πίνακα theseis, στη θέση του πίνακα που αντιστοιχεί στη θέση του επιβάτη*/
        }
    }
    fclose(fin);                                                            /*κλείνει το αρχείο εισόδου*/
}


void plithoskenwn() {                                                       /*ορισμός της συνάρτησης plithoskenwn τύπου void*/
    for (sunolokenwn=0,i=0; i<arithm; i++) {
        if (theseis[i].onomateponimo[0]=='\0') {                            /*μετράει το σύνολο των κενών θέσεων*/
            sunolokenwn++;
        }
    }
    printf("\nTo Sunolo twn Kenwn Thesewn einai: %d\n", sunolokenwn);
    printf("Kenes einai oi theseis me arithmo: \n");
    for (i=0; i<arithm; i++) {                                              /*τυπώνει διαδοχικά τους αριθμούς των κενών θέσεων*/
        if (theseis[i].onomateponimo[0]=='\0')
            printf("%d. \t", theseis[i].arithmosthesis);
    }
}


int kratisithesis(int x) {                                                  /*ορισμός της συνάρτησης kratisithesis τύπου int με μια μεταβλητη x τύπου int*/
    if (x<1 || x>arithm) {                                                  /*ελέγχει αν ο αριθμός θέσης που έδωσε ο χρήστης είναι εντός ορίων*/
        printf("H thesi pou epelekses einai ektos oriwn! \n");
        a=1;                                                                /*επιστρέφει στην main την τιμή a=1*/
    }
    else if (0<x<=arithm && theseis[x-1].onomateponimo[0]!='\0') {          /*ελέγχει αν η θέση που εδωσε ο χρήστης είναι κενή*/
        printf("H thesi pou epelekses den einai keni! \n");
        a=1;                                                                /*επιστρέφει στην main την τιμή a=1*/
    }
    else if (0<x<=arithm && theseis[x-1].onomateponimo[0]=='\0') {
        printf("Dwse to Epitheto tou Epivati: \n");                         /*ζητάει από τον χρήστη το επίθετο του επιβάτη*/
        scanf(" %s", epitheto);
        printf("Dwse to Onoma tou Epivati: \n");                            /*ζητάει το όνομα του επιβάτη*/
        scanf(" %s", onoma);
        printf("Dwse to Tilefono tou Epivati: \n");                         /*ζητάει το τηλέφωνο του επιβάτη*/
        scanf(" %s", til);
        strcat(epitheto, " ");                                              /*μετά το επίθετο προσθέτει το κενό*/
        strcat(epitheto, onoma);                                            /*και μετά το επίθετο και το κενό προσθέτει το όνομα*/
        strcpy(theseis[x-1].onomateponimo, epitheto);                       /*αντιγράφει το ονοματεπώνυμο του επιβάτη στο πεδίο ονοματεπώνυμο του πίνακα θέσεων, στην αντιστοιχη θέση που γίνεται η κράτηση*/
        m=0;
        for (i=0; til[i]>='0' && til[i]<='9'; i++) {                        /*μετατρέπει έναν-εναν τους χαρακτήρες του πίνακα χαρακτήρων til σε ακεραίους για να περαστούν στο πεδίο tilefono του struct*/
            m=(til[i]-'0');
            theseis[x-1].tilefono[i]=m;                                     /*αντιγράφει το τηλέφωνο του επιβάτη στο πεδίο τηλεφωνο του πίνακα θέσεων, στην αντιστοιχη θέση που γίνεται η κράτηση*/
        }
        printf("\nEgine kratisi tis thesis %d sto omomateponimo %s!! \n", x, epitheto);
        a=0;                                                                /*επιστρέφει στην main την τιμή a=0 και τερματιζει τον βρόγχο*/
    }
return (a);
}


int anazitisithesis(int y) {                                                /*ορισμός της συνάρτησης anazitisithesis τύπου int με μια μεταβλητη y τύπου int*/
    if (y!=1 && y!=2) {                                                     /*ελέγχει αν η επιλογή του χρήστη είναι έγκυρη*/
        printf("H epilogi sou den einai egkuri!! \n");
        b=1;                                                                /*επιστρέφει στην main την τιμή b=1*/
    }
    if (y==1) {                                                             /*αν η επιλογή είναι 1 η αναζήτηση γινεται με βάση το ονοματεπώνυμο*/
        printf("Dwse to Epitheto tou Epivati: \n");                         /*ζητάει το επίθετο και μετά το όνομα*/
        scanf(" %s", epitheto);
        printf("Dwse to Onoma tou Epivati: \n");
        scanf(" %s", onoma);
        strcat(epitheto, " ");
        strcat(epitheto, onoma);
        z=0;
        for (i=0; i<arithm; i++) {                                          /*η αναζήτηση γίνεται σε όλες τις θέσεις του πίνακα*/
            j=strcmp(epitheto, theseis[i].onomateponimo);                   /*η μεταβλητή j παίρνει την τιμή 0 αν οι δύο συμβολοσειρές που συγκρίνονται είναι ίδιες*/
            if (j==0) {
                printf("Sto onomateponimo %s exei kratithei i thesi %d \n", epitheto, i+1);
                z++;                                                        /*η μεταβλητή z μετράει πόσες θέσεις είναι κρατημένες στο ίδιο όνοματεπώνυμο*/
            }
        }
        if (j!=0 && z==0) printf("Oxi den uparxei kratisi sto onomateponimo %s \n", epitheto);
        b=0;                                                                /*επιστρέφει στην main την τιμή b=0 και τερματίζει τον βρόγχο*/
        }
    else if (y==2) {                                                        /*αν η επιλογή είναι 2 η αναζήτηση γινεται με βάση το τηλέφωνο*/
        printf("Dwse to Tilefono tou Epivati: \n");                         /*ζητάει το τηλέφωνο*/
        scanf(" %s", til);
        z=0;
        for (i=0; i<arithm; i++) {                                          /*η αναζήτηση γίνεται σε όλες τις θέσεις του πίνακα*/
            m=0;
            for (j=0; til[j]>='0' && til[j]<='9'; j++) {                    /*μετατρέπει έναν-εναν τους χαρακτήρες του πίνακα χαρακτήρων til σε ακεραίους και τους περνά στον πίνακα num*/
                m=(til[j]-'0');
                num[j]=m;
            }
            /*συγκρίνουμε όλα τα στοιχεία του πίνακα num με τα αντίστοιχα του πίνακα tilefono στο struct*/
            if (theseis[i].tilefono[0]==num[0] && theseis[i].tilefono[1]==num[1] && theseis[i].tilefono[2]==num[2] && theseis[i].tilefono[3]==num[3] && theseis[i].tilefono[4]==num[4] && theseis[i].tilefono[5]==num[5] && theseis[i].tilefono[6]==num[6] && theseis[i].tilefono[7]==num[7] && theseis[i].tilefono[8]==num[8] && theseis[i].tilefono[9]==num[9]) {
                printf("Sto tilefono %s exei kratithei i thesi %d \n", til, i+1);
                z++;                                                        /*η μεταβλητή z μετράει πόσες θέσεις είναι κρατημένες στο ίδιο τηλεφωνο*/
            }
        }
        if (z==0) {
            printf("Oxi den uparxei kratisi sto tilefono %s \n", til);
        }
        b=0;                                                                /*επιστρέφει στην main την τιμή b=0 και τερματιζει τον βρόγχο*/
    }
return (b);
}


int akurwsithesis(int l) {                                                  /*ορισμός της συνάρτησης akurwsithesis τύπου int με μια μεταβλητη l τύπου int*/
    if (l<1 || l>arithm) {                                                  /*ελέγχει αν η θέση που έδωσε ο χρήστης είναι εντός ορίων*/
        printf("H thesi pou epelekses einai ektos oriwn! \n");
        c=1;                                                                /*επιστρέφει στην main την τιμή c=1*/
    }
    else if (0<l<=arithm && theseis[l-1].onomateponimo[0]=='\0') {          /*ελέγχει αν η θέση είναι ήδη κενή*/
        printf("H thesi pou epelekses einai idi keni! \n");
        c=1;                                                                /*επιστρέφει στην main την τιμή c=1*/
    }
    else if (0<l<=arithm && theseis[l-1].onomateponimo[0]!='\0') {          /*κάνει την ακύρωση*/
        strcpy(theseis[l-1].onomateponimo, "\0");
        theseis[l-1].tilefono[0]=0;
        printf("\nEgine akurwsi kratisis tis thesis %d!! \n", l);
        c=0;                                                                /*επιστρέφει στην main την τιμή c=0 και τερματίζει τον βρόγχο*/
    }
return (c);
}


void lista() {                                                              /*ορισμός της συνάρτησης lista τύπου void*/
    printf("H lista kratisewn einai: \n");
    for (i=0; i<arithm; i++) {
        if (theseis[i].onomateponimo[0]!='\0') {                            /*εμφανίζει τη λίστα κρατήσεων που είναι ήδη ταξινομημένη κατά αριθμό θέσης*/
            printf("%d. \t", theseis[i].arithmosthesis);
            printf("%s \t", theseis[i].onomateponimo);
            for (j=0; j<10; j++) {
                printf("%d", theseis[i].tilefono[j]);
            }
            printf("\n");
        }
    }
}


void kleisimo() {                                                           /*ορισμός της συνάρτησης kleisimo τύπου void*/
    fout=fopen("bus.txt", "w");
    if (fout==NULL) {                                                       /*ελέγχει αν υπάρχει πρόβλημα με το ανοιγμα του αρχείου εξόδου*/
        printf("**ERROR sto anoigma tou arxeiou!** \n");
        exit(1);
    }
    fprintf(fout, "%s %d", pinakida, arithm);                               /*εγγράφει στο αρχείο εξόδου την πινακίδα και τον αριθμό των θέσεων*/
    for (i=0; i<arithm; i++) {
        if (theseis[i].onomateponimo[0]!='\0') {                            /*εγγράφει στο αρχείο εξόδου την λίστα κρατήσεων ως εξής:  */
            fprintf(fout, "\n%s ", theseis[i].onomateponimo);               /*ονοματεπώνυμο "κενό"  */
            fprintf(fout, "%d ", theseis[i].arithmosthesis);                /*αριθμό θέσης "κενό"   */
            for (j=0; j<10; j++) {
                fprintf(fout, "%d", theseis[i].tilefono[j]);                /*και τηλέφωνο*/
            }
        }
    }
    fclose(fout);                                                           /*κλείνει το αρχείο εξόδου*/
    printf("Egine apothikeusi twn kratisewn se arxeio \n");                 /*εμφανίζει κατάλληλο μήνυμα κατά την έξοδο*/
    printf("Exodos Programmatos \n");
}
