#pragma once
#include <QGraphicsScene>
#include "interfacePiece.h"

namespace Affichage
{
	class InterfaceEchiquier : public QGraphicsScene
	{
		Q_OBJECT

	public:
		InterfaceEchiquier(QObject* parent = nullptr);
		~InterfaceEchiquier() = default;

	public slots:
		void actualiserPosition(std::pair<int, int>& position);

	private:
		QList<InterfacePiece*> listePieces;
	};
}
