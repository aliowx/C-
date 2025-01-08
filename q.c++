#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};


struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};


Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;


    for (const auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }


    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}


void generateHuffmanCodes(Node* root, const string& currentCode, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (root->ch != '\0') {
        huffmanCodes[root->ch] = currentCode;
    }

    generateHuffmanCodes(root->left, currentCode + "0", huffmanCodes);
    generateHuffmanCodes(root->right, currentCode + "1", huffmanCodes);
}


string decodeHuffman(Node* root, const string& encodedData) {
    string decodedData;
    Node* current = root;

    for (char bit : encodedData) {
        current = (bit == '0') ? current->left : current->right;

        if (current->left == nullptr && current->right == nullptr) {
            decodedData += current->ch;
            current = root;
        }
    }

    return decodedData;
}

int main() {
    string data = "hello huffman";
    cout << "input Enter: " << data << endl;


    unordered_map<char, int> freqMap;
    for (char ch : data) {
        freqMap[ch]++;
    }


    Node* root = buildHuffmanTree(freqMap);


    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);


    cout << "huffman code:" << endl;
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }


    string encodedData;
    for (char ch : data) {
        encodedData += huffmanCodes[ch];
    }

    cout << "this is the data coding : " << encodedData << endl;


    string decodedData = decodeHuffman(root, encodedData);
    cout << "data about the huffman: " << decodedData << endl;

    return 0;
}
