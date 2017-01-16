#pragma once
#include <QString>
#include <QStringList>
#include <QList>




class AGenerator

{
public:

	AGenerator(); //constructor
	virtual ~AGenerator(); //destructor


	void appendChars(const QStringList &chars); //append new chars

private:


	QList<uint> mData;



	uint convertToUTF8(const QString &character) const; //convert to UTF8

};

