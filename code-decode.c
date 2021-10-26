#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int determinant(int msg[100][100])
{
    int d;
    d = msg[0][0]*((msg[1][1]*msg[2][2])-(msg[1][2]*msg[2][1])) - msg[0][1]*((msg[1][0]*msg[2][2])-(msg[2][0]*msg[1][2])) + msg[0][2]*((msg[1][0]*msg[2][1])-(msg[2][0]*msg[1][1]));
    return d;
}

void transpose (float msg[100][100])
{
   int temp;
   temp = msg[0][1];
   msg[0][1] = msg[1][0];
   msg[1][0] = temp;
   temp = msg[0][2];
   msg[0][2] = msg[2][0];
   msg[2][0] = temp;
   temp = msg[1][2];
   msg[1][2] = msg[2][1];
   msg[2][1] = temp;
}

void cofactors (int a[100][100], float cos[100][100])
{
    cos[0][0]=(a[1][1]*a[2][2])-(a[1][2]*a[2][1]);
    cos[0][1]=-((a[1][0]*a[2][2])-(a[1][2]*a[2][0]));
    cos[0][2]=(a[1][0]*a[2][1])-(a[1][1]*a[2][0]);
    cos[1][0]=-((a[0][1]*a[2][2])-(a[0][2]*a[2][1]));
    cos[1][1]=(a[0][0]*a[2][2])-(a[0][2]*a[2][0]);
    cos[1][2]=-((a[0][0]*a[2][1])-(a[0][1]*a[2][0]));
    cos[2][0]=(a[0][1]*a[1][2])-(a[0][2]*a[1][1]);
    cos[2][1]=-((a[0][0]*a[1][2])-(a[0][2]*a[1][0]));
    cos[2][2]=(a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
}

void inverse (int key[100][100], int inkey[100][100])
{
    int d, i, j;
    float cos[100][100];
    cofactors(key, cos);
    transpose(cos);
    d=determinant(key);
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            cos[i][j]=cos[i][j]/(float)d;
            if(cos[i][j]-cos[i][j]/1>=0.5)
                cos[i][j]=(int)cos[i][j]/1 + 1;
            else
                cos[i][j]=(int)cos[i][j]/1;
        }
    }
    for (i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            inkey[i][j]=cos[i][j];
        }
    }
}

void multiplication (int msg[100][100], int m, int key[100][100], int mult[100][100])
{
    int c, d, k, sum=0;
    for ( c = 0 ; c < m ; c++ )
    {
      for ( d = 0 ; d < 3 ; d++ )
      {
        for ( k = 0 ; k < 3 ; k++ )
        {
          sum = sum + msg[c][k]*key[k][d];
        }

        mult[c][d] = sum;
        sum = 0;
      }
    }
}


