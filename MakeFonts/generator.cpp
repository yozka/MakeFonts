#include "generator.h"
#include <QDataStream>
#include <QVector>


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

		if (!mData.contains(utf))
		{
			mData.append(utf);
		}
	}
}




//convert to UTF8
uint AGenerator :: convertToUTF8(const QString &character) const
{
	auto ucs = character.toUcs4();
	
	switch ( ucs.size())
	{
		case 1 :
			{
				return ucs[0];
			}
		case 2 :
			{
				uint data = ucs[0] | ucs[1] << 8;
				return data;
			}
		case 3 :
			{
				uint data = ucs[0] | (ucs[1] << 8) | (ucs[2] << 16);
				return data;
			}
	}
	return 0;
}


//создать описание шрифта
QString AGenerator :: build(const QString &nameFont, const int sizeFont)
{
	qSort(mData);
	QStringList source;
	
	source.append("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	source.append("<XnaContent xmlns:Graphics=\"Microsoft.Xna.Framework.Content.Pipeline.Graphics\">");
	source.append("<Asset Type=\"Graphics:FontDescription\">");
	source.append("<FontName>" + nameFont + "</FontName>");
	source.append("<Size>" + QString::number(sizeFont) + "</Size>");
	source.append("<Spacing>0</Spacing>");
	source.append("<UseKerning>true</UseKerning>");
	source.append("<Style>Regular</Style>");
	source.append("<DefaultCharacter>*</DefaultCharacter>");
	source.append("<CharacterRegions>");

	source.append(toRegion(38, 63));

	uint literStart = 0;
	uint literEnd = 0;
	uint next = 0;
	for (auto item = mData.cbegin(); item != mData.cend(); ++item)
	{
		uint liter = *item;
		if (next != liter && literStart != 0 && literEnd != 0)
		{
			source.append(toRegion(literStart, literEnd));
			literStart = 0;
			literEnd = 0;
		}

		if (literStart == 0)
		{
			literStart = liter;
			next = liter;
		}

		literEnd = liter;
		next++;
	}

	source.append(toRegion(literStart, literEnd));



	source.append("</CharacterRegions>");
	source.append("</Asset>");
	source.append("</XnaContent>");
	return source.join("\n");
}


//convert to XML 
QStringList AGenerator :: toRegion(const uint literStart, const uint literEnd) const
{
	QString start = QString::number(literStart);
	QString end = QString::number(literEnd);

	QStringList region;
	region.append("<CharacterRegion>");
	region.append("   <Start>&#" + start + ";</Start>");
	region.append("   <End>&#" + end + ";</End>");
	region.append("</CharacterRegion>");

	return region;
}