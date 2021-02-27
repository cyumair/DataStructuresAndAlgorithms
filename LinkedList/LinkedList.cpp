#include<iostream>
#include<cmath>
using namespace std;

class LinkedList{
    public:
        int length = 0;
        struct node{
            int value;
            node* next;
            node* prev;
        };
        node* first = NULL;
        node* last = NULL;

    
    //size
    int size(){
        node* current = first;
        int len = 0;
        while(current!=NULL){
            len++;
            current = current->next;
        }
        return len;
    }

    //display
    void display(){
        if(first == NULL){
            cout << "List is Empty!" << endl;
        }
        else{
            node* current = first;
            while(current != NULL){
                cout << current->value << endl;
                current = current->next;
            }
        }
    }

    //add at specific index any value
    void add(int index, int item){
        node* newnode = new node;
        newnode->next = NULL;
        newnode->value = item;
        //if user wants to insert at start
        if(index > size() || index < 0){
            cout << "Index out of bound. Cannot Add" << endl;
        }

        else if(index == 0){
            if (first == NULL){
                first = last = newnode;
            }
            else{
                newnode->next = first;
                first = newnode;
            }
        }
        //if user wants to insert at end
        else if(index == size()){
            if(first == NULL){
                first = last = newnode;
            }
            else{
                last->next = newnode;
                last = newnode;
            }
        }

        else{ //insert in between
            node* currentnode = nodebeforeindex(index);
            newnode->next = currentnode->next;
            currentnode->next = newnode;
        }
    }

    //remove
    void removeindex(int index){
        if(first == NULL){
            cout << "List is empty No items needed to be removed" << endl;
        }
        else if(index >= size() || index < 0){
            cout << "No Node at that index, Cannot Delete." << endl;
        }
        else{
            //delete from start
            if(index == 0){
                node* temp = first;
                first = first->next;
                delete temp;
            }
            //delete from end
            else if(index == size() - 1){
                node* previous = nodebeforeindex(index);
                delete last;
                last = previous;
                previous->next = NULL;
            }
            else{
                node* previous = nodebeforeindex(index);
                node* temp = previous->next;
                previous->next = temp->next;
                delete temp;
            }

        }
    }

    void removeitem(int item){
        if(first == NULL){
            cout << "List is empty No items needed to be removed" << endl;
        }
    
        else{
            //delete from start
            if(item == first->value){
                node* temp = first;
                first = first->next;
                delete temp;
            }
            //delete from end
            else if(item == last->value){
                node* current = nodebeforevalue(item);
                delete current->next;
                current->next = NULL;
                //last = current;
            }

            else{
                node* current = nodebeforevalue(item);
                if(current == NULL){
                    cout << "Item you are looking to delete not found in List." << endl;
                }
                else{
                    node* temp = current->next;
                    current->next = temp->next;
                    delete temp;
                }
                
            }
        }
    }



    //duplicate list
    LinkedList duplicate(){
        /*Create a new Object of linked list add the nodes with values same as orignal ones
        and simply return that new list. 
        return type is LinkedList object.*/
        LinkedList list;
        node* current = first;
        int i = 0;
        while(current!= NULL){
            list.add(i, current->value);
            i++;
            current = current->next;
        }
        return list;
    }


    //deletesmallest
    void DeleteSmallest(){
        if(first == NULL){
            cout << "List is empty, Nothing to delete." << endl;
        }
        else if(first == last){
            delete first;
            first = last = NULL;
        }
        else{
            node* current = first;
            node* smallest = first;
            while(current != NULL){
                if(current->value < smallest->value){
                    smallest = current;
                }
                current = current->next;
            }
            if(smallest == first){
                node* temp = first;
                first = first->next;
                delete temp;
            }
            else{
                current = nodebeforevalue(smallest->value);
                if (smallest == last){
                    last = current;
                }
                current->next = smallest->next;
                delete smallest;
            }
        }
    }

    //deletes dublicate nodes from the list
    void deleteDuplicates(){  
        /*while current is not null
        loop each node by every other node
        keep a track of previous node, helps in deleting.
        check if the current node matches any other node then delete it
        if node doesnt match the current node value then simply check for the next one
        repeat the process for every node*/
        node* current = first;
        while (current != NULL){
            node* current2 = current->next;
            node* previous = current;
            while(current2 != NULL){
                if (current2->value == current->value){
                    if(current2 == last){
                        last = previous;
                    }
                    previous->next = current2->next;
                    delete current2;
                    current2 = previous->next; 
                }
                else{
                    previous = current2;
                    current2 = current2->next;
                }
            } 
            current = current->next;         
        }
    }

