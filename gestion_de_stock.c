#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[20];
    float prix; 
    long ref;
    int nbr;
}produit;

typedef struct{
    char type[20];
    int jour,mois,annee;
    char nom[20];
    float prix; 
    long ref;
    int nbr;
} operation;

struct node1{
    operation val;
    struct node1 *suiv;
};

struct node{
    produit val;
    struct node *suiv;
};
void ajout_arch(struct node1 **q1,struct node *q,int x,int n){
    struct node1 *temp1, *r; 
    struct node *aux ;
    operation op;
    temp1 = *q1;
    aux=q;
    char entre[]="entree";
    
    
    printf("Donner la date \nAnnee:\n");
    scanf("%i",&op.annee);
    while(op.annee<0){
        printf("Donner une Annee positive:\n");
        scanf("%i",&op.annee);
    }
     printf("Mois:\n");
    scanf("%i",&op.mois);
    while(op.mois<0 || op.mois>12){
        printf("Donner un mois entre 1 et 12 :\n");
        scanf("%i",&op.mois);
    }
     printf("Jour:\n");
    scanf("%i",&op.jour);
    while(op.jour<0 || op.jour>31){
        printf("Donner un jour entre 1 et 31 :\n");
        scanf("%i",&op.jour);
    }
    
    
    strcpy(op.type,entre);
    
    while( aux -> suiv!= NULL)
            aux = aux -> suiv;
    strcpy(op.nom,aux->val.nom);
    op.prix=aux->val.prix;
    op.ref=aux->val.ref;
    op.nbr=n;
    
    
    if(*q1 == NULL){
        temp1 = malloc(sizeof(struct node1));
        temp1 -> val = op;
        temp1 -> suiv = NULL;
        *q1 = temp1;
        
    }
    else{
        temp1 = *q1;
        while( temp1 -> suiv!= NULL)
            temp1 = temp1 -> suiv;
        r = malloc(sizeof(struct node1));
        r -> val = op;
        r -> suiv = NULL;
        temp1 -> suiv = r;
    } 
    
}

