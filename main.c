#include <stdio.h>
#include <math.h>

//Welcome to spaghetti world

void sumWithNum(int n,int m,int mt[n][m],int num)// Òîçè ìåòîä ñúáèðà ìàòðèöà ñ ÷èñëî
{

    for(int i=0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            printf("%d ",mt[i][j]+num);
        }
        printf("\n");
    }

}
void subWithNum(int n,int m,int mt[n][m],int num)// Òîçè ìåòîä èçâàæäà ÷èñëî îò ìàòðèöà
{

    for(int i=0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            printf("%d ",mt[i][j]-num);
        }
        printf("\n");
    }

}
void mulWithNum(int n, int m,int mt[n][m],int num)// Òîè ìåòîä óìíîæàâà
{

    for(int i=0; i<n; i++)
    {
        for(int j =0; j<m; j++)
        {
            printf("%d ",mt[i][j]*num);
        }
        printf("\n");
    }

}
void mulWithMat(int n, int m,int mt[n][m])
{
    printmat(1);
    int k,p;
    scanf("%d %d",&k,&p);
    printmat(0);
    int arr[k][p],arr2[k][p];
    for(int i=0; i<k; i++)
    {
        for(int j =0; j<p; j++)
        {
            scanf("%d",&arr[i][j]);
            arr2[i][j]=0;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j =0; j<p; j++)
        {
            for(int t=0; t<n; t++)
            {
                arr2[i][j]+=mt[i][t]*arr[i][j];
            }
        }
    }
    for(int i=0; i<k; i++)
    {
        for(int j =0; j<p; j++)
        {
            printf("%d ",arr2[i][j]);
        }
        printf("\n");
    }
}
void sumWithMat(int n, int m,int mt[n][m])
{

    printmat(0);
    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ",mt[i][j]+arr[i][j]);
        }
        printf("\n");
    }
}
void subWithMat(int n, int m,int mt[n][m])
{
    printmat(0);
    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ",mt[i][j]-arr[i][j]);
        }
        printf("\n");
    }
}
void transponding(int n, int m,int mt[n][m])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; i>j&&j<m; j++)
        {
            int k = mt[i][j];
            mt[i][j]=mt[j][i];
            mt[j][i] = k;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%d ",mt[i][j]);
        }
        printf("\n");
    }
}
int determinant(int n, int m,int mt[n][m])
{
    int determinanta=0;
    int poddet=0;

    if(n>2)
    {
        int k=0,p=0;
        int arr[n-1][m-1];
        for(int d=0; d<m; d++)
        {
            k=0;
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(i != 0)
                        if(j != d)
                        {
                            arr[k][p] = mt[i][j];
                            p++;
                        }

                }
                if(i!=0)
                {
                    k++;
                }
                p=0;

            }
            poddet = determinant(n-1,m-1,arr);
            determinanta += mt[0][d]*pow((-1),d)*poddet ;
        }
        return determinanta;

    }
    if(n==2)
    {
        poddet = ((mt[0][0]*mt[1][1])-(mt[1][0]*mt[0][1]));
        return poddet;
    }
}
void printmat(char firstUse)
{
    if(firstUse)
        printf("Enter matrix size:");

    else
        printf("Enter matrix:\n");

}
int printMenu(int n,int m,int mt[n][m])
{
    int option;
    printf("Choose action :\n"
           "1. Sum with number\n"
           "2. Sum with another matrix\n"
           "3. Multiply with number\n"
           "4. Multiply with matrix\n"
           "5. Subtract a number\n"
           "6. Subtract a matrix\n"
           "7. Matrix transpose\n"
           "8. Find matrix determinant\n"
           "9. Inversed matrix\n"
          );
    scanf("%d",&option);
    int num;

    switch (option)
    {
    case 1:
        printf("Enter a number: ");
        scanf("%d",&num);
        sumWithNum(n,m,mt,num);
        break;
    case 2:
        sumWithMat(n,m,mt);
        break;
    case 3:
        printf("Enter a number: ");
        scanf("%d",&num);
        mulWithNum(n,m,mt,num);
        break;
    case 4:
        mulWithMat(n,m,mt);
        break;
    case 5:
        printf("Enter a number: ");
        scanf("%d",&num);
        subWithNum(n,m,mt,num);
        break;
    case 6:
        subWithMat(n,m,mt);
        break;
    case 7:
        transponding(n,m,mt);
        break;
    case 8:
        printf("The determinant is : %d\n",determinant(n,m,mt));
        break;
    case 9:
        invercedMat(n,m,mt);
    default:
        break;
    }
    printf("Do you want to use the new matrix,or type a new one\n"
           "Type \'O\' for old one and \'N\' to enter a new one : ");
    char a;
    scanf(" %c",&a);
    system("cls");
    if(a == 'O')
        printMenu(n,m,mt);
    else if(a=='N')
    {
        printFirst();
       // printMenu(n,m,mt);
    }


}
void printFirst()
{
    printmat(1);
    int n,m;3 3
    scanf("%d %d",&n,&m);
    int matrix[n][m];
    printmat(0);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printMenu(n,m,matrix);

}
void invercedMat(int n,int m,int mt[n][m])
{
    int det = determinant(n,m,mt);
    double mt2[n][m];
    if(det!= 0&&n>2&&m>2)
    {
        int arr[n-1][m-1];
        int prom1 = 0,prom2 = 0,t = 0,z = 0,andx=0,andy=0;

        for(int k=0; k<n*m; k++)
        {
            for(int i = 0; i<n; i++)
            {
                for(int j = 0; j<m; j++)
                {
                    if(i!= prom1)
                    {
                        if(j!= prom2)
                        {
                            arr[t][z] = mt[i][j];
                            z++;
                        }
                    }
                }
                if(i!= prom1)
                    t++;
                z = 0;
            }
            t=0;
            z=0;

            if(andy == m)
            {
                andy = 0;
                andx++;
            }
            int d = andx+1+andy+1;


            mt2[andx][andy] = (pow((-1),d)*determinant(n-1,m-1,arr))/det;
            andy ++;

            prom2++;
            if(prom2==m)
            {
                prom1++;
                prom2 = 0;
            }
        }
    }
    else if(det!=0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int d = i+1+j+1;
                mt2[i][j] = (pow((-1),d)*mt[j][i])/det;
            }
        }
        double asd = mt2[0][0];
        mt2[0][0]=mt2[1][1];
        mt2[1][1]=asd;
    }
    //
    for(int i=0; i<n; i++)
    {
        for(int j=0; i>j&&j<m; j++)
        {
            double k = mt2[i][j];
            mt2[i][j]=mt2[j][i];
            mt2[j][i] = k;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            printf("%.02f ",mt2[i][j]);
        }
        printf("\n");
    }
    //



}
int main()
{
    printFirst();
    return 0;
}
