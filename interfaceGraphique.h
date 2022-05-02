#pragma once
#include <QMainWindow>
#include <QGraphicsView>

#include "interfaceEchiquier.h"

namespace Affichage
{
	class InterfaceGraphique : public QMainWindow
	{
		Q_OBJECT

	public:
		InterfaceGraphique(QWidget* parent = nullptr);
		~InterfaceGraphique();

	private:
		QGraphicsView* vue;
		InterfaceEchiquier* echiquier;
	};
}
