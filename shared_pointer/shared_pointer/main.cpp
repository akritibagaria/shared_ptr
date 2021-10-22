

#include <iostream>

using namespace std;

template < typename T >
class SP
{

T* data ;
int* ref_count ;

public :
SP(){
    data = NULL;
    ref_count = new int ;

}

~SP(){

     printf("Destructor called" );
    *ref_count = *ref_count -1 ;
    if(*ref_count == 0)
    {
        printf("Memory released" );
        data = NULL ;
        ref_count = NULL ;
        delete data ;
        delete ref_count ;
    }

}

SP(T* pValue)
    {
        data = pValue ;
        *ref_count =1 ;
    }

SP(const SP<T> & shptr){
    this->data = shptr.data ;
    (*shptr.ref_count)++;
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
    SP<Person> p = new Person("Scott", 25);
    p->Display();
    {
        SP<Person> q = p;
        q->Display();
        // Destructor of Q will be called here..
        printf("q exiting" );
    }
    p->Display();
    printf("p exiting" );
    return 0;
}





