#include <iostream>

using namespace std;

class Homework{
    public:
    Homework(const std::string& title, const std::string& object,
             const int& numberOfPages, const std::string& name)
             :studentName(name),
              title(title),
              numberOfPages(numberOfPages),
              object(object)
             {
             }

    Homework(const Homework& rhs, const std::string& newName){
            this->studentName= newName;
            this->title= rhs.title;
            this->numberOfPages= rhs.numberOfPages;
            this->object= rhs.object;
    }//you might not be able to simply assign a homework, but you can copy one. You only need to change your name.

    void showHomework(){
        if(this->numberOfPages == 0)
        cout << "My dog ate my homework\n";
        else
        cout << "My name is "<< this->studentName <<". My homework for the object "<< this->object <<" is titled:" << this->title <<" and has a number of " << this->numberOfPages <<" pages\n";
    }

    private:
    std::string studentName;
    std::string title;
    int numberOfPages;
    std::string object;

    Homework& operator=(const Homework&); //Only declared, because you can't simply assign a homework of an another student.
                                          //Also, we want to show that we dont want the compiler to silently write and call this function.
};


int main()
{
    Homework e1("First Homework","IEP",2, "Denis");
    Homework e2(e1,"Jhon");
    Homework e3("", "", 0, "");

    e1.showHomework();
    e2.showHomework();
    e3.showHomework();
    //e3=e2;// if you excluse the first comment dashes it will give you a warning for    
}