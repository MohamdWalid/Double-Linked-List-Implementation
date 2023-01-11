#include <iostream>
using namespace std;
template<class v>
struct node
{
    v data;
    node *next;
    node *prev;
};
template<class t>
class FCIDLL
{
private:
    node<t> *head=NULL,*tail=NULL;
    int length=0;
    int check=0;
public:
    void addToHead (t item)
    {
     node<t> *newnode=new node<t>;
     newnode->data=item;
     if(length==0)
     {
         head=newnode;
         tail=newnode;
         newnode->next=NULL;
         newnode->prev=NULL;
     }
     else
     {
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        head=newnode;
     }
     length++;
    }
    void addToTail (t item)
    {
        node<t> *newnode=new node<t>;
        newnode->data=item;
        if(length==0)
        {
            head=newnode;
            tail=newnode;
            newnode->next=NULL;
            newnode->prev=NULL;
        }
        else
        {
            newnode->next=NULL;
            newnode->prev=tail;
            tail->next=newnode;
            tail=newnode;
        }
        length++;
    }
    void addToIndex(t item, int index)
    {
        if(index>=0 && index<=length)
        {
            if(index==0)
            {
                addToHead(item);
            }
            else if(index==length)
            {
                addToTail(item);
            }
            else
            {
               node<t> *newnode=new node<t>;
               node<t> *previous=head;
               node<t> *next2=head;
               newnode->data=item;
               for(int i=0;i<index-1;i++)
               {
                   previous=previous->next;
               }
               for(int i=0;i<index;i++)
               {
                   next2=next2->next;
               }
               newnode->next=next2;
               newnode->prev=previous;
               previous->next=newnode;
               next2->prev=newnode;
               length++;
            }
        }
        else
        {
            cout<<"that index not found in the range"<<endl;
        }
    }
    void removeHead()
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            node<t> *currhead=head;
            if(length==1)
            {
                head=NULL;
                delete currhead;
            }
            else
            {
                head=head->next;
                head->prev=NULL;
                delete currhead;
            }
            length--;
        }

    }
    void removeTail()
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            node<t> *currtail=tail;
            if(length==1)
            {
                tail=NULL;
                delete currtail;
            }
            else
            {
                tail=tail->prev;
                tail->next=NULL;
                delete currtail;
            }
            length--;
        }

    }
    void removeItem(t item)
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            if(item==head->data)
            {
                removeHead();
            }
            else if(item==tail->data)
            {
                removeTail();
            }
            else
            {
                node<t> *currpoint=head;
                while(item!=currpoint->data && currpoint!=tail)
                {
                    currpoint=currpoint->next;
                }
                if(item!=currpoint->data)
                {
                    cout<<"this item not found in list"<<"\n";
                }
                else
                {
                    node<t> *previous=currpoint->prev;
                    node<t> *next2=currpoint->next;
                    previous->next=next2;
                    next2->prev=previous;
                    delete currpoint;
                    length--;
                }

            }
        }

    }
    bool Search(t item)
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            node<t> *currpoint=head;
            int i=0;
            while(item!=currpoint->data&&i<length-1)
            {
                currpoint=currpoint->next;
                i++;
            }
            if(item!=currpoint->data)
            {
                return false;
            }
            else
            {
                return true;
            }
        }


    }
    void reverse_list()
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            node<t> *curr=head;
            node<t> *curr2=tail;
            t y;
            if(length%2==0)
            {
                for(int i=0; i<length/2; i++)
                {
                    y=curr->data;
                    curr->data=curr2->data;
                    curr2->data=y;
                    curr=curr->next;
                    curr2=curr2->prev;
                }
            }
            else
            {
                for(int i=0; i<length/2+1; i++)
                {
                    y=curr->data;
                    curr->data=curr2->data;
                    curr2->data=y;
                    curr=curr->next;
                    curr2=curr2->prev;
                    if(curr==curr2)
                    {
                        break;
                    }
                }
            }
        }


    }
    void sort1()
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            node<t> *curr=head;
            if(curr!=tail)
            {
                node<t> *curr2=head->next;
                t y;
                for(int i=0; i<length; i++)
                {
                    if(curr->data>curr2->data)
                    {
                        y=curr->data;
                        curr->data=curr2->data;
                        curr2->data=y;
                        curr=head;
                        curr2=head->next;
                        i=0;
                    }
                    else
                    {
                        curr=curr->next;
                        if(curr==tail)
                        {
                            break;
                        }
                        curr2=curr2->next;
                    }
                }
            }

        }

    }
    bool isempty()
    {
        if(length==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print()
    {
        if(isempty())
        {
            cout<<"list empty"<<endl;
        }
        else
        {
            node<t> *newnode=head;
            for(int i=0; i<length; i++)
            {
                cout<<newnode->data<<"\n";
                newnode=newnode->next;
            }
        }

    }
};
int main()
{
    FCIDLL<int> o1;
    int choice,choice2,index,data;
    while(true)
    {
        do
        {
            cout<<"[1] add to head"<<endl<<"[2] add to tail"<<endl<<"[3] add to index"<<endl<<"[4] remove from head"<<endl<<"[5] remove from tail"<<endl<<"[6] remove item "<<endl<<"[7] search in list"<<endl<<"[8] reverse list"<<endl<<"[9] sort list"<<endl<<"[10] print list"<<endl;
            cout<<"Enter choice: ";
            cin>>choice;
        }
        while(choice<1 || choice>10);
        switch(choice)
        {
        case 1:
            cout<<"Enter data: ";
            cin>>data;
            o1.addToHead(data);
            break;

        case 2:
            cout<<"Enter data: ";
            cin>>data;
            o1.addToTail(data);
            break;

        case 3:
            cout<<"Enter data: ";
            cin>>data;
            cout<<"Enter index: ";
            cin>>index;
            o1.addToIndex(data,index);
            break;

        case 4:
            o1.removeHead();
            break;

        case 5:
            o1.removeTail();
            break;

        case 6:
            cout<<"Enter data: ";
            cin>>data;
            o1.removeItem(data);
            break;

        case 7:
            cout<<"Enter data: ";
            cin>>data;
            if(o1.Search(data))
            {
             cout<<"this item found in list"<<"\n";
            }
            else
            {
             cout<<"this item not found in list"<<"\n";
            }
            break;

        case 8:
            o1.reverse_list();
            break;

        case 9:
            o1.sort1();
            break;

        case 10:
            o1.print();
            break;
        }
        do
        {
          cout<<"[1] continue"<<"[2] stop"<<endl;
          cin>>choice2;
        }while(choice2!=1 && choice2!=2);
        if(choice2==2)
        {
            break;
        }
    }
    return 0;
}
