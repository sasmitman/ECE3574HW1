#ifndef BIRTHDAYLIST_H
#define BIRTHDAYLIST_H

#include <QDebug>
#include <QDate>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QList>
#include "Birthdays.h"
#include "BdayException.h"

class BirthdayList
{
private:
    QList<Birthdays>* bday_list;
    int size;

    bool nameCheck( QString name );
    bool dateCheck( QString date );
public:
    BirthdayList();
    ~BirthdayList();

    void init();
    void clear();
    void addBday( QString newName, QString newDate );
    void removeBday(QString data);
    QList<Birthdays>::iterator findBday(QString data);

    void outputAll();

};

///////////////////////////////////
//PRIVATE MEMBER FUNCTIONS
/////////////////////////////////

//Checks if a name has any non letters other than "'"
bool BirthdayList::nameCheck(QString name)
{
    for(int i = 0; i <= 38; i++){
        char ascii = 0;
        if(name.contains(ascii)) return false;
        else ascii++;
    }

    for(int i = 40; i <= 96; i++){
        char ascii = 0;
        if(name.contains(ascii)) return false;
        else ascii++;
    }

    for(int i = 123; i <= 127; i++){
        char ascii = 0;
        if(name.contains(ascii)) return false;
        else ascii++;
    }
    return true;
}


//checks if a date has any non-numbers other than "-"
bool BirthdayList::dateCheck(QString date)
{
    for(int i = 0; i <= 44; i++){
        char ascii = 0;
        if(date.contains(ascii)) return false;
        else ascii++;
    }

    for(int i = 46; i <= 47; i++){
        char ascii = 0;
        if(date.contains(ascii)) return false;
        else ascii++;
    }

    for(int i = 58; i <= 127; i++){
        char ascii = 0;
        if(date.contains(ascii)) return false;
        else ascii++;
    }
    return true;
}

///////////////////////////////////
//PUBLIC MEMBER FUNCTIONS
/////////////////////////////////

//constructor
BirthdayList::BirthdayList() : bday_list(), size(0)
{

}

//destructor
BirthdayList::~BirthdayList()
{
    clear();
}

//Initializes a list
void BirthdayList::init()
{
    //Opening a file
    QString path = "birthdays.dat";
    QFile input(path);
    input.open(QIODevice::ReadOnly);
    QTextStream stream(&input);


    //QList<Birthdays> *bdays = new QList<Birthdays>();    //construct an empty list
    while(!stream.atEnd())
    {
        QString line = stream.readLine();   //extract the line into "line"
        QStringList temp = line.split("\t");    //split "line" into name and date

        QString temp_name = temp[0];        //make "temp_name", line[0]
        QString whole_date = temp[1];       //make "whole_date", line[1]

        addBday( temp_name, whole_date );
    }
    input.close();

    qDebug() << "size is " << size;
}

//clears birthday list
void BirthdayList::clear()
{
    bday_list->clear();
    size = 0;
}

//add a birthday to the list with inputs of name and date strings
 void BirthdayList::addBday( QString newName, QString newDate )
{
     try
     {
         if(!nameCheck( newName ))  //check if valid name string
             wrongInput.raise();
         else if(!nameCheck( newName )) //check if valid date string
             wrongInput.raise();
         else
         {
             Birthdays* temp = new Birthdays( newName, newDate );
             bday_list->append(*temp);
             size++;
         }
     }
     catch(BdayException &wrongInput)
     {
         qDebug() << newName << " is not acceptable as input.";
     }


}

//finds the birthday on the list and removes it
void BirthdayList::removeBday( QString data )
{
    bday_list->erase(findBday( data ));
    size--;
}

//finds the iterator on the list
QList<Birthdays>::iterator BirthdayList::findBday( QString data )
{
    //recognize if data is name or date
    try
    {
        if(nameCheck( data ))   //check if data is a name
        {
            QList<Birthdays>::iterator i;
            for(i = bday_list->begin(); i < bday_list->end(); i++)
            {
                Birthdays current = *i;
                if(current.getName() == data ) return i;
            }
        }
        else if( dateCheck( data ))    //check if data is a date
        {
            QList<Birthdays>::iterator i;
            for(i = bday_list->begin(); i < bday_list->end(); i++)
            {
                Birthdays current = *i;
                if(current.getDate().toString( "yyyy-MM-dd" ) == data ) return i;
            }
        }
        else nonExistant.raise();
    }
    catch(BdayException &nonExistant)
    {
        qDebug() << data << " is not in the database.";
    }

}

void BirthdayList::outputAll()
{
    QList<Birthdays>::iterator i;
    for(i = bday_list->begin(); i < bday_list->end(); i++)
    {
        Birthdays current = *i;
        qDebug() << current.getName() << "\t" << current.getDate();
    }
}

#endif // BIRTHDAYLIST_H

