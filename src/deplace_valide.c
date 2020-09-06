#include <stdio.h>
#include <stdlib.h>





int main()
{
	
}
/**********************FONCTION PRINCIPALE VALIDE *********************/
/**********************FONCTION PRINCIPALE VALIDE *********************/
/**********************FONCTION PRINCIPALE VALIDE *********************/
int deplacement_valide(coordonnees_t depart,coordonnees_t arrivee,partie_t *partie)
{
	if(arrivee.x < TAILLE-1 && arrivee.x > 0 && arrivee.y < TAILLE-1 && arrivee.y > 0)
	{
		if(depart.x < TAILLE-1 && depart.x > 0 && depart.y < TAILLE-1 && depart.y > 0) 
		{
			if(partie->bool_joueur == piece_joueur(partie->tablier[depart.x][depart.y]))
			{
				switch(tolower(partie->tablier[depart.x][depart.y].type))
				{
					if(partie->tablier[depart.x][depart.y].statut==PROMUE)
					{
						case 'p': return deplacement_valide_pion(depart,arrivee,partie);
						case 'l': return deplacement_valide_lance(depart,arrivee,partie);
						case 'n': return deplacement_valide_cavalier(depart,arrivee,partie);
						case 'b': return deplacement_valide_fou(depart,arrivee,partie);
						case 'r': return deplacement_valide_tour(depart,arrivee,partie);
						case 's': return deplacement_valide_silver(depart,arrivee,partie);
						case 'g': return deplacement_valide_gold(depart,arrivee,partie);
						case 'k': return deplacement_valide_roi(depart,arrivee,partie);
					}
					else
					{
						case 'd': return deplacement_valide_gold(depart,arrivee,partie);
						case 'j': return deplacement_valide_gold(depart,arrivee,partie);
						case 'c': return deplacement_valide_gold(depart,arrivee,partie);
						case 'f': return deplacement_valide_horse(depart,arrivee,partie);
						case 't': return deplacement_valide_dragon(depart,arrivee,partie);
						case 'a': return deplacement_valide_gold(depart,arrivee,partie);
					}
				}
			}
		}

		else if((depart.x<TAILLE) && (depart.x>=0) && (depart.y<TAILLE) && (depart.y>=0))
		{
			if(partie->bool_joueur == piece_joueur(partie->tablier[depart.x][depart.y]))
			{
				//parachutageeeeeeeeeeee.........................................
				/***************************************************************/
				switch(tolower(partie->tablier[depart.x][depart.y].type))
				{
					case 'p': return parachutage_valide_pion(depart,arrivee,partie);
					case 'l': return parachutage_valide_lance(depart,arrivee,partie);
					case 'n': return parachutage_valide_cavalier(depart,arrivee,partie);
					case 'b': return parachutage_valide_fou(depart,arrivee,partie);
					case 'r': return parachutage_valide_tour(depart,arrivee,partie);
					case 's': return parachutage_valide_silver(depart,arrivee,partie);
					case 'g': return parachutage_valide_gold(depart,arrivee,partie);
					case 'k': return parachutage_valide_roi(depart,arrivee,partie);

				}
			}
		}
	}
	return FAUX;
}

/**********************FONCTION PRINCIPALE VALIDE *********************/
/**********************FONCTION PRINCIPALE VALIDE *********************/
/**********************FONCTION PRINCIPALE VALIDE *********************/



/**********************FONCTION VALIDE TOUR *********************/
/**********************FONCTION  VALIDE TOUR *********************/
/**********************FONCTION  VALIDE TOUR *********************/

