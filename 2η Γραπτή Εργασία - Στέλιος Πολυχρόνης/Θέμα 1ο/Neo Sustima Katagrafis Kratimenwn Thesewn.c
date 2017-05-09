/*������� ���������� �� 123603 ����� ���-1*/
/*2� ������ ������� - ���� 1�*/
/*��� ������� ���������� ���������� ������*/

#include <stdio.h>
#include <stdlib.h>

FILE *fin, *fout;                                                           /*������� ������� ������� ��� ������*/
char onoma[20], epitheto[40], til[11], pinakida[8];                         /*������� ������� ����������*/
int num[10];                                                                /*������� ������ ��������*/
int i, n, m, k, N, upo, kratisi, epilogi, epilogi2, arithm;                 /*������� �������� ����������*/
int sunolokenwn, sunolokratimenwn, j, z, a, b, c, seires;                   /*������� �������� ����������*/

struct epivatis {                                                           /*������� struct epivatis �� �����:  */
    char onomateponimo[40];                                                 /*���� ������ ���������� 40 ������ ��� �� �������������*/
    unsigned short tilefono[10];                                            /*���� ������ unsigned short 10 ������ ��� �� ��������*/
    unsigned int arithmosthesis;                                            /*��� ��������� unsigned int ��� ��� ������ ����� ��� �������*/
} theseis[53];                                                              /*������� ���� ������ 53 ������ ����� struct epivatis*/

/*��������� ����������� ��� �������� ��� ���������*/
void anoigma();
void plithoskenwn();
int kratisithesis(int x);
int anazitisithesis(int y);
int akurwsithesis(int l);
void lista();
void kleisimo();

/*���� ��� main*/
void main()
{
    for (i=0; i<53; i++) {                                                  /*������������ ��� ������ ������ �� ��� ���� ��������� ��� ��   */
        strcpy (theseis[i].onomateponimo, "\0");                            /*������������� ��� �� �������� ��� ������������ ���� ����� ��� */
        theseis[i].tilefono[0]=0;                                           /*������ �� ��� ������ ��� ����������� ����� ��� ����������*/
        theseis[i].arithmosthesis=i+1;
    }

    anoigma();                                                              /*����� ��� ��������� anoigma*/

    do {                                                                    /*������� ������� do-while ��� ������������ ��� ���������� ����� �� �������� � ������� 0.Exodos*/
            printf("\n\n Lista Epilogwn: \n");                              /*����� �������� ��� ��� ������*/
            printf(" --------------- \n\n");
            printf(" 1. Emfanisi Kenwn Thesewn \n");
            printf(" 2. Kratisi Sugkekrimenis Thesis \n");
            printf(" 3. Anazitisi Kratimenis Thesis \n");
            printf(" 4. Akurwsi Kratisis Thesis \n");
            printf(" 5. Lista Kratimenwn Thesewn \n");
            printf(" 0. Exodos \n\n");
            printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n"); /*������ ��� ������� ��� ������*/
            scanf(" %d", &epilogi);                                         /*�������� ��� �������*/
            printf("\n");

            if (epilogi==1) {                                               /*�� � ������� ����� 1*/
                plithoskenwn();                                             /*����� ��� ��������� plithoskenwn*/
            }
            else if (epilogi==2){                                           /*�� � ������� ����� 2*/
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis na kratiseis: \n");     /*������ ��� ������ ��� ����� ��� �������*/
                    scanf(" %d", &kratisi);                                 /*�������� ��� ������ ����� ��� ����� � �������*/
                    kratisithesis(kratisi);                                 /*����� ��� ��������� kratisithesis ����������� ��� ��� ���� ��� kratisi*/
                }
                while (a==1);                                               /*� ������� do-while ���������� ��� � ��������� kratisithesis ���������� ��� ���� a=1*/
            }
            else if (epilogi==3) {                                          /*�� � ������� ����� 3*/
                do {
                    printf("\n\nH Anazitisi Kratimenis Thesis, Theleis na ginei me vasi: \n\n");    /*������ ��� ��� ������ �� �������� �� � ��������� �� �����:  */
                    printf("1) to onomateponimo tou epivati? \n");                                  /*�� ���� �� ������������� � �� ��������  */
                    printf("2) to tilefono tou epivati? \n\n");
                    printf("Dwse ton arithmo pou antistoixei stin epilogi sou \n");
                    scanf(" %d", &epilogi2);                                /*�������� ��� ������� ��� ������*/
                    anazitisithesis(epilogi2);                              /*����� ��� ��������� anazitisithesis ����������� ��� ��� ���� ��� epilogi2*/
                }
                while (b==1);                                               /*� ������� do-while ���������� ��� � ��������� anazitisithesis ���������� ��� ���� b=1*/
            }
            else if (epilogi==4){                                           /*�� � ������� ����� 4*/
                do {
                    printf("Epilekse ton arithmo tis thesis pou theleis na akurwseis: \n");     /*������ ��� ������ ��� ����� ��� �������*/
                    scanf(" %d", &kratisi);                                 /*�������� ��� ������ ����� ��� ����� � �������*/
                    akurwsithesis(kratisi);                                 /*����� ��� ��������� akurwsithesis ����������� ��� ��� ���� ��� kratisi*/
                }
                while (c==1);                                               /*� ������� do-while ���������� ��� � ��������� akurwsithesis ���������� ��� ���� c=1*/
            }
            else if (epilogi==5) {                                          /*�� � ������� ����� 5*/
                lista();                                                    /*����� ��� ��������� lista*/
            }
            else if (epilogi==0) {                                          /*�� � ������� ����� 0*/
                kleisimo();                                                 /*����� ��� ��������� kleisimo*/
            }
            else if (epilogi!=0 || epilogi!=1 || epilogi!=2 || epilogi!=3 || epilogi!=4 || epilogi!=5) {
                printf("H epilogi sou den einai egkuri!! \n");
            }
    }
    while (epilogi!=0);
}


