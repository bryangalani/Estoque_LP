#include "menu.h"
#include "ui_menu.h"

QVector<Refrigerados> refrigerado;
QVector<Quentes> quente;
QVector<Snacks> snack;


Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    hideButtons();
}

Menu::~Menu()
{
    delete ui;

}

void Menu::hideButtons(){

    ui->lb_val->setHidden(true);
    ui->lb_temp->setHidden(true);
    ui->lb_sabor->setHidden(true);

    ui->le_sabor->setHidden(true);
    ui->le_validade->setHidden(true);
    ui->le_temp->setHidden(true);

    ui->pushButton->setEnabled(false);
}

void Menu::on_cb_Refrigerado_clicked(bool checked)
{
    if(checked){
       ui->le_temp->setHidden(false);
       ui->lb_temp->setHidden(false);

       ui->pushButton->setEnabled(true);

       ui->cb_Quentes->setEnabled(false);
       ui->cb_Snack->setEnabled(false);

       ui->lb_sabor->setHidden(true);
       ui->lb_val->setHidden(true);

       ui->le_validade->setHidden(true);
       ui->lb_val->setHidden(true);


    }else{
        ui->pushButton->setEnabled(false);
        ui->le_temp->setHidden(true);
        ui->lb_temp->setHidden(true);
        desativar();
    }
}

void Menu::on_cb_Quentes_clicked(bool checked)
{
    if(checked){
        ui->le_validade->setHidden(false);
        ui->lb_val->setHidden(false);

        ui->pushButton->setEnabled(true);

        ui->cb_Refrigerado->setEnabled(false);
        ui->cb_Snack->setEnabled(false);

        ui->lb_sabor->setHidden(true);
        ui->le_sabor->setHidden(true);

        ui->le_temp->setHidden(true);
        ui->lb_temp->setHidden(true);
    }else{
        ui->pushButton->setEnabled(false);
        ui->le_validade->setHidden(true);
        ui->lb_val->setHidden(true);
        desativar();
    }

}

void Menu::on_cb_Snack_clicked(bool checked)
{
    if(checked){
        ui->lb_sabor->setHidden(false);
        ui->le_sabor->setHidden(false);

        ui->pushButton->setEnabled(true);

        ui->cb_Refrigerado->setEnabled(false);
        ui->cb_Quentes->setEnabled(false);

        ui->le_validade->setHidden(true);
        ui->lb_val->setHidden(true);

        ui->le_temp->setHidden(true);
        ui->lb_temp->setHidden(true);
    }else{
        ui->pushButton->setEnabled(false);
        ui->lb_sabor->setHidden(true);
        ui->le_sabor->setHidden(true);
        desativar();
    }

}

void Menu::desativar(){
    ui->cb_Quentes->setEnabled(true);
    ui->cb_Refrigerado->setEnabled(true);
    ui->cb_Snack->setEnabled(true);
}

void Menu::on_pushButton_clicked()
{
    if(ui->cb_Refrigerado->isChecked()){
        Refrigerados elemento;
        int el_quantidade = ui->le_quantidade->value();
        string el_nome = ui->le_nome->text().toStdString();
        float el_temperatura = ui->le_temp->text().toFloat();
        cout << el_temperatura << endl;

        elemento.set_quantidade(el_quantidade);
        elemento.set_nome(el_nome);
        elemento.set_temp(el_temperatura);
        cout << elemento.get_temp() << endl;

        refrigerado.append(elemento);
        cout.precision(2);
        QStringListModel *model = new QStringListModel();
        QStringList list;
        for(int i = 0; i <refrigerado.length(); i++){
            QString txt;
            if(i ==0){
                txt.append("REFRIGERADOS: \n");
            }
            txt.append("Item: " + QString::fromStdString(refrigerado[i].get_nome())+
                       ",  Quantidade: " + QString::fromStdString(to_string(refrigerado[i].get_quantidade())) +
                       ",  Temperatura: " + QString::fromStdString(to_string(refrigerado[i].get_temp()) +"ºC"));
            list.append(txt);
        }

        //mostra uma lista de anotações
        model->setStringList(list);
        ui->listView_menu->setModel(model);

        ui->le_nome->clear();
        ui->le_quantidade->clear();
        ui->le_temp->clear();

    }else if (ui->cb_Quentes->isChecked()){

        Quentes elemento;
        int el_quantidade = ui->le_quantidade->value();
        string el_nome = ui->le_nome->text().toStdString();
        int el_validade = ui->le_validade->text().toInt();

        elemento.set_quantidade(el_quantidade);
        elemento.set_nome(el_nome);
        elemento.set_validade(el_validade);

        quente.append(elemento);


        QStringListModel *model = new QStringListModel();
        QStringList list;
        for(int i = 0; i <quente.length(); i++){
            QString txt;
            if(i ==0){
                txt.append("QUENTES: \n");
            }
            txt.append("Item: " + QString::fromStdString(quente[i].get_nome())+
                       ",  Quantidade: " + QString::fromStdString(to_string(quente[i].get_quantidade())) +
                       ",  Validade: " + QString::fromStdString(to_string(quente[i].get_validade())) +" meses");
            list.append(txt);
        }

        model->setStringList(list);
        ui->listView_menu->setModel(model);

        ui->le_nome->clear();
        ui->le_quantidade->clear();
        ui->le_validade->clear();

    }else if (ui->cb_Snack->isChecked()){

        Snacks elemento;
        int el_quantidade = ui->le_quantidade->value();
        string el_nome = ui->le_nome->text().toStdString();
        string el_sabor = ui->le_sabor->text().toStdString();

        elemento.set_quantidade(el_quantidade);
        elemento.set_nome(el_nome);
        elemento.set_sabor(el_sabor);

        snack.append(elemento);


        QStringListModel *model = new QStringListModel();
        QStringList list;
        for(int i = 0; i <snack.length(); i++){
            QString txt;
            if(i ==0){
                txt.append("SNACKS: \n");
            }
            txt.append("Item: " + QString::fromStdString(snack[i].get_nome())+
                       ",  Quantidade: " + QString::fromStdString(to_string(snack[i].get_quantidade())) +
                       ",  Sabor: " + QString::fromStdString(snack[i].get_sabor()) );
            list.append(txt);
        }

        model->setStringList(list);
        ui->listView_menu->setModel(model);

        ui->le_nome->clear();
        ui->le_quantidade->clear();
        ui->le_sabor->clear();
    }



}




