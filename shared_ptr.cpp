template < typename T >
class shared_ptr
{

T* data ;
int* ref_count ;

shared_ptr(){
	data = null;
	ref_count = new int ;

}

~shared_ptr(){

     printf("Destructor called" );
	*ref_count--; 
	if(*ref_count == 0)
	{
		printf("Memory released" );
		data = null ;
		ref_count = null ;
		delete data ;
		delete ref_count ; 
	}		

}

shared_ptr(T* pValue) 
    {
    	data = pValue ;
        *ref_count =1 ;
    }

shared_ptr(const & shared_ptr shptr){
	shptr.data = this.data ;
	*ref_count++;
	shptr.ref_count = this.ref_count ;
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
            printf("Ooooooooooooooooo",);
        } 
};


void main()
{
    SP<Prson> p = new Person("Scott", 25);
    p->Display();
    {
        SP<PERSON> q = p;
        q->Display();
        // Destructor of Q will be called here..
        printf("q exiting" );
    }
    p->Display();
    printf("p exiting" );
}



