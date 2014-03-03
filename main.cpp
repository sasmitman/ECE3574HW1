#include <QDate>
#include <QFile>
#include <QString>
#include <QList>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
#include "Birthdays.h"
#include "BirthdayList.h"


int main(int argc, char *argv[])
{
//    //Opening a file
//    QString path = "birthdays.dat";
//    QFile input(path);
//    input.open(QIODevice::ReadOnly);
//    QTextStream stream(&input);


//    QList<Birthdays> *bdays = new QList<Birthdays>();    //construct an empty list
//    while(!stream.atEnd())
//    {
//        QString line = stream.readLine();   //extract the line into "line"
//        QStringList temp = line.split("\t");    //split "line" into name and date

//        QString temp_name = temp[0];        //make "temp_name", line[0]
//        QString whole_date = temp[1];       //make "whole_date", line[1]


//        Birthdays *temp2 = new Birthdays( temp_name, whole_date );
//        bdays->append(*temp2);
//    }
//    input.close();


//    qDebug() << bdays->size();
//    QList<Birthdays>::iterator i;
//    for(i = bdays->begin(); i < bdays->end(); i++)
//    {
//        Birthdays current = *i;
//        qDebug() << current.getName();
//    }
    BirthdayList *theList = new BirthdayList();
    theList->init();
    //theList->outputAll();


//    if((QString)argv[1] == "-a")
//    {
//        QString name = (QString)(argv[3]);
//        name += " ";
//        name += (QString)(argv[4]);

//        Birthdays *temp = new Birthdays( name, argv[2] );   //create new Birthdays
//        bdays->append(*temp);   //add to list


//    }

//    QList<Birthdays>::iterator i;
//    for(i = bdays->begin(); i < bdays->end(); i++)
//    {
//        Birthdays current = *i;
//        qDebug() << current.getName();
//        qDebug() << current.getDate().toString("yyyy.MM.dd");
//    }

    return 0;
}

