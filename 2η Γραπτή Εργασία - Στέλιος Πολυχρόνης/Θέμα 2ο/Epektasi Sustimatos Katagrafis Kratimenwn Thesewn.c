/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*2η Γραπτή Εργασία - Θέμα 2ο*/
/*Επέκταση Συστήματος Καταγραφής Κρατημένων Θέσεων*/

#include <stdio.h>
#include <stdlib.h>

FILE *fin, *fout;                                                   /*δηλωση των αρχειων εισοδου και εξοδου*/
char onoma[20], epitheto[40], til[11], pinakida[8];                 /*δήλωση των πινάκων χαρακτήρων*/
int num[10];                                                        /*δήλωση πίνακα ακεραίων*/
int i, n, m, e, k, N, upo, kratisi, epilogi, epilogi2, arithm;      /*δηλωση των ακεραιων μεταβλητων*/
int sunolokenwn, sunolokratimenwn, j, z, a, b, c, d, seires;        /*δήλωση των ακεραιων μεταβλητων*/

struct epivatis {                                                   /*δήλωση της δομης (struct) epivatis με στοιχεία: */
    char onomateponimo[40];                                         /*έναν πίνακα χαρακτηρων 40 θεσεων, */
    unsigned short tilefono[10];                                    /*έναν πίνακα unsigned short 10 θέσεων και */
    unsigned int arithmosthesis;                                    /*μια ακεραιη μεταβλητη unsigned int*/
} *theseis, temp;                                                   /*δήλωση ενος δείκτη *theseis και μιας μεταβλητης temp τύπου struct epivatis*/

struct komvos {                                                     /*δήλωση της δομής (struct) komvos με στοιχεία: */
    struct epivatis data;                                           /*μια μεταβλητή data τυπου struct epivatis και */
    struct komvos *next;                                            /*ενός δεικτη *next τυπου struct komvos*/
} *list_head;                                                       /*δήλωση ενος δείκτη *list_head τυπου struct komvos*/

/*προδήλωση των συναρτήσεων που ορίζονται στο τέλος*/
void anoigma();
void plithoskenwn();
int kratisithesis(int x);
int anazitisithesis(int y);
int akurwsithesis(int l);
int lista(int m);
void kleisimo();
struct komvos *prosthikikomvou(struct komvos *p, struct epivatis da);
void emfanisikomvwn(struct komvos *lh);
void eggrafikomvwn(struct komvos *lh);