void Menu::on_pb_show_clicked()
{
    QStringListModel *model = new QStringListModel();
    QStringList list;

    for(int i = 0; i <refrigerado.length(); i++){
        QString txt;
        if(i ==0){
            txt.append("REFRIGERADOS: \n");
        }
        txt.append("Item: " + QString::fromStdString(refrigerado[i].get_nome())+
                   ",  Quantidade: " + QString::fromStdString(to_string(refrigerado[i].get_quantidade())) +
                   ",  Temperatura: " + QString::fromStdString(to_string(refrigerado[i].get_temp())) +"ºC");
        list.append(txt);
    }

    for(int i = 0; i <quente.length(); i++){
        QString txt;
        if(i ==0){
            txt.append("\n QUENTES: \n");
        }
        txt.append("Item: " + QString::fromStdString(quente[i].get_nome())+
                   ",  Quantidade: " + QString::fromStdString(to_string(quente[i].get_quantidade())) +
                   ",  Validade: " + QString::fromStdString(to_string(quente[i].get_validade())) +" meses");
        list.append(txt);
    }

    for(int i = 0; i <snack.length(); i++){
        QString txt;
        if(i ==0){
            txt.append("\n SNACKS: \n");
        }
        txt.append("Item: " + QString::fromStdString(snack[i].get_nome())+
                   ",  Quantidade: " + QString::fromStdString(to_string(snack[i].get_quantidade())) +
                   ",  Sabor: " + QString::fromStdString(snack[i].get_sabor()) );
        list.append(txt);
    }

    model->setStringList(list);
    ui->listView_menu->setModel(model);
    }



void Menu::on_pb_media_clicked()
{
    float med;
    string tipo;
    if(ui->cb_Refrigerado->isChecked()){
        med = media(refrigerado);
        tipo = " 'Refrigerados' ";
    }else if (ui->cb_Quentes->isChecked()){
        med = media(quente);
        tipo = " 'Quentes' ";
    }else if (ui->cb_Snack->isChecked()){
        med = media(snack);
        tipo = " 'Snacks' ";
    }

    QStringListModel *model = new QStringListModel();
    QStringList list;
    QString txt;
    txt.append("A média da quantidade dos itens"+ QString::fromStdString(tipo) + "é: " + QString::fromStdString(to_string(med)));
    list.append(txt);

    model->setStringList(list);
    ui->listView_menu->setModel(model);

}

float Menu::media(QVector<Refrigerados> elementos){
    cout << "refrig" << endl;
    if(elementos.length() != 0){
    float sum = 0.0;
    for(int i = 0 ; i < elementos.length() ; i++){
         sum += elementos[i].get_quantidade();
    }
    sum = sum/elementos.length();
    cout << sum << endl;
        return sum;
    }
    return 0.0;
}
float Menu::media(QVector<Quentes> elementos){
    cout << "quent" << endl;
    if(elementos.length() != 0){
    float sum = 0.0;
    for(int i = 0 ; i < elementos.length() ; i++){
         sum += elementos[i].get_quantidade();
    }
    sum = sum/elementos.length();
    cout << sum << endl;
    return sum;
    }
    return 0.0;

}
float Menu::media(QVector<Snacks> elementos){
    cout << "snack" << endl;
    if(elementos.length() != 0){
    float sum = 0.0;
    for(int i = 0 ; i < elementos.length() ; i++){
         sum += elementos[i].get_quantidade();
    }
    sum = sum/elementos.length();
    cout << sum << endl;
    return sum;
    }
    return 0.0;
}