    //Duplicate Reversed
    LinkedList duplicateReversed(){
        /*Duplicate the list and reverse the nodes and then return it.
        Duplicating and reversing functions are already written.*/
        LinkedList list = duplicate();
        //now if there is no or 1 element in the list then no need to perfrom any function
        if(first == NULL || first == last){
            return list; 
        }
        else{
            list.reverseNodes(list.first, list.first->next);
            return list; 
        }
    }

    //reverse Display()
    void reverseDisplay(){
        if(first == NULL){
            cout << "Linked list is empty"<< endl;
        }
        else{
            cout << "Displaying Reversed: " << endl;
            reverseDisplayRecurr(first);
        }
    }

    //Reverse display recursive function
    void reverseDisplayRecurr(node* curr){
    
        /* Base case = current node is last node(we have reached the last node of list);
        We will reach the last node and then display it
        then it will go back to function that called last node;
        in the function our current node is node before last.
        it will keeping going back to its caller and also displaying the current node of caller function*/
        if(curr != last){
            reverseDisplayRecurr(curr->next);
        }
        cout << curr->value << endl;
    }
    

    void reverseDisplayLoop(){
        
        node* p = last;
        while(p!= first){
            node* current = first;
            node* prev = current;
            while(current != p){
                prev = current;
                current = current->next;
            }
            cout << current->value << endl;
            p = prev;
        }
        cout << first->value << endl;

    }
    //Reverse Nodes
    void reverseNodes(node* pre, node* curr){
        /*This function uses recursion to reverse the nodes.
        we will pass previous node and current node as parameters.
        Keep calling this recursively until we reach last, 
        as soon as we reach last node then start reversing, set the next of last(current) to its previous node.
        now our method will go back, where our current was second last and previous was third last. 
        now all it has to do is point current with previous.
        in the end we have to swap the last with first to complete our reversing.*/
        //cout << "executed."<<endl;
        if(curr != last){
            reverseNodes(curr, curr->next);
        }
        curr->next = pre;
        //swaping first and last node in the end
        if(pre == first){
            pre->next = NULL;
            node* temp = last;
            last = pre;
            first = temp;
        }
    }

    //print Middle
    void PrintMiddle(){
        if(first == NULL){
            cout << "Linked List is empty." << endl;
        }
        /*Find the node at mid index and display its value,
        if there is no mid then print second value so we are using ceil math function*/
        else{
            cout <<"Item at Middle: " << nodeatindex(ceil(size()/2))->value << endl;
        }
        
    }

    //checks if linked list is Palindrome
    void isPalindrome(){
        int i = 0;
        int len = floor(size()/2);
        bool isPalindrome = true;
        while(i < len){
            if(i % 2 == 0){
                if(nodeatindex(i)->value != nodeatindex((size() -1)- i)->value){
                    isPalindrome = false;
                    break;
                }
            }
            i++;
        }
        if(isPalindrome == true){
            cout << "Linked List is Palindrome" << endl;
        }
        else{
            cout << "Linked List is not Palindrome" << endl;
        }
    }


    void Frequency(){
        if(first == NULL){
            cout << "Linked List is Empty" << endl;
        }
        else{
            int len = size();
            //this array will keep a track of already counted items so we dont count anything twice
            int counted[len];
            int i = 0; //index to store data in above array
            node* current = first; 
            //loop through all the nodes;
            while (current != NULL){ 
                //check if the value is already counted or not
                bool isCounted = false;
                for(int i = 0; i < len; i++){
                    if(current->value == counted[i]){
                        isCounted = true;
                        break;
                    }
                }
                //if it is not counted then loop through items and check its occurrance in the list
                if (!isCounted){
                    node* current2 = current->next;
                    int frequency = 1;
                    while(current2 != NULL){
                        if (current2->value == current->value){
                            frequency+=1;
                            //now we have counted a value store it in counted array
                            counted[i] = current->value;
                        }
                        current2 = current2->next;
                    } 
                    //display frequency of the counted item
                    cout << "Frequency of " << current->value << " is: " << frequency << endl;
                }
                //repeat the counting process for next item
                i++;
                current = current->next;         
            } 
        }
    }
    