/*ξεκινημα της main*/
void main()
{
    anoigma();                                                              /*καλεί την συναρτηση anoigma τύπου void*/

    do {                                                                    /*ξεκινάει ο βασικός βρόγχος της main*/
            printf("\n\n Lista Epilogwn: \n");                              /*εμφανίζει στην οθόνη την λίστα επιλογών*/
            printf(" --------------- \n\n");
            printf(" 1. Emfanisi Kenwn Thesewn \n");
            printf(" 2. Kratisi Sugkekrimenis Thesis \n");
            printf(" 3. Anazitisi Kratimenis Thesis \n");
            printf(" 4. Akurwsi Kratisis Thesis \n");
            printf(" 5. Lista Kratimenwn Thesewn \n");
            printf(" 0. Exodos \n\n");
            printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n");     /*ζητάει την επιλογη του χρήστη*/
            scanf(" %d", &epilogi);                                             /*διαβαζει την επιλογή του χρήστη*/
            printf("\n");

            if (epilogi==1) {                                                   /*αν η επιλογή είναι 1:   */
                plithoskenwn();                                                 /*καλεί την συναρτηση plithoskenwn τυπου void*/
            }
            else if (epilogi==2){                                               /*αν η επιλογή είναι 2:  */
                do {                                                            /*βρόγχος do-while που επαναλαμβάνεται όσο a=1*/
                    printf("Epilekse ton arithmo tis thesis pou theleis na kratiseis: \n");     /*ζητάει από τον χρήστη τον αριθμό θεσης για κράτηση*/
                    scanf(" %d", &kratisi);                                     /*διαβαζει τον αριθμό της θέσης και τον αναθετει στην μεταβλητη kratisi*/
                    kratisithesis(kratisi);                                     /*καλεί την συναρτηση kratisithesis περνώντας της τη τιμή της kratisi*/
                }
                while (a==1);
            }
            else if (epilogi==3) {                                              /*αν η επιλογή είναι 3:  */
                do {                                                            /*βρόγχος do-while που επαναλαμβάνεται όσο b=1*/
                    printf("\n\nH Anazitisi Kratimenis Thesis, Theleis na ginei me vasi: \n\n");
                    printf("1) to onomateponimo tou epivati? \n");              /*εμφανιζει δευτερο μενου για αναζητηση θέσης με ονοματεπώνυμο ή με τηλεφωνο*/
                    printf("2) to tilefono tou epivati? \n\n");
                    printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n");
                    scanf(" %d", &epilogi2);                                    /*διαβαζη την τιμη για την epilogi2*/
                    anazitisithesis(epilogi2);                                  /*καλεί την συναρτηση anazitisithesis περνώντας της τη τιμή της epilogi2*/
                }
                while (b==1);
            }
            else if (epilogi==4){                                               /*αν η επιλογή είναι 4:  */
                do {                                                            /*βρόγχος do-while που επαναλαμβάνεται όσο c=1*/
                    printf("Epilekse ton arithmo tis thesis pou theleis na akurwseis: \n");
                    scanf(" %d", &kratisi);
                    akurwsithesis(kratisi);                                     /*καλεί την συναρτηση akurwsithesis περνώντας της τη τιμή της kratisi*/
                }
                while (c==1);
            }
            else if (epilogi==5) {                                              /*αν η επιλογή είναι 5:  */
                do {                                                            /*βρόγχος do-while που επαναλαμβάνεται όσο d=1*/
                    printf("\nTheleis i taksinomisi tis listas na ginei me vasi: \n\n");
                    printf("1) ton arithmo thesis? \n");                        /*εμφανιζει δευτερο μενου για ταξινομηση της λίστας με ονοματεπώνυμο ή με αριθμο θεσης*/
                    printf("2) to onomateponimo tou epivati? \n\n");
                    printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n");
                    scanf(" %d", &epilogi2);                                    /*διαβαζει την τιμή για την epilogi2*/
                    lista(epilogi2);                                            /*καλεί την συναρτηση lista περνώντας της τη τιμή της epilogi2*/
                }
                while (d==1);
            }
            else if (epilogi==0) {                                              /*αν η επιλογή είναι 0:  */
                kleisimo();                                                     /*καλεί την συναρτηση kleisimo*/
            }
            else if (epilogi!=0 || epilogi!=1 || epilogi!=2 || epilogi!=3 || epilogi!=4 || epilogi!=5) {
                printf("H epilogi sou den einai egkuri!! \n");
            }
    }
    while (epilogi!=0);

    return;
} /*τέλος της main*/


