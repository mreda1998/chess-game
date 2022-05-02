#pragma once
#include <utility>
#include <map>
#include <memory>
#include "piece.h"

namespace LogiqueJeu 
{
	using PointeurPiece = std::unique_ptr<LogiqueJeu::Piece>;
	using GrilleEchiquier = std::map<std::pair<int, int>, PointeurPiece>;
	using IterateurGrilleEchiquier = GrilleEchiquier::iterator;

	class Echiquier
	{
	public:
		static Echiquier& echiquier();

		PointeurPiece& prendrePiece(pair<int, int> position);
		void ajouterPiece(PointeurPiece piece, pair<int, int> position);
		void deplacerPiece(pair<int, int>& positionInitiale, pair<int, int>& nouvellePosition);
	
		IterateurGrilleEchiquier begin();
		IterateurGrilleEchiquier end();

	private:
		Echiquier() = default;

		bool verifierObstacle(const pair<int, int>& positionInitiale, const pair<int, int>& nouvellePosition);
		GrilleEchiquier grille_;
		const static int taille_ = 8;
	};
}