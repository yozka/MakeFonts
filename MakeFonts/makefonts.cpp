#include "makefonts.h"
#include <QFileDialog>
#include <QSettings>
#include <QCloseEvent>
#include <QList>
#include <QTextStream>

#include "text.h"
#include "generator.h"


MakeFonts::MakeFonts(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initHeader();	

	connect(ui.butAddTextFile, SIGNAL(clicked()), this, SLOT(slot_addTextFile()));
	connect(ui.butRemoveTextFile, SIGNAL(clicked()), this, SLOT(slot_removeTextFile()));
	connect(ui.butAddFont, SIGNAL(clicked()), this, SLOT(slot_addFont()));
	connect(ui.butRemoveFont, SIGNAL(clicked()), this, SLOT(slot_removeFont()));
	

	connect(ui.butGenerate, SIGNAL(clicked()), this, SLOT(slot_generate()));

	readSettings();
}


MakeFonts::~MakeFonts()
{

}


void MakeFonts :: closeEvent(QCloseEvent *e)
{
      saveSettings();
      e->accept();
}


void MakeFonts :: readSettings()
{
	const QString nameGroup = qApp->applicationFilePath();
	QSettings settings("make_fonts");
	QString name = settings.value(nameGroup).toString();
	if (name.isEmpty())
	{
		name = nameGroup;
	}
	ui.settingName->setText(name);
	settings.beginGroup(name);


	//read filenames
	const int filesCount = settings.value("filesCount").toInt();
	ui.tableTexts->setRowCount(filesCount);

	for (int i = 0; i < filesCount; i++)
	{
		QString fileName = settings.value("file_" + QString::number(i)).toString();
		ui.tableTexts->setItem(i, 0, new QTableWidgetItem (fileName));
	}
	//



	//read fonts
	const int fontsCount = settings.value("fontsCount").toInt();
	ui.tableFonts->setRowCount(fontsCount);

	for (int i = 0; i < fontsCount; i++)
	{
		ui.tableFonts->setItem(i, 0, new QTableWidgetItem (settings.value("font0_" + QString::number(i)).toString()));
		ui.tableFonts->setItem(i, 1, new QTableWidgetItem (settings.value("font1_" + QString::number(i)).toString()));
		ui.tableFonts->setItem(i, 2, new QTableWidgetItem (settings.value("font2_" + QString::number(i)).toString()));
	}
	//

	settings.endGroup();

}



void MakeFonts::saveSettings()
{
	QSettings settings("make_fonts");

	QString name = ui.settingName->text();
	settings.setValue(qApp->applicationFilePath(), name);

	settings.beginGroup(name);
	
	//save filenames
	const int filesCount = ui.tableTexts->rowCount();
	settings.setValue("filesCount", filesCount);
	for (int i = 0; i < filesCount; i++)
	{
		QString fileName =ui.tableTexts->item(i, 0)->text();
		settings.setValue("file_" + QString::number(i), fileName);
	}
	//


	//save fonts
	const int fontsCount = ui.tableFonts->rowCount();
	settings.setValue("fontsCount", fontsCount);
	for (int i = 0; i < fontsCount; i++)
	{
		if (ui.tableFonts->item(i, 0))
		{
			settings.setValue("font0_" + QString::number(i), ui.tableFonts->item(i, 0)->text());
		}

		if (ui.tableFonts->item(i, 1))
		{
			settings.setValue("font1_" + QString::number(i), ui.tableFonts->item(i, 1)->text());
		}

		if (ui.tableFonts->item(i, 2))
		{
			settings.setValue("font2_" + QString::number(i), ui.tableFonts->item(i, 2)->text());
		}
	}

	settings.endGroup();
}




void MakeFonts :: initHeader()
{
	ui.tableTexts->clear();
	ui.tableTexts->setRowCount(0);
	ui.tableTexts->setColumnCount(1);
	ui.tableTexts->setHorizontalHeaderLabels(QString("Text files").split(";"));	
	ui.tableTexts->horizontalHeader()->setVisible(true);


	ui.tableFonts->clear();
	ui.tableFonts->setRowCount(0);
	ui.tableFonts->setColumnCount(3);
	ui.tableFonts->setHorizontalHeaderLabels(QString("Font name;Font size;File path").split(";"));	
	ui.tableFonts->horizontalHeader()->setVisible(true);

}



//добавление файла с текстом для анализа
void MakeFonts :: slot_addTextFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("Файл с текстом"));
	if (!fileName.isEmpty())
	{
		int row = ui.tableTexts->rowCount();
		ui.tableTexts->insertRow(row);
		ui.tableTexts->setItem(row, 0, new QTableWidgetItem (fileName));
	}

}


//удаление текущего выделеного файла
void MakeFonts :: slot_removeTextFile()
{
	QModelIndexList indexes =  ui.tableTexts->selectionModel()->selectedRows();
	qSort(indexes);
	int countRow = indexes.count();
	for( int i = countRow; i > 0; i--)
	{
       ui.tableTexts->removeRow(indexes.at(i-1).row());
	}
}



//добавление шрифта
void MakeFonts :: slot_addFont()
{
	QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("Выходной Файл с описанием шрифта"));
	if (!fileName.isEmpty())
	{
		int row = ui.tableFonts->rowCount();
		ui.tableFonts->insertRow(row);

		ui.tableFonts->setItem(row, 0, new QTableWidgetItem (QString()));
		ui.tableFonts->setItem(row, 1, new QTableWidgetItem (QString()));
		ui.tableFonts->setItem(row, 2, new QTableWidgetItem (fileName));
	}
}


//удаление шрифта
void MakeFonts :: slot_removeFont()
{
	QModelIndexList indexes =  ui.tableFonts->selectionModel()->selectedRows();
	qSort(indexes);
	int countRow = indexes.count();
	for( int i = countRow; i > 0; i--)
	{
       ui.tableFonts->removeRow(indexes.at(i-1).row());
	}
}



//генерация выходных файлов
void MakeFonts :: slot_generate()
{
	AGenerator generator;

	const int filesCount = ui.tableTexts->rowCount();
	for (int i = 0; i < filesCount; i++)
	{
		const QString fileName =ui.tableTexts->item(i, 0)->text();
		AText text;
		if (!text.loadFile(fileName))
		{
			continue;
		}
		generator.appendChars(text.chars());
	}
	//


	const int fontsCount = ui.tableFonts->rowCount();
	for (int i = 0; i < fontsCount; i++)
	{
		const QString nameFont =  ui.tableFonts->item(i, 0)->text();
		const int sizeFont = ui.tableFonts->item(i, 1)->text().toInt();
		const QString fileName = ui.tableFonts->item(i, 2)->text();
		if (nameFont.isEmpty() || sizeFont <= 0 || fileName.isEmpty())
		{
			continue;
		}

		const QString source = generator.build(nameFont, sizeFont);
		
		QFile file(fileName);
		if (file.open(QIODevice::ReadWrite | QIODevice::Truncate)) 
		{
			QTextStream stream(&file);
			stream << source << endl;
			file.close();
		}
	}





}