/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*2η Γραπτή Εργασία - Θέμα 3ο*/
/*Υλοποίηση Παραλλαγής Παιχνιδιού Set*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, k, l, z, energos, elenktis;                                           /*ορισμός ακέραιων μεταβλητών*/
int x[3], y[3], tuxaioi[12];                                                    /*ορισμός πινάκων ακεραίων*/
char id;                                                                        /*ορισμός μεταβλητής χαρακτήρα*/


struct karta {                                                                  /*ορισμός struct karta με στοιχεία 4 μονοδιαστατους πινακες χαρακτήρων*/
        char xrwma[4], sxima[3], arithmos[3], ifi[3];
    } kartes[82], tablo[3][4];                                                  /*ορισμός ενος μονοδιάστατου πίνακα kartes και ενός δυδιαστατου πινακα tablo τυπου struct karta*/

struct paiktis {                                                                /*ορισμός struct paiktis με στοιχεία:  */
        char onoma[18];                                                         /*εναν πινακα χαρακτηρων για το ονομα του παικτη,*/
        unsigned int bathmologia;                                               /*μια ακέραια μεταβλητη για την βαθμολογία και */
        char xaraktiras;                                                        /*έναν χαρακτήρα για το id του κάθε παίκτη*/
    } paiktes[3];                                                               /*ορισμός ενός πίνακα 3 θεσεων τύπου struct paiktis για τους 3 παικτες*/

/*προδήλωση των συναρτήσεων που θα οριστούν παρακάτω*/
int elegxosSet();
int getNextCard();

