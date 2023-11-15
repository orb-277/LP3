#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Node structure for Huffman tree
struct Node {
    char data;
    unsigned freq;
    Node *left, *right;

    Node(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to build Huffman tree
Node* buildHuffmanTree(const string& text) {
    // Count the frequency of each character
    unordered_map<char, unsigned> freq;
    for (char c : text) {
        freq[c]++;
    }

    cout << "Frequency Table:\n";
    for (auto& pair : freq) {
        cout << pair.first << ": " << pair.second << " times\n";
    }
    cout << "-----------------\n";

    // Create a priority queue to store the nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto& pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    // The top of the priority queue contains the root of the Huffman tree
    return pq.top();
}

// Function to print the codes for each character in the Huffman tree
void printCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != '$') {
        huffmanCodes[root->data] = code;
        cout << "Huffman Code for " << root->data << ": " << code << "\n";
    }

    printCodes(root->left, code + "0", huffmanCodes);
    printCodes(root->right, code + "1", huffmanCodes);
}

// Function to encode the text using the Huffman codes
string encode(const string& text, unordered_map<char, string>& huffmanCodes) {
    string encodedText = "";
    for (char c : text) {
        encodedText += huffmanCodes[c];
    }
    return encodedText;
}

// Function to decode the encoded text using the Huffman tree
string decode(Node* root, const string& encodedText) {
    string decodedText = "";
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedText += current->data;
            current = root;
        }
    }
    return decodedText;
}

int main() {
    string text = "Huffman says Hello fff";

    // Build Huffman tree
    Node* root = buildHuffmanTree(text);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCodes;
    printCodes(root, "", huffmanCodes);

    // Encode the text
    string encodedText = encode(text, huffmanCodes);
    cout << "Encoded text: " << encodedText << endl;

    // Decode the text
    string decodedText = decode(root, encodedText);
    cout << "Decoded text: " << decodedText << endl;


    // Clean up memory
    // You should implement a proper cleanup function to delete the allocated nodes in a real-world application
    return 0;
}
