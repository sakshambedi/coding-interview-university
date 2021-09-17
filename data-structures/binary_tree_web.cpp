#include <iostream>
#include <memory>  // unique_ptr
#include <queue>
#include <string>

/**
 * @brief Binary Search Tree implementation
 * source : unkown for now
 *
 */
template <typename T>
class BSTree {
 public:
  // constructors
  BSTree() : root(nullptr) {}

  // member functions
  void Print() const;
  void Insert(T val);
  bool Contains(T val) const;
  void Remove(T val);

 private:
  struct TreeNode {
    // member vars
    T data;
    std::unique_ptr<TreeNode> left;
    std::unique_ptr<TreeNode> right;

    // constructor
    TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
  };

  std::unique_ptr<TreeNode> root;
  std::string SubTreeAsString(const std::unique_ptr<TreeNode> &node)
      const;  // Helper method for Print()
  void Insert(
      T val,
      std::unique_ptr<TreeNode> &node);  // Helper method for Insert(int val)
  bool Contains(T val, std::unique_ptr<TreeNode> &node)
      const;  // Helper method for Contains(int val)
  void Remove(
      T val,
      std::unique_ptr<TreeNode> &node);  // Helper method for Remove(int val)
  std::unique_ptr<TreeNode> &FindMin(
      std::unique_ptr<TreeNode> &node);  // Helper method for Remove(int val)
  void preOrderTranversal(const std::unique_ptr<TreeNode> &node) const;
  void postOrderTranversal(const std::unique_ptr<TreeNode> &node) const;
  void inOrderTranversal(const std::unique_ptr<TreeNode> &node) const;
  void BFSTranversal(const std::unique_ptr<TreeNode> &node) const;
  int height(const std::unique_ptr<TreeNode> &node) const;
  void printCurrentLevel(const std::unique_ptr<TreeNode> &node,
                         int level) const;
};

/// Print the tree
template <typename T>
void BSTree<T>::Print() const {
  if (this->root == nullptr) {
    std::cout << "{}" << std::endl;
  } else {
    std::cout << "\nPre-order : " << std::endl;
    this->preOrderTranversal(this->root);
    std::cout << "\nPost-order : " << std::endl;
    this->postOrderTranversal(this->root);
    std::cout << "\nIN-order : " << std::endl;
    this->inOrderTranversal(this->root);
    std::cout << "\nBFS : " << std::endl;
    this->BFSTranversal(this->root);
    std::cout << std::endl;
    // std::cout << this->SubTreeAsString(this->root) << std::endl;
  }
}

// Depth First Tranversal
/**
 * @brief Print preorder transversal for the tree. Refer
 * https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 * for explanation
 *
 * @tparam T
 * @param node
 */
template <typename T>
void BSTree<T>::preOrderTranversal(
    const std::unique_ptr<TreeNode> &node) const {
  if (node == nullptr) return;
  std::cout << std::to_string(node->data) << " ";
  this->preOrderTranversal(node->left);
  this->preOrderTranversal(node->right);
}
/**
 * @brief Print postorder transversal for the tree. Refer
 * https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 * for explanation
 *
 * @tparam T
 * @param node
 */
template <typename T>
void BSTree<T>::postOrderTranversal(
    const std::unique_ptr<TreeNode> &node) const {
  if (node == nullptr) return;
  this->postOrderTranversal(node->left);
  this->postOrderTranversal(node->right);
  std::cout << std::to_string(node->data) << " ";
}

/**
 * @brief Print inorder transversal for the tree. Refer
 * https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 * for explanation
 *
 * @tparam T
 * @param node
 */
template <typename T>
void BSTree<T>::inOrderTranversal(const std::unique_ptr<TreeNode> &node) const {
  if (node == nullptr) return;
  this->inOrderTranversal(node->left);
  std::cout << std::to_string(node->data) << " ";
  this->inOrderTranversal(node->right);
}

// Breadth first Tranversal
/**
 * @brief Breadth first transversal for the Binary Search tree
 *
 * @tparam T
 * @param node
 */
template <typename T>
void BSTree<T>::BFSTranversal(const std::unique_ptr<TreeNode> &node) const {
  if (node == nullptr) return;

  int h = height(root);
  for (int i = 0; i <= h; i++) {
    printCurrentLevel(node, i);
  }
}

/**
 * @brief Print the node at the current level
 *
 * @tparam T
 * @param node
 * @param level
 */
template <typename T>
void BSTree<T>::printCurrentLevel(const std::unique_ptr<TreeNode> &node,
                                  const int level) const {
  if (node == nullptr) return;
  if (level == 1)
    std::cout << node->data << " ";
  else if (level > 1) {
    printCurrentLevel(node->left, level - 1);
    printCurrentLevel(node->right, level - 1);
  }
}

