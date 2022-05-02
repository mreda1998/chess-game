#pragma once
#include "piece.h"
#include <iostream>

LogiqueJeu::Piece::~Piece() {
	cout << "Destruction de piece" << endl;
}
