// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include "Vec2.hpp"
#include "Vec2T.h"
#include "Vec3T.h"
#include "Arr.h"
#include <string>

using namespace std;

void subFunction(){

	/* suprrime
	
	Vec2 sapin(77);
	Vec2* sapinPtr = new Vec2(66);
	
	delete sapinPtr;*/


	Arr<int> foo(4);

	cout << foo.get(0) << endl;
	foo.get(0) = 33;
	cout << foo.get(0) << endl;

}


int main()
{
	subFunction();

	//char * tab = new char[1024 * 1024 * 1024]; // allouer 1 Gigat

	/* affiche les valeurs des vecteurs

	Vec2 toto(66, 67);

	Vec2T<int> t0(4, 4);
	Vec2T<int> t1(4, 4);

	auto tres = t1.add(t0); 
	cout << to_string(tres.x) << endl;

	Vec2T<float> t3(2.6, 4.9);
	Vec2T<float> t4(7.2, 1.8);

	auto tres1 = t4.add(t3);

	Vec2T<char> vc0('a', 'b');
	Vec2T<char> vc1('d', 'e');

	auto vcres = vc1.add(vc0);

	cout << string(1, 'a') << endl;
	cout << string(1, vcres.x) << " " << string(1, vcres.y) << endl;
	auto end = 0;


	Vec3T<int> t5(5, 5, 5);
	Vec3T<int> t6(5, 5, 5);

	auto tres2 = t5.add(t6);
	
	Vec3T<float> t7(7.2, 5.1, 4.3);
	Vec3T<float> t8(1.5, 0.8, 9.4);

	auto tres3 = t8.add(t7);*/


	//---------------------------------------------------------------------------------------


	/*affiche les valeurs du tableau ,la taille du tableau et l'emplacament du pointeur dans la mémoire

	int tab[] = { 0,1,2,3 };
	int szTab = sizeof(tab) / sizeof(int);  // taille du tableau

	for (int i = 0; i < szTab; i++) {
		cout << tab[i];
	}

	int* c0 = tab;
	int* c1 = &(tab[0]);

	int valC = *c0++;*/

	cout << endl;
}	

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