void main()
{
    int msg[100][100], key[100][100], inkey[100][100], i, j, l, c=3, m, n=0, coded[100][100], decoded[100][100];
    char option, str[100], ans[100];
    printf("Enter your message to be coded or decoded:\n");
    gets(str);
    printf("Enter\n'c' to code the message\n'd' to decode the message\n");
    scanf("%c", &option);
    l = strlen(str);
    if(l%3==0)
        m=l/3;
    else
        m=l/3+1;
    printf("Enter the elements of a 3 x 3 key:\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    if(option=='c' || option=='C')
    {
        for (i=0;i<m;i++)
        {
            for(j=0;j<3;j++)
            {
                switch(str[n])
                {
                    case 'A':
                    case 'a':msg[i][j] = 1;
                    break;
                    case 'B':
                    case 'b':msg[i][j] = 2;
                    break;
                    case 'C':
                    case 'c':msg[i][j] = 3;
                    break;
                    case 'D':
                    case 'd':msg[i][j] = 4;
                    break;
                    case 'E':
                    case 'e':msg[i][j] = 5;
                    break;
                    case 'F':
                    case 'f':msg[i][j] = 6;
                    break;
                    case 'G':
                    case 'g':msg[i][j] = 7;
                    break;
                    case 'H':
                    case 'h':msg[i][j] = 8;
                    break;
                    case 'I':
                    case 'i':msg[i][j] = 9;
                    break;
                    case 'J':
                    case 'j':msg[i][j] = 10;
                    break;
                    case 'K':
                    case 'k':msg[i][j] = 11;
                    break;
                    case 'L':
                    case 'l':msg[i][j] = 12;
                    break;
                    case 'M':
                    case 'm':msg[i][j] = 13;
                    break;
                    case 'N':
                    case 'n':msg[i][j] = 14;
                    break;
                    case 'O':
                    case 'o':msg[i][j] = 15;
                    break;
                    case 'P':
                    case 'p':msg[i][j] = 16;
                    break;
                    case 'Q':
                    case 'q':msg[i][j] = 17;
                    break;
                    case 'R':
                    case 'r':msg[i][j] = 18;
                    break;
                    case 'S':
                    case 's':msg[i][j] = 19;
                    break;
                    case 'T':
                    case 't':msg[i][j] = 20;
                    break;
                    case 'U':
                    case 'u':msg[i][j] = 21;
                    break;
                    case 'V':
                    case 'v':msg[i][j] = 22;
                    break;
                    case 'W':
                    case 'w':msg[i][j] = 23;
                    break;
                    case 'X':
                    case 'x':msg[i][j] = 24;
                    break;
                    case 'Y':
                    case 'y':msg[i][j] = 25;
                    break;
                    case 'Z':
                    case 'z':msg[i][j] = 26;
                    break;
                    case ' ':msg[i][j] = 0;
                    break;
                    default:msg[i][j] = 0;
                }
                n+=1;
            }
        }
        if(m*3-l==1)
        msg[m-1][2]=0;
        else if(m*3-l==2)
        {
            msg[m-1][1]=0;
            msg[m-1][2]=0;
        }
        multiplication(msg, m, key, coded);
        for(i=0; i<m; i++)
        {
            for(j=0; j<3; j++)
            {
                while(coded[i][j]<0 || coded[i][j]>26)
                {
                    if(coded[i][j]>26)
                        coded[i][j]-=27;
                    if(coded[i][j]<0)
                        coded[i][j]+=27;
                }
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<3; j++)
            {
                switch(coded[i][j])
                {
                    case 1:strcat(ans,"A");
                    break;
                    case 2:strcat(ans,"B");
                    break;
                    case 3:strcat(ans,"C");
                    break;
                    case 4:strcat(ans,"D");
                    break;
                    case 5:strcat(ans,"E");
                    break;
                    case 6:strcat(ans,"F");
                    break;
                    case 7:strcat(ans,"G");
                    break;
                    case 8:strcat(ans,"H");
                    break;
                    case 9:strcat(ans,"I");
                    break;
                    case 10:strcat(ans,"J");
                    break;
                    case 11:strcat(ans,"K");
                    break;
                    case 12:strcat(ans,"L");
                    break;
                    case 13:strcat(ans,"M");
                    break;
                    case 14:strcat(ans,"N");
                    break;
                    case 15:strcat(ans,"O");
                    break;
                    case 16:strcat(ans,"P");
                    break;
                    case 17:strcat(ans,"Q");
                    break;
                    case 18:strcat(ans,"R");
                    break;
                    case 19:strcat(ans,"S");
                    break;
                    case 20:strcat(ans,"T");
                    break;
                    case 21:strcat(ans,"U");
                    break;
                    case 22:strcat(ans,"V");
                    break;
                    case 23:strcat(ans,"W");
                    break;
                    case 24:strcat(ans,"X");
                    break;
                    case 25:strcat(ans,"Y");
                    break;
                    case 26:strcat(ans,"Z");
                    break;
                    case 0:strcat(ans," ");
                    break;
                    default:printf("Invaild");
                }
            }
        }
        printf("The coded string is-\n%s", ans);
    }
    else if(option=='d' || option=='D')
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<3;j++)
            {
                switch(str[n])
                {
                    case 'A':
                    case 'a':msg[i][j] = 1;
                    break;
                    case 'B':
                    case 'b':msg[i][j] = 2;
                    break;
                    case 'C':
                    case 'c':msg[i][j] = 3;
                    break;
                    case 'D':
                    case 'd':msg[i][j] = 4;
                    break;
                    case 'E':
                    case 'e':msg[i][j] = 5;
                    break;
                    case 'F':
                    case 'f':msg[i][j] = 6;
                    break;
                    case 'G':
                    case 'g':msg[i][j] = 7;
                    break;
                    case 'H':
                    case 'h':msg[i][j] = 8;
                    break;
                    case 'I':
                    case 'i':msg[i][j] = 9;
                    break;
                    case 'J':
                    case 'j':msg[i][j] = 10;
                    break;
                    case 'K':
                    case 'k':msg[i][j] = 11;
                    break;
                    case 'L':
                    case 'l':msg[i][j] = 12;
                    break;
                    case 'M':
                    case 'm':msg[i][j] = 13;
                    break;
                    case 'N':
                    case 'n':msg[i][j] = 14;
                    break;
                    case 'O':
                    case 'o':msg[i][j] = 15;
                    break;
                    case 'P':
                    case 'p':msg[i][j] = 16;
                    break;
                    case 'Q':
                    case 'q':msg[i][j] = 17;
                    break;
                    case 'R':
                    case 'r':msg[i][j] = 18;
                    break;
                    case 'S':
                    case 's':msg[i][j] = 19;
                    break;
                    case 'T':
                    case 't':msg[i][j] = 20;
                    break;
                    case 'U':
                    case 'u':msg[i][j] = 21;
                    break;
                    case 'V':
                    case 'v':msg[i][j] = 22;
                    break;
                    case 'W':
                    case 'w':msg[i][j] = 23;
                    break;
                    case 'X':
                    case 'x':msg[i][j] = 24;
                    break;
                    case 'Y':
                    case 'y':msg[i][j] = 25;
                    break;
                    case 'Z':
                    case 'z':msg[i][j] = 26;
                    break;
                    case ' ':msg[i][j] = 0;
                    break;
                    default:msg[i][j] = 0;
                }
                n+=1;
            }
        }
        if(m*3-l==1)
        msg[m-1][2]=0;
    else if(m*3-l==2)
        {
            msg[m-1][1]=0;
            msg[m-1][2]=0;
        }
        inverse(key, inkey);
        multiplication(msg, m, inkey, decoded);
        for(i=0; i<m; i++)
        {
            for(j=0; j<3; j++)
            {
                while(decoded[i][j]<0 || decoded[i][j]>26)
                {
                    if(decoded[i][j]>26)
                        decoded[i][j]-=27;
                    if(decoded[i][j]<0)
                        decoded[i][j]+=27;
                }
            }
        }
        for(i=0; i<m; i++)
        {
            for(j=0; j<3; j++)
            {
                switch(decoded[i][j])
                {
                    case 1:strcat(ans,"A");
                    break;
                    case 2:strcat(ans,"B");
                    break;
                    case 3:strcat(ans,"C");
                    break;
                    case 4:strcat(ans,"D");
                    break;
                    case 5:strcat(ans,"E");
                    break;
                    case 6:strcat(ans,"F");
                    break;
                    case 7:strcat(ans,"G");
                    break;
                    case 8:strcat(ans,"H");
                    break;
                    case 9:strcat(ans,"I");
                    break;
                    case 10:strcat(ans,"J");
                    break;
                    case 11:strcat(ans,"K");
                    break;
                    case 12:strcat(ans,"L");
                    break;
                    case 13:strcat(ans,"M");
                    break;
                    case 14:strcat(ans,"N");
                    break;
                    case 15:strcat(ans,"O");
                    break;
                    case 16:strcat(ans,"P");
                    break;
                    case 17:strcat(ans,"Q");
                    break;
                    case 18:strcat(ans,"R");
                    break;
                    case 19:strcat(ans,"S");
                    break;
                    case 20:strcat(ans,"T");
                    break;
                    case 21:strcat(ans,"U");
                    break;
                    case 22:strcat(ans,"V");
                    break;
                    case 23:strcat(ans,"W");
                    break;
                    case 24:strcat(ans,"X");
                    break;
                    case 25:strcat(ans,"Y");
                    break;
                    case 26:strcat(ans,"Z");
                    break;
                    case 0:strcat(ans," ");
                    break;
                    default:strcat(ans," ");
                }
            }
        }
        printf("The decoded string is-\n%s", ans);
    }
    else printf("Incorrect input of option");
}
