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

	void slot_addTextFile();	//���������� ����� � ������� ��� �������
	void slot_removeTextFile(); //�������� �������� ���������� �����
	
	void slot_addFont();		//���������� ������
	void slot_removeFont();		//�������� ������
	
	void slot_generate();		//��������� �������� ������
};

#endif // MAKEFONTS_H
