
#include "interfaceEchiquier.h"
#include "echiquier.h"


	void Affichage::InterfaceEchiquier::actualiserPosition(pair<int, int>& position) {
		for (InterfacePiece* piece : listePieces) {
			if (piece->positionActuelle_ == position) {
				delete piece;
				break;
			}
		}
	}

	Affichage::InterfaceEchiquier::InterfaceEchiquier(QObject* parent) : QGraphicsScene(parent) {
		for (int i = 0; i <= NOMBRE_CASES; i++) {
			addLine(0, i * LONGUEUR_CASE, NOMBRE_CASES * LONGUEUR_CASE, i * LONGUEUR_CASE, QPen(Qt::gray));
			addLine(i * LONGUEUR_CASE, 0, i * LONGUEUR_CASE, NOMBRE_CASES * LONGUEUR_CASE), QPen(Qt::gray);
		}

		for (auto& element : LogiqueJeu::Echiquier::echiquier()) {
			if (element.second.get() != nullptr)
			{
				InterfacePiece* interfacePiece = new InterfacePiece(element.first);
				interfacePiece->setPos((element.first.first - 1) * LONGUEUR_CASE, (NOMBRE_CASES - element.first.second) * LONGUEUR_CASE);
				listePieces.append(interfacePiece);
				addItem(interfacePiece);

				QObject::connect(interfacePiece, &InterfacePiece::changementPosition, this, &InterfaceEchiquier::actualiserPosition);
			}
		}
	}
