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
		//garder le fait que la cl� de left et la cl� de right 
		//sont sup�rieur a la cl� en cours
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
		Node * cur = this;
		
		if (val == key) 
			cur = cur->deleteMin();
		if (cur == nullptr) return nullptr;

		if (cur->left)cur->left = cur->left->remove(val);
		if (cur->right)cur->right = cur->right->remove(val);

		return cur;
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

		if (l == nullptr)return r;
		if (r == nullptr)return l;

		return Node::merge(l, r);
	}

	static Node* merge(Node* a0, Node* a1) {

		if (a0 == nullptr)return a0;
		if (a1 == nullptr)return a0;

		float val = a1->getMin();
		Node* cur = a0;
		cur = cur->heapify(val);

		Node * l = a1->left;
		Node * r = a1->right;

		a1->left = nullptr;
		a1->right = nullptr;

		delete a1;

		cur = merge(cur, l);
		cur = merge(cur, r);

		return cur;

	}

	static Node* fromTabRec(float* t, int tlen) {
		if (!tlen)return nullptr;
		Node* cur = new Node(t[0]);
		if (tlen > 1) {
			cur->merge(cur, fromTabRec(t + 1, tlen - 1));
			return cur;
		}
	}

	static Node* fromTab(float* t, int tlen) {
		if (!tlen)return nullptr;
		Node* root = new Node(t[0]);

		if (tlen > 1) {
			for (int i = 1; i < tlen; ++i) {
				root->heapify(t[i]);
			}
		}
		return root;
	}
};
