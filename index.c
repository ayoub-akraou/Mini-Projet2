#include <stdio.h>
#include <string.h>

struct Contact
{
    char nom[50];
    char telephone[50];
    char email[100];
};

struct Contact carnet_de_contacts[100];
int n = 0;

// helper function
int rechercher_indice(char target[50])
{
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(target, carnet_de_contacts[i].nom) == 0)
        {
            return i;
        }
    }
    printf("ce contact n'est pas trouve\n");
    return -1;
}

void ajouter_contact()
{
    printf("nom: \n");
    scanf("%s", &carnet_de_contacts[n].nom);
    printf("telephone: \n");
    scanf("%s", &carnet_de_contacts[n].telephone);
    printf("email: \n");
    scanf("%s", &carnet_de_contacts[n].email);
    n++;
}

void modifier_un_contact()
{
    char nom[50];
    printf("saisi le nom:\n");
    scanf("%s", nom);
    int indice = rechercher_indice(nom);
    if (indice != -1)
    {
        char nouveau_telephone[50];
        printf("saisi le nouveau numero:\n");
        scanf("%s", nouveau_telephone);
        strcpy(carnet_de_contacts[indice].telephone, nouveau_telephone);

        char nouveau_email[50];
        printf("saisi le nouveau email:\n");
        scanf("%s", nouveau_email);
        strcpy(carnet_de_contacts[indice].email, nouveau_email);
    }
}

void supprimer_un_contact()
{
    char nom[50];
    printf("saisi le nom: \n");
    scanf("%s", nom);
    int indice = rechercher_indice(nom);
    if (indice != -1)
    {

        for (size_t i = indice; i < n - 1; i++)
        {
            carnet_de_contacts[i] = carnet_de_contacts[i + 1];
        }
        n--;
    }
}

void afficher_les_contacts()
{
    if (n == 0)
    {
        printf("aucun contact trouve\n");
    }

    for (size_t i = 0; i < n; i++)
    {
        printf("le contact N%i: \n", i + 1);
        printf("le nom: %s \n", carnet_de_contacts[i].nom);
        printf("le telephone: %s \n", carnet_de_contacts[i].telephone);
        printf("email: %s \n\n", carnet_de_contacts[i].email);
    }
}

void rechercher_contact()
{
    printf("saisie le nom:\n");
    char nom[50];
    scanf("%s", nom);
    int indice = rechercher_indice(nom);
    if (indice != -1)
    {
        printf("*****************\n");
        printf("le nom: %s\n", carnet_de_contacts[indice].nom);
        printf("le numero de telephone: %s\n", carnet_de_contacts[indice].telephone);
        printf("adresse email: %s\n", carnet_de_contacts[indice].email);
    }
}

int main()
{
    int choix;

    printf("============================\n");
    printf("Saisi le numero d'operation:\n");
    printf("1. Ajouter un Contact\n");
    printf("2. Modifier un Contact\n");
    printf("3. Supprimer un Contact\n");
    printf("4. Afficher Tous les Contacts\n");
    printf("5. Rechercher un Contact\n");
    scanf("%i", &choix);

    switch (choix)
    {
    case 1:
        ajouter_contact();
        break;
    case 2:
        modifier_un_contact();
        break;
    case 3:
        supprimer_un_contact();
        break;
    case 4:
        afficher_les_contacts();
        break;
    case 5:
        rechercher_contact();
        break;

    default:
        printf("choix invalide\n");
        break;
    }

    main();
    return 0;
}