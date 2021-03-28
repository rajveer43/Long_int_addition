/*
	Name: Arithmatic_Operations Using LinkedList
	Copyright: subject to copyright
	Author: Rajveer Rathod
	Date: 28-03-21 11:55
	Description: Write a C++ program to perform Arithmatic operations of two numbers using linkedlist 
	
*/

#include <bits/stdc++.h>

using namespace std;

//StruCture to Create Linked list
struct NODE
{
    //to store a single digit
    int data;

    //pointers to the Previous_Node and Next_Node digit 
    struct NODE* Next_Node;
    struct NODE* Previous_Node;

    //To initialize the struCture with a single digit
    NODE(int value)
    {
        data = value;
        Next_Node = Previous_Node = NULL;
    }  
};

//Class for the task
class Long_Int_Num_Arithmatic_Linked_List
{
    public:
        NODE* Head_of_LinkedList;
        NODE* Tail_of_LinkedList;
        int size; 

        //ConstruCtor of the Class
        Long_Int_Num_Arithmatic_Linked_List()
        {
            Head_of_LinkedList = Tail_of_LinkedList = NULL;
        }
        //~Long_Int_Num_ArithmatiC_Linked_List();

        //FunCtion to Insert Value at the beginning of the list
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

        //FunCtion to Insert Value at the end of the list
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
        //To display the number Can be modified to remove leading zeros
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

