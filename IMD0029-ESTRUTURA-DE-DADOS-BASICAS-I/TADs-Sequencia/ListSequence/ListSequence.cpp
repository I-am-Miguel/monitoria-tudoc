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
    Node* atual = first;
    while(atual!=NULL)
    {
        Node* aux = atual;
        atual = atual->getNext();
        delete aux;
    }
}

/**
 Returns the i-th element in this sequence.
 */
std::string Sequence::get(int i)
{
    Node* atual = first;
    int counter = 1;
    
    while( atual!= NULL && counter < i )
    {
        atual = atual->getNext();
        counter++;
    }
    
    return atual->getValue();
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, std::string element)
{
   if(first == NULL){
       insertBegin(element);       
   }else{
        Node* node = new Node(element);
        Node* atual = first;        
        for(int posicao = 0; posicao < i; posicao++)
        {
            if(atual->getNext()!= NULL)
            {                
                atual = atual->getNext();
            }
               
        }
        node->setNext(atual->getNext());
        atual->setNext(node);
        this->quantity++;        
   }
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
        Node* atual = first;
        while(atual->getNext()!=NULL)
        {
            atual = atual->getNext();
        }
        node->setNext(atual->getNext());
        atual->setNext(node);
    }
    this->quantity++;

}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
std::string Sequence::remove(int i)
{    
    if(i == 1)
    {
        return removeBegin();
    }
    
    Node* remover = first;
    Node* anterior = NULL;
    while(remover->getNext()!=NULL && i > 0)
    {
        anterior = remover;
        remover = remover->getNext();
        i--;
    }
    std::string valorRemovido = remover->getValue();
    anterior->setNext(remover->getNext());
    delete remover;
    
    this->quantity--;
    return valorRemovido;
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
    return remove(this->quantity);

}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
