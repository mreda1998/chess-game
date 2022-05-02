#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Fou : public Piece
	{
	public:
		Fou(Couleur couleur);

	protected:
		bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition) const override;
	};
}