/*αρχή της main*/
void main()
{
    strcpy (paiktes[0].onoma, "Marina Andreou");                                /*εγγράφουμε τα ονοματα των 3 παικτων στο πεδίο onoma και στην αντίστοιχη θέση του πίνακα paiktes*/
    strcpy (paiktes[1].onoma, "Kostas Grammenos");
    strcpy (paiktes[2].onoma, "Maria Perdika");
    paiktes[0].xaraktiras='a';                                                  /*εγγράφουμε τα id των 3 παικτων στο πεδίο xaraktiras και στην αντίστοιχη θέση του πίνακα paiktes*/
    paiktes[1].xaraktiras='g';
    paiktes[2].xaraktiras='p';
    for (i=0; i<3; i++) {                                                       /*μηδενίζουμε την βαθμολογία των 3 παικτών*/
        paiktes[i].bathmologia=0;
    }
    /*με την παρακατω διαδικασία φτιάχνουμε τις 81 καρτες που αντιστοιχούν στους 81 πιθανούς συνδυασμούς και τους  */
    /*αντιγράφουμε στις 81 αντιστοιχες θέσεις του πίνακα kartes. Συμπεριλαμβάνουμε και τους χαρακτηρες "[" "]" και ","*/
    for (i=0; i<27; i++) {
        strcpy (kartes[i].xrwma, "[r,");
        strcpy (kartes[i+27].xrwma, "[g,");
        strcpy (kartes[i+54].xrwma, "[b,");
        strcpy (kartes[3*i].ifi, "b]");
        strcpy (kartes[(3*i)+1].ifi, "h]");
        strcpy (kartes[(3*i)+2].ifi, "e]");
    }
    for (i=0; i<9; i++) {
        for (j=0; j<3; j++) {
            strcpy (kartes[(9*i)+j].arithmos, "1,");
            strcpy (kartes[(9*i)+j+3].arithmos, "2,");
            strcpy (kartes[(9*i)+j+6].arithmos, "3,");
        }
    }
    for (i=0; i<3; i++) {
        for (j=0; j<9; j++) {
            strcpy (kartes[(27*i)+j].sxima, "c,");
            strcpy (kartes[(27*i)+j+9].sxima, "t,");
            strcpy (kartes[(27*i)+j+18].sxima, "r,");
        }
    }

    /* εκτυπωνει και τις 81 καρτες για να μπορούμε να τις ελεγξουμε αν χρειαστεί*/
    /*
    for (l=0; l<81; l++) {
        printf("%s", kartes[l].xrwma);
        printf("%s", kartes[l].sxima);
        printf("%s", kartes[l].arithmos);
        printf("%s \t", kartes[l].ifi);
    }
    */

    getNextCard();                                                                  /*καλεί την συναρτηση getNextCard που επιστρέφει τον πίνακα tuxaioi με 12 τυχαίους αριθμούς*/

    do {                                                                            /*βασικός βρογχος do-while του προγράμματος, που επαναλλαμβάνεται όσο k=1*/
        printf("Oi 12 tuxaies kartes einai: \n");
        printf("--------------------------- \n\n");
        for (i=0; i<3; i++) {                                                       /*στη συνεχεια με βάση τους 12 τυχαίους αριθμούς που επέστρεψε η getNextCard καταχωρεί  */
            for (j=0; j<4; j++) {                                                   /*τα δεδομένα των πεδίων των αντίστοιχων (με τους 12 αριθμούς) καρτών στα αντιστοιχα πεδία  */
                k=tuxaioi[4*i+j];                                                   /*του διδιάστατου πίνακα tablo*/
                strcpy(tablo[i][j].xrwma, kartes[k].xrwma);
                strcpy(tablo[i][j].sxima, kartes[k].sxima);
                strcpy(tablo[i][j].arithmos, kartes[k].arithmos);
                strcpy(tablo[i][j].ifi, kartes[k].ifi);
                printf("\t%s", tablo[i][j].xrwma);                                  /*τέλος εμφανίζει στην οθονη αυτες τις κάρτες που έχουν καταχωρηθεί στον πίνακα tablo, που  */
                printf("%s", tablo[i][j].sxima);                                    /*είναι και οι καρτες (δωδεκάδα) με τις οποίες ξεκινά το παιχνίδι*/
                printf("%s", tablo[i][j].arithmos);
                printf("%s", tablo[i][j].ifi);
            }
            printf("\n\n");
        }
        for (i=0; i<3; i++) {                                                       /*κάτω από το ταμπλό με τις 12 κάρτες εμφανίζει τα στοιχεία των παικτών (id, βαθμούς και όνομα)*/
            printf("\tId: %c \tBathmoi: %d \tOnoma: %s \n", paiktes[i].xaraktiras, paiktes[i].bathmologia, paiktes[i].onoma);
        }
        printf("\nDwse to **id** tou paikti pou paizei, alliws dwse **0** gia exodo!! \n");     /*ζητάει το id του παίκτη που θέλει να παίξει/γίνει ενεργός ή "0" για έξοδο*/
        scanf(" %c", &id);
        if (id=='0') {                                                              /*αν η επιλογή του χρήστη είναι "0" εμφανίζει την τελική βαθμολογία και τερματίζει το πρόγραμμα*/
            printf("***Epelekses Exodo!!!***\n\n");
            printf("H teliki bathmologia einai: \n");
            printf("--------------------------- \n");
            for (i=0; i<3; i++) {
                printf("Onoma: %16s \tBathmoi: %d \n", paiktes[i].onoma, paiktes[i].bathmologia);
            }
            exit(1);
        }
        if (id!='0' && id!='a' && id!='g' && id!='p') {                             /*αν η επιλογή του χρήστη είναι διάφορη του "0" και του id των 3 παικτων τότε καλεί την συνάρτηση  */
            printf("**To id pou edwses den uparxei** \n");                          /*getNextCard και επαναλαμβάνει τον βρογχο από την αρχή ώστε να εμφανισει καινουρια 12δα καρτών και */
            printf("**Allagi tou tablo me tis kartes** \n\n");                      /*ζητά εκ νεου επιλογή για id ή έξοδο */
            getNextCard();
            k=1;
            continue;
        }

        for (i=0; i<3; i++) {                                                       /*ανάλογα με την επιλογή του id εμφανίζει τον ενεργό παίκτη*/
            if (paiktes[i].xaraktiras==id) {
                energos=i;
                printf("\nEnergos einai o paiktis: *** %s *** \n", paiktes[energos].onoma);
            }
        }
        elegxosSet();                                                               /*καλεί την συνάρτηση elegxosSet που επιστρέφει την τιμή της μεταβλητής elenktis*/

        if (elenktis==1) {                                                          /*αν η μεταβλητή elenktis επιστρέφει με την τιμή 1, δηλαδή έχουμε set, τότε:   */
            paiktes[energos].bathmologia=paiktes[energos].bathmologia+2;            /*η βαθμολογία του ενεργού παίκτη αυξάνεται κατα 2 μονάδες και εμφανίζεται στην οθόνη*/
            printf("Prostethikan +2 bathmoi ston paikth: %s !!!\n", paiktes[energos].onoma);
            printf("Sunolo Bathmwn tou paikti %s einai: %d\n\n\n",paiktes[energos].onoma, paiktes[energos].bathmologia);
            k=1;
            getNextCard();                                                          /*καλεί την getNextCard για να έχουμε νέα 12άδα καρτών και αρχίζει η ίδια διαδικασία από την αρχή*/
        }
        else if (elenktis==0) {                                                     /*αν η μεταβλητή elenktis επιστρέφει με την τιμή 0, δηλαδή δεν έχουμε set,*/
            if (paiktes[energos].bathmologia>0) {                                   /*και η βαθμολογία του ενεργού παίκτη είναι μεγαλύτερη από 0, τότε μειώνεται κατα 1 μονάδα και εμφανίζεται στην οθόνη*/
                paiktes[energos].bathmologia=paiktes[energos].bathmologia-1;
                printf("Afairethike -1 bathmos apo ton paikti: %s !!!\n", paiktes[energos].onoma);
                printf("Sunolo Bathmwn tou paikti %s: %d\n\n\n",paiktes[energos].onoma, paiktes[energos].bathmologia);
                k=1;
            }
            else {                                                                  /*αν όμως η βαθμολογία του είναι ήδη 0, τότε δεν αφαιρούνται βαθμοί*/
                printf("H bathmologia tou paikti %s einai: %d\n\n\n", paiktes[energos].onoma, paiktes[energos].bathmologia);
                k=1;
            }
        }                                                                           /*σε αυτή την περίπτωση οι 12άδα των καρτών παραμένει η ίδια*/

        for (i=0; i<3; i++) {                                                       /*στο τέλος κάθε προσπάθειας ελέγχει αν κάποιος παίκτης έχει βαθμολογία μεγαλύτερη ή ίση με 10 και τον ανακυρήσει νικητή*/
            if (paiktes[i].bathmologia>=10) {
                printf("\t*****Nikitis einai o paiktis: %s*****\n\n", paiktes[i].onoma);
                printf("\t\t\t*****GAME OVER*****");
                exit(1);
            }
            else k=1;
        }
    }
    while (k==1);
}
/*τέλος της main*/


