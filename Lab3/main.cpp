#include <iomanip>

int checkNum(int a) {
    char temp = a + '0';
    if((a<9) && (a>0)) {
        if(temp >= '0' && temp <= '9'){
            return 1;
        } else {
            return 0;
        }
    }else {
        char tens = a/10 + '0';
        char nums = a%10 + '0';
        if((tens >= '0' && tens <='9') && (nums >= '0' && nums <= '9')) {
            return 1;

        }else {
            return 0;
        }
    }
}

int main()
{
int n;
int m;
while (true) {
rewind(stdin);
printf("n= ");
scanf("%d",&n);
if(checkNum(n)==1) {
    break;
  } else {
    printf("wrong type\n");
  }
}
while (true) {
rewind(stdin);
printf("m= ");
scanf("%d",&m);
if(checkNum(m)==1) {
    break;
  } else {
    printf("wrong type\n");
  }
}

int Arr[n][m];
int i=0, j, k = 0, p=1;

while (i < n*m) /*Цикл по номеру витка*/
 {
    k++;
    for (j=k-1;j<m-k+1;j++)
    {
        Arr[k-1][j]=p++;
        i++;
    }   /*Определение значений верхнего гор столбца*/

    for (j=k;j<n-k+1;j++)
    {
        Arr[j][m-k]=p++;
        i++;
    }   /* --//-- По правому вертикальному столбцу*/

    for (j=m-k-1;j>=k-1;j--)
    {
        Arr[n-k][j]=p++;
        i++;
    }   /* --//-- по нижнему горизонтальному столбцу*/

    for (j=n-k-1;j>=k;j--)
    {
        Arr[j][k-1]=p++;
        i++;
    }   /* --//-- по левому вертикальному столбцу*/

 }

for (int q=0; q<n; q++)
{
    for (int w=0; w<m; w++)
    {
        printf("%d \t",Arr[q][w]);
    };
    printf("\n");
}

return(0);
}
