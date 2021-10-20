#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    static int count; 
protected:
    string n_name;
    int n_age;
    string n_sex;
    int n_wight;
 
 
public:
    static int GetCount(){return count;}
    Person(const string& name, const int& age, const string& sex, const int& wight)
        : n_name ( name ), n_age( age ), n_wight( wight ), n_sex( sex )
    {
        count++; 
    }
 
    string GetName(){ return n_name; }
    int GetAge(){ return n_age; }
    int GetWight(){ return n_wight; }
    
    virtual void Print()   
    {
        cout<<n_name<<' '<<n_age<<' '<<n_sex<<' '<<n_wight;
    }
};
 
class Student : public Person
{
private:
    int n_year;
public:
    Student(int year, const string& name, const int age, const string& sex, const int wight)
        :Person(name, age, sex, wight),n_year(year)
    {}
    int GetYear(){ return n_year; }
 
    void Print()
    {
		Person::Print();
        cout<<' '<<n_year<<endl;
    }
};
int Person::count=0; 
int main()
{
    const int N=2;
    Person* p[N];
    for(int i=0;i<N;i++)
    { 
        int year,wight,age;
        string name, sex;
        cout<<"Enter: name age sex weight year:"<<endl;
        cin>> name>>age>> sex>>wight>>year;
        p[i]=new Student(year,name, age, sex, wight); 
        cout<<"Count="<<p[i]->GetCount()<<endl; 
    }
    for(int i=0;i<N;i++)
        p[i]->Print();
    for(int i=0;i<N;i++)
        delete p[i];
    return 0;
}
