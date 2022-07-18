template <class V>
class Tree {
private:
	struct Node {
		Node(V v, shared_ptr<Node>& l, shared_ptr <Node>& r) : value(v), left(l), right(r) {}
		V value;
		shared_ptr <Node>& left;
		shared_ptr <Node>& right;
	};
	explicit Tree(shared_ptr <Node> & node) : root(node) {}
	shared_ptr <Node> root;
public:
	Tree() {}
	Tree(Tree const & lft, V value, Tree const & rgt) :
		root(Node(val, lft ->root, rgt.root)) {}
	bool isEmpty() const;
	V root() const;
	Tree* left() const;
	Tree* right() const;
	bool member(V x) const;
	bool isLeaf() const;

	bool Tree::isEmpty const{ return !root };

	template<typename V>
	V Tree::root() const {
		return root->val;
	}

	template <typename V>
	Tree& Tree::left() const {
		return Tree(root->left);
	}

	Tree& Tree::right() const {
		return Tree(root->right)
	}
}