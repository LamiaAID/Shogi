#include <stdio.h>
#include <stdlib.h>
#include "partie.h"




int main(int argc, char **argv)
{
	partie_t *p=NULL;
	char *nom_argv=NULL;
	int reponse=1;

	if(argc == 1)
	{
		printf("\n\n********** Nouvelle partie **********\n");
		p=partie_nouvelle();
		partie_jouer(p,FAUX,nom_argv);	/*nom_argv=NULL*/	
	}
	else if(argc == 2)
	{
		nom_argv=malloc(sizeof(char)*25);
		strcpy(nom_argv,argv[1]);

		if(((p=partie_charger(nom_argv))) != NULL && replay_charger(nom_argv) != NULL ) /* on donne juste le nom pas le chemin */
		{	do
			{
				printf("\nSi vous voulez charger la partie \nTappez 1\nSi vous voulez faire un replay\nTappez 0\n");
				scanf(" %d",&reponse);
			} while (reponse != 1 && reponse != 0);
			
			if(reponse)
			{
				partie_jouer(p,VRAI,nom_argv);	
			}
			else
			{
				p=replay_charger(nom_argv);
				replay_jouer(p);
			}
		}
		else if((p=partie_charger(nom_argv)) != NULL)
		{
			partie_jouer(p,VRAI,nom_argv);
		}

		else if((p=replay_charger(nom_argv)) != NULL)
		{
			replay_jouer(p);
		}
		else
		{
			printf("\n\t/!\\ Erreur le fichier n'existe pas /!\\\n");
			return EXIT_FAILURE;
		}

	}
	else
	{
		 printf("\n\t/!\\ Erreur veuillez saisir moins de 2 arguments /!\\\n");
		 return EXIT_FAILURE;
	}

	
	partie_detruire(p);	
	
	

	return EXIT_SUCCESS;
}