void anoigma()                                                              /*οριζεται η συναρτηση anoigma τυπου void που ξεκινά το συστημα καταγραφής*/
{
    fin=fopen("bus.txt", "r");                                              /*ανοιγει το αρχειο εισόδου bus.txt για ανάγνωση*/
    if (fin==NULL) {
        printf("**ERROR sto anoigma tou arxeiou!** \n");                    /*μήνυμα λαθους για το ανοιγμα του αρχείου και */
        exit(1);                                                            /*εξοδος από το πρόγραμμα*/
    }
    else {
        printf("Epektasi Sustimatos Katagrafis Thesewn Lewforeiou \n");     /*τίτλος του συστήματος καταγραφής*/
        printf("************************************************* \n\n");
        fscanf(fin, " %s %d", pinakida, &arithm);                           /*διαβαζει απο το αρχειο την πινακιδα και τον αριθμό των θέσεων*/
        printf("Lewforeio me Pinakida Kukloforias: %s \n", pinakida);       /*εμφανίζει την πινακίδα και */
        printf("Sunolikos Arithmos Thesewn: %d \n", arithm);                /*τον αριθμό των θέσεων*/

    }
    N=(arithm-5)/4;                                                         /*υπολογίζει τον αριθμό των σειρών των θέσεων*/
    upo=(arithm-5)%4;                                                       /*και το υπόλοιπο της διαίρεσης των θέσεων-5 με το 4*/
    if (arithm>53 || N<0 || upo!=0) {
        printf("**ERROR me ton arithmo twn thesewn tou lewforeiou** \n");   /*μύνημα λάθους ότι ο αριθμός των θέσεων δεν πληρεί τις προϋποθέσεις */
        exit(1);                                                            /*και έξοδος από το πρόγραμμα*/
    }
    theseis=calloc(arithm, sizeof(struct epivatis));                        /*ορισμός ενος μονοδιάστατου δυναμικού πίνακα με θέσεις όσες ο αριθμός arithm των θέσεων και μέγεθος του καθενός όσο το μέγεθος του struct epivatis*/
    if (theseis==NULL) {
        printf("**ERROR Den uparxei diathesimi mnimi!!");                   /*μήνυμα λάθους αν δεν υπάρχει διαθεσιμη μνήμη */
        exit(1);                                                            /*και έξοδος από το πρόγραμμα*/
    }
    for (i=0; i<53; i++) {                                                  /*αρχικοποίηση του πίνακα των θέσεων,ώστε όλες να είναι κενές, ως εξής: */
        strcpy (theseis[i].onomateponimo, "\0");                            /*αντιγράφει στο πεδίο ονοματεπώνυμο τον κενό χαρακτήρα, */
        theseis[i].tilefono[0]=0;                                           /*αντιγράφει στο πεδίο τηλέφωνο τον κενο χαρακτήρα και */
        theseis[i].arithmosthesis=i+1;                                      /*θέτει στο πεδιο αριθμος θεσης τον αντίστοιχο αριθμό*/
    }
    while (!feof(fin)) {                                                    /*σαρώνει το αρχείο εισόδου ως το τέλος του και:  */
        epitheto[0]='\0';
        onoma[0]='\0';
        til[0]='\0';
        fscanf(fin, " %s %s %d %s", epitheto, onoma, &n, til);              /*διαβάζει απο το αρχείο το επίθετο, το όνομα, τον αριθμό θέσης και το τηλέφωνο των αποθηκευμένων κρατήσεων*/
        strcat(epitheto, " ");                                              /*προσθέτει στο τέλος του επίθετου ένα κενό*/
        strcat(epitheto, onoma);                                            /*προσθετει στο τέλος του επίθετου, μετά το κενό, το όνομα*/
        strcpy(theseis[n-1].onomateponimo, epitheto);                       /*αντιγράφει τα παραπανω περιεχόμενα του πίνακα epitheto στο πεδίο ονοματεπώνυμο στην αντίστοιχη θέση του πίνακα*/
        m=0;
        for (i=0; til[i]>='0' && til[i]<='9'; i++) {                        /*μετατρέπει έναν-εναν τους χαρακτήρες του πίνακα χαρακτήρων til σε ακεραίους για να περαστούν στο πεδίο tilefono του struct*/
            m=(til[i]-'0');
            theseis[n-1].tilefono[i]=m;                                     /*αντιγράφει το τηλέφωνο στο πεδίο τηλέφωνο του πίνακα theseis, στη θέση του πίνακα που αντιστοιχεί στη θέση του επιβάτη*/
        }
    }
    fclose(fin);                                                            /*κλείνει το αρχείο εισόδου*/
}


