#pragma once
#include <QObject>
#include <QGraphicsRectItem>

namespace Affichage 
{
	constexpr int LONGUEUR_CASE = 60;
	constexpr int NOMBRE_CASES = 8;
	
	class InterfacePiece : public QObject, public QGraphicsRectItem
	{
		Q_OBJECT

	public:
		InterfacePiece(std::pair<int, int> position);

	protected:
		void mouseReleaseEvent(QGraphicsSceneMouseEvent* evenement) override;

	signals:
		void changementPosition(std::pair<int, int>& position);

	private:
		std::pair<int, int> positionActuelle_;
		friend class InterfaceEchiquier;
	};
}