void anoigma() {                                                            /*������� ��� ���������� anoigma ����� void*/
    fin=fopen("bus.txt", "r");                                              /*������� �� ������ ������� bus.txt ��� ��������*/
    if (fin==NULL) {                                                        /*������� �� ������� ����� ��� ������� ��� �������*/
        printf("**ERROR sto anoigma tou arxeiou!** \n");
        exit(1);
    }
    else {
        printf("Neo Sustima Katagrafis Thesewn Lewforeiou \n");
        printf("***************************************** \n\n");
        fscanf(fin, " %s %d", pinakida, &arithm);                           /*�������� ��� �� ������ ��� �������� ��� ��� ������ ������ ��� ���������� ��� �� ������� ���� �����*/
        printf("Lewforeio me Pinakida Kukloforias: %s \n", pinakida);
        printf("Sunolikos Arithmos Thesewn: %d \n", arithm);

    }
    N=(arithm-5)/4;
    upo=(arithm-5)%4;
    if (arithm>53 || N<0 || upo!=0) {                                       /*������� �� � ������� ������ ����� ����������*/
        printf("**ERROR me ton arithmo twn thesewn tou lewforeiou** \n");
        exit(1);
    }
    while (!feof(fin)) {                                                    /*������� �� ������ ������� ����� �� ����� ��� ���:   */
        epitheto[0]='\0';
        onoma[0]='\0';
        til[0]='\0';
        fscanf(fin, " %s %s %d %s", epitheto, onoma, &n, til);              /*�������� ��� �� ������ �� �������, �� �����, ��� ������ ����� ��� �� �������� ��� �������*/
        strcat(epitheto, " ");                                              /*���� �� ������� ��������� �� ����*/
        strcat(epitheto, onoma);                                            /*���� �� ������� ��� �� ���� ��������� �� �����*/
        strcpy(theseis[n-1].onomateponimo, epitheto);                       /*���������� ��� �� ����� ��� ����� ������������� ��� ������ theseis, ��� ���� ��� ������ ��� ����������� ��� ���� ��� �������*/
        m=0;
        for (i=0; til[i]>='0' && til[i]<='9'; i++) {                        /*���������� ����-���� ���� ���������� ��� ������ ���������� til �� ��������� ��� �� ��������� ��� ����� tilefono ��� struct*/
            m=(til[i]-'0');
            theseis[n-1].tilefono[i]=m;                                     /*���������� �� �������� ��� ����� �������� ��� ������ theseis, ��� ���� ��� ������ ��� ����������� ��� ���� ��� �������*/
        }
    }
    fclose(fin);                                                            /*������� �� ������ �������*/
}


void plithoskenwn() {                                                       /*������� ��� ���������� plithoskenwn ����� void*/
    for (sunolokenwn=0,i=0; i<arithm; i++) {
        if (theseis[i].onomateponimo[0]=='\0') {                            /*������� �� ������ ��� ����� ������*/
            sunolokenwn++;
        }
    }
    printf("\nTo Sunolo twn Kenwn Thesewn einai: %d\n", sunolokenwn);
    printf("Kenes einai oi theseis me arithmo: \n");
    for (i=0; i<arithm; i++) {                                              /*������� ��������� ���� �������� ��� ����� ������*/
        if (theseis[i].onomateponimo[0]=='\0')
            printf("%d. \t", theseis[i].arithmosthesis);
    }
}