void plithoskenwn()                                                         /*ορίζεται η συναρτηση plithoskenwn τυπου void*/
{
    for (sunolokenwn=0,i=0; i<arithm; i++) {                                /*σαρώνει τον δυναμικό πίνακα και μετράει το σύνολο των κενών θέσεων*/
        if (theseis[i].onomateponimo[0]=='\0') {
            sunolokenwn++;
        }
    }
    printf("\nTo Sunolo twn Kenwn Thesewn einai: %d\n", sunolokenwn);       /*εμφανίζει το σύνολο των κενων θέσεων*/
    printf("Kenes einai oi theseis me arithmo: \n");
    for (i=0; i<arithm; i++) {                                              /*σαρώνει τον πίνακα και τυπώνει έναν έναν τους αριθμούς των κενων θέσεων*/
        if (theseis[i].onomateponimo[0]=='\0')
            printf("%d. \t", theseis[i].arithmosthesis);
    }
}


int kratisithesis(int x)                                                    /*ορίζεται η συνάρτηση kratisithesis τύπου int*/
{
    if (x<1 || x>arithm) {                                                  /*ελεγχει αν η θεση ειναι εκτός ορίων και τυπωνει καταλληλο μήνυμα*/
        printf("H thesi pou epelekses einai ektos oriwn! \n");
        a=1;                                                                /*η συναρτηση επιστρέφει την τιμη a=1 ώστε να συνεχιστει ο βρόγχος στη main*/
    }
    else if (0<x<=arithm && theseis[x-1].onomateponimo[0]!='\0') {          /*ελεγχει αν η θεση ειναι κενη και τυπωνει καταλληλο μήνυμα*/
        printf("H thesi pou epelekses den einai keni! \n");
        a=1;                                                                /*η συναρτηση επιστρέφει την τιμη a=1 ώστε να συνεχιστει ο βρόγχος στη main*/
    }
    else if (0<x<=arithm && theseis[x-1].onomateponimo[0]=='\0') {
        printf("Dwse to Epitheto tou Epivati: \n");                         /*ζηταει τα στοιχεια (επιθετο, όνομα, τηλεφωνο) του επιβατη*/
        scanf(" %s", epitheto);
        printf("Dwse to Onoma tou Epivati: \n");
        scanf(" %s", onoma);
        printf("Dwse to Tilefono tou Epivati: \n");
        scanf(" %s", til);
        strcat(epitheto, " ");                                              /*περνάει τα δοθέντα στοιχεία στην θεση του πινακα που αντιστοιχει στη θεση κρατησης*/
        strcat(epitheto, onoma);
        strcpy(theseis[x-1].onomateponimo, epitheto);
        m=0;
        for (i=0; til[i]>='0' && til[i]<='9'; i++) {                        /*μετατρέπει έναν-εναν τους χαρακτήρες του πίνακα χαρακτήρων til σε ακεραίους για να περαστούν στο πεδίο tilefono του struct*/
            m=(til[i]-'0');
            theseis[x-1].tilefono[i]=m;                                     /*αντιγράφει το τηλέφωνο του επιβάτη στο πεδίο τηλεφωνο του πίνακα θέσεων, στην αντιστοιχη θέση που γίνεται η κράτηση*/
        }
        printf("\nEgine kratisi tis thesis %d sto omomateponimo %s!! \n", x, epitheto);
        a=0;                                                                /*η συναρτηση επιστρέφει την τιμη a=0 ώστε να σταματήσει ο βρόγχος στη main*/
    }
return (a);
}


