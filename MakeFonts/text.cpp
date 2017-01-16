#include "text.h"
#include <QFile>
#include <QTextStream>


//constructor
AText :: AText()
{

}



//destructor
AText :: ~AText()
{

}



//load from text file and parser
bool AText :: loadFile(const QString &fileName)
{
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly)) 
	{
		return false;
	}

	QTextStream in(&file);
	const QString data = in.readAll();
	file.close();

	mChars.clear();

	for (auto item = data.cbegin(); item != data.cend(); ++item)
	{
		const QString ch = *item;
		if (ch == "\n" || ch == "\r" || ch == "\t")
		{
			continue;
		}
		int count = 0;
		if (mChars.contains(ch))
		{
			count = mChars[ch];
		}
		mChars[ch] = count + 1;
	}

	return true;
}


//return all loading schars
QStringList AText :: chars() const
{
	return mChars.keys();
}