int kratisithesis(int x) {                                                  /*������� ��� ���������� kratisithesis ����� int �� ��� ��������� x ����� int*/
    if (x<1 || x>arithm) {                                                  /*������� �� � ������� ����� ��� ����� � ������� ����� ����� �����*/
        printf("H thesi pou epelekses einai ektos oriwn! \n");
        a=1;                                                                /*���������� ���� main ��� ���� a=1*/
    }
    else if (0<x<=arithm && theseis[x-1].onomateponimo[0]!='\0') {          /*������� �� � ���� ��� ����� � ������� ����� ����*/
        printf("H thesi pou epelekses den einai keni! \n");
        a=1;                                                                /*���������� ���� main ��� ���� a=1*/
    }
    else if (0<x<=arithm && theseis[x-1].onomateponimo[0]=='\0') {
        printf("Dwse to Epitheto tou Epivati: \n");                         /*������ ��� ��� ������ �� ������� ��� �������*/
        scanf(" %s", epitheto);
        printf("Dwse to Onoma tou Epivati: \n");                            /*������ �� ����� ��� �������*/
        scanf(" %s", onoma);
        printf("Dwse to Tilefono tou Epivati: \n");                         /*������ �� �������� ��� �������*/
        scanf(" %s", til);
        strcat(epitheto, " ");                                              /*���� �� ������� ��������� �� ����*/
        strcat(epitheto, onoma);                                            /*��� ���� �� ������� ��� �� ���� ��������� �� �����*/
        strcpy(theseis[x-1].onomateponimo, epitheto);                       /*���������� �� ������������� ��� ������� ��� ����� ������������� ��� ������ ������, ���� ���������� ���� ��� ������� � �������*/
        m=0;
        for (i=0; til[i]>='0' && til[i]<='9'; i++) {                        /*���������� ����-���� ���� ���������� ��� ������ ���������� til �� ��������� ��� �� ��������� ��� ����� tilefono ��� struct*/
            m=(til[i]-'0');
            theseis[x-1].tilefono[i]=m;                                     /*���������� �� �������� ��� ������� ��� ����� �������� ��� ������ ������, ���� ���������� ���� ��� ������� � �������*/
        }
        printf("\nEgine kratisi tis thesis %d sto omomateponimo %s!! \n", x, epitheto);
        a=0;                                                                /*���������� ���� main ��� ���� a=0 ��� ���������� ��� ������*/
    }
return (a);
}


int anazitisithesis(int y) {                                                /*������� ��� ���������� anazitisithesis ����� int �� ��� ��������� y ����� int*/
    if (y!=1 && y!=2) {                                                     /*������� �� � ������� ��� ������ ����� ������*/
        printf("H epilogi sou den einai egkuri!! \n");
        b=1;                                                                /*���������� ���� main ��� ���� b=1*/
    }
    if (y==1) {                                                             /*�� � ������� ����� 1 � ��������� ������� �� ���� �� �������������*/
        printf("Dwse to Epitheto tou Epivati: \n");                         /*������ �� ������� ��� ���� �� �����*/
        scanf(" %s", epitheto);
        printf("Dwse to Onoma tou Epivati: \n");
        scanf(" %s", onoma);
        strcat(epitheto, " ");
        strcat(epitheto, onoma);
        z=0;
        for (i=0; i<arithm; i++) {                                          /*� ��������� ������� �� ���� ��� ������ ��� ������*/
            j=strcmp(epitheto, theseis[i].onomateponimo);                   /*� ��������� j ������� ��� ���� 0 �� �� ��� ������������� ��� ������������ ����� �����*/
            if (j==0) {
                printf("Sto onomateponimo %s exei kratithei i thesi %d \n", epitheto, i+1);
                z++;                                                        /*� ��������� z ������� ����� ������ ����� ���������� ��� ���� �������������*/
            }
        }
        if (j!=0 && z==0) printf("Oxi den uparxei kratisi sto onomateponimo %s \n", epitheto);
        b=0;                                                                /*���������� ���� main ��� ���� b=0 ��� ���������� ��� ������*/
        }
    else if (y==2) {                                                        /*�� � ������� ����� 2 � ��������� ������� �� ���� �� ��������*/
        printf("Dwse to Tilefono tou Epivati: \n");                         /*������ �� ��������*/
        scanf(" %s", til);
        z=0;
        for (i=0; i<arithm; i++) {                                          /*� ��������� ������� �� ���� ��� ������ ��� ������*/
            m=0;
            for (j=0; til[j]>='0' && til[j]<='9'; j++) {                    /*���������� ����-���� ���� ���������� ��� ������ ���������� til �� ��������� ��� ���� ����� ���� ������ num*/
                m=(til[j]-'0');
                num[j]=m;
            }
            /*����������� ��� �� �������� ��� ������ num �� �� ���������� ��� ������ tilefono ��� struct*/
            if (theseis[i].tilefono[0]==num[0] && theseis[i].tilefono[1]==num[1] && theseis[i].tilefono[2]==num[2] && theseis[i].tilefono[3]==num[3] && theseis[i].tilefono[4]==num[4] && theseis[i].tilefono[5]==num[5] && theseis[i].tilefono[6]==num[6] && theseis[i].tilefono[7]==num[7] && theseis[i].tilefono[8]==num[8] && theseis[i].tilefono[9]==num[9]) {
                printf("Sto tilefono %s exei kratithei i thesi %d \n", til, i+1);
                z++;                                                        /*� ��������� z ������� ����� ������ ����� ���������� ��� ���� ��������*/
            }
        }
        if (z==0) {
            printf("Oxi den uparxei kratisi sto tilefono %s \n", til);
        }
        b=0;                                                                /*���������� ���� main ��� ���� b=0 ��� ���������� ��� ������*/
    }
return (b);
}