int elegxosSet() {                                                                  /*ορισμός της συνάρτησης elegxosSet τύπου int*/

int xrwma[3], sxima[3], arithmos[3], ifi[3], elegxos[4];                            /*ορισμός πινάκων ακεραίων*/

    printf("\n%s prepei na epilekseis 3 pithanes kartes gia Set!! \n", paiktes[energos].onoma);
    printf("\nDwse tis suntetagmenes x kai y twn kartwn sto plegma \n");
    for (i=0; i<3; i++) {                                                           /*ζητάει από τον ενεργό παίκτη να δώσει τις συντεταγμένες των καρτών που θεωρεί ότι είναι set */
        do {                                                                        /*για να αποφύγουμε τα πιθανά λάθη στον τρόπο εισαγωγής των συντεταγμένων, επέλεξα να τις  */
            k=0;                                                                    /*ζητάει για κάθε κάρτα ξεχωριστά και επείσης να ζητά ξεχωριστά το x και ξεχωριστά το y */
            z=i+1;
            printf("Dwse x%d gia tin %dh karta:\n", z, z);
            scanf(" %d", &x[i]);
            printf("Dwse y%d gia tin %dh karta:\n", z, z);
            scanf(" %d", &y[i]);
            if (x[i]<0 || x[i]>2 || y[i]<0 || y[i]>3) {                             /*ελέγχει αν οι δωθείσες συντεταγμένες είναι εντός ορίων*/
                printf("Oi times pou edwses einai ektos oriwn!! \n");
                k=1;
            }
            for (j=i; j>0; j--) {                                                   /*ελέγχει αν οι δηλωθείσες κάρτες είναι μοναδικές και δεν επαναλαμβάνεται κάποια/ες από αυτές*/
                if (x[i]==x[j-1] && y[i]==y[j-1]) {
                    printf("Den mporeis na dwseis tin idia karta duo fores!! \n");
                    k=1;
                }
            }
        }
        while (k==1);
    }

    /*εκτυπωνει τις συντεταγμενες x y των 3 καρτων και διπλα τις καρτες */
    printf("\nH epilogi sou einai: \n");
    printf("x \ty ");
    for (i=0; i<3; i++) {
        printf("\n%d \t%d ", x[i], y[i]);
        printf("\t%s", tablo[x[i]][y[i]].xrwma);
        printf("%s", tablo[x[i]][y[i]].sxima);
        printf("%s", tablo[x[i]][y[i]].arithmos);
        printf("%s", tablo[x[i]][y[i]].ifi);
    }
    /*Στην παρακάτω διαδικασία συγκρίνει με την strcmp τα αντίστοιχα πεδία των 3 καρτών που επέλεξε ο ενεργός παίκτης και το αποτέλεσμα της σύγκρισης
    αποθηκεύεται στις αντίστοιχες θέσεις των πινάκων xrwma, sxima, arithmos και ifi. Οι πίνακες αυτοί είναι πίνακες ακεραίων γιατί η strcmp, ανάλογα με
    το αποτέλεσμα της συγκρισης, επιστρέφει ακέραια τιμή (-1 για μικρότερο, 0 για ίδιο και 1 για μεγαλύτερο) */
    xrwma[0]=strcmp(tablo[x[0]][y[0]].xrwma, tablo[x[1]][y[1]].xrwma);
    sxima[0]=strcmp(tablo[x[0]][y[0]].sxima, tablo[x[1]][y[1]].sxima);
    arithmos[0]=strcmp(tablo[x[0]][y[0]].arithmos, tablo[x[1]][y[1]].arithmos);
    ifi[0]=strcmp(tablo[x[0]][y[0]].ifi, tablo[x[1]][y[1]].ifi);

    xrwma[1]=strcmp(tablo[x[0]][y[0]].xrwma, tablo[x[2]][y[2]].xrwma);
    sxima[1]=strcmp(tablo[x[0]][y[0]].sxima, tablo[x[2]][y[2]].sxima);
    arithmos[1]=strcmp(tablo[x[0]][y[0]].arithmos, tablo[x[2]][y[2]].arithmos);
    ifi[1]=strcmp(tablo[x[0]][y[0]].ifi, tablo[x[2]][y[2]].ifi);

    xrwma[2]=strcmp(tablo[x[1]][y[1]].xrwma, tablo[x[2]][y[2]].xrwma);
    sxima[2]=strcmp(tablo[x[1]][y[1]].sxima, tablo[x[2]][y[2]].sxima);
    arithmos[2]=strcmp(tablo[x[1]][y[1]].arithmos, tablo[x[2]][y[2]].arithmos);
    ifi[2]=strcmp(tablo[x[1]][y[1]].ifi, tablo[x[2]][y[2]].ifi);

    /*Αν και στις 3 καρτες το χρώμα είναι ίδιο ή και στις 3 είναι διαφορετικό τότε η θέση 0 του πίνακα elegxos παιρνει την τιμή "1", αλλιώς την τιμή "0"*/
    if (xrwma[0]==0 && xrwma[1]==0 && xrwma[2]==0) {
        elegxos[0]=1;
    }
    else if (xrwma[0]!=0 && xrwma[1]!=0 && xrwma[2]!=0) {
        elegxos[0]=1;
    }
    else {elegxos[0]=0;}

    /*Αν και στις 3 καρτες το σχήμα είναι ίδιο ή και στις 3 είναι διαφορετικό τότε η θέση 1 του πίνακα elegxos παιρνει την τιμή "1", αλλιώς την τιμή "0"*/
    if (sxima[0]==0 && sxima[1]==0 && sxima[2]==0) {
        elegxos[1]=1;
    }
    else if (sxima[0]!=0 && sxima[1]!=0 && sxima[2]!=0) {
        elegxos[1]=1;
    }
    else {elegxos[1]=0;}

    /*Αν και στις 3 καρτες ο αριθμός είναι ίδιος ή και στις 3 είναι διαφορετικός τότε η θέση 2 του πίνακα elegxos παιρνει την τιμή "1", αλλιώς την τιμή "0"*/
    if (arithmos[0]==0 && arithmos[1]==0 && arithmos[2]==0) {
        elegxos[2]=1;
    }
    else if (arithmos[0]!=0 && arithmos[1]!=0 && arithmos[2]!=0) {
        elegxos[2]=1;
    }
    else {elegxos[2]=0;}

    /*Αν και στις 3 καρτες η υφή είναι ίδια ή και στις 3 είναι διαφορετική τότε η θέση 3 του πίνακα elegxos παιρνει την τιμή "1", αλλιώς την τιμή "0"*/
    if (ifi[0]==0 && ifi[1]==0 && ifi[2]==0) {
        elegxos[3]=1;
    }
    else if (ifi[0]!=0 && ifi[1]!=0 && ifi[2]!=0) {
        elegxos[3]=1;
    }
    else {elegxos[3]=0;}

    /*Αν όλες οι θέσεις έχουν την τιμή 1 τότε έχουμε set (3άδα) και η μεταβλητή elenktis παίρνει την τιμή "1", διαφορετικά δεν έχουμε set και παίρνει την τιμή "0"*/
    if (elegxos[0]==1 && elegxos[1]==1 && elegxos[2]==1 && elegxos[3]==1) {
        elenktis=1;
        printf("\n\n***Bravo i triada pou epelekses einai Set*** \n");
    }
    else {
        elenktis=0;
        printf("\n\n***Lupame i triada pou epelekses den einai Set*** \n");
    }

return (elenktis);                                                              /*η συνάρτηση επιστρέφη την τιμή της elenktis στην main*/
}


int getNextCard() {                                                             /*ορισμός της συνάρτησης getNextCard τύπου int*/
    srand(time(NULL));                                                          /*καλεί τη συναρτηση srand για την αρχικοποίηση της συναρτησης rand*/
    do {
        for (i=0; i<12; i++) {                                                  /*επιλεγει 12 από τους 81 τυχαίους αριθμούς και τους καταχωρεί στον πίνακα tuxaioi*/
        tuxaioi[i]=rand()%81;
        }
        printf("\n");
        z=1;
        for (j=0; j<12; j++) {                                                  /*ελέγχει οτι οι 12 τυχαίοι αριθμοί δεν επαναλαμβανονται*/
            for (k=0; k<12; k++) {
                if (tuxaioi[k]==tuxaioi[j] && j!=k) {                           /*αν επαναλαμβάνεται καποιος αριθμός τοτε ο βρόγχος do-while επαναλαμβάνεται  */
                    z=0;                                                        /*μέχρι η δωδεκαδα να αποτελείται από μοναδικούς αριθμούς*/
                }
            }
        }
    }
    while (z==0);

return (tuxaioi[12]);                                                           /*η συναρτηση επιστρέφει στην main τον πινακα με τους 12 τυχαίους αριθμούς*/
}