void ajout( struct node *q,struct node1 **q1){
    struct node1 *temp1, *r;
    operation op;
    temp1 = *q1;
    struct node *aux; 
    produit p;
    aux=q;
    int m;
    printf("Donner la reference  : \n");
    scanf("%ld", &p.ref);
    while(p.ref<0){
        printf("la reference doit etre positive");
        scanf("%ld", &p.ref);
    }
    while((aux != NULL) && ((aux->val.ref)!=(p.ref))){
    aux=aux->suiv;
    } 
    if(aux == NULL){
        printf("Ce produit n'exite pas , il faut le creer donc tapez 1 \n");
    }else{
        printf("Combien de pieces voulez-vous ajouter: \n");
        scanf("%d", &m);
        while(m<0){
            printf("Il faut ajouter un nombre positive de peices: \n");
        scanf("%d", &m);
        }
        aux->val.nbr=aux->val.nbr+m;
        printf("Donner la date \nAnnee:\n");
    scanf("%i",&op.annee);
    while(op.annee<0){
        printf("Donner une Annee positive:\n");
        scanf("%i",&op.annee);
    }
     printf("Mois: \n");
    scanf("%i",&op.mois);
    while(op.mois<0 || op.mois>12){
        printf("Donner un mois entre 1 et 12 :\n");
        scanf("%i",&op.mois);
    }
     printf("Jour: \n");
    scanf("%i",&op.jour);
    while(op.jour<0 || op.jour>31){
        printf("Donner un jour entre 1 et 31 :\n");
        scanf("%i",&op.jour);
    }
    char entre[]="Ajout";
    strcpy(op.type,entre);
    op.prix=aux->val.prix;
    strcpy(op.nom,aux->val.nom);
    op.ref=aux->val.ref;
    op.nbr=m;
    while( temp1 -> suiv!= NULL)
            temp1 = temp1 -> suiv;
        r = malloc(sizeof(struct node1));
        r -> val = op;
        r -> suiv = NULL;
        temp1 -> suiv = r;
    
    printf("Operation effectuee avec succees \n" );
    }
    
}
void afficher_hist(struct node1 *q1){
    struct node1 *aux;
    int a,m,j,n;
    if (q1==NULL){
        printf("L'historique est vide \n");
    }else{
        printf("(1)Historique d'un jour\n(2)Historique d'un mois\n(3)Historique d'un an\nDonner votre choix\n");
        scanf("%i",&n);
        while(n<1 || n>3){
            printf("choisissez un choix entre 1 et 3\n");
            scanf("%i",&n);
        }
        if(n==1){
            printf("donner la date pour la quelle vous voulez avoir l'historique \nAnnee:\n");
    scanf("%d",&a);
    while(a<0){
        printf("Donner une Annee positive:\n");
        scanf("%i",&a);
    }
     printf("Mois:\n");
    scanf("%d",&m);
    while(m<0 || m>12){
        printf("Donner un mois entre 1 et 12 :\n");
        scanf("%i",&m);
    }
     printf("Jour:\n");
    scanf("%d",&j);
    while(j<0 || j>31){
        printf("Donner un jour entre 1 et 31 :\n");
        scanf("%i",&j);
    }
        aux=q1;
       while( aux!=NULL){
         if(aux->val.jour==j && aux->val.mois==m && aux->val.annee==a){
             printf("Jour %i-%i-%i : %s de %d pieces du produit %s de reference %li et de prix %.2f\n",aux->val.jour,aux->val.mois,aux->val.annee,aux->val.type,aux->val.nbr,aux->val.nom,aux->val.ref,aux->val.prix);
             aux=aux->suiv;
         }else{
        aux=aux->suiv;
        } 
        }
        }else if(n==2) {
            printf("Donner la date pour la quelle vous voulez avoir l'historique \nAnnee:\n");
    scanf("%d",&a);
    while(a<0){
        printf("Donner une Annee positive:\n");
        scanf("%i",&a);
    }
     printf("Mois:\n");
    scanf("%d",&m);
    while(m<0 || m>12){
        printf("Donner un mois entre 1 et 12 :\n");
        scanf("%i",&m);
    }
        aux=q1;
       while( aux!=NULL){
         if( aux->val.mois==m && aux->val.annee==a){
             printf("Jour %i-%i-%i : %s de %d pieces du produit %s de reference %li et de prix %.2f\n",aux->val.jour,aux->val.mois,aux->val.annee,aux->val.type,aux->val.nbr,aux->val.nom,aux->val.ref,aux->val.prix);
             aux=aux->suiv;
         }else{
             
    aux=aux->suiv;

    } 
}
        }else if(n==3) {
            printf("donner la date pour la quelle vous voulez avoir l'historique \nAnnee:\n");
    scanf("%d",&a);
    while(a<0){
        printf("Donner une Annee positive:\n");
        scanf("%i",&a);
    }
     
        aux=q1;
       while( aux!=NULL){
         if(aux->val.annee==a){
             printf("Jour %i-%i-%i : %s de %d pieces du produit %s de reference %li et de prix %.2f\n",aux->val.jour,aux->val.mois,aux->val.annee,aux->val.type,aux->val.nbr,aux->val.nom,aux->val.ref,aux->val.prix);
             aux=aux->suiv;
         }else{
             
    aux=aux->suiv;

        } 
        }
        }
    
    }
    }
    
void afficher(struct node *q){
    struct node *aux;
    if (q==NULL){
        printf("Le stock est vide \n");
    }else{
        aux=q;
      while(aux != NULL){
        printf("Le produit %s de reference %li est de  %.2f  dinars, il y'a %d pieces dans le stock.\n",aux->val.nom,aux->val.ref, aux->val.prix,aux->val.nbr);
        aux = aux->suiv;
    }
    }
    }