int akurwsithesis(int l) {                                                  /*������� ��� ���������� akurwsithesis ����� int �� ��� ��������� l ����� int*/
    if (l<1 || l>arithm) {                                                  /*������� �� � ���� ��� ����� � ������� ����� ����� �����*/
        printf("H thesi pou epelekses einai ektos oriwn! \n");
        c=1;                                                                /*���������� ���� main ��� ���� c=1*/
    }
    else if (0<l<=arithm && theseis[l-1].onomateponimo[0]=='\0') {          /*������� �� � ���� ����� ��� ����*/
        printf("H thesi pou epelekses einai idi keni! \n");
        c=1;                                                                /*���������� ���� main ��� ���� c=1*/
    }
    else if (0<l<=arithm && theseis[l-1].onomateponimo[0]!='\0') {          /*����� ��� �������*/
        strcpy(theseis[l-1].onomateponimo, "\0");
        theseis[l-1].tilefono[0]=0;
        printf("\nEgine akurwsi kratisis tis thesis %d!! \n", l);
        c=0;                                                                /*���������� ���� main ��� ���� c=0 ��� ���������� ��� ������*/
    }
return (c);
}


void lista() {                                                              /*������� ��� ���������� lista ����� void*/
    printf("H lista kratisewn einai: \n");
    for (i=0; i<arithm; i++) {
        if (theseis[i].onomateponimo[0]!='\0') {                            /*��������� �� ����� ��������� ��� ����� ��� ������������ ���� ������ �����*/
            printf("%d. \t", theseis[i].arithmosthesis);
            printf("%s \t", theseis[i].onomateponimo);
            for (j=0; j<10; j++) {
                printf("%d", theseis[i].tilefono[j]);
            }
            printf("\n");
        }
    }
}


void kleisimo() {                                                           /*������� ��� ���������� kleisimo ����� void*/
    fout=fopen("bus.txt", "w");
    if (fout==NULL) {                                                       /*������� �� ������� �������� �� �� ������� ��� ������� ������*/
        printf("**ERROR sto anoigma tou arxeiou!** \n");
        exit(1);
    }
    fprintf(fout, "%s %d", pinakida, arithm);                               /*�������� ��� ������ ������ ��� �������� ��� ��� ������ ��� ������*/
    for (i=0; i<arithm; i++) {
        if (theseis[i].onomateponimo[0]!='\0') {                            /*�������� ��� ������ ������ ��� ����� ��������� �� ����:  */
            fprintf(fout, "\n%s ", theseis[i].onomateponimo);               /*������������� "����"  */
            fprintf(fout, "%d ", theseis[i].arithmosthesis);                /*������ ����� "����"   */
            for (j=0; j<10; j++) {
                fprintf(fout, "%d", theseis[i].tilefono[j]);                /*��� ��������*/
            }
        }
    }
    fclose(fout);                                                           /*������� �� ������ ������*/
    printf("Egine apothikeusi twn kratisewn se arxeio \n");                 /*��������� ��������� ������ ���� ��� �����*/
    printf("Exodos Programmatos \n");
}
