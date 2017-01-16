#include "generator.h"
#include <QDataStream>



//constructor
AGenerator :: AGenerator()
{


}


//destructor
AGenerator :: ~AGenerator()
{

}



//append new chars
void AGenerator :: appendChars(const QStringList &chars)
{
	for (auto item = chars.cbegin(); item != chars.cend(); ++item)
	{
		const QString ch = *item;
		uint utf = convertToUTF8(ch);
		if (utf == 0)
		{
			continue;
		}


		

	}
}




//convert to UTF8
uint AGenerator :: convertToUTF8(const QString &character) const
{
	auto character.toUcs4(
	
		/*
	const QByteArray UTF8 = character.toUtf8();
	switch ( UTF8.size())
	{
		case 1 :
			{
				return UTF8[0];
			}
		case 2 :
			{
				uint data = 0;
				memcpy(&data, UTF8, 2);
				return data;
			}
		case 3 :
			{
				uint data = 0;
				memcpy(&data, UTF8, 3);
				return data;
			}

	}*/
	return 0;
}