    LinkedList insertNodesatAlternatePos(LinkedList list){
        /*loop through both the lists and insert nodes in
        a new list. Add node of first list and second list.
        if one of the list gets empty and then insert all
        remaining nodes of other list. 
        Simply return the list with alternate nodes added in the end;
        */

        LinkedList newlist;
        node* current1 = first;
        node* current2 = list.first;
        int len = size() + list.size();
        int index = 0;
        while(index < len){
            if(current1 != NULL && current2 != NULL){
                newlist.add(index, current1->value);
                newlist.add(index + 1, current2->value);
                index += 2;
                current1 = current1->next;
                current2 = current2->next;
            
            }
            else if(current1 == NULL){
                newlist.add(index, current2->value);
                index++;
                current2 = current2->next;
            }
            else{
                newlist.add(index, current1->value);
                index ++;
                current1 = current1->next;
            }
        }
        return newlist;
    }

    //swap two nodes
    void swapNodes(int index1, int index2){
        /*We have to take care of all conditions in swapping
        swapping with first, with last, with a node that is right next*/ 
      // index1--; //indexes given by user is actually 1 greater than index,
        //index2--; // if we say swap 1st and 6th , we have to swap 0 and 5 index
        if(first == NULL){
            cout << "List is empty, Nothing to swap" << endl;
        }
        else if(index1 > size()-1 || index2 > size()-1 || index1 < 0 || index2 < 0){
            cout<< "Index out of bound, no node at this index" << endl;
        }

        else{
            //if we are swapping with itself;
            if(index1 == index2){
                return;
            }
            //if we swapping node is first
            else if(index1 == 0){
                //if we are swapping first and last node;
                if(index2 == (size()-1)){
                    last = first;
                }
                node* beforeIndex2 = nodebeforeindex(index2);
                //if nodes are right next to each other
                if(beforeIndex2 == first){
                    node* next2 = first->next->next;
                    node* node2 = first->next;
                    node* node1 = first;
                    node2->next = first;
                    node1->next = next2;
                    first = node2;  
                }
                else{
                // node* beforeIndex1 = nodebeforeindex(index1);
                    node* next2 = beforeIndex2->next->next;
                    node* next1 = first->next;
                    node* node1 = first;
                    node* node2 = beforeIndex2->next;
                    node1->next = next2;
                    node2->next = next1;
                    beforeIndex2->next = node1;
                    first = node2;
                }
            }

            //if swapping node is first
            else if(index2 == 0){
                if(index1 == size()-1){
                    last = first;
                }
                
                node* beforeIndex1 = nodebeforeindex(index1);
                //if nodes are next to each other
                if(beforeIndex1 == first){
                    node* next1 = first->next->next;
                    node* node1 = first->next;
                    node* node2 = first;
                    node1->next = first;
                    node2->next = next1;
                    first = node1;  
                }
                else{
                // node* beforeIndex1 = nodebeforeindex(index1);
                    node* next1 = beforeIndex1->next->next;
                    node* next2 = first->next;
                    node* node2 = first;
                    node* node1 = beforeIndex1->next;
                    node2->next = next1;
                    node1->next = next2;
                    beforeIndex1->next = node2;
                    first = node1;
                }

            }

            //if we are not swapping first node
            else{
                node* beforeIndex1 = nodebeforeindex(index1);
                node* beforeIndex2 = nodebeforeindex(index2);
                node* node1 = beforeIndex1->next;
                node* node2 = beforeIndex2->next;
                //check if we are swapping last node then change last node reference
                if(node1 == last){
                    last = node2; //replacing the last node pointer so it points to right last
                }
                else if(node2 == last){
                    last = node1;
                }

                if(node1->next == node2){
                    node* next2 = beforeIndex2->next->next;
                    node2->next = node1;
                    node1->next = next2;
                    beforeIndex1->next = node2;  
                }

                else if(node2->next == node1){
                    node* next1 = beforeIndex1->next->next;
                    node1->next = node2;
                    node2->next = next1;
                    beforeIndex2->next = node1;  
                }

                else{
                    node* next1 = beforeIndex1->next->next;
                    node* next2 = beforeIndex2->next->next;
                    node1->next = next2;
                    node2->next = next1;
                    beforeIndex1->next = node2;
                    beforeIndex2->next = node1;
                }
            }
        }
    }



