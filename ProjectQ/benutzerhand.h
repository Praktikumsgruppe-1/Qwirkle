#ifndef BENUTZERHAND_H
#define BENUTZERHAND_H

#include <QFrame>

class Benutzerhand : public QFrame
{
public:
    explicit Benutzerhand(QWidget *parent = nullptr);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

extern int randInt(int low, int high);
extern QPixmap getPixmap( int a, int b);

#endif // BENUTZERHAND_H
