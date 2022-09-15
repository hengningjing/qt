#pragma execution_character_set("utf-8")
#include "demo.h"
#include "QDir"
#include "QFileDialog"
#include "QTextStream"

Demo::Demo(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	setCentralWidget(ui.tabWidget);
}

void Demo::on_actOpen_IODevice_triggered()
{
	QString curPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
	QString dlgTitle = "��һ���ļ�"; //�Ի������
	QString filter = "�����ļ�(*.h *.cpp);;�ı��ļ�(*.txt);;�����ļ�(*.*)"; //�ļ�������
	QString fileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

	if (fileName.isEmpty())
		return;

	openTextByIODevice(fileName);
}

void Demo::on_actOpen_TextStream_triggered()
{
	QString curPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
	QString dlgTitle = "��һ���ļ�"; //�Ի������
	QString filter = "�����ļ�(*.h *.cpp);;�ı��ļ�(*.txt);;�����ļ�(*.*)"; //�ļ�������
	QString fileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);

	if (fileName.isEmpty())
		return;

	openTextByStream(fileName);
}

void Demo::on_actSave_IODevice_triggered()
{
	QString curPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
	QString dlgTitle = "���Ϊһ���ļ�"; //�Ի������
	QString filter = "h�ļ�(*.h);;c++�ļ�(*.cpp);;�ı��ļ�(*.txt);;�����ļ�(*.*)"; //�ļ�������
	QString fileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);

	if (fileName.isEmpty())
		return;

	saveTextByIODevice(fileName);
}

void Demo::on_actSave_TextStream_triggered()
{
	QString curPath = QDir::currentPath();//��ȡϵͳ��ǰĿ¼
	QString dlgTitle = "���Ϊһ���ļ�"; //�Ի������
	QString filter = "h�ļ�(*.h);;c++�ļ�(*.cpp);;�ı��ļ�(*.txt);;�����ļ�(*.*)"; //�ļ�������
	QString fileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);

	if (fileName.isEmpty())
		return;

	saveTextByStream(fileName);
}

bool Demo::openTextByIODevice(QString fileName)
{
	QFile   file(fileName);

	if (!file.exists()) //�ļ�������
		return false;

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // ��ʧ��
		return false;

	ui.pTEIoDevice->setPlainText(file.readAll());
	
	file.close();
	ui.tabWidget->setCurrentIndex(0);

	return  true;
}

bool Demo::openTextByStream(QString fileName)
{
	QFile   file(fileName);

	if (!file.exists()) //�ļ�������
		return false;

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // ��ʧ��
		return false;

	QTextStream stream(&file); //���ı�����ȡ�ļ�

	ui.pTETextStream->setPlainText(stream.readAll());

	file.close();
	ui.tabWidget->setCurrentIndex(1);

	return  true;
}

bool Demo::saveTextByIODevice(QString fileName)
{
	QFile   file(fileName);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;

	QString str = ui.pTEIoDevice->toPlainText();//����������Ϊ�ַ���

	QByteArray  strBytes = str.toUtf8();//ת��Ϊ�ֽ�����

	file.write(strBytes, strBytes.length());  //д���ļ�

	file.close();
	ui.tabWidget->setCurrentIndex(0);
	return  true;
}

bool Demo::saveTextByStream(QString fileName)
{
	QFile   file(fileName);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;

	QTextStream aStream(&file); //���ı�����ȡ�ļ�

	QString str = ui.pTETextStream->toPlainText(); //ת��Ϊ�ַ���

	aStream << str; //д���ı���

	file.close();//�ر��ļ�

	return  true;
}