  //swap 1st node with last , 2nd with 2nd last and so on...
    void MirrorNodeSwap(){
        swapMirrorNodes(0, size()-1);
    }

    //swap 1st with 2nd, 3rd with 4rth  and so on..
    void pairWiseNodeSwapping(){
        int index = 0;
        int len = size() - 1;
        while(index < len){
            swapNodes(index, index+1);
            index+=2;
        }
    }

    void swapKthNode(int k){
        //WE have to decrement k because 1st node has 0 index.
        swapNodes(k-1, (size() - k));
    }

    void addtoItself(){
        /*Start index will be the one where our list ended,
        simply loop through whole list and keeping adding values at the index
        keep incrementing the index*/
        int index = size(); // the index at which we want to insert is the index after last value
        int newlen = 2*index;
        node* current = first;
        while(index < newlen){
            add(index, current->value);
            current = current->next;
            index++;
        } 
    }

    void ReverseinSize(int len){
        int startindex = 0;
        //how many time will the reversing occur
        int loop = floor(size()/len);
        for(int i = 1; i <= loop; i++){
            swapMirrorNodes(startindex , len*i - 1);//4th node is actually 3rd index
            startindex += len;
        }
        //if there are any left less than the size reverse them too
        int leftnodes = size() - (floor(size()/len) * len);
        if (leftnodes != 0){
            swapMirrorNodes(startindex, startindex + leftnodes-1);
        }
    }

    void update(){
        node* current = first;
        while(current->next != NULL){
            current->next->prev = current;
            current = current->next;
        }
        first->prev = NULL;
    }

    void displayyy(){
        node* curr = last;
        while (curr != NULL)
        {
            cout << curr->value << endl;
            curr = curr->prev;
        }
        
    }


    private:
    //mirror swaps the nodes between start and end index
    void swapMirrorNodes(int startindex, int endindex){
        int len = floor((endindex-startindex)/2);
        int index = 0;
        while(index <= len){
            swapNodes(index + startindex, (endindex - index));
            index++;
        }  
    }
        
    node* nodeatindex(int index){
        node* currentnode = first;
        int i = 0;
        while(!(i == (index) || currentnode == NULL)){
            currentnode = currentnode->next;
            i++;
        }
        return currentnode;
    }

    node* nodebeforeindex(int index){
        node* currentnode = first;
        int i = 0;
        while(!(i == (index - 1) || currentnode == NULL)){
            currentnode = currentnode->next;
            i++;
        }
        return currentnode;
    }

    node* nodebeforevalue(int item){
        node* currentnode = first;
        bool found = false;
        while(!(currentnode->next == NULL)){
            if(currentnode->next->value == item){
                found = true;
                break;
            }
            currentnode = currentnode->next;
        }
        if (found){
            return currentnode;
        }
        else{
            return NULL;
        }
    }

    node* nodeatvalue(int item){
        node* currentnode = first;
        bool found = false;
        while(!(currentnode == NULL)){
            if(currentnode->value == item){
                found = true;
                break;
            }
            currentnode = currentnode->next;
        }
        if (found){
            return currentnode;
        }
        else{
            return NULL;
        }
    }
};

int main(){
    LinkedList myLinkedList;
    LinkedList l2;

    myLinkedList.add(0, 1);
    // myLinkedList.DeleteSmallest();
    myLinkedList.add(1, 2);
    myLinkedList.add(2, 3);
    myLinkedList.add(3, 4);
    myLinkedList.add(4, 5);
    myLinkedList.add(5, 3);
    myLinkedList.add(6, 6);
    myLinkedList.add(7, 1);

    myLinkedList.isPalindrome();
    //myLinkedList.deleteDuplicates();
    //LinkedList l3 = myLinkedList.insertNodesatAlternatePos(l2);

    //myLinkedList.swapNodes(0, 0);
    //myLinkedList.Frequency();
    //myLinkedList.isPalindrome();
    //myLinkedList.removeindex(5);
    //myLinkedList.display();
 
    return 0;

}
