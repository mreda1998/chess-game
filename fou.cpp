#include "fou.h"

namespace LogiqueJeu
{
	Fou::Fou(Couleur couleur) {
		couleur_ = couleur;
	}

	bool LogiqueJeu::Fou::estMouvementPossible(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition) const {
		return (abs(positionInitiale.first - nouvellePosition.first) == abs(positionInitiale.second - nouvellePosition.second));
	}
}