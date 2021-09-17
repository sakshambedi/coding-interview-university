#include "./huffman.h"

#include <iostream>
#include <queue>
#include <vector>

using namespace huffman;
namespace huffman {
Huffman::Huffman(const std::string text) {
  // counting the number of times a character is repeated and storing its
  // frequency
  std::unordered_map<char, int> frequency;
  for (char x : text) frequency[x]++;

  std::priority_queue<node *, std::vector<node *>, comp> pq;
  // Create a leaf node for each character and add it
  // to the priority queue.
  for (auto pair : frequency)
    pq.push(getNode(pair.first, pair.second, nullptr, nullptr));

  while (pq.size() != 1) {
    // Remove the two nodes of highest priority
    // (lowest frequency) from the queue
    node *left = pq.top();
    pq.pop();
    node *right = pq.top();
    pq.pop();

    // Create a new internal node with these two nodes
    // as children and with frequency equal to the sum
    // of the two nodes' frequencies. Add the new node
    // to the priority queue.
    int sum = left->freq + right->freq;
    pq.push(getNode('\0', sum, left, right));
  }
  node *root = pq.top();

  // traverse the Huffman Tree and store Huffman Codes
  // in a map. Also prints them
  std::unordered_map<char, std::string> huffmanCode;
  encode(root, "", huffmanCode);

  std::cout << "Huffman Codes are :\n" << '\n';
  for (auto pair : huffmanCode) {
    std::cout << pair.first << " " << pair.second << '\n';
  }

  std::cout << "\nOriginal string was :\n" << text << '\n';

  // print encoded string
  std::string str = "";
  for (char ch : text) {
    str += huffmanCode[ch];
  }

  std::cout << "\nEncoded string is :\n" << str << '\n';

  // traverse the Huffman Tree again and this time
  // decode the encoded string
  int index = -1;
  std::cout << "\nDecoded string is: \n";
  while (index < (int)str.size() - 2) {
    decode(root, index, str);
  }
  std::cout << std::endl;
}

void Huffman::encode(node *root, std::string str,
                     std::unordered_map<char, std::string> &huffmanCode) {
  if (root == nullptr) return;

  // found a leaf node
  if (!root->left && !root->right) {
    huffmanCode[root->ch] = str;
  }

  encode(root->left, str + "0", huffmanCode);
  encode(root->right, str + "1", huffmanCode);
  return;
}

void Huffman::decode(node *root, int &index, std::string str) {
  if (root == nullptr) {
    return;
  }

  // found a leaf node
  if (!root->left && !root->right) {
    std::cout << root->ch;
    return;
  }

  index++;

  if (str[index] == '0')
    decode(root->left, index, str);
  else
    decode(root->right, index, str);
  return;
}

};  // namespace huffman

int main() {
  std::string text = "Huffman coding is a data compression algorithm.";
  Huffman enc(text);

  std::string tempString = "sexySaks is the best\ts";
  Huffman lo(tempString);
  return 0;
}
