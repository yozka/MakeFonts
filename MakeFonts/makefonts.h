#ifndef MAKEFONTS_H
#define MAKEFONTS_H

#include <QtWidgets/QDialog>
#include "ui_makefonts.h"

class MakeFonts : public QDialog
{
	Q_OBJECT

public:
	MakeFonts(QWidget *parent = 0);
	~MakeFonts();

private:
	Ui::MakeFontsClass ui;

	void initHeader();

	void readSettings();
	void saveSettings();

	void closeEvent(QCloseEvent *e);

public slots:

	void slot_addTextFile();	//добавление файла с текстом для анализа
	void slot_removeTextFile(); //удаление текущего выделеного файла
	
	void slot_addFont();		//добавление шрифта
	void slot_removeFont();		//удаление шрифта
	
	void slot_generate();		//генерация выходных файлов
};

#endif // MAKEFONTS_H
