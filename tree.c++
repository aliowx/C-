#include <iostream>
#include <vector>
using namespace std;

class CompleteBinaryTree {
private:
    vector<int> tree;

public:

    void insert(int value) {
        tree.push_back(value);
    }

    void display() {
        cout << "Tree Elements: ";
        for (int i = 0; i < tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }


    void displayRelations() {
        for (int i = 0; i < tree.size(); i++) {
            cout << "Parent: " << tree[i];
            if (2 * i + 1 < tree.size())
                cout << ", Left Child: " << tree[2 * i + 1];
            if (2 * i + 2 < tree.size())
                cout << ", Right Child: " << tree[2 * i + 2];
            cout << endl;
        }
    }
};

int main() {
    CompleteBinaryTree tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);

    tree.display();
    tree.displayRelations();

    return 0;
}
