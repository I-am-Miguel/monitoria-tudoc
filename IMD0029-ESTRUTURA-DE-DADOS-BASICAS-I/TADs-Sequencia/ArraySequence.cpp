//
//  ArraySequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"

Node **content;
const int SIZE = 7;
unsigned int init;
unsigned int end;

Sequence::Sequence()
{
    content         = new Node*[SIZE];
    this->quantity  = 0;
    init            = 0;
    end             = 0;
}

Sequence::~Sequence()
{
    // TO - DO
    delete [] content;
}

/**
 Returns the i-th element in this sequence.
 */
Node* Sequence::get(int i)
{
    return content[i-1];
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, Node* element)
{
    //Movendo os elementos para a ultima posição, permitindo a inserção na posição I
    for(int posicao = end; posicao > i-1; posicao--)
    {
        content[posicao] = content[posicao-1];
    }

    content[i-1] = element;
    end++;
    this->quantity++;   
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(Node* element)
{
    this->insert(1,element);
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(Node* element)
{
    this->insert(end+1,element);
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
Node* Sequence::remove(int i)
{
    std::string valorRemovido = content[i-1]->getValue();
    Node* nodeCopia = new Node(valorRemovido); 

    for(int unsigned posicao = i-1; posicao < end; posicao++)
    {
        content[posicao] = content[posicao+1];
    }

    this->quantity--; 
    end--;

    return nodeCopia;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeBegin()
{
    return remove(1);
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeEnd()
{
    return remove(end);
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
