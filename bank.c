#include <stdio.h>
struct customer {
    int ac;
    char name[30];
    int bal;
};
struct customer ct[10];
void belo1000()
{
    printf("Customers with balance less than Rs.1000\n");
    for(int i=0; i<10; i++)
        if(ct[i].bal<1000)
            printf("A/C : %d\nName : %s\n",ct[i].ac,ct[i].name);
}
void witdepo()
{
    int ac_no,i;
    printf("Enter account number:");
    scanf("%d",&ac_no);
    for(i=0; i<10; i++)
        if(ct[i].ac==ac_no)
            break;
    int ans,with;
    printf("Enter 1 for deposit and 0 for withdrawal:");
    scanf("%d",&ans);
    if(ans==0) {
        printf("Enter the amount to withdraw:");
        scanf("%d",&with);
        if(ct[i].bal-with<1000)
            printf("The balance is insufficient for specific withdrawal.\n");
        else {
            printf("Amount Rs.%d withdrawn\n",with);
            printf("Available Balance : %d",ct[i].bal-with);
        }
    }
    if(ans==1) {
        int depo;
        printf("Enter the amount to deposit:");
        scanf("%d",&depo);
        printf("Total balance : %d",ct[i].bal+depo);
    }
}
void main()
{
    for(int i=0; i<10; i++) {
        printf("Enter account number, name and balance of cutomer %d:",i+1);
        scanf("%d%s%d",&ct[i].ac,ct[i].name,&ct[i].bal);
        while(getchar()!='\n');
    }
    belo1000();
    char ans;
    printf("Do you want to do transaction(Y/N):");
    scanf("%c",&ans);
    if(ans=='Y')
        witdepo();
    else
        printf("Thanks! have a nice day");
}
