#ifndef QSAVEFILELINEEDIT_H
#define QSAVEFILELINEEDIT_H

#include "QAbstractButtonLineEdit.h"

#include <QFileDialog>

class QSaveFileLineEdit : public QAbstractButtonLineEdit
{
    Q_OBJECT
    class QSaveFileLineEditPrivate* d;

    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath USER true NOTIFY filePathChanged)
    Q_PROPERTY(QString caption READ caption WRITE setCaption)
    Q_PROPERTY(QString directory READ directory WRITE setDirectory)
    Q_PROPERTY(QStringList filter READ filter WRITE setFilter)
    Q_PROPERTY(QFileDialog::Options options READ options WRITE setOptions)

public:
    QSaveFileLineEdit(QWidget *parent = 0);

    QString filePath() const;
    void setFilePath(const QString &filePath);

    QString caption() const;
    void setCaption(const QString &caption);

    QString directory() const;
    void setDirectory(const QString &directory);

    QStringList filter() const;
    void setFilter(const QStringList &filter);

    QFileDialog::Options options() const;
    void setOptions(QFileDialog::Options options);

signals:
    void filePathChanged(const QString &filePath);
};

#endif // QSAVEFILELINEEDIT_H
