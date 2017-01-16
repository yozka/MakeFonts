#pragma once
#include <QString>
#include <QMap>
#include <QStringList>

class AText

{
public:

	AText(); //constructor
	virtual ~AText(); //destructor


	bool loadFile(const QString &fileName); //load from text file and parser
	QStringList chars()const; //return all loading schars

private:


	QMap<QString, int> mChars;

};

