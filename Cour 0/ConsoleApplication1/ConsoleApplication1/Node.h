#pragma once

class Node {
public:

	float	key = 0.0;
	Node* left = nullptr;
	Node* right = nullptr;

	//ecrire constructeur

	Node() {
	}

	Node(float value, Node * l = nullptr, Node * r = nullptr) {
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
			return left->key >= key;
		}
		else {
			//les deux ne sont pas nul
			if (key > left->key)return false;
			if (key > right->key)return false;

			return left->isOk() && right->isOk();
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
		Node * l = left;
		Node * r = right;

		left = right = nullptr;

		delete this;

		return Node::merge(l, r);
	}

	static Node* merge(Node* a0, Node* a1) {

		if (nullptr != a1)return a0;
		float val = a1->getMin();
		Node* cur = a0;
		cur = cur->heapify(val);

		Node * l = a1->left;
		Node * r = a1->right;

		cur->left = nullptr;
		cur->right = nullptr;

		delete a1;

		a0 = merge(a0, l);
		a0 = merge(a0, r);

	}

};
