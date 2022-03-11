#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


struct compte
{
    char cin[18];
    char Nom[20];
    char Prenom[20];
    float montant;
};

struct compte client[100];

int index=0;
float montant;


int intro_compte ()
{
    printf("entrez cin : ");
    scanf("%s", client[index].cin);

    printf("entrez le nom : ");
    scanf("%s", client[index].Nom);

    printf("entrez le prenom : ");
    scanf("%s",client[index].Prenom);

    printf("entrez montant : ");
    scanf("%f", client[index].montant);

    index++;

    return 0;

}


int intro_plus_comptes()
{

    int nbr;
    int i;

    printf(" entrez le nombre du comptes: ");
    scanf("%d", &nbr);

    for( i=0;i<nbr;i++)
    {
        printf("entrez cin : ");
        scanf("%s", &client[index].cin);

        printf("entrez le nom : ");
        scanf("%s", &client[index].Nom);

        printf("entrez le prenom : ");
        scanf("%s", &client[index].Prenom);

        printf("entrez montant : ");
        scanf("%f", &client[index].montant);

        index++;
     }

     return 0;
}



int depot_retrait()
{
    char cin[10];
    int i;
    bool find=false;

    printf("entrez cin : ");
    scanf("%s", &cin);

    for( i=0;i<index;i++)
    {
        if( strcmp(client[i].cin,cin) ==0 )
        {
        find=true;
        break;
        }
    }

    if ( find==true)
{
     int choice;
     float solde;

     printf("1 - retrait \n2 - depot \n");

     printf("entrez votre choix: ");
     scanf("%d", &choice);

     if(choice==1)
     {
     printf("entrez le montant : ");
     scanf("%f", &solde);
     client[i].montant=client[i].montant-solde;
     printf("Votre Nouveau Solde Est : %f \n",client[i].montant);
     }

     else if(choice==2)
     {
     printf("entrez le montant : ");
     scanf("%f", &solde);
     client[i].montant=client[i].montant+solde;
     printf("Votre Nouveau Solde Est : %f \n",client[i].montant);
     }

     else
    {
        printf("cin non valid \n");
    }
     return 0;
}

}



void affichage()
{
    for (int i=0; i < index ; i++)
    {
        printf("%s | %s | %s | %.2f Dh\n",client[i].cin , client[i].Nom , client[i].Prenom , client[i].montant);
    }

}

int main()
{

int choix;
menu:
do{

printf("menu\n");
printf(" 1-introduire un compte bancaire \n");
printf(" 2-Introduire plusieurs comptes bancaires  \n");
 printf(" 3-operations \n");
 printf(" 4-affichage   \n");
 printf(" 5-Fidelisation  \n");
 printf(" 6-quitter  \n");


printf(" votre choix \n");
scanf("%d",&choix);



   switch(choix){

                case 1:  intro_compte();
                goto menu;



                case 2:  intro_plus_comptes();goto menu; break;



                case 3:  depot_retrait();goto menu;break;



                case 4:  affichage(); goto menu;break;

                case 6: printf("AU REVOIRE...\n");break;



                default : printf("entrez valeur entre 1 et 6 \n");







   }

}while(choix<1 || choix>6);






return 0;


}
