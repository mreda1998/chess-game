#include "echiquier.h"

int calculerDirection(int valeurInitiale, int nouvelleValeur);

namespace LogiqueJeu 
{
	Echiquier& Echiquier::echiquier() {
		static Echiquier echiquier;
		return echiquier;
	}

	PointeurPiece& Echiquier::prendrePiece(pair<int, int> position) {
		return grille_[position];
	}

	void Echiquier::ajouterPiece(PointeurPiece piece, pair<int, int> position) {
		grille_[position] = move(piece);
	}

	void Echiquier::deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) {
		PointeurPiece& piece = prendrePiece(positionInitiale);

		if (piece->estMouvementPossible(positionInitiale, nouvellePosition))
		{
			if (!verifierObstacle(positionInitiale, nouvellePosition))
			{
				const PointeurPiece& autrePiece = prendrePiece(nouvellePosition);
				if (autrePiece != nullptr)
				{
					if (autrePiece->couleur_ != piece->couleur_) {
						grille_[nouvellePosition] = move(piece);
					}
				}

				else {
					grille_[nouvellePosition] = move(piece);
				}
			}
		}
	}

	IterateurGrilleEchiquier Echiquier::begin() {
		return grille_.begin();
	}

	IterateurGrilleEchiquier Echiquier::end() {
		return grille_.end();
	}

	bool Echiquier::verifierObstacle(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition)
	{
		//TODO: Si c'est un cheval, passer la vérification.

		const int directionHorizontale = calculerDirection(positionInitiale.first, nouvellePosition.first);
		const int directionVerticale = calculerDirection(positionInitiale.second, nouvellePosition.second);
		int x = positionInitiale.first;
		int y = positionInitiale.second;

		while (true) {
			x += directionHorizontale;
			y += directionVerticale;

			if (nouvellePosition == pair<int, int>{x, y})
				break;

			else if (grille_[{ x, y }] != nullptr)
				return true;
		}

		return false;
	}
}

int calculerDirection(int valeurInitiale, int nouvelleValeur) 
{
	const int variation = nouvelleValeur - valeurInitiale;

	return (variation == 0) ? 0 : variation / abs(variation);
}
