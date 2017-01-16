#include "makefonts.h"
#include <QFileDialog>
#include <QSettings>
#include <QCloseEvent>
#include <QList>

#include "text.h"
#include "generator.h"


MakeFonts::MakeFonts(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initHeader();	

	connect(ui.butAddTextFile, SIGNAL(clicked()), this, SLOT(slot_addTextFile()));
	connect(ui.butRemoveTextFile, SIGNAL(clicked()), this, SLOT(slot_removeTextFile()));
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



	settings.endGroup();
}




void MakeFonts :: initHeader()
{
	ui.tableTexts->clear();
	ui.tableTexts->setRowCount(0);
	ui.tableTexts->setColumnCount(1);
	ui.tableTexts->setHorizontalHeaderLabels(QString("Text files").split(";"));	
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





}