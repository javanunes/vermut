#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class FORM;
}

namespace DarCu{
  class QMainWindow;
}

class FORM : public QMainWindow
{
    Q_OBJECT

public:
    explicit FORM(QWidget *parent = 0);
    ~FORM();
    QString executor="xterm -e ";
    void CyndiLooper(QString aviso){
        QMessageBox msgBox;
        msgBox.setText(aviso);
        msgBox.exec();
    }

    QString User(){
        QString login = qEnvironmentVariable("USER");
        return login;
    }

    void Alert(QString mensagem){
        QMessageBox msgBox;
        msgBox.setText(mensagem);
        msgBox.exec();
    }


private slots:
    void on_pushButton_clicked();

    void on_botaoAtaque_clicked();

    void on_butaoPrepare_clicked();

    void on_buttonWifite_clicked();

    void on_buttonAirodump_clicked();

    void on_radioButton_clicked();

private:
    Ui::FORM *ui;
};

#endif // FORM_H