void ajout_nouveau_produit( struct node **q){
    struct node *temp, *r,*aux; 
    produit p;
    temp = *q;
    int exist=0;
    aux= *q;
    printf("Donner le nom : \n");
    scanf("%s", &p.nom);
    printf("Donner la reference : \n");
    scanf("%ld", &p.ref);
    while(p.ref<0){
        printf("la reference doit etre positive");
        scanf("%ld", &p.ref);
    }
    while(aux!=NULL && exist==0){
        if(aux->val.ref==p.ref){
            exist=1;
        }
        aux=aux->suiv;
    }
    if(exist==1){
        printf("ce produit existe deja dans le stock \n");
    }else {
        printf("Donner le prix : \n");
    scanf("%f", &p.prix);
    while(p.prix<0){
        printf("le prix doit etre positif");
        scanf("%f", &p.prix);
    }
    printf("Combien de pieces voulez-vous ajouter: \n");
    scanf("%d", &p.nbr);
    while(p.nbr<0){
        printf("le nombre doit etre positive");
        scanf("%d", &p.nbr);
    }

    if(*q == NULL){
        temp = malloc(sizeof(struct node));
        temp -> val = p;
        temp -> suiv = NULL;
        *q = temp;
    }
    else{
        temp = *q;
        while( temp -> suiv!= NULL)
            temp = temp -> suiv;
        r = malloc(sizeof(struct node));
        r -> val = p;
        r -> suiv = NULL;
        temp -> suiv = r;
    }
    }
     
    
    
}


void chercher (struct node *q){
    struct node *aux;
    aux=q;
    long ref;
    printf("Donner la reference du produit \n");
    scanf("%ld", &ref);
    while(ref<0){
        printf("la reference doit etre positive");
        scanf("%ld", &ref);
    }
    while((aux!= NULL) && (aux->val.ref != ref)){
        aux=aux->suiv;
    }
    if (aux!=NULL){
        printf("On a %d pieces de ce produit dans le stock\n",aux->val.nbr);
    }else{
        printf("Ce produit n'existe pas dans le stock\n");
    }
}

