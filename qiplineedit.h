#ifndef QIPLINEEDIT_H
#define QIPLINEEDIT_H

#include <QLineEdit>
#include <QEvent>

class QIpLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    QIpLineEdit(QWidget *parent = Q_NULLPTR);
    ~QIpLineEdit();

    void setText(const QString &strIP);
    QString text() const;
    bool getText(QString &strIP);
    void setIp(uint8_t *ip);
    void getIp(uint8_t *ip);
protected:
    void paintEvent(QPaintEvent *event);
    bool eventFilter(QObject *obj, QEvent *ev);

    int getIndex(QLineEdit *pEdit);
    bool isTextValid(const QString &strIP);
private:
    QLineEdit *m_lineEidt[4];

};

#endif // QIPLINEEDIT_H
