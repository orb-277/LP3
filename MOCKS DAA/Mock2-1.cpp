#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	int frequency;
	char data;
	Node(char data, int frequency) {
		this->data = data;
		this->frequency = frequency;
		left = NULL;
		right = NULL;
	}

};


struct Compare {
	bool operator()(Node* l, Node* r) {
		return l->frequency < r->frequency;
	}
};


Node* buildHuffmanTree(string text) {
	unordered_map<char, int> freqtable;

	for (auto &i : text )
	{
		freqtable[i]++;
	}

	priority_queue<Node*, std::vector<Node*>, Compare> pq;

	for (auto &pair : freqtable) {
		pq.push(new Node(pair.first, pair.second));
	}

	while (pq.size() > 1) {
		Node* l = pq.top();
		pq.pop();
		Node* r = pq.top();
		pq.pop();

		Node* internalNode = new Node('*', l->frequency + r->frequency);
		internalNode->left = l;
		internalNode->right = r;

		pq.push(internalNode);
	}

	return pq.top();
}

void constructHuffmanCodes(Node* root, string code, unordered_map <char, string> &huffmanCodes) {
	if (root == NULL) return;
	if (root->data != '*') {
		huffmanCodes[root->data] = code;
		cout << root->data << " " << code << endl;
	}

	constructHuffmanCodes(root->left, code + "0", huffmanCodes);
	constructHuffmanCodes(root->right, code + "1", huffmanCodes);

}

string encoder(string text, unordered_map <char, string> &huffmanCodes) {
	string encodedText = "";
	for (auto &i : text) {
		encodedText += huffmanCodes[i];
	}
	return encodedText;
}

int main() {
	string inp_text = "Huffman says Hello fff";
	Node* root = buildHuffmanTree(inp_text);
	unordered_map<char, string> huffmanCodes;
	constructHuffmanCodes(root, "", huffmanCodes);
	cout << inp_text << endl;
	cout << encoder(inp_text, huffmanCodes) << endl;

}