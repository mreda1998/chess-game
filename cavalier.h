#pragma once
#include "piece.h"

namespace LogiqueJeu
{
	class Cavalier : public Piece
	{
	public:
		Cavalier(Couleur couleur);

	protected:
		bool estMouvementPossible(pair<int, int>& positionInitile,
			pair<int, int>& nouvellePosition) const override;
	};
}
