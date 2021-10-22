//
//  shared_ptr.cpp
//  shared_ptr
//
//  Created by Akriti Bagaria on 22/10/21.
//

#include <iostream>
using namespace std;

/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

template < typename T >
class shared_ptr
{

T* data ;
int* ref_count ;

public :
shared_ptr(){
    data = NULL;
    ref_count = new int ;

}

~shared_ptr(){

     printf("Destructor called" );
    *ref_count--;
    if(*ref_count == 0)
    {
        printf("Memory released" );
        data = NULL ;
        ref_count = NULL ;
        delete data ;
        delete ref_count ;
    }

}

shared_ptr(T* pValue)
    {
        data = pValue ;
        *ref_count =1 ;
    }

shared_ptr(const shared_ptr<T> & shptr){
    this->data = shptr.data ;
    *ref_count++;
    this->ref_count = shptr.ref_count ;
}

T& operator*(){
  return *data ;
}

T* operator->(){
    return data ;
}



};





class Person
{
    int age;
    char* pName;

    public:
        Person(): pName(0),age(0)
        {
        }
        Person(char* pName, int age): pName(pName), age(age)
        {
        }
        ~Person()
        {
        }

        void Display()
        {
            printf("Name = %s Age = %d \n", pName, age);
        }
        void Shout()
        {
            printf("Ooooooooooooooooo");
        }
};


int main()
{
    shared_ptr<Person> p = new Person("Scott", 25);
    p->Display();
    {
        shared_ptr<Person> q = p;
        q->Display();
        // Destructor of Q will be called here..
        printf("q exiting" );
    }
    p->Display();
    printf("p exiting" );
    return 0;
}





