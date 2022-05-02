#pragma once
#include <utility>
using namespace std;

enum class Couleur {
	Blanc,
	Noir
};

namespace LogiqueJeu 
{
	class Piece
	{
	public:
		virtual ~Piece();

	protected:
		virtual bool estMouvementPossible(pair<int, int>& positionInitiale,
			pair<int, int>& nouvellePosition) const = 0;

		Couleur couleur_;

	private:
		friend class Echiquier;
	};
}