void menu(){
  printf("1)Creer un nouveau produit \n2)Ajouter un produit \n3)Chercher un produit dans le stock\n4)Modifier un produit\n5)Retirer un produit du stock \n6)Afficher le stock\n7)Afficher l'historique\n8)quitter le programme\n");
 
}
void retirer( struct node *q,struct node1 **q1){
    struct node1 *temp1, *r;
    operation op;
    temp1 = *q1;
    struct node *aux; 
    produit p;
    aux=q;
    int m;
    int minimum_stock=10;
    printf("Donner la reference  : \n");
    scanf("%ld", &p.ref);
    while(p.ref<0){
        printf("la reference doit etre positive");
        scanf("%ld", &p.ref);
    }
    while((aux != NULL) && ((aux->val.ref)!=(p.ref))){
    aux=aux->suiv;
    } 
    if(aux == NULL){
        printf("Ce produit n'exite pas \n");
    }else{
        
        printf("Combien de pieces voulez-vous retirer: \n");
        scanf("%d", &m);
        while(m<0){
        printf("le nombre doit etre positive");
        scanf("%d", &m);
    }
        if(m>aux->val.nbr){
            printf("\nLe stock n'est pas suffisant pour ce retrait\n");
        }else{
            aux->val.nbr=aux->val.nbr-m;
        printf("donner la date \nAnnee:\n");
    scanf("%i",&op.annee);
     while(op.annee<0){
        printf("Donner une Annee positive:\n");
        scanf("%i",&op.annee);
    }
     printf("Mois: \n");
    scanf("%i",&op.mois);
    while(op.mois<0 || op.mois>12){
        printf("Donner un mois entre 1 et 12 :\n");
        scanf("%i",&op.mois);
    }
     printf("Jour: \n");
    scanf("%i",&op.jour);
    while(op.jour<0 || op.jour>31){
        printf("Donner un jour entre 1 et 31 :\n");
        scanf("%i",&op.jour);
    }
    char entre[]="Retrait";
    strcpy(op.type,entre);
    op.prix=aux->val.prix;
    strcpy(op.nom,aux->val.nom);
    op.ref=aux->val.ref;
    op.nbr=m;
    while( temp1 -> suiv!= NULL)
            temp1 = temp1 -> suiv;
        r = malloc(sizeof(struct node1));
        r -> val = op;
        r -> suiv = NULL;
        temp1 -> suiv = r;
    
    printf("\nOperation effectuee avec succees \n " );
    if (aux->val.nbr <= minimum_stock){
        printf("\nALERTE : il vous reste que %i pieces, donc il faut alimenter des %s\n",aux->val.nbr , aux->val.nom);
    }
        }
        
    }
    
}
void modifier (struct node *q){
    struct node *aux; 
    produit p;
    aux=q;
    int modif;
    printf("Donner la reference : \n");
    scanf("%ld", &p.ref);
    while(p.ref<0){
        printf("la reference doit etre positive");
        scanf("%ld", &p.ref);
    }
    while((aux != NULL) && ((aux->val.ref)!=(p.ref))){
    aux=aux->suiv;
    } 
    if(aux == NULL){
        printf("\nCe produit n'exite pas \n");
    }else{
        printf("(1) Modifier le nom\n(2) Modifier le prix\n");
        scanf("%i",&modif);
        while (modif!=1 && modif!=2){
            printf("Choisissez soit (1) ou (2)\n");
            scanf("%i",&modif);
        }
    if (modif==2){
        printf("donner le nouveau prix \n");
        scanf("%f",&(aux->val.prix));
    }else if (modif==1){
        printf("donner le nouveau nom \n");
        scanf("%s",&(aux->val.nom));
    }
    }
    printf("\nOperation effectuee avec succees \n" );
}
int retour() {
    int e;
    printf("00)quitter\n1)retour au menu\n");
    scanf("%d",&e);
    if(e==1){
        menu();
        return 1;
    }else if(e!=00&&e!=1){ 
        retour();}
    else{
        return 0;
    }
}
int main(){
    int e=1;
    long refr;
    int i,j;
    
    struct node *q;
    q=NULL;
    struct node1 *q1;
    q1=NULL;
    printf("\n\n\t\t ************************************************************");
		printf("\n\t\t                         Bienvenue                  ");
        
		printf("\n\t\t ************************************************************ \n");
        printf("\n");
    
    menu();
    while(e==1){
    int n;
     
    printf("\n");
    printf("  Donner votre choix :\n");
    scanf("%d",&n);
    while((n<1)||(n>8)){
        printf("  Donner votre choix :\n");
        scanf("%d",&n);
    }
    
    switch (n){
        case 1: i=0;j=0;
                struct node *aux ;
                aux=q;
                while(aux!=NULL){
                    aux=aux->suiv;
                    i++;
                }
                ajout_nouveau_produit (&q);
                aux=q;
                while(aux!=NULL){
                    aux=aux->suiv;
                    j++;
                }
                if(i!=j){
                    struct node *aux ;
                aux=q;
                while( aux -> suiv!= NULL)
                aux = aux -> suiv;
                
                ajout_arch(&q1,q,1,aux->val.nbr);
                printf("\nOperation effectuee avec succees \n" );
                }
                
        printf("\n");         
        e=retour();        
        break;
        case 2:
                
                ajout(q,&q1);
                printf("\n");
          e=retour();      
        break;
        case 3:chercher(q);
        printf("\n");
        e=retour();
        break;
        case 4: modifier(q);
        printf("\n");
        e=retour();
        break;
        case 5: retirer(q,&q1);
        printf("\n");
        e=retour();
        break;
        case 6: afficher (q);
        printf("\n");
        e=retour();
        break;
        case 7: afficher_hist(q1);
        printf("\n");
        e=retour();
        break;
        case 8: e=1;exit(0);
        break;
        
        
    }
}
exit(0);
}
