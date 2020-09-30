#pragma once

class Node {
public:

	float	key = 0.0;
	Node* left = nullptr;
	Node* right = nullptr;

	//ecrire constructeur

	Node() {
	}

	Node(float value) {
		key = value;
	}

	//ecrire destructeur
	~Node() {
		delete left;
		delete right;
	}

	Node* heapify(float newVal) {
		//newval il doit
		//garder le fait que la clé de left et la clé de right 
		//sont supérieur a la clé en cours
		if (newVal < key) {
			Node* nuNode = new Node(newVal);
			nuNode->left = this;
			return nuNode;
		}
		else {
			if (right == nullptr)
				right = new Node(newVal);
			else if (left == nullptr)
				left = new Node(newVal);
			else {//gauche est pas nul, droit est pas nul
				//le fils gauche devient le resultat de l'entassement de la nouvelle valeur dans le fils gauche
				left = left->heapify(newVal);
			}
			return this;
		}
	}

	bool isOk() {
		if (left == nullptr && right == nullptr)
			return true;
		else if (left == nullptr)
			return right->key >= key;
		else if (right == nullptr)
		{

		}
		else {

		}
	}

	Node* remove(float val) {
		//si on a est la clé, on supprime la valeur et on restructure l'arbre
		//sinon chercher a gauche 
		// chercher a droite
	}

	float getMin() {
		//la valeur la plus faible de l'arbre
		return key;
	}

	Node* deleteMin() {
		//supprime la valeur la plus faible de l'arbre
		//delete left;
	}

	Node* merge(Node* a0, Node* a1) {

	}

};