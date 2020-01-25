#ifndef BENUTZERHAND_H
#define BENUTZERHAND_H

#include <QFrame>

class Benutzerhand : public QFrame
{
public:
    explicit Benutzerhand(QWidget *parent = nullptr, int a = 0, int b = 0);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

extern int randInt(int low, int high);
extern QPixmap getPixmap( int a, int b);
extern int getFarbePixmap( QPixmap );
extern int getFormPixmap( QPixmap );

#endif // BENUTZERHAND_H
