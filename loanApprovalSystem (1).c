#include <stdio.h>
#include<time.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int managerLogin();
void waitMethod();
int main()
{
    int login = 0;
    login = (int)managerLogin();
    if(login==0){
        exit(0);
    }
  
    int n, m, i, j, k,a;
    printf("Enter the number of loans to be sanctioned: ");
    scanf("%d",&n); // n is number of loans
    int savings[n][1],loan[n][1],avail[1];
    m = 1; // resource for loan is 1 bank
    printf("\nEnter the savings amounts of the customers: \n");
    for(a=0;a<n;a++){
        printf("Customer %d: ",a+1);
        scanf("%d",&savings[0][a]);
    }
    printf("\nEnter the loan amounts required: \n");
    for(a=0;a<n;a++){
        printf("Customer %d: ",a+1);
        scanf("%d",&loan[0][a]);
    }
    printf("\nEnter the available resource amount: ");
    scanf("%d", &avail[0]);
    printf("\n\nChecking the available resources for approving the loan");
    printf("\n");
    waitMethod();   
    
    printf("\n");
    
   //Process
    int f[n], ans[n], ind = 0, un=0, unsafe[10];
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = loan[i][j] - savings[i][j];
    }
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
  
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;       //unsafe state
                         printf("Approving loan to Customer %d can lead the bank to an unsafe state \n", (i+1));
                         printf("Loan rejected for customer %d",(i+1));
                         exit(0);
                    }
                }
  
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += savings[i][y];
                    f[i] = 1;
                }
                
                if(flag == 1){
                    unsafe[un++] = i;
                }
            }
        }
    }
    
    /*for(i=0;i<n;i++)
    {
        printf("%d",f[i]);
    }*/
  
    printf("\nOrder for loan to be sanctioned for the bank to be in safe state: \n");
    for (i = 0; i < n - 1; i++)
       {
           printf("Customer %d \n", ans[i]+1);
           sleep(1);
       }
       
    
    //printf("Customer %d can create an unsafe state to the bank \n", (ans[1]+1));
    
    printf("Customer %d \n", ans[n-1]+1);
  
    return (0);
}


int managerLogin()
{
    char admin[20]="admin", password[10]="admin",pass[10];

    printf("-------LOGIN-------\n");
    printf("\n Username: ");
    scanf("%s",admin);
    printf(" Password: ");
    scanf("%s",pass);

    if(strcmp(password,pass)==0)
    {
       printf("\n ------------------\n");
       printf(" | LOGIN SUCCESS! |");
       printf("\n ------------------\n");
       return 1;
    }
    else
    { 
        printf("Manager details did not match");
        return 0;
    }

}

void waitMethod()
{
    for(int i = 0; i<5; i++)
    {
        printf(".\n");
        sleep(1);
    }
    
}

















