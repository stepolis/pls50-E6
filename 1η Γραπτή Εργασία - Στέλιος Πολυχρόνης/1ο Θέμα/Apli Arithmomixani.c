/*������� ���������� �� 123603 ����� ���-1*/
/*1� ������ ������� - ���� 1�*/
/* ���� ������������*/


#include <stdio.h>

int main()
{
    char praksi;
    float arithm1, arithm2, apot;

    printf("Apli Arithmomixani\n");                                         /*��������� ��� �����������*/
    printf("******************\n");                                         /*��� �� ����� �������� � �����������*/
    printf(" \n");
    printf("Dwse arithmo praksi arithmo\n");                                /*������ �� ��������*/

    scanf("%f %c %f", &arithm1, &praksi, &arithm2);                         /*�������� �� �������� ��� ����� � �������*/

    if (praksi=='+') {                                                      /*�� � ������� �������� ��������*/
        printf("apotelesma = %5.2f\n", apot=arithm1+arithm2);
    }

        else if (praksi=='-') {                                             /*�� � ������� �������� ��������*/
            printf("apotelesma = %5.2f\n", apot=arithm1-arithm2);
        }

        else if (praksi=='*') {                                             /*�� � ������� �������� ��������������*/
            printf("apotelesma = %5.2f\n", apot=arithm1*arithm2);
        }

        else if (praksi=='/') {                                             /*�� � ������� �������� ��������*/
                if (arithm2==0)
                    printf("**ERROR** i diairesi me to 0 den orizetai\n");  /*������ ������ �� ��������� ��� � ��������� ����� 0*/
                else
                    printf("apotelesma = %5.2f\n", apot=arithm1/arithm2);
        }

    else
        printf("**ERROR** i praksi prepei na einai +,-,*,/\n");             /*������ ������ �� ��������� ��� � ������ ��� �������� ��� ��� ��� ���������� �������*/

    return 0;
}