int anazitisithesis(int y)                                                  /*ορίζεται η συνάρτηση anazitisithesis τύπου int*/
{
    if (y!=1 && y!=2) {                                                     /*ελεγχει αν η επιλογη είναι εγκυρη*/
        printf("H epilogi sou den einai egkuri!! \n");
        b=1;                                                                /*η συναρτηση επιστρέφει την τιμη b=1 ώστε να συνεχιστει ο βρόγχος στη main*/
    }
    if (y==1) {                                                             /*αν y=1 κανει αναζητηση με ονοματεπώνυμο*/
        printf("Dwse to Epitheto tou Epivati: \n");
        scanf(" %s", epitheto);
        printf("Dwse to Onoma tou Epivati: \n");
        scanf(" %s", onoma);
        strcat(epitheto, " ");
        strcat(epitheto, onoma);
        z=0;                                                                /*η μεταβλητη z μετραει ποσες θεσεις ειναι κρατημενες στο ιδιο ονοματεπώνυμο*/
        for (i=0; i<arithm; i++) {
            j=strcmp(epitheto, theseis[i].onomateponimo);                   /*η μεταβλητη j περνει την τιμή που επιστρεφει η strcmp που συγκρινει το ομοματεπώνυμο σε όλες τις θεσεις του πίνακα*/
            if (j==0) {
                printf("Sto onomateponimo %s exei kratithei i thesi %d \n", epitheto, i+1);
                z++;
            }
        }
        if (j!=0 && z==0) printf("Oxi den uparxei kratisi sto onomateponimo %s \n", epitheto);
        b=0;                                                                /*η συναρτηση επιστρέφει την τιμη b=0 ώστε να σταματήσει ο βρόγχος στη main*/
        }
    else if (y==2) {                                                        /*αν y=2 κανει αναζήτηση με τηλέφωνο*/
        printf("Dwse to Tilefono tou Epivati: \n");
        scanf(" %s", til);
        z=0;                                                                /*η μεταβλητη z μετραει ποσες θεσεις ειναι κρατημενες στο ιδιο τηλέφωνο*/
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
        b=0;                                                                /*η συναρτηση επιστρέφει την τιμη b=0 ώστε να σταματήσει ο βρόγχος στη main*/
    }
return (b);
}


int akurwsithesis(int l)                                                    /*ορίζεται η συνάρτηση akurwsithesis τύπου int*/
{
    if (l<1 || l>arithm) {                                                  /*ελέγχει αν η τιμή είναι εντός ορίων*/
        printf("H thesi pou epelekses einai ektos oriwn! \n");
        c=1;                                                                /*η συναρτηση επιστρέφει την τιμη c=1 ώστε να συνεχιστει ο βρόγχος στη main*/
    }
    else if (0<l<=arithm && theseis[l-1].onomateponimo[0]=='\0') {          /*ελέγχει αν η θέση είναι ήδη κενή*/
        printf("H thesi pou epelekses einai idi keni! \n");
        c=1;                                                                /*η συναρτηση επιστρέφει την τιμη c=1 ώστε να συνεχιστει ο βρόγχος στη main*/
    }
    else if (0<l<=arithm && theseis[l-1].onomateponimo[0]!='\0') {
        strcpy(theseis[l-1].onomateponimo, "\0");
        theseis[l-1].tilefono[0]=0;
        printf("\nEgine akurwsi kratisis tis thesis %d!! \n", l);
        c=0;                                                                /*η συναρτηση επιστρέφει την τιμη c=0 ώστε να σταματησει ο βρόγχος στη main*/
    }
return (c);
}


