#include <iostream>

using namespace std;

struct Node {
    int mItem;
    Node *mNext;
    Node(int item, Node *next)
    {
        mItem = item;
        mNext = next;
    };
};

int main()
{
    cout << "Vvedit kilkist lyudey ta interval vidalennya: ";
    int N, M;
    cin >> N >> M;
    Node* first = new Node(1, 0);
    first->mNext = first;
    Node* temp = first;
    cout << "Vidaleni elementi: \n";
    for (int i = 2; i <= N; i++) {
        temp->mNext = new Node(i, first);
        temp = temp->mNext;
    }
    while (temp != temp->mNext) {
        for (int i = 1; i < M; i++) {
            temp = temp->mNext;
        }
        Node* deleteNode = temp->mNext;
        temp->mNext = temp->mNext->mNext;

        cout << deleteNode->mItem << "\n";
        delete deleteNode;
    }
    cout << "Zalishivsya element: " << temp->mItem;
}

