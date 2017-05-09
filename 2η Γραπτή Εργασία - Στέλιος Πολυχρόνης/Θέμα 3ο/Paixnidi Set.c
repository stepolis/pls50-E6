/*������� ���������� �� 123603 ����� ���-1*/
/*2� ������ ������� - ���� 3�*/
/*��������� ���������� ���������� Set*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i, j, k, l, z, energos, elenktis;                                           /*������� �������� ����������*/
int x[3], y[3], tuxaioi[12];                                                    /*������� ������� ��������*/
char id;                                                                        /*������� ���������� ���������*/


struct karta {                                                                  /*������� struct karta �� �������� 4 �������������� ������� ����������*/
        char xrwma[4], sxima[3], arithmos[3], ifi[3];
    } kartes[82], tablo[3][4];                                                  /*������� ���� ������������� ������ kartes ��� ���� ����������� ������ tablo ����� struct karta*/

struct paiktis {                                                                /*������� struct paiktis �� ��������:  */
        char onoma[18];                                                         /*���� ������ ���������� ��� �� ����� ��� ������,*/
        unsigned int bathmologia;                                               /*��� ������� ��������� ��� ��� ���������� ��� */
        char xaraktiras;                                                        /*���� ��������� ��� �� id ��� ���� ������*/
    } paiktes[3];                                                               /*������� ���� ������ 3 ������ ����� struct paiktis ��� ���� 3 �������*/

/*��������� ��� ����������� ��� �� �������� ��������*/
int elegxosSet();
int getNextCard();

