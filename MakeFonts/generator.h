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
	QString build(const QString &nameFont, const int sizeFont); //создать описание шрифта

private:


	QList<uint> mData;



	uint convertToUTF8(const QString &character) const; //convert to UTF8
	QStringList toRegion(const uint literStart, const uint literEnd) const;//convert to XML 
};

