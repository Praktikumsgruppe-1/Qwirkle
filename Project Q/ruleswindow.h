/**********************************************************************/
// Datei: ruleswindow.h
// Die Klasse rulesWindow enthaelt ein QWidget um ein neues Fenster bei
// Bedarf zu oeffnen, wo die Regeln dargestellt werden.
/**********************************************************************/
#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QWidget>

namespace Ui
{
class rulesWindow;
}

class rulesWindow : public QWidget
{
    Q_OBJECT

public:
    explicit rulesWindow( QWidget *parent = nullptr );
    ~rulesWindow( );

    void showRules( );

private slots:
    void on_pushButton_clicked( );

private:
    Ui::rulesWindow *ui;
};

#endif // RULESWINDOW_H
