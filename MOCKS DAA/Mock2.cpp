#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	char data;
	int frequency;
	Node* left;
	Node* right;
	Node() {
		this->data = ' ';
		this->frequency = -1;
		this->left = NULL;
		this->right = NULL;
	}
	Node(char data, int frequency) {
		this->data = data;
		this->frequency = frequency;
		this->left = NULL;
		this->right = NULL;
	}

};
struct Compare {
	bool operator()(Node* l, Node* r) {
		return l->frequency > r->frequency;
	}

};

Node* buildHuffmanTree(const string text) {
	unordered_map <char, int> freqtable;
	for (auto &i : text)
	{
		freqtable[i]++;
	}
	cout << "-----------------------" << endl;
	for (auto &pair : freqtable) {
		cout << pair.first << ":" << pair.second << endl;

	}
	cout << "-----------------------" << endl;
	priority_queue<Node*, vector<Node*>, Compare> pq;
	for (auto &pair : freqtable) {
		pq.push(new Node(pair.first, pair.second));
	}

	while (pq.size() > 1) {
		Node * left = pq.top();
		pq.pop();
		Node * right = pq.top();
		pq.pop();

		Node* x = new Node('*', left->frequency + right->frequency);
		x->left = left;
		x->right = right;

		pq.push(x);
	}

	return pq.top();
}

void HuffmanCodes(Node* root, string code, unordered_map <char, string>& huffmanCodes) {
	if (root == NULL) {
		return;
	}
	if (root->data != '*') {
		huffmanCodes[root->data] = code;
		cout << "Huffman Code for " << root->data << ": " << code << "\n";
	}
	HuffmanCodes(root->left, code + "0", huffmanCodes);
	HuffmanCodes(root->right, code + "1", huffmanCodes);
}

string encode(const string& text, unordered_map<char, string>& huffmanCodes) {
	string encodedText = "";
	for (char c : text) {
		encodedText += ' ';
		encodedText += huffmanCodes[c];
	}
	return encodedText;
}

int main() {
	string text = "Huffman says Hello fff";

	// Build Huffman tree
	Node* root = buildHuffmanTree(text);

	// Generate Huffman codes
	unordered_map<char, string> huffmanCodes;
	HuffmanCodes(root, "", huffmanCodes);

	// Encode the text
	string encodedText = encode(text, huffmanCodes);
	cout << "Encoded text: " << encodedText << endl;





	return 0;
}