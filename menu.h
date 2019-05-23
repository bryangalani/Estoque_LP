#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <string.h>
#include <string>
#include "itens.h"
#include<QStringListModel>
#include<iostream>
#include<cmath>

using namespace std;
namespace Ui {
class Menu;
}

class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_cb_Refrigerado_clicked(bool checked);

    void on_cb_Quentes_clicked(bool checked);

    void desativar();

    void hideButtons();

    void on_cb_Snack_clicked(bool checked);

    void on_pushButton_clicked();

    void on_pb_show_clicked();

    void on_pb_media_clicked();

    float media(QVector<Refrigerados> elementos);
    float media(QVector<Quentes> elementos);
    float media(QVector<Snacks> elementos);

private:
    Ui::Menu *ui;
};

#endif // MENU_H