/**
 * @brief Calculate the max height of the sub-tree from a input node
 *
 * @tparam T
 * @param node : std::unique_ptr<TreeNode>
 * @return int
 */
template <typename T>
int BSTree<T>::height(const std::unique_ptr<TreeNode> &node) const {
  if (node == nullptr)
    return 0;
  else {
    /* compute the height of each subtree */
    int lheight = height(node->left);
    int rheight = height(node->right);

    /* use the larger one */
    return lheight > rheight ? lheight + 1 : rheight + 1;
  }
}

/// Print the subtree starting at node
template <typename T>
std::string BSTree<T>::SubTreeAsString(
    const std::unique_ptr<TreeNode> &node) const {
  std::string leftStr =
      (node->left == nullptr) ? "{}" : SubTreeAsString(node->left);
  std::string rightStr =
      (node->right == nullptr) ? "{}" : SubTreeAsString(node->right);
  std::string result =
      "{" + std::to_string(node->data) + ", " + leftStr + ", " + rightStr + "}";
  return result;
}

/// Insert a new value into the tree
template <typename T>
void BSTree<T>::Insert(T val) {
  this->Insert(val, this->root);
}

/// Insert a new value into the subtree starting at node
template <typename T>
void BSTree<T>::Insert(T val, std::unique_ptr<TreeNode> &node) {
  if (node == nullptr) {
    // Case: node is a nullptr
    // Make a new TreeNode for it to point to
    node = std::make_unique<TreeNode>(val);
  } else {
    if (val < node->data) {
      // Case: val is < node's data
      this->Insert(val, node->left);
    } else if (val > node->data) {
      // Case: val is > node's data
      this->Insert(val, node->right);
    } else {
      // Case: val is equal to node's data
      std::cout << "Warning: Value already exists, so nothing will be done."
                << std::endl;
    }
  }
}

/// Check if the given value exists in the BSTree
template <typename T>
bool BSTree<T>::Contains(T val) const {
  return Contains(val, this->root);
}

/// Check if the given value exists in the subtree
/// starting at node
template <typename T>
bool BSTree<T>::Contains(T val, std::unique_ptr<TreeNode> &node) const {
  if (node == nullptr) {
    return false;
  } else if (val == node->data) {
    return true;
  } else if (val < node->data) {
    return this->Contains(val, node->left);
  } else {
    return this->Contains(val, node->right);
  }
}

/// Remove given value from the tree
template <typename T>
void BSTree<T>::Remove(T val) {
  this->Remove(val, this->root);
}

/// Remove given value from the subtree starting at node
template <typename T>
void BSTree<T>::Remove(T val, std::unique_ptr<TreeNode> &node) {
  if (node == nullptr) {
    // Case: nullptr

    std::cout << "val not found in tree" << std::endl;

  } else if (val == node->data) {
    // Found value

    if (node->left == nullptr && node->right == nullptr) {
      // Case: node is a leaf

      node = nullptr;

    } else if (node->left != nullptr && node->right == nullptr) {
      // Case: node has a left subtree (but not right)
      // Point node's parent at node's left subtree

      node = std::move(node->left);

    } else if (node->left == nullptr && node->right != nullptr) {
      // Case: node has a right subtree (but not left)

      node = std::move(node->right);

    } else {
      // Case: node has left and right subtrees

      std::unique_ptr<TreeNode> &minNode =
          this->FindMin(node->right);  // returns a reference to the actual
                                       // pointer in the tree
      node->data = minNode->data;
      this->Remove(minNode->data, minNode);
    }

  } else if (val < node->data) {
    // Case: remove val from this node's left subtree
    this->Remove(val, node->left);
  } else {
    // Case: remove val from this node's right subtree
    this->Remove(val, node->right);
  }
}

/// Search the subtree starting at node and return a pointer to the
/// minimum-value node The returned pointer will be a reference of an actual
/// pointer in the tree, not a copy
template <typename T>
std::unique_ptr<typename BSTree<T>::TreeNode> &BSTree<T>::FindMin(
    std::unique_ptr<TreeNode> &node) {
  if (node == nullptr) {
    throw "Min value not found";
  } else if (node->left == nullptr) {
    return node;
  } else {
    return this->FindMin(node->left);
  }
}

int main() {
  BSTree<int> bt;
  bt.Insert(25);
  bt.Insert(50);
  bt.Insert(15);
  bt.Insert(70);
  bt.Insert(35);
  bt.Insert(44);
  bt.Insert(31);
  bt.Insert(66);
  bt.Insert(90);
  bt.Insert(10);
  bt.Insert(22);
  bt.Insert(4);
  bt.Insert(12);
  bt.Insert(18);
  bt.Insert(24);
  bt.Print();
  return 1;
}
