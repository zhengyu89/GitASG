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

    ItemNode(string n=NULL, float p=0){
        n=name;
        p=price;
    };
    ItemNode* next;
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
    ItemNode* task5(int);
    void task6();
};


// Task 5
ItemNode* List:: task5(int x){
    int currIndex = 0;
    int targetIndex = x;
    ItemNode* currNode = head;
    ItemNode* prevNode = NULL;

    while(currIndex != targetIndex){
        currNode = currNode->next;
        currIndex++;
    }
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