int deplacement_valide_tour(coordonnees_t d, coordonnees_t a, partie_t* partie)
{
	if(d.x==a.x)
	{
		if(a.y<d.y && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			int i;
			for(i=(d.y-1);i>a.y;i--)
			{
				if(!case_vide(partie->tablier[a.x][i]))
				{
					return FAUX;
				}
			}
		}
		else if(a.y>d.y && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			int i;
			for(i=(d.y+1);i<a.y;i++)
			{
				if(!case_vide(partie->tablier[a.x][i]))
				{
					return FAUX;
				}
			}
		}
		return VRAI;
	}
	else if(d.y==a.y)
	{
		if(a.x<d.x && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			int i;
			for(i=(d.x-1);i>a.x;i--)
			{
				if(!case_vide(partie->tablier[i][a.y]))
				{
					return FAUX;
				}
			}
		}
		else if(a.x>d.x && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			int i;
			for(i=(d.x+1);i<a.x;i++)
			{
				if(!case_vide(partie->tablier[i][a.y]))
				{
					return FAUX;
				}
			}
		}
		return VRAI;
	}
	return FAUX;
}
/**********************FONCTION VALIDE TOUR *********************/
/**********************FONCTION  VALIDE TOUR *********************/
/**********************FONCTION  VALIDE TOUR *********************/



/**********************FONCTION VALIDE HORSE *********************/
/**********************FONCTION  VALIDE HORSE *********************/
/**********************FONCTION  VALIDE HORSE *********************/

