#ifndef PIECE_H
#define PIECE_H
#define JOUEUR_1 1
#define JOUEUR_0 0
#define JOUEUR_VIDE -1
#define VIDE -1
#define PROMUE 1
#define NON_PROMUE 0
#define PION 1
#define CAVALIER 2
#define ROI 3
#define TOUR 4
#define FOU 5
#define LANCE 6
#define OR 7
#define ARGENT 8

typedef struct piece piece;
struct piece
{
	 int joueur;
	char type;
	int statut;
};
piece piece_creer(int joueur, char type,  int statut);

 int piece_joueur(piece p);

piece piece_identifier(char c);

char piece_caractere(piece p);

void piece_afficher(piece p);

#endif
