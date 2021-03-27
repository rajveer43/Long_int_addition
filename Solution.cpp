/*Write a complete C++ program to add two signed very long numbers using appropriate linked lists. Input  numbers as strings. Make suitable assumption by stating them clearly.*/

#include <bits/stdc++.h>

using namespace std;

//Structure to create Linked list
struct NODE
{
    //to store a single digit
    int data;

    //pointers to the Previous_Node and Next_Node digit 
    struct NODE* Next_Node;
    struct NODE* Previous_Node;

    //To initialize the structure with a single digit
    NODE(int value)
    {
        data = value;
        Next_Node = Previous_Node = NULL;
    }  
};

class Long_Int_Num_Add_LinkedList
{
    public:
        NODE* Head_of_LinkedList;
        NODE* Tail_of_LinkedList;
        int size; 

        //Constructor of the Class
        Long_Int_Num_Add_LinkedList()
        {
            Head_of_LinkedList = Tail_of_LinkedList = NULL;
        }

        //Function to Insert Value at the beginning of the list
        void Insert_At_Head(int value)
        {
            NODE* temp = new NODE(value);

            if(Head_of_LinkedList == NULL)
            {
                Head_of_LinkedList = Tail_of_LinkedList = temp;
            }
            else
            {
                Head_of_LinkedList->Previous_Node = temp;
                temp->Next_Node = Head_of_LinkedList;
                Head_of_LinkedList = temp;
            }

            size++;
        }

        //Function to Insert Value at the end of the list
        void Insert_At_Tail(int value)
        {
            NODE* temp = new NODE(value);

            if(Tail_of_LinkedList == NULL)
            {
                Head_of_LinkedList = Tail_of_LinkedList = temp;
            }
            else
            {
                Tail_of_LinkedList->Next_Node = temp;
                temp->Previous_Node = Tail_of_LinkedList;
                Tail_of_LinkedList = temp;
            }

            size++;
        }
        //To display the number can be modified to remove leading zeros
        void display()
        {
            NODE* temp = Head_of_LinkedList;

            while(temp != NULL)
            {
                cout << temp->data;
                temp = temp->Next_Node;
            }
        }

        //Returns the number of digits
        int length()
        {
            return size;
        }

        //Uses simple addition method that we follow using carry
        void Long_Int_Num_Addition(Long_Int_Num_Add_LinkedList* a, Long_Int_Num_Add_LinkedList* b)
        {
            int Carry = 0, S;
            Long_Int_Num_Add_LinkedList* a1 = new Long_Int_Num_Add_LinkedList(*a);
            Long_Int_Num_Add_LinkedList* b1 = new Long_Int_Num_Add_LinkedList(*b);

            //default copy constructor
            //copy contructor = used to copy object 
            this->Head_of_LinkedList = NULL;
            this->Tail_of_LinkedList = NULL;
            this->size = 0;

            while (a1->Tail_of_LinkedList != NULL || b1->Tail_of_LinkedList != NULL)
            {
                /* code */
                if(a1->Tail_of_LinkedList != NULL && b1->Tail_of_LinkedList != NULL)
                {
                    S = ((a1->Tail_of_LinkedList->data) + (b1->Tail_of_LinkedList->data) + Carry) % 10;
                    Carry = ((a1->Tail_of_LinkedList->data) + (b1->Tail_of_LinkedList->data) + Carry) / 10;
                    a1->Tail_of_LinkedList = a1->Tail_of_LinkedList->Previous_Node;
                    b1->Tail_of_LinkedList = b1->Tail_of_LinkedList->Previous_Node;    
                }
                else if(a1->Tail_of_LinkedList == NULL && b1->Tail_of_LinkedList != NULL)
                {
                    S = ((b1->Tail_of_LinkedList->data) + Carry) % 10;
                    Carry = ((b1->Tail_of_LinkedList->data) + Carry) / 10;
                    b1->Tail_of_LinkedList = b1->Tail_of_LinkedList->Previous_Node;
                }
                else if(a1-> Tail_of_LinkedList != NULL && b1->Tail_of_LinkedList == NULL)
                {
                    S = ((a1->Tail_of_LinkedList->data) + Carry) % 10;
                    Carry = ((a1->Tail_of_LinkedList->data) + Carry) / 10;
                    a1->Tail_of_LinkedList = a1->Tail_of_LinkedList->Previous_Node;
                }

                //inserting the Addition digit
                Insert_At_Head(S);

            }

            //Inserting last carry
            if(Carry != 0)
            {
                Insert_At_Head(Carry);
            }
        }
};

//Driver Code
int main()
{
    Long_Int_Num_Add_LinkedList* Num1 = new Long_Int_Num_Add_LinkedList();
    Long_Int_Num_Add_LinkedList* Num2 = new Long_Int_Num_Add_LinkedList();
    Long_Int_Num_Add_LinkedList* Addition = new Long_Int_Num_Add_LinkedList();
    

    string number1, number2;
    
    cout<<" Enter numbers to add: ";
    cin >> number1 >> number2;


    for(int i = 0; i < number1.length(); i++)
    {
        Num1->Insert_At_Tail(number1.at(i) - '0');
    }

    for(int i = 0; i < number2.length(); i++)
    {
        Num2->Insert_At_Tail(number2.at(i) - '0');
    }

    cout << "Sum: " << endl;
    Addition->Long_Int_Num_Addition(Num1, Num2);
    Addition->display();
    cout << endl;

    return 0;
}
