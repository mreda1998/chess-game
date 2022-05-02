/* TD6 : Programme avec l'utilisation de namespaces, d'un compteur d'instances de rois et 
 * de pointeur intelligents pour impl�menter le RAII.
 * Fichier : main.cpp
 * Auteurs : Reda Rhanmouni,	2087548,
 *			 Huy Viet Nguyen,	2136378
 * Date : 25 avril 2022
 */

#include "roi.h"
#include "reine.h"
#include "tour.h"
#include "fou.h"
#include "cavalier.h"
#include "pion.h"

#include "interfaceGraphique.h"
#include "echiquier.h"

#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <stdexcept>

#if __has_include("bibliotheque_cours.hpp")
#include "bibliotheque_cours.hpp"
#define BIBLIOTHEQUE_COURS_INCLUS
using bibliotheque_cours::cdbg;
#else
auto& cdbg = clog;
#endif

#if __has_include("verification_allocation.hpp")
#include "verification_allocation.hpp"
#include "debogage_memoire.hpp"  //NOTE: Incompatible avec le "placement new", ne pas utiliser cette ent�te si vous utilisez ce type de "new" dans les lignes qui suivent cette inclusion.
#endif

void initialiserBibliothequeCours([[maybe_unused]] int argc, [[maybe_unused]] char* argv[])
{
#ifdef BIBLIOTHEQUE_COURS_INCLUS
	bibliotheque_cours::activerCouleursAnsi();  // Permet sous Windows les "ANSI escape code" pour changer de couleurs https://en.wikipedia.org/wiki/ANSI_escape_code ; les consoles Linux/Mac les supportent normalement par d�faut.

	// cdbg.setTee(&clog);  // D�commenter cette ligne pour que cdbg affiche sur la console en plus de la "Sortie" du d�bogueur.

	bibliotheque_cours::executerGoogleTest(argc, argv); // Attention de ne rien afficher avant cette ligne, sinon l'Explorateur de tests va tenter de lire votre affichage comme un r�sultat de test.
#endif
//NOTE: C'est normal que la couverture de code dans l'Explorateur de tests de Visual Studio ne couvre pas la fin de cette fonction ni la fin du main apr�s l'appel � cette fonction puisqu'il ex�cute uniquement les tests Google Test dans l'appel ci-dessus.
}

int main(int argc, char* argv[])
{
	//Attention, l'impl�mentation du move et du make_unique fait appel au destructeur lors de l'ajout de piece. 
	//N. B. L'�chiquier est un singleton.
	cout << "Ajout d'un roi blanc a la position a1" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc)), pair<int, int> {1, 1});

	cout << "Ajout d'une reine en b1" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Noir)), pair<int, int> {2, 1});

	cout << "Ajout d'une tour en g1" << endl;
	LogiqueJeu::Echiquier::echiquier().ajouterPiece(make_unique<LogiqueJeu::Reine>(LogiqueJeu::Reine(Couleur::Blanc)), pair<int, int> {7, 1});

	QApplication jeu(argc, argv);
	Affichage::InterfaceGraphique interface(nullptr);

	//Il devrait y avoir trois pi�ces (carr�s rouges) : un roi blanc en a1 et une reine noire en b1 et une tour blanche en g1 
	//qui peuvent �tre d�plac�s. Les captures sont impl�ment�es, mais pas les �checs ou les tours de jeu. La capture
	//d�truit l'objet en question � la fois dans la vue et le mod�le (l'�chiquier), et d�salloue la m�moire.
	interface.show();

	//Test Exception
	try {
		cout << "Creation d'un deuxieme roi" << endl;
		unique_ptr<LogiqueJeu::Roi> roi2 = make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Blanc));
		cout << "Tentative de creation d'un troisieme roi" << endl;
		unique_ptr<LogiqueJeu::Roi> roi3 = make_unique<LogiqueJeu::Roi>(LogiqueJeu::Roi(Couleur::Noir));
	}

	catch (logic_error& e) {
		cout << "Erreur " << e.what() << endl;
	}
	
	return jeu.exec();
}