﻿#include "qiplineedit.h"
#include <QRegExpValidator>
#include <QPainter>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

QIpLineEdit::QIpLineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    QRegExp regx("(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})"); //只能输入IP
    QHBoxLayout *pHBox = new QHBoxLayout(this);
    pHBox->setSpacing(10);
    pHBox->setContentsMargins(2, 2, 2, 2);  //不能设置为全0，否则四周的黑色边框无法正常显示
    for (int i = 0; i < 4; i++)
    {
        m_lineEidt[i] = new QLineEdit(this);
        m_lineEidt[i]->setFrame(false);
        m_lineEidt[i]->setMaxLength(3);
        m_lineEidt[i]->setAlignment(Qt::AlignCenter);
        m_lineEidt[i]->installEventFilter(this);
        m_lineEidt[i]->setAttribute(Qt::WA_InputMethodEnabled, false); //屏蔽中文输入法干扰
        QRegExpValidator *validator = new QRegExpValidator(regx, m_lineEidt[i]);
        m_lineEidt[i]->setValidator(validator);
        m_lineEidt[i]->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        pHBox->addWidget(m_lineEidt[i]);
    }
    this->setReadOnly(true);
}

QIpLineEdit::~QIpLineEdit()
{

}

void QIpLineEdit::paintEvent(QPaintEvent *event)
{
    QLineEdit::paintEvent(event);
    QPainter painter(this);
    QBrush brush;
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    brush.setColor(Qt::black);
    painter.setBrush(brush);

    int width = 0;
    for (int i = 0; i < 3; i++)
    {
        width += m_lineEidt[i]->width() + (i == 0 ? 3 : 10);//布局的间隔
        painter.drawEllipse(width, height() / 1.5 - 2, 1, 1);//IP地址之间的点点位置和大小
    }
}

int QIpLineEdit::getIndex(QLineEdit *pEdit)
{
    int index = -1;
    for (int i = 0; i < 4; i++)
    {
        if (pEdit == m_lineEidt[i])
            index = i;
    }
    return index;
}

bool QIpLineEdit::eventFilter(QObject *obj, QEvent *ev)
{
    if (children().contains(obj) && QEvent::KeyPress == ev->type())
    {
        QKeyEvent *keyEvent = dynamic_cast<QKeyEvent *>(ev);
        QLineEdit *pEdit = qobject_cast<QLineEdit *>(obj);
        switch (keyEvent->key())
        {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
        {
            QString strText = pEdit->text();
            if (pEdit->selectedText().length())
            {
                pEdit->text().replace(pEdit->selectedText(), QChar(keyEvent->key()));
            }
            else if (strText.length() == 3 || strText.length() < 3 && strText.toInt() * 10 > 255)
            {
                int index = getIndex(pEdit);
                if (index != -1 && index != 3)
                {
                    m_lineEidt[index + 1]->setFocus();
                    m_lineEidt[index + 1]->selectAll();
                }
            }
            else if (strText.length() == 2 && strText.toInt() * 10 < 255)
            {
                if (Qt::Key_0 == keyEvent->key() && strText.toInt())
                {
                    pEdit->setText(strText.insert(pEdit->cursorPosition(), QChar(Qt::Key_0)));
                }
            }
            return QLineEdit::eventFilter(obj, ev);
        }
        break;
        case Qt::Key_Backspace:
        {
            QString strText = pEdit->text();
            if (!strText.length() || strText.length() && !pEdit->cursorPosition())
            {
                int index = getIndex(pEdit);
                if (index != -1 && index != 0)
                {
                    m_lineEidt[index - 1]->setFocus();
                    int length = m_lineEidt[index - 1]->text().length();
                    m_lineEidt[index - 1]->setCursorPosition(length ? length : 0);
                }
            }
            return QLineEdit::eventFilter(obj, ev);
        }
        case Qt::Key_Left:
        {
            if (!pEdit->cursorPosition())
            {
                int index = getIndex(pEdit);
                if (index != -1 && index != 0)
                {
                    m_lineEidt[index - 1]->setFocus();
                    int length = m_lineEidt[index - 1]->text().length();
                    m_lineEidt[index - 1]->setCursorPosition(length ? length : 0);
                }
            }
            return QLineEdit::eventFilter(obj, ev);
        }
        case Qt::Key_Right:
        {
            if (pEdit->cursorPosition() == pEdit->text().length())
            {
                int index = getIndex(pEdit);
                if (index != -1 && index != 3)
                {
                    m_lineEidt[index + 1]->setFocus();
                    m_lineEidt[index + 1]->setCursorPosition(0);
                }
            }
            return QLineEdit::eventFilter(obj, ev);
        }
        case Qt::Key_Period:  //小数点
        {
            if (pEdit->cursorPosition() == pEdit->text().length())
            {
                int index = getIndex(pEdit);
                if (index != -1 && index != 3)
                {
                    m_lineEidt[index + 1]->setFocus();
                    m_lineEidt[index + 1]->setCursorPosition(0);
                    m_lineEidt[index + 1]->selectAll();
                }
            }
            return QLineEdit::eventFilter(obj, ev);
        }
        default:
            break;
        }
    }
    return false;
}

void QIpLineEdit::setText(const QString &strIP)
{
    if (!isTextValid(strIP))
    {
        return;
    }
    else
    {
        QStringList ipList = strIP.split(".");
        for(int i=0; i<ipList.size(); i++)
        {
            QString ip=ipList.at(i);
            m_lineEidt[i]->setText(ip);
        }
    }
}

bool QIpLineEdit::getText(QString &strIP)
{
    QString strIPtmp;
    for (int i = 0; i < 4; i++)
    {
        if(i>0)
        {
            strIPtmp.append(".");
        }

        if(0 == m_lineEidt[i]->text().size())
        {
            return false;
        }

        strIPtmp.append(m_lineEidt[i]->text());
    }

    strIP = strIPtmp;
    return true;
}

bool QIpLineEdit::isTextValid(const QString &strIP)
{
    QRegExp rx2("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");
    if (!rx2.exactMatch(strIP))
        return false;
    return true;
}

QString QIpLineEdit::text() const
{
    QString strIP;
    for (int i = 0; i < 4; i++)
    {
        if(i>0)
        {
            strIP.append(".");
        }
        strIP.append(m_lineEidt[i]->text());
    }
    return strIP;
}

void QIpLineEdit::setIp(uint8_t *ip)
{

    for(int i = 0; i < 4; i++)
    {
        m_lineEidt[i]->setText(QString::number(ip[i]));
    }
}

void QIpLineEdit::getIp(uint8_t *ip)
{
    for(int i=0; i < 4; i++)
    {
        ip[i] = m_lineEidt[i]->text().toInt();
    }
}
