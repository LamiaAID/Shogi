#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "piece.h"


piece piece_creer(int joueur, char type, int statut)
{
	piece p;
	p.joueur=joueur;
	p.type=type;
	p.statut=statut;
	return p;
}
//**************************************************************************//

int piece_joueur(piece p)
{
	return p.joueur;
}

//***************************************************************************//

piece piece_identifier(char c)
{
  int i=0;
  char tab_type[]= "malloc(15*sizeof(char))";
  piece piece=piece_creer(JOUEUR_VIDE,'.',VIDE);
  
  strcpy(tab_type,"plnbrsgkdjcfta");
  
  if(isupper(c))
    {
      
      for(i=0; i<14; i++)
		{
		  if(i<8)
		    {
		      if (toupper(tab_type[i])==c)
			{
			  return piece_creer(JOUEUR_0, c,NON_PROMUE);
			}
		      else 
			{
			  return piece_creer(JOUEUR_0, '.', NON_PROMUE);
			}
		    }
		  else
		    {
		      if (toupper(tab_type[i])==c)
			{
			  return piece_creer(JOUEUR_0, c, PROMUE);
			}
		      else 
			{
			  return piece_creer(JOUEUR_0, '.', PROMUE);
			}
		    }
		  
		}
	}
  else 
    {
      for (i = 0; i < 14; ++i)
	{
	  if(i<8)
	    {
	      if(tab_type[i]==c)
		{
		  return piece_creer(JOUEUR_1,c,NON_PROMUE);
		}
	      else 
		
		{
		  return piece_creer(JOUEUR_1, '.', NON_PROMUE);
		}
	    }
	  else
	    {
	      if(tab_type[i]==c)
		{
		  return piece_creer(JOUEUR_1,c,PROMUE);
		}
	      else 
		
		{
		  return piece_creer(JOUEUR_1, '.', PROMUE);
		}
	    }
	  
	}
    }
  return;
}

//********************************************************************//

char piece_caractere(piece p)
{
	return p.type;
}

//********************************************************************//

void piece_afficher(piece p)
{
    printf("%2c",p.type);
}

