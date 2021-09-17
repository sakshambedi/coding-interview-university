#include <string>
#include <unordered_map>

namespace huffman {
class Huffman {
 private:
  struct node {
    char ch;
    int freq;
    node *right, *left;
  };
  node *getNode(char input_char, int input_freq, node *right, node *left) {
    node *r_node = new node;
    r_node->ch = input_char;
    r_node->freq = input_freq;
    r_node->right = right;
    r_node->left = left;
    return r_node;
  }

  struct comp {
    bool operator()(const node *ipt_left, node *ipt_right) {
      return ipt_left->freq > ipt_right->freq;
    }
  };
  void encode(node *root, std::string,
              std::unordered_map<char, std::string> &huffmanCode);
  void decode(node *root, int &index, std::string str);

 public:
  Huffman(const std::string text);
};

};  // namespace huffman