        //Uses simple addition method that we follow using Carry
        void Long_Int_Num_Addition(Long_Int_Num_Arithmatic_Linked_List* a, Long_Int_Num_Arithmatic_Linked_List* b)
        {
            int Carry = 0, S;
            Long_Int_Num_Arithmatic_Linked_List* a1 = new Long_Int_Num_Arithmatic_Linked_List(*a);
            Long_Int_Num_Arithmatic_Linked_List* b1 = new Long_Int_Num_Arithmatic_Linked_List(*b);

            //default Copy ConstruCtor
            //Copy ContruCtor = used to Copy objeCt 
            this->Head_of_LinkedList = NULL;
            this->Tail_of_LinkedList = NULL;
            this->size = 0;

            while (a1->Tail_of_LinkedList != NULL || b1->Tail_of_LinkedList != NULL)
            {
                /* Code */
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

            //Inserting last 
            if(Carry != 0)
            {
                Insert_At_Head(Carry);
            }
        }

        //Function to substract the numbers
        void Long_Int_Num_Substraction(Long_Int_Num_Arithmatic_Linked_List* a, Long_Int_Num_Arithmatic_Linked_List* b)
        {
            int Carry = 0, S;
            Long_Int_Num_Arithmatic_Linked_List* a1 = new Long_Int_Num_Arithmatic_Linked_List(*a);
            Long_Int_Num_Arithmatic_Linked_List* b1 = new Long_Int_Num_Arithmatic_Linked_List(*b);

            this->Head_of_LinkedList = NULL;
            this->Tail_of_LinkedList = NULL;
            this->size = 0;

            while(a1->Tail_of_LinkedList != NULL || b1->Tail_of_LinkedList != NULL)
            {
                if(a1->Tail_of_LinkedList != NULL && b1->Tail_of_LinkedList != NULL)
                {
                    if((a1->Tail_of_LinkedList->data) + Carry >= (b1->Tail_of_LinkedList->data))
                    {
                        S = ((a1->Tail_of_LinkedList->data) + Carry - (b1->Tail_of_LinkedList->data));
                        Carry = 0;
                    }
                    else
                    {
                        S = ((a1->Tail_of_LinkedList->data) + Carry + 10 - (b1->Tail_of_LinkedList->data));
                        Carry = -1;
                    }

                    a1->Tail_of_LinkedList = a1->Tail_of_LinkedList->Previous_Node;
                    b1->Tail_of_LinkedList = b1->Tail_of_LinkedList->Previous_Node;
                }
                else if(a1->Tail_of_LinkedList != NULL && b1->Tail_of_LinkedList == NULL)
                {
                    if(a1->Tail_of_LinkedList->data >= 1)
                    {
                        S = ((a1->Tail_of_LinkedList->data) + Carry);
                        Carry = 0;
                    }
                    else
                    {
                        if(Carry != 0)
                        {
                            S = ((a1->Tail_of_LinkedList->data) + 10 + Carry);
                            Carry = -1;
                        }
                        else
                        {
                            S = a1->Tail_of_LinkedList->data;
                        }
                    }
                    a1->Tail_of_LinkedList = a1->Tail_of_LinkedList->Previous_Node;

                }

                Insert_At_Head(S);
            }
        }
        
        //this Compares the two numebrs and returns true when a is greater 
        int Long_Int_Num_Compare(Long_Int_Num_Arithmatic_Linked_List* a, Long_Int_Num_Arithmatic_Linked_List* b)
        {
            if(a->size != b->size)
            {
                return ((a->size > b->size) ? 1 : 0);
            }
            else
            {
                Long_Int_Num_Arithmatic_Linked_List* a1 = new Long_Int_Num_Arithmatic_Linked_List(*a);
                Long_Int_Num_Arithmatic_Linked_List* b1 = new Long_Int_Num_Arithmatic_Linked_List(*b);

                while(a1->Head_of_LinkedList != NULL && b1->Head_of_LinkedList != NULL)
                {
                    if(a1->Head_of_LinkedList->data > b1->Head_of_LinkedList->data)
                    {
                        return 1;
                    }
                    else if(a1->Head_of_LinkedList->data < b1->Head_of_LinkedList->data)
                    {
                        return 0;
                    }
                    else
                    {
                        a1->Head_of_LinkedList = a1->Head_of_LinkedList->Next_Node;
                        b1->Head_of_LinkedList = b1->Head_of_LinkedList->Next_Node;
                    }
                }

                return 2;
            }
        }
        
        //Function for Quotient
        void Long_Int_Num_Quotient(Long_Int_Num_Arithmatic_Linked_List* a, Long_Int_Num_Arithmatic_Linked_List* b)
        {
            Long_Int_Num_Arithmatic_Linked_List* a1 = new Long_Int_Num_Arithmatic_Linked_List(*a);
            Long_Int_Num_Arithmatic_Linked_List* b1 = new Long_Int_Num_Arithmatic_Linked_List(*b);
            Long_Int_Num_Arithmatic_Linked_List* ex = new Long_Int_Num_Arithmatic_Linked_List();
            Long_Int_Num_Arithmatic_Linked_List* mp = new Long_Int_Num_Arithmatic_Linked_List();
            Long_Int_Num_Arithmatic_Linked_List* pr = new Long_Int_Num_Arithmatic_Linked_List();
            int i;
            for(i = 0; i < b1->size; i++)
            {
                ex->Insert_At_Tail(a1->Head_of_LinkedList->data);
                a1->Head_of_LinkedList = a1->Head_of_LinkedList->Next_Node;
            }

            for(i = 0; i < 10; i++)
            {
                Long_Int_Num_Arithmatic_Linked_List* b2 = new Long_Int_Num_Arithmatic_Linked_List(*b);
                mp->Insert_At_Tail(i);
                pr->Long_Int_Num_Multiplication(b2, mp);
                if(!Long_Int_Num_Compare(ex, pr))
                {
                    break;
                }

                mp->Head_of_LinkedList = mp->Tail_of_LinkedList = NULL;
                pr->Head_of_LinkedList = pr->Tail_of_LinkedList = NULL;
                mp->size = pr->size = 0;
            }

            mp->Head_of_LinkedList = mp->Tail_of_LinkedList = NULL;
            pr->Head_of_LinkedList = pr->Tail_of_LinkedList = NULL;
            mp->size = pr->size = 0;

            mp->Insert_At_Tail(i-1);
            pr->Long_Int_Num_Multiplication(b1, mp);
            ex->Long_Int_Num_Substraction(ex, pr);
            Insert_At_Tail(i-1);
            mp->Head_of_LinkedList = mp->Tail_of_LinkedList = NULL;
            pr->Head_of_LinkedList = pr->Tail_of_LinkedList = NULL;
            mp->size = pr->size = 0;

            while(a1->Head_of_LinkedList != NULL)
            {
                ex->Insert_At_Tail(a1->Head_of_LinkedList->data);
                while(ex->Head_of_LinkedList->data == 0)
                {
                    ex->Head_of_LinkedList = ex->Head_of_LinkedList->Next_Node;
                    ex->size--;
                }

                for(i = 0; i < 10; i++)
                {
                    Long_Int_Num_Arithmatic_Linked_List* b2 = new Long_Int_Num_Arithmatic_Linked_List(*b);
                    mp->Insert_At_Tail(i);
                    pr->Long_Int_Num_Multiplication(b2, mp);
                    if(!Long_Int_Num_Compare(ex, pr))
                    {
                        break;
                    }

                    mp->Head_of_LinkedList = mp->Tail_of_LinkedList = NULL;
                    pr->Head_of_LinkedList = pr->Tail_of_LinkedList = NULL;
                    mp->size = pr->size = 0;
                }

                mp->Head_of_LinkedList = mp->Tail_of_LinkedList = NULL;
                pr->Head_of_LinkedList = pr->Tail_of_LinkedList = NULL;
                mp->size = pr->size = 0;

                mp->Insert_At_Tail(i - 1);
                pr->Long_Int_Num_Multiplication(b1, mp);
                ex->Long_Int_Num_Substraction(ex, pr);

                Insert_At_Tail(i - 1);

                mp->Head_of_LinkedList = mp->Tail_of_LinkedList = NULL;
                pr->Head_of_LinkedList = pr->Tail_of_LinkedList = NULL;
                mp->size = pr->size = 0;

                a1->Head_of_LinkedList = a1->Head_of_LinkedList->Previous_Node;
            }

            cout << endl << "/n Modulus: " << endl;
            ex->display();
        }
        
        //Function to multiply the numbers
        void Long_Int_Num_Multiplication(Long_Int_Num_Arithmatic_Linked_List* a, Long_Int_Num_Arithmatic_Linked_List* b)
        {
            int K = 0, I;
            Long_Int_Num_Arithmatic_Linked_List* tpro = new Long_Int_Num_Arithmatic_Linked_List();
            while(b->Tail_of_LinkedList != NULL)
            {
                int Carry = 0, S;
                Long_Int_Num_Arithmatic_Linked_List* temp = new Long_Int_Num_Arithmatic_Linked_List(*a);
                Long_Int_Num_Arithmatic_Linked_List* Pro = new Long_Int_Num_Arithmatic_Linked_List();
                while(temp->Tail_of_LinkedList != NULL)
                {
                    S = ((temp->Tail_of_LinkedList->data) * (b->Tail_of_LinkedList->data) + Carry) % 10;
                    Carry = ((temp->Tail_of_LinkedList->data) * (b->Tail_of_LinkedList->data) + Carry) / 10;
                    Pro->Insert_At_Head(S);
                    temp->Tail_of_LinkedList = temp->Tail_of_LinkedList->Previous_Node;
                }

                if (Carry != 0)
                {
                    Pro->Insert_At_Head(Carry);
                }

                for(I = 0; I < K; I++)
                {
                    Pro->Insert_At_Tail(0);
                }

                Long_Int_Num_Addition(this, Pro);
                K++;
                b->Tail_of_LinkedList = b->Tail_of_LinkedList->Previous_Node;
                Pro->size = 0;
                
            }
        }
};

//Driver Code
int main()
{
    Long_Int_Num_Arithmatic_Linked_List* Num1 = new Long_Int_Num_Arithmatic_Linked_List();
    Long_Int_Num_Arithmatic_Linked_List* Num2 = new Long_Int_Num_Arithmatic_Linked_List();
    Long_Int_Num_Arithmatic_Linked_List* Addition = new Long_Int_Num_Arithmatic_Linked_List();
    Long_Int_Num_Arithmatic_Linked_List* Substraction = new Long_Int_Num_Arithmatic_Linked_List();
	Long_Int_Num_Arithmatic_Linked_List* Multiplication = new Long_Int_Num_Arithmatic_Linked_List();
	Long_Int_Num_Arithmatic_Linked_List* Quotient = new Long_Int_Num_Arithmatic_Linked_List();
		
    string number1, number2;
    
    cout<<" Enter numbers to perform arithmatic operations: ";
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
    
    cout <<"Substraction: " <<endl;
    Substraction->Long_Int_Num_Substraction(Num1, Num2);
    Substraction->display();
    cout<<endl;
    
    cout << "Multiplication: " << endl;
    Multiplication->Long_Int_Num_Multiplication(Num1, Num2);
    Multiplication->display();
    cout << endl;

    return 0;
}
