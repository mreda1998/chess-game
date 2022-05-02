#include "interfaceGraphique.h"
#include <QDebug>

namespace Affichage
{
	Affichage::InterfaceGraphique::InterfaceGraphique(QWidget* parent) : QMainWindow(parent)
	{
		setWindowTitle("Jeu d'echec (prototype)");

		vue = new QGraphicsView(this);
		echiquier = new InterfaceEchiquier(vue);

		vue->setScene(echiquier);

		vue->setAlignment(Qt::AlignLeft | Qt::AlignTop);

		vue->centerOn(0, 0);

		vue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		vue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

		setCentralWidget(vue);
	}

	Affichage::InterfaceGraphique::~InterfaceGraphique() {
		qDebug() << "Destruction de l'interface graphique" << Qt::endl;
	}
}