/*���� ��� main*/
void main()
{
    strcpy (paiktes[0].onoma, "Marina Andreou");                                /*���������� �� ������� ��� 3 ������� ��� ����� onoma ��� ���� ���������� ���� ��� ������ paiktes*/
    strcpy (paiktes[1].onoma, "Kostas Grammenos");
    strcpy (paiktes[2].onoma, "Maria Perdika");
    paiktes[0].xaraktiras='a';                                                  /*���������� �� id ��� 3 ������� ��� ����� xaraktiras ��� ���� ���������� ���� ��� ������ paiktes*/
    paiktes[1].xaraktiras='g';
    paiktes[2].xaraktiras='p';
    for (i=0; i<3; i++) {                                                       /*����������� ��� ���������� ��� 3 �������*/
        paiktes[i].bathmologia=0;
    }
    /*�� ��� �������� ���������� ���������� ��� 81 ������ ��� ������������ ����� 81 �������� ����������� ��� ����  */
    /*������������ ���� 81 ����������� ������ ��� ������ kartes. ����������������� ��� ���� ���������� "[" "]" ��� ","*/
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

    /* ��������� ��� ��� 81 ������ ��� �� �������� �� ��� ��������� �� ���������*/
    /*
    for (l=0; l<81; l++) {
        printf("%s", kartes[l].xrwma);
        printf("%s", kartes[l].sxima);
        printf("%s", kartes[l].arithmos);
        printf("%s \t", kartes[l].ifi);
    }
    */

    getNextCard();                                                                  /*����� ��� ��������� getNextCard ��� ���������� ��� ������ tuxaioi �� 12 �������� ��������*/

    do {                                                                            /*������� ������� do-while ��� ������������, ��� ���������������� ��� k=1*/
        printf("Oi 12 tuxaies kartes einai: \n");
        printf("--------------------------- \n\n");
        for (i=0; i<3; i++) {                                                       /*��� �������� �� ���� ���� 12 �������� �������� ��� ��������� � getNextCard ���������  */
            for (j=0; j<4; j++) {                                                   /*�� �������� ��� ������ ��� ����������� (�� ���� 12 ��������) ������ ��� ���������� �����  */
                k=tuxaioi[4*i+j];                                                   /*��� ����������� ������ tablo*/
                strcpy(tablo[i][j].xrwma, kartes[k].xrwma);
                strcpy(tablo[i][j].sxima, kartes[k].sxima);
                strcpy(tablo[i][j].arithmos, kartes[k].arithmos);
                strcpy(tablo[i][j].ifi, kartes[k].ifi);
                printf("\t%s", tablo[i][j].xrwma);                                  /*����� ��������� ���� ����� ����� ��� ������ ��� ����� ����������� ���� ������ tablo, ���  */
                printf("%s", tablo[i][j].sxima);                                    /*����� ��� �� ������ (��������) �� ��� ������ ������ �� ��������*/
                printf("%s", tablo[i][j].arithmos);
                printf("%s", tablo[i][j].ifi);
            }
            printf("\n\n");
        }
        for (i=0; i<3; i++) {                                                       /*���� ��� �� ������ �� ��� 12 ������ ��������� �� �������� ��� ������� (id, ������� ��� �����)*/
            printf("\tId: %c \tBathmoi: %d \tOnoma: %s \n", paiktes[i].xaraktiras, paiktes[i].bathmologia, paiktes[i].onoma);
        }
        printf("\nDwse to **id** tou paikti pou paizei, alliws dwse **0** gia exodo!! \n");     /*������ �� id ��� ������ ��� ����� �� ������/����� ������� � "0" ��� �����*/
        scanf(" %c", &id);
        if (id=='0') {                                                              /*�� � ������� ��� ������ ����� "0" ��������� ��� ������ ���������� ��� ���������� �� ���������*/
            printf("***Epelekses Exodo!!!***\n\n");
            printf("H teliki bathmologia einai: \n");
            printf("--------------------------- \n");
            for (i=0; i<3; i++) {
                printf("Onoma: %16s \tBathmoi: %d \n", paiktes[i].onoma, paiktes[i].bathmologia);
            }
            exit(1);
        }
        if (id!='0' && id!='a' && id!='g' && id!='p') {                             /*�� � ������� ��� ������ ����� ������� ��� "0" ��� ��� id ��� 3 ������� ���� ����� ��� ���������  */
            printf("**To id pou edwses den uparxei** \n");                          /*getNextCard ��� ������������� ��� ������ ��� ��� ���� ���� �� ��������� ��������� 12�� ������ ��� */
            printf("**Allagi tou tablo me tis kartes** \n\n");                      /*���� �� ���� ������� ��� id � ����� */
            getNextCard();
            k=1;
            continue;
        }

        for (i=0; i<3; i++) {                                                       /*������� �� ��� ������� ��� id ��������� ��� ������ ������*/
            if (paiktes[i].xaraktiras==id) {
                energos=i;
                printf("\nEnergos einai o paiktis: *** %s *** \n", paiktes[energos].onoma);
            }
        }
        elegxosSet();                                                               /*����� ��� ��������� elegxosSet ��� ���������� ��� ���� ��� ���������� elenktis*/

        if (elenktis==1) {                                                          /*�� � ��������� elenktis ���������� �� ��� ���� 1, ������ ������ set, ����:   */
            paiktes[energos].bathmologia=paiktes[energos].bathmologia+2;            /*� ���������� ��� ������� ������ ��������� ���� 2 ������� ��� ����������� ���� �����*/
            printf("Prostethikan +2 bathmoi ston paikth: %s !!!\n", paiktes[energos].onoma);
            printf("Sunolo Bathmwn tou paikti %s einai: %d\n\n\n",paiktes[energos].onoma, paiktes[energos].bathmologia);
            k=1;
            getNextCard();                                                          /*����� ��� getNextCard ��� �� ������ ��� 12��� ������ ��� ������� � ���� ���������� ��� ��� ����*/
        }
        else if (elenktis==0) {                                                     /*�� � ��������� elenktis ���������� �� ��� ���� 0, ������ ��� ������ set,*/
            if (paiktes[energos].bathmologia>0) {                                   /*��� � ���������� ��� ������� ������ ����� ���������� ��� 0, ���� ��������� ���� 1 ������ ��� ����������� ���� �����*/
                paiktes[energos].bathmologia=paiktes[energos].bathmologia-1;
                printf("Afairethike -1 bathmos apo ton paikti: %s !!!\n", paiktes[energos].onoma);
                printf("Sunolo Bathmwn tou paikti %s: %d\n\n\n",paiktes[energos].onoma, paiktes[energos].bathmologia);
                k=1;
            }
            else {                                                                  /*�� ���� � ���������� ��� ����� ��� 0, ���� ��� ����������� ������*/
                printf("H bathmologia tou paikti %s einai: %d\n\n\n", paiktes[energos].onoma, paiktes[energos].bathmologia);
                k=1;
            }
        }                                                                           /*�� ���� ��� ��������� �� 12��� ��� ������ ��������� � ����*/

        for (i=0; i<3; i++) {                                                       /*��� ����� ���� ����������� ������� �� ������� ������� ���� ���������� ���������� � ��� �� 10 ��� ��� ���������� ������*/
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
/*����� ��� main*/


int elegxosSet() {                                                                  /*������� ��� ���������� elegxosSet ����� int*/

int xrwma[3], sxima[3], arithmos[3], ifi[3], elegxos[4];                            /*������� ������� ��������*/

    printf("\n%s prepei na epilekseis 3 pithanes kartes gia Set!! \n", paiktes[energos].onoma);
    printf("\nDwse tis suntetagmenes x kai y twn kartwn sto plegma \n");
    for (i=0; i<3; i++) {                                                           /*������ ��� ��� ������ ������ �� ����� ��� ������������� ��� ������ ��� ������ ��� ����� set */
        do {                                                                        /*��� �� ���������� �� ������ ���� ���� ����� ��������� ��� �������������, ������� �� ���  */
            k=0;                                                                    /*������ ��� ���� ����� ��������� ��� ������� �� ���� ��������� �� x ��� ��������� �� y */
            z=i+1;
            printf("Dwse x%d gia tin %dh karta:\n", z, z);
            scanf(" %d", &x[i]);
            printf("Dwse y%d gia tin %dh karta:\n", z, z);
            scanf(" %d", &y[i]);
            if (x[i]<0 || x[i]>2 || y[i]<0 || y[i]>3) {                             /*������� �� �� �������� ������������� ����� ����� �����*/
                printf("Oi times pou edwses einai ektos oriwn!! \n");
                k=1;
            }
            for (j=i; j>0; j--) {                                                   /*������� �� �� ���������� ������ ����� ��������� ��� ��� ��������������� ������/�� ��� �����*/
                if (x[i]==x[j-1] && y[i]==y[j-1]) {
                    printf("Den mporeis na dwseis tin idia karta duo fores!! \n");
                    k=1;
                }
            }
        }
        while (k==1);
    }

    /*��������� ��� ������������� x y ��� 3 ������ ��� ����� ��� ������ */
    printf("\nH epilogi sou einai: \n");
    printf("x \ty ");
    for (i=0; i<3; i++) {
        printf("\n%d \t%d ", x[i], y[i]);
        printf("\t%s", tablo[x[i]][y[i]].xrwma);
        printf("%s", tablo[x[i]][y[i]].sxima);
        printf("%s", tablo[x[i]][y[i]].arithmos);
        printf("%s", tablo[x[i]][y[i]].ifi);
    }
    /*���� �������� ���������� ��������� �� ��� strcmp �� ���������� ����� ��� 3 ������ ��� ������� � ������� ������� ��� �� ���������� ��� ���������
    ������������ ���� ����������� ������ ��� ������� xrwma, sxima, arithmos ��� ifi. �� ������� ����� ����� ������� �������� ����� � strcmp, ������� ��
    �� ���������� ��� ���������, ���������� ������� ���� (-1 ��� ���������, 0 ��� ���� ��� 1 ��� ����������) */
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

    /*�� ��� ���� 3 ������ �� ����� ����� ���� � ��� ���� 3 ����� ����������� ���� � ���� 0 ��� ������ elegxos ������� ��� ���� "1", ������ ��� ���� "0"*/
    if (xrwma[0]==0 && xrwma[1]==0 && xrwma[2]==0) {
        elegxos[0]=1;
    }
    else if (xrwma[0]!=0 && xrwma[1]!=0 && xrwma[2]!=0) {
        elegxos[0]=1;
    }
    else {elegxos[0]=0;}

    /*�� ��� ���� 3 ������ �� ����� ����� ���� � ��� ���� 3 ����� ����������� ���� � ���� 1 ��� ������ elegxos ������� ��� ���� "1", ������ ��� ���� "0"*/
    if (sxima[0]==0 && sxima[1]==0 && sxima[2]==0) {
        elegxos[1]=1;
    }
    else if (sxima[0]!=0 && sxima[1]!=0 && sxima[2]!=0) {
        elegxos[1]=1;
    }
    else {elegxos[1]=0;}

    /*�� ��� ���� 3 ������ � ������� ����� ����� � ��� ���� 3 ����� ������������ ���� � ���� 2 ��� ������ elegxos ������� ��� ���� "1", ������ ��� ���� "0"*/
    if (arithmos[0]==0 && arithmos[1]==0 && arithmos[2]==0) {
        elegxos[2]=1;
    }
    else if (arithmos[0]!=0 && arithmos[1]!=0 && arithmos[2]!=0) {
        elegxos[2]=1;
    }
    else {elegxos[2]=0;}

    /*�� ��� ���� 3 ������ � ��� ����� ���� � ��� ���� 3 ����� ����������� ���� � ���� 3 ��� ������ elegxos ������� ��� ���� "1", ������ ��� ���� "0"*/
    if (ifi[0]==0 && ifi[1]==0 && ifi[2]==0) {
        elegxos[3]=1;
    }
    else if (ifi[0]!=0 && ifi[1]!=0 && ifi[2]!=0) {
        elegxos[3]=1;
    }
    else {elegxos[3]=0;}

    /*�� ���� �� ������ ����� ��� ���� 1 ���� ������ set (3���) ��� � ��������� elenktis ������� ��� ���� "1", ����������� ��� ������ set ��� ������� ��� ���� "0"*/
    if (elegxos[0]==1 && elegxos[1]==1 && elegxos[2]==1 && elegxos[3]==1) {
        elenktis=1;
        printf("\n\n***Bravo i triada pou epelekses einai Set*** \n");
    }
    else {
        elenktis=0;
        printf("\n\n***Lupame i triada pou epelekses den einai Set*** \n");
    }

return (elenktis);                                                              /*� ��������� ��������� ��� ���� ��� elenktis ���� main*/
}


int getNextCard() {                                                             /*������� ��� ���������� getNextCard ����� int*/
    srand(time(NULL));                                                          /*����� �� ��������� srand ��� ��� ������������ ��� ���������� rand*/
    do {
        for (i=0; i<12; i++) {                                                  /*�������� 12 ��� ���� 81 �������� �������� ��� ���� ��������� ���� ������ tuxaioi*/
        tuxaioi[i]=rand()%81;
        }
        printf("\n");
        z=1;
        for (j=0; j<12; j++) {                                                  /*������� ��� �� 12 ������� ������� ��� ����������������*/
            for (k=0; k<12; k++) {
                if (tuxaioi[k]==tuxaioi[j] && j!=k) {                           /*�� ��������������� ������� ������� ���� � ������� do-while ���������������  */
                    z=0;                                                        /*����� � �������� �� ����������� ��� ���������� ��������*/
                }
            }
        }
    }
    while (z==0);

return (tuxaioi[12]);                                                           /*� ��������� ���������� ���� main ��� ������ �� ���� 12 �������� ��������*/
}