int deplacement_valide_horse(coordonnees_t d, coordonnees_t a, partie_t* partie)
{
	if(deplacement_valide_fou(d,a,partie)==FAUX)
	{
		if(d.x==a.x)
		{
			if(abs(d.y-a.y)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
			{
				return VRAI;
			}
		}
		else if(d.y==a.y)
		{
			if(abs(d.x-a.x)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
			{
				return VRAI;
			}
		}
		return FAUX;
	}
	return VRAI;
}

/**********************FONCTION VALIDE HORSE *********************/
/**********************FONCTION  VALIDE HORSE *********************/
/**********************FONCTION  VALIDE HORSE *********************/




/**********************FONCTION VALIDE DRAGON *********************/
/**********************FONCTION  VALIDE DRAGON *********************/
/**********************FONCTION  VALIDE DRAGON *********************/

int deplacement_valide_dragon(coordonnees_t d, coordonnees_t a, partie_t* partie)
{
	if(deplacement_valide_tour(d,a,partie)==FAUX)
	{
		if(abs(d.x-a.x)==abs(d.y-a.y) && abs(d.x-a.x)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			return VRAI;
		}
		return FAUX;
	}
	return VRAI;
}
/**********************FONCTION VALIDE DRAGON *********************/
/**********************FONCTION  VALIDE DRAGON *********************/
/**********************FONCTION  VALIDE DRAGON *********************/




/**********************FONCTION VALIDE ROI *********************/
/**********************FONCTION  VALIDE ROI *********************/
/**********************FONCTION  VALIDE ROI *********************/

int deplacement_valide_roi(coordonnees_t d, coordonnees_t a, partie_t *partie)
{
	if(abs(d.x-a.x)==abs(d.y-a.y) && abs(d.x-a.x)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
	{
		return VRAI;
	}
	else if(d.x==a.x)
	{
		if(abs(d.y-a.y)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			return VRAI;
		}
	}
	else if(d.y==a.y)
	{
		if(abs(d.x-a.x)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			return VRAI;
		}
	}
	return FAUX;
}
/**********************FONCTION VALIDE ROI *********************/
/**********************FONCTION  VALIDE ROI *********************/
/**********************FONCTION  VALIDE ROI *********************/


/**********************FONCTION VALIDE SILVER *********************/
/**********************FONCTION  VALIDE SILVER *********************/
/**********************FONCTION  VALIDE SILVER *********************/

int deplacement_valide_silver(coordonnees_t d, coordonnees_t a, partie_t* partie)
{
	if(abs(d.x-a.x)==abs(d.y-a.y) && abs(d.x-a.x)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
	{
		return VRAI;
	}
	else if(d.x==a.x)
	{
		if(partie->bool_joueur==JOUEUR1 && d.y==a.y+1 && partie->tablier[a.x][a.y].joueur!=JOUEUR1)
		{
			return VRAI;
		}
		else if(partie->bool_joueur==JOUEUR0 && d.y==a.y-1 && partie->tablier[a.x][a.y].joueur!=JOUEUR0)
		{
			return VRAI;
		}
	}
	return FAUX;
}
/**********************FONCTION VALIDE SILVER *********************/
/**********************FONCTION  VALIDE SILVER *********************/
/**********************FONCTION  VALIDE SILVER *********************/


/**********************FONCTION VALIDE GOLD *********************/
/**********************FONCTION  VALIDE GOLD *********************/
/**********************FONCTION  VALIDE GOLD *********************/

int deplacement_valide_gold(coordonnees_t d, coordonnees_t a, partie_t* partie)
{
	if(a.y==d.y)
	{
		if(abs(d.x-a.x)==1 && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			return VRAI;
		}	
	}
	else if(abs(a.y-d.y)==1)
	{
		if(a.x==d.x && partie->tablier[a.x][a.y].joueur!=partie->bool_joueur)
		{
			return VRAI;
		}
		else if(partie->bool_joueur==JOUEUR1 && a.x==d.x-1 && partie->tablier[a.x][a.y].joueur!=JOUEUR1)
		{
			return VRAI;
		}
		else if(partie->bool_joueur==JOUEUR0 && a.x==d.x+1 && partie->tablier[a.x][a.y].joueur!=JOUEUR0)
		{
			return VRAI;
		}
	}
	return FAUX;
}

/**********************FONCTION VALIDE GOLD *********************/
/**********************FONCTION  VALIDE GOLD *********************/
/**********************FONCTION  VALIDE GOLD *********************/



/**********************FONCTION VALIDE FOU *********************/
/**********************FONCTION  VALIDE FOU *********************/
/**********************FONCTION  VALIDE FOU *********************/

int deplacement_valide_fou(coordonnees_t depart,coordonnees_t arrivee,partie_t *partie)
{
	int i,j;
	if(partie->tablier[depart.x][depart.y].joueur == partie->tablier[arrivee.x][arrivee.y].joueur) // Si la piece qui se trouve dans les coordonnées d'arrivée est celle du joueur qui fait le deplacement
		{
			return FAUX; // alors on ne peut pas faire le deplacement
		}
	if(abs(arrivee.x-depart.x) == abs(arrivee.y-depart.y)) // Si la case d'arrivée est l'une des quatres coins d'un carré
	{
		if((arrivee.x < depart.x) && (arrivee.y < depart.y)) // si la case d'arrivée se trouve en haut a gauche
		{
			for(i=depart.x+1,j=depart.y; i>arrivee.x; i--,j--) // on parcour toutes les cases entre la case de depart et celle d'arrivée
			{
				if(!case_vide(partie->tablier[i][j])) // on verifie si la case n'est pas vide alors on peut pas faire le deplacement
				{
					return FAUX;
				}
			}
		}
		else if((arrivee.x < depart.x) && (arrivee.y > depart.y)) // si la case d'arrivée se trouve en haut a droite
		{
			for(i=depart.x-1,j=depart.y; i>arrivee.x; i--,j++)
			{
				if(!case_vide(partie->tablier[i][j]))
				{
					return FAUX;
				}
			}
		}
		else if((arrivee.x > depart.x) && (arrivee.y < depart.y)) // si la case d'arrivée se trouve en bas a gauche
		{
			for(i=depart.x+1,j=depart.y; i>arrivee.x; i++,j--)
			{
				if(!case_vide(partie->tablier[i][j]))
				{
					return FAUX;
				}
			}
		}
		else // si la case d'arrivée se trouve en bas a droite
		{
			for(i=depart.x-1,j=depart.y; i>arrivee.x; i++,j++)
			{
				if(!case_vide(partie->tablier[i][j]))
				{
					return FAUX;
				}
			}
		}
		return VRAI;
	}
	return FAUX;
}
/**********************FONCTION VALIDE FOU *********************/
/**********************FONCTION  VALIDE FOU *********************/
/**********************FONCTION  VALIDE FOU *********************/



/**********************FONCTION VALIDE CAVALIER *********************/
/**********************FONCTION  VALIDE CAVALIER *********************/
/**********************FONCTION  VALIDE CAVALIER *********************/

int deplacement_valide_cavalier(coordonnees_t depart,coordonnees_t arrivee,partie_t *partie)
{
	if((depart.y == arrivee.y+1) || (depart.y == arrivee.y-1)) // si la colonne d'arrivée est la colonne suivante gauche/droite de la colonne de depart 
	{
		if(partie->tablier[depart.x][depart.y].joueur == JOUEUR1) // le joueur 1 qui fait le deplacement
		{
			if(depart.x+2 == arrivee.x)// si la ligne d'arrivée se trouve a deux lignes de la ligne de depart 
			{
				if(partie->tablier[arrivee.x][arrivee.y].joueur != JOUEUR1)// Si la piece qui se trouve dans les coordonnées d'arrivée est celle du joueur 1
				{
					return VRAI;
				}
			}
		}
		else // le joueur 0 qui fait le deplacement
		{
			if(depart.x-2 == arrivee.x)
			{
				if(partie->tablier[arrivee.x][arrivee.y].joueur != JOUEUR0)// Si la piece qui se trouve dans les coordonnées d'arrivée est celle du joueur 0
				{
					return VRAI;
				}
			}
		}
	}
	return FAUX;
}

/**********************FONCTION VALIDE CAVALIER *********************/
/**********************FONCTION  VALIDE CAVALIER *********************/
/**********************FONCTION  VALIDE CAVALIER *********************/




/**********************FONCTION VALIDE LANCE *********************/
/**********************FONCTION  VALIDE LANCE *********************/
/**********************FONCTION  VALIDE LANCE *********************/

int deplacement_valide_lance(coordonnees_t depart,coordonnees_t arrivee,partie_t *partie)
{
	int i;
	if(arrivee.y == depart.y)
	{
		if(partie->tablier[depart.x][depart.y].joueur != partie->tablier[arrivee.x][arrivee.y].joueur)
		{
			if(partie->tablier[depart.x][depart.y].joueur == JOUEUR1)
			{
				for(i=depart.x+1; i>arrivee.x; i--)
				{
					if(!case_vide(partie->tablier[i][depart.y]))
					{
						return FAUX;
					}
				}
				return VRAI;
			}
		}
		else 
		{
			for(i=depart.x-1; i<arrivee.x; i++)
			{
				if(!case_vide(partie->tablier[i][depart.y]))
					{
						return FAUX;
					}
			}
			return VRAI;
		}
	}
	return FAUX;
}

/**********************FONCTION VALIDE LANCE *********************/
/**********************FONCTION  VALIDE LANCE *********************/
/**********************FONCTION  VALIDE LANCE *********************/




/**********************FONCTION VALIDE PION *********************/
/**********************FONCTION  VALIDE PION *********************/
/**********************FONCTION  VALIDE PION *********************/

int deplacement_valide_pion(coordonnees_t depart,coordonnees_t arrivee,partie_t *partie)
{
	if(partie->tablier[depart.x][depart.y].joueur == JOUEUR1)
	{
		if((arrivee.y == depart.y) && ((arrivee.x+1) == depart.x))
		{
			if(partie->tablier[arrivee.x][arrivee.y].joueur != JOUEUR1)
			{
				return VRAI;
			}
		}
	}
	else
	{
		if((arrivee.y == depart.y) && ((arrivee.x-1) == depart.x))
		{
			if(partie->tablier[arrivee.x][arrivee.y].joueur != JOUEUR0)
			{
				return VRAI;
			}
		}
	}
	return FAUX;
}
/**********************FONCTION VALIDE PION *********************/
/**********************FONCTION  VALIDE PION *********************/
/**********************FONCTION  VALIDE PION *********************/































