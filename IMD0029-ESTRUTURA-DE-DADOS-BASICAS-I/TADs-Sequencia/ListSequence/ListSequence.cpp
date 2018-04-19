//
//  Sequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"

Node *first;

Sequence::Sequence()
{
    first = NULL;
    this->quantity = 0;
}

Sequence::~Sequence()
{
    Node* curr = first;
    while(curr!=NULL)
    {
        Node* aux = curr;
        curr = curr->getNext();
        delete aux;
    }
}

/**
 Returns the i-th element in this sequence.
 */
std::string Sequence::get(int i)
{
    Node* curr = first;
    int counter = 1;
    
    while( curr!= NULL && counter < i )
    {
        curr = curr->getNext();
        counter++;
    }
    
    return curr->getValue();
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, std::string element)
{
   // TO DO
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(std::string element)
{
    Node* node = new Node(element);
    
    if( first != NULL ){
        node->setNext( first );
    }
    first = node;
    
    this->quantity++;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(std::string element)
{
   Node* node = new Node(element);
    if(first == NULL)
    {
        first = node;
    }else
    {
        Node* curr = first;
        while(curr->getNext()!=NULL)
        {
            curr = curr->getNext();
        }
        node->setNext(curr->getNext());
        curr->setNext(node);
    }
    this->quantity++;

}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
std::string Sequence::remove(int i)
{
    // TO - DO
    return NULL;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeBegin()
{
    Node* remover = first;
    std::string valorRemovido = remover->getValue();
    first = remover->getNext();
    this->quantity--;
    return valorRemovido;
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
std::string Sequence::removeEnd()
{
    Node* remover = first;
    Node* anterior = first;
     while(remover->getNext()!=NULL)
    {
        anterior = remover;
        remover = remover->getNext();
    }
    if(anterior == NULL){
       return removeBegin();
    }
    std::string valorRemovido = remover->getValue();
    anterior->setNext(remover->getNext());
    delete remover;
    
    this->quantity--;
    return valorRemovido;

}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
