#include <QPen>
#include "interfacePiece.h"
#include "echiquier.h"

namespace Affichage
{
	//TODO ajouter des images différents pour les pieces
	InterfacePiece::InterfacePiece(std::pair<int, int> position) {
		setRect(0, 0, LONGUEUR_CASE, LONGUEUR_CASE);
		setPen(QPen(Qt::black));

		setBrush(QBrush(Qt::red));

		setFlag(QGraphicsItem::ItemIsMovable);
		setFlag(QGraphicsItem::ItemIsSelectable);

		positionActuelle_ = position;
	}

	void InterfacePiece::mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) {
		int x = (pos().x() + LONGUEUR_CASE / 2) - ((int(pos().x()) + LONGUEUR_CASE / 2) % LONGUEUR_CASE);
		int y = (pos().y() + LONGUEUR_CASE / 2) - ((int(pos().y()) + LONGUEUR_CASE / 2) % LONGUEUR_CASE);
		std::pair<int, int> nouvellePosition = { x / LONGUEUR_CASE + 1, 8 - y / LONGUEUR_CASE };

		LogiqueJeu::Echiquier::echiquier().deplacerPiece(positionActuelle_, nouvellePosition);

		if (LogiqueJeu::Echiquier::echiquier().prendrePiece(positionActuelle_).get() == nullptr) {
			emit changementPosition(nouvellePosition);
			setPos(x, y);
			positionActuelle_ = nouvellePosition;
		}

		else {
			setPos((positionActuelle_.first - 1) * LONGUEUR_CASE, (NOMBRE_CASES - positionActuelle_.second) * LONGUEUR_CASE);
		}

		QGraphicsRectItem::mouseReleaseEvent(evenement);
	}
}
