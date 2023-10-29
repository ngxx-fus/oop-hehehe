#ifndef _CUSTOMERS_H
#define _CUSTOMERS_H

#include "templateClass.h"

class _customers : public templateClass
{
private:
    int point;
    QString phoneNumber;
public:
    _customers(QString new_name = "none", QString new_phoneNumber = "none", int new_point = 0)
    //: QListWidgetItem(new_phoneNumber) //to notice QListWidgetItem know what will be showed in LIST
    {
        setName(new_name);
        setPhoneNumber(new_phoneNumber);
        setPoint(new_point);
        setID(generate_ID("cus"));
    }


    void setPhoneNumber(QString phoneNumber){
        this->phoneNumber = phoneNumber;
    }

    void setPoint(int point){
        this->point = point;
    }

    QString getPhoneNumber(){
        return this->phoneNumber;
    }

    int getPoint(){
        return this->point;
    }

    bool operator == (_customers o){
        if(
               this->getName() != o.getName()
            || this->getID() != o.getID()
            || this->getPhoneNumber() != o.getPhoneNumber()
            || this->getDOB() != o.getDOB()
          )
            return false;
        return true;
    }
};

#endif // _CUSTOMERS_H