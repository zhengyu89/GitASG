//Program 1 
/*Group Member List 
Member Name 1: CHANG WEI LAM
Matric Number: A23CS0212
Section: 09
Member Name 2: KAREN VOON XIU WEN
Matric Number: A23CS0229
Section: 09
Member Name 3: TAN ZHENG YU
Matric Number: A23CS5017
Section: 09
*/ 
#include <iostream>
#include <iomanip>
using namespace std;

class ItemNode{
    public:
    string name;
    float price;
    ItemNode* aft;
    ItemNode* bef;

    ItemNode(string n="", float p=0.0){
        name=n;
        price=p;
        aft=NULL;
        bef=NULL;
    };

};

class List{
    private:
    ItemNode* head;
    ItemNode* tail;
    public:
    void task1(ItemNode*);
    void task2(ItemNode*);
    void task3();
    void task4(ItemNode*,int);
    void task5(int);
    void task6();
};

// Task 1
void List:: task1(ItemNode* N){
    head = N;
    tail = N;
    N->aft = NULL;
    N->bef = NULL;
}

//Task 2
void List::task2(ItemNode* N){
    N->aft = head;
    head->bef = N;
    N->bef = NULL;
    head = N;
}

//Task3
void List::task3(){
    ItemNode* currNode = tail;
    cout<<"Print backward:"<<endl;
    while(currNode != NULL){
        cout << "[" << currNode->name;
        cout << "\t" << currNode->price << "]\t";
        currNode = currNode->bef;
    }
    cout<<endl<<endl;
}

//Task 4
void List::task4(ItemNode* n,int position){
        ItemNode* currNode = head;
        int currIndex = 1;

        while (currNode && currIndex < position) {
            currNode = currNode->aft;
            currIndex++;
        }

        // If ending
        if (currNode == NULL) {
            // Insert at the end
            tail->aft = n;
            n->bef = tail;
            tail = n;
            return;
        }
        n->aft = currNode;
        n->bef = currNode->bef;

        // Update previous node's pointer
        if (currNode->bef) {
            currNode->bef->aft = n;
        } else {
            // If inserting at the head
            head = n;
        }

        // Update current node's previous pointer
        currNode->bef = n;
}

//Task 5
void List::task5(int x){
    if (head == NULL) return;

    ItemNode* currNode = head;
    int currIndex = 1;

    // Move cursor
    while (currNode && currIndex < x) {
        currNode = currNode->aft;
        currIndex++;
    }

    // If index out of bounds
    if (!currNode) return;

    // Delete head
    if (currNode == head) {
        head = currNode->aft;
        if (head) head->bef = NULL;
        else tail = NULL; 
    }
    // Delete tail
    else if (currNode == tail) {
        tail = currNode->bef;
        if (tail) tail->aft = NULL;
        else head = NULL; 
    }
    // Deleting middle node
    else {
        currNode->bef->aft = currNode->aft;
        currNode->aft->bef = currNode->bef;
    }

    delete currNode;
}

//Task 6
void List::task6() {
    // If list is empty
    if (tail == NULL) {
        cout << "List is empty. Cannot delete." << endl;
        return;
    }

    // If only one node
    if (head == tail) {
        delete tail;
        head = NULL;
        tail = NULL;
        return;
    }

    // Multiple nodes
    ItemNode* temp = tail;
    tail = tail->bef;
    
    // Update the new tail's aft pointer
    if (tail != NULL) {
        tail->aft = NULL;
    }
    else
        head=NULL;

    // Delete the last node
    delete temp;
}

int main() { 
    List ItemList; 
    ItemNode *n1 = new ItemNode("Book", 9.59); 
    ItemNode *n2 = new ItemNode("Ruler", 3.45); 
    ItemNode *n3 = new ItemNode("Pen", 5.69); 
    ItemNode *n4 = new ItemNode("Eraser", 2.25); 
    cout << fixed << setprecision(2) << left; 
    ItemList.task1(n1); 
    ItemList.task2(n2); 
    ItemList.task3(); 
    ItemList.task4(n3, 2); 
    ItemList.task4(n4, 2); 
    ItemList.task3(); 
    ItemList.task5(3); 
    ItemList.task3(); 
    ItemList.task6(); 
    ItemList.task3(); 
    return 0; 
}