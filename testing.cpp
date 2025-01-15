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

void List::task2(ItemNode* N){
    N->aft = head;
    head->bef = N;
    N->bef = NULL;
    head = N;
}

//Task3
void List::task3(){
    ItemNode* currNode = tail;
    while(currNode != NULL){
        cout << "[" << currNode->name;
        cout << "\t" << currNode->price << "]"<<endl;
        currNode = currNode->bef;
    }
}

//Task 
void List::task5(int x){
    if (head == NULL) return;

    ItemNode* currNode = head;
    int currIndex = 0;

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
        else tail = NULL;  // List becomes empty
    }
    // Delete tail
    else if (currNode == tail) {
        tail = currNode->bef;
        if (tail) tail->aft = NULL;
        else head = NULL;  // List becomes empty
    }
    // Deleting middle node
    else {
        currNode->bef->aft = currNode->aft;
        currNode->aft->bef = currNode->bef;
    }

    // Free memory
    delete currNode;
}

/*
void List:: task5(int x){
    int currIndex = 0;
    int targetIndex = x;
    ItemNode* currNode = head;

    // Delete begining
    if(targetIndex == 0){
        head = currNode->aft;
        head->bef = NULL;
        return;
    }

    //Move cursor
    while(currIndex && currIndex < x){
        currNode = currNode->aft;
        currIndex++;
    }

    if(!currNode) {
        cout << "Out of bound\n";
        return;
    }

    if (currNode == head) {
        head = currNode->aft;
        if (head) head->bef = NULL;
        else tail = NULL;  // List becomes empty
    }
    // If deleting tail
    else if (currNode == tail) {
        tail = currNode->bef;
        if (tail) tail->aft = NULL;
        else head = NULL;  // List becomes empty
    }
    // Deleting middle node
    else {
        currNode->bef->aft = currNode->aft;
        currNode->aft->bef = currNode->bef;
    }

    // Free memory
    delete currNode;
    

    //Delete last
    if(currNode == tail){
        tail = currNode->bef;
        tail->aft = NULL;
        return;
    }

    //Delete certain index
    currNode->bef->aft = currNode->aft;
    currNode->aft->bef = currNode->bef;
          
    delete currNode;
}
*/


int main(){
   List ItemList; 
   ItemNode *n1 = new ItemNode("Book", 9.59);
   ItemNode *n2 = new ItemNode("Ruler", 3.45);
   ItemNode *n3 = new ItemNode("Pen", 5.69);
   ItemList.task1(n1); 
   ItemList.task2(n2); 
   ItemList.task2(n3); 
   ItemList.task3();
   ItemList.task5(1);
   ItemList.task3();
   return 0;
}