int lista(int m)                                                            /*ορίζεται η συνάρτηση lista τύπου int*/
{
    if (m!=1 && m!=2) {                                                     /*ελέγχει αν είναι εγκυρη η επιλογή*/
        printf("\nH epilogi sou den einai egkuri!! \n");
        d=1;                                                                /*η συναρτηση επιστρέφει την τιμη d=1 ώστε να συνεχιστει ο βρόγχος στη main*/
    }
    if (m==1) {
        printf("\nH lista kratisewn kata arithmo thesis einai: \n");
        for (i=0; i<arithm; i++) {                                          /*σαρώνει των πίνακα θέσεων και τυπώνει τη λίστα κρατήσεων σύμφωνα με τον αριθμό θέσης*/
            if (theseis[i].onomateponimo[0]!='\0') {
                printf("%d. \t", theseis[i].arithmosthesis);
                printf("%s \t", theseis[i].onomateponimo);
                for (j=0; j<10; j++) {
                    printf("%d", theseis[i].tilefono[j]);
                }
                printf("\n");
            }
        }
        d=0;                                                                /*η συναρτηση επιστρέφει την τιμη d=0 ώστε να σταματησει ο βρόγχος στη main*/
    }
    else if (m==2) {
        for (i=1; i<arithm; i++) {                                          /*αλγόριθμος φυσαλλίδας για αλφαβητικη ταξινομηση του πίνακα θέσεων*/
            for (k=arithm-1; k>=i; k--) {
                j=strcmp(theseis[k].onomateponimo, theseis[k-1].onomateponimo);
                if (j==-1) {
                    strcpy(temp.onomateponimo, theseis[k].onomateponimo);
                    strcpy(theseis[k].onomateponimo, theseis[k-1].onomateponimo);
                    strcpy(theseis[k-1].onomateponimo, temp.onomateponimo);
                    temp.arithmosthesis=theseis[k].arithmosthesis;
                    theseis[k].arithmosthesis=theseis[k-1].arithmosthesis;
                    theseis[k-1].arithmosthesis=temp.arithmosthesis;
                    for (e=0; e<10; e++) {
                        temp.tilefono[e]=theseis[k].tilefono[e];
                        theseis[k].tilefono[e]=theseis[k-1].tilefono[e];
                        theseis[k-1].tilefono[e]=temp.tilefono[e];
                    }
                }
            }
        }
        printf("\nH alfavitiki lista kratisewn einai: \n");
        for (i=0; i<arithm; i++) {                                          /*σαρώνει τον πίνακα θέσεων και τυπώνει την λίστα κρατήσεων αλφαβητικά*/
            if (theseis[i].onomateponimo[0]!='\0') {
                printf("%d. \t", theseis[i].arithmosthesis);
                printf("%s \t", theseis[i].onomateponimo);
                for (j=0; j<10; j++) {
                    printf("%d", theseis[i].tilefono[j]);
                }
                printf("\n");
            }
        }
        for (i=1; i<arithm; i++) {                                          /*με αλγόριθμο φυσαλλίδας επαναφέρει τον πίνακα θέσεων στην προηγούμενη ταξινόμηση με τον αριθμό θέσης*/
            for (k=arithm-1; k>=i; k--) {
                if (theseis[k].arithmosthesis<theseis[k-1].arithmosthesis) {
                    strcpy(temp.onomateponimo, theseis[k].onomateponimo);
                    strcpy(theseis[k].onomateponimo, theseis[k-1].onomateponimo);
                    strcpy(theseis[k-1].onomateponimo, temp.onomateponimo);
                    temp.arithmosthesis=theseis[k].arithmosthesis;
                    theseis[k].arithmosthesis=theseis[k-1].arithmosthesis;
                    theseis[k-1].arithmosthesis=temp.arithmosthesis;
                    for (e=0; e<10; e++) {
                        temp.tilefono[e]=theseis[k].tilefono[e];
                        theseis[k].tilefono[e]=theseis[k-1].tilefono[e];
                        theseis[k-1].tilefono[e]=temp.tilefono[e];
                    }
                }
            }
        }
        d=0;                                                                /*η συναρτηση επιστρέφει την τιμη d=0 ώστε να σταματησει ο βρόγχος στη main*/
    }
return (d);
}


void kleisimo()                                                             /*ορίζεται η συνάρτηση kleisimo τύπου void*/
{
    for (i=1; i<arithm; i++) {                                              /*αλγόριθμος φυσαλλίδας για αλφαβητικη ταξινομηση του πίνακα θέσεων*/
        for (k=arithm-1; k>=i; k--) {
            j=strcmp(theseis[k].onomateponimo, theseis[k-1].onomateponimo);
            if (j==-1) {
                strcpy(temp.onomateponimo, theseis[k].onomateponimo);
                strcpy(theseis[k].onomateponimo, theseis[k-1].onomateponimo);
                strcpy(theseis[k-1].onomateponimo, temp.onomateponimo);
                temp.arithmosthesis=theseis[k].arithmosthesis;
                theseis[k].arithmosthesis=theseis[k-1].arithmosthesis;
                theseis[k-1].arithmosthesis=temp.arithmosthesis;
                for (e=0; e<10; e++) {
                    temp.tilefono[e]=theseis[k].tilefono[e];
                    theseis[k].tilefono[e]=theseis[k-1].tilefono[e];
                    theseis[k-1].tilefono[e]=temp.tilefono[e];
                }
            }
        }
    }
    list_head=NULL;                                                         /*αρχικοποίηση του δείκτη list_head προς τη κεφαλή της λίστας*/
    for (i=0; i<arithm; i++) {                                              /*σαρώνει τον αλφαβητικά ταξινομημενο πίνακα θεσεων και   */
        if (theseis[i].onomateponimo[0]!='\0') {                            /*για καθε κρατημενη θεση καλεί την συναρτηση prosthikikomvou  */
            list_head=prosthikikomvou(list_head, theseis[i]);               /*που δημιουργει την απλά συνδεδεμένη λίστα*/
        }
    }
    emfanisikomvwn(list_head);                                              /*καλεί την συναρτηση emfanisikomvwn που εμφανίζει τη συνδεδεμενη λίστα στην οθόνη*/

    eggrafikomvwn(list_head);                                               /*καλεί την συναρτηση eggrafikomvwn που αποθηκευει τη συνδεδεμενη λίστα στο αρχειο εξοδου*/

    printf("\n\nEgine apothikeusi twn kratisewn se arxeio \n");
    printf("Exodos Programmatos \n");
}


struct komvos *prosthikikomvou(struct komvos *p, struct epivatis da) {      /*ορίζεται η συνάρτηση prosthikikomvou τύπου struct komvos*/
    struct komvos *neos;
    if (p==NULL){                                                           /*αναδρομικός αλγόριθμος για την προσθήκη νέων κόμβων στην συνδεδεμένη λίστα*/
        neos=malloc(sizeof(struct komvos));
        strcpy(neos->data.onomateponimo, da.onomateponimo);
        neos->data.arithmosthesis=da.arithmosthesis;
        for (e=0; e<10; e++) {
            neos->data.tilefono[e]=da.tilefono[e];
        }
        neos->next=NULL;
    }
    else {
        p->next=prosthikikomvou(p->next, da);
    }
return (neos);                                                              /*επιστρέφει στον βρόγχο που την κάλεσε τον τελευταίο νέο κόμβο*/
}


void emfanisikomvwn(struct komvos *lh)                                      /*ορίζεται η συνάρτηση emfanisikomvwn τύπου void*/
{
    if (lh==NULL) {                                                         /*εμφανίζει στην οθόνη τους κόμβους της συνδεδεμένης λίστας*/
        printf("H lista einai keni!!!\n");
    }
    printf("H sundedemeni lista einai: \n");
    printf("--------------------------");
    while (lh!=NULL) {
        printf("\n%s ", lh->data.onomateponimo);
        printf("%d ", lh->data.arithmosthesis);
        for (j=0; j<10; j++) {
            printf("%d", lh->data.tilefono[j]);
        }
        lh=lh->next;
    }
}


void eggrafikomvwn(struct komvos *lh)                                       /*ορίζεται η συνάρτηση eggrafikomvwn τύπου void*/
{
    fout=fopen("bus.txt", "w");                                             /*ανοίγει το αρχείο εξόδου για εγγραφή*/
    if (fout==NULL) {
        printf("**ERROR sto anoigma tou arxeiou!** \n");
        exit(1);
    }
    fprintf(fout, "%s %d", pinakida, arithm);                               /*γραφει στο αρχείο την πινακίδα και τον αριθμό των θέσεων*/
    while (lh!=NULL) {                                                      /*γράφει στο αρχείο όλους τους κόμβους της συνδεδεμένης λίστας*/
        fprintf(fout, "\n%s ", lh->data.onomateponimo);
        fprintf(fout, "%d ", lh->data.arithmosthesis);
        for (j=0; j<10; j++) {
            fprintf(fout, "%d", lh->data.tilefono[j]);
        }
        lh=lh->next;
    }
    fclose(fout);                                                           /*κλείνει το αρχείο εξόδου*/
}
