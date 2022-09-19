#ifndef QMACLINEEDIT_H
#define QMACLINEEDIT_H

#include <QLineEdit>
#include <QEvent>

class QMacLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    QMacLineEdit(QWidget *parent = Q_NULLPTR);
    ~QMacLineEdit();

    void setMac(uint8_t *mac);
    void getMac(uint8_t *mac);
    QString text() const;
    bool getText(QString &strMac);
protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *obj, QEvent *ev);

    int getIndex(QLineEdit *pEdit);
    bool isTextValid(const QString &strMac);
private:
    QLineEdit *m_lineEidt[6];

};

#endif // QMACLINEEDIT_H
