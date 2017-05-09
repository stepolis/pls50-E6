/*Στέλιος Πολυχρόνης ΑΜ 123603 Τμήμα ΘΕΣ-1*/
/*1η Γραπτή Εργασία - Θέμα 4ο*/
/* Σύστημα Καταγραφής Κρατημένων Θέσεων*/


#include <stdio.h>
#include <stdlib.h>

void main() {

    FILE *fin, *fout;
    char pinakida[7];
    int i, k, N, upo, arithm, epilogi, kenithesi, kratisi, theseis[53];
    int sunolokenwn, sunolokratimenwn, j, seires;
        for (i=0; i<53; i++) theseis[i]=0;

        fin=fopen("bus.txt", "r");
        fout=fopen("layout.txt", "w");
        if (fin==NULL|| fout==NULL) {
            printf("**ERROR sto anoigma tou arxeiou!** \n");
            exit(1);
        }
        else {
            printf("Sustima Katagrafis Thesewn Lewforeiou \n");
            printf("************************************* \n\n");
            fscanf(fin, " %s %d", &pinakida, &arithm);
            printf("Lewforeio me Pinakida Kukloforias: %s \n", pinakida);
            printf("Sunolikos Arithmos Thesewn: %d \n", arithm);
        }
        N=(arithm-5)/4;
        upo=(arithm-5)%4;
        if (arithm>53 || N<0 || upo!=0) {
            printf("**ERROR me ton arithmo twn thesewn tou lewforeiou** \n");
            exit(1);
        }
        do {
            printf("\n\n Lista Epilogwn: \n");
            printf(" --------------- \n\n");
            printf(" 1. Emfanisi Kenwn Thesewn \n");
            printf(" 2. Kratisi Sugkekrimenis Thesis \n");
            printf(" 3. Kratisi Kenis Thesis se Parathuro \n");
            printf(" 4. Akurwsi Kratisis Thesis \n");
            printf(" 5. Anazitisi Kratimenis Thesis \n");
            printf(" 6. Emfanisi Kratimenwn Thesewn \n");
            printf(" 7. Diagramma Thesewn Lewforeiou \n");
            printf(" 8. Apothikeusi Diagrammatos se Arxeio \n");
            printf(" 0. Exodos \n\n");
            printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n");
            scanf(" %d", &epilogi);

            if (epilogi==1) {
                for (sunolokenwn=0,i=0; i<53; i++) {
                    if (theseis[i]==0) {
                        sunolokenwn++;
                    }
                }
                printf("\nTo Sunolo twn Kenwn Thesewn einai: %d\n", sunolokenwn);
                printf("Kenes einai oi theseis me arithmo: \n");
                for (i=0; i<53; i++) {
                    if (theseis[i]==0) {
                        kenithesi=i+1;
                        printf("%d. \t", kenithesi);
                    }
                }
            }
            else if (epilogi==2){
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis: \n");
                    scanf(" %d", &kratisi);
                    if (kratisi<1 || kratisi>arithm) {
                        printf("H thesi pou epelekses einai ektos oriwn! \n");
                        k=1;                                                            /*Η k είναι μεταβλητή ελέγχου του βρόγχου do-while*/
                    }
                    if (theseis[kratisi-1]==1) {
                        printf("H thesi pou epelekses den einai keni! \n");
                        k=1;
                    }
                    else if (theseis[kratisi-1]==0) {
                        theseis[kratisi-1]=1;
                        printf("Egine kratisi tis thesis: %d \n", kratisi);
                        k=0;
                    }
                }
                while (k==1);
            }
            else if (epilogi==3) {
                for (i=0; i<53; i++)
                {
                    if (i%4==0 && theseis[i]==0)
                    {
                        kenithesi=i+1;
                        theseis[i]=1;
                        printf("Egine kratisi tis thesis: %d \n", kenithesi);
                        break;
                    }
                    else if ((i-3)%4==0 && i!=51 && theseis[i]==0)
                    {
                        kenithesi=i+1;
                        theseis[i]=1;
                        printf("Egine kratisi tis thesis: %d \n", kenithesi);
                        break;
                    }
                    else if (i==48 && theseis[i]==0)
                    {
                        kenithesi=49;
                        theseis[i]=1;
                        printf("Egine kratisi tis thesis: %d \n", kenithesi);
                    }
                    else if (i==52 && theseis[i]==0)
                    {
                        kenithesi=53;
                        theseis[i]=1;
                        printf("Egine kratisi tis thesis: %d \n", kenithesi);
                    }
                    else if (i==52 && theseis[i]==1)
                    {
                        printf("Den yparxei keni thesi se parathuro! \n");
                    }
                }
            }
            else if (epilogi==4) {
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis na akurwseis: \n");
                    scanf(" %d", &kratisi);
                    if (kratisi<1 || kratisi>arithm) {
                        printf("H thesi pou epelekses einai ektos oriwn! \n");
                        k=1;                                                            /*Η k είναι μεταβλητή ελέγχου του βρόγχου do-while*/
                    }
                    if (theseis[kratisi-1]==0) {
                        printf("H thesi pou epelekses einai idi keni! \n");
                        k=1;
                    }
                    else if (theseis[kratisi-1]==1) {
                        theseis[kratisi-1]=0;
                        printf("Egine akurwsi kratisis tis thesis: %d \n", kratisi);
                        k=0;
                    }
                }
                while (k==1);
            }
            else if (epilogi==5) {
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis na tsekareis: \n");
                    scanf(" %d", &kratisi);
                    if (kratisi<1 || kratisi>arithm) {
                        printf("H thesi pou epelekses einai ektos oriwn! \n");
                        k=1;                                                            /*Η k είναι μεταβλητή ελέγχου του βρόγχου do-while*/
                    }
                    if (theseis[kratisi-1]==0) {
                        printf("H thesi pou epelekses einai keni! \n");
                        k=0;
                    }
                    else if (theseis[kratisi-1]==1) {
                        printf("H thesi pou epelekses einai kratimeni! \n", kratisi);
                        k=0;
                    }
                }
                while (k==1);
            }
            else if (epilogi==6) {
                for (sunolokratimenwn=0,i=0; i<53; i++) {
                    if (theseis[i]==1) {
                        sunolokratimenwn++;
                    }
                }
                printf("\nTo Sunolo twn Kratimenwn Thesewn einai: %d\n", sunolokratimenwn);
                printf("Kratimenes einai oi theseis me arithmo: \n");
                for (i=0; i<53; i++) {
                    if (theseis[i]==1) {
                        kratisi=i+1;
                        printf("%d. \t", kratisi);
                    }
                }
            }
            else if (epilogi==7) {
                printf("\n%s \n", pinakida);
                seires=(arithm-5)/4;
                for (i=0; i<seires; i++) {
                    for (j=0; j<2; j++) {
                        if (theseis[(i*4+j)]==0) printf("_");
                        else if (theseis[(i*4+j)]==1) printf("*");
                    }
                    printf(" ");
                    for (j=2; j<4; j++) {
                        if (theseis[(i*4+j)]==0) printf("_");
                        else if (theseis[(i*4+j)]==1) printf("*");
                    }
                printf(" \n");
                }
                for (j=0; j<5; j++) {
                    if (theseis[(seires*4+j)]==0) printf("_");
                    else if (theseis[(seires*4+j)]==1) printf("*");
                }
                printf(" \n");
            }
            else if (epilogi==8) {
                fprintf(fout, "\n%s \n", pinakida);
                seires=(arithm-5)/4;
                for (i=0; i<seires; i++) {
                    for (j=0; j<2; j++) {
                        if (theseis[(i*4+j)]==0) fprintf(fout, "_");
                        else if (theseis[(i*4+j)]==1) fprintf(fout, "*");
                    }
                    fprintf(fout, " ");
                    for (j=2; j<4; j++) {
                        if (theseis[(i*4+j)]==0) fprintf(fout, "_");
                        else if (theseis[(i*4+j)]==1) fprintf(fout, "*");
                    }
                fprintf(fout, " \n");
                }
                for (j=0; j<5; j++) {
                    if (theseis[(seires*4+j)]==0) fprintf(fout, "_");
                    else if (theseis[(seires*4+j)]==1) fprintf(fout, "*");
                }
                fprintf(fout, " \n");
                printf("To diagramma apothikeutike se arxeio! \n");
            }
            else if (epilogi==0) {
                fclose(fin);
                fclose(fout);
                printf("Exodos Programmatos \n");
            }
            else if (epilogi!=0 || epilogi!=1 || epilogi!=2 || epilogi!=3 || epilogi!=4 || epilogi!=5 || epilogi!=6 || epilogi!=7 || epilogi!=8) {
                printf("H epilogi sou den einai egkuri!! \n");
            }
        }
        while (epilogi!=0);

    return 0;
}
