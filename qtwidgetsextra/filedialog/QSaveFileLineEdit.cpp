#include "QSaveFileLineEdit.h"
#include "QFileAction.h"

class QSaveFileLineEditPrivate : public QObject
{
    Q_OBJECT

public:
    QSaveFileLineEditPrivate(QSaveFileLineEdit *widgetP)
        : QObject(widgetP)
        , widget(widgetP)
        , action(new QFileAction(this))
    {
        Q_ASSERT(widget);

        action->setType(QFileAction::SaveFile);
        widget->setDefaultAction(action);

        connect(widget, SIGNAL(textChanged(QString)), this, SLOT(textChanged(QString)));
        connect(action, SIGNAL(filePathChanged(QString)), this, SLOT(filePathChanged(QString)));
        connect(action, SIGNAL(filePathChanged(QString)), widget, SIGNAL(filePathChanged(QString)));
    }

public slots:
    void textChanged(const QString &text) {
        action->setFilePath(text);
    }

    void filePathChanged(const QString &text) {
        if (widget->text() != text) {
            widget->setText(text);
        }
    }

public:
    QSaveFileLineEdit *widget;
    QFileAction *action;
};

QSaveFileLineEdit::QSaveFileLineEdit(QWidget *parent)
    : QAbstractButtonLineEdit(parent)
    , d(new QSaveFileLineEditPrivate(this))
{
}

QString QSaveFileLineEdit::filePath() const
{
    return d->action->filePath();
}

void QSaveFileLineEdit::setFilePath(const QString &filePath)
{
    d->action->setFilePath(filePath);
}

QString QSaveFileLineEdit::caption() const
{
    return d->action->caption();
}

void QSaveFileLineEdit::setCaption(const QString &caption)
{
    d->action->setCaption(caption);
}

QString QSaveFileLineEdit::directory() const
{
    return d->action->directory();
}

void QSaveFileLineEdit::setDirectory(const QString &directory)
{
    d->action->setDirectory(directory);
}

QStringList QSaveFileLineEdit::filter() const
{
    return d->action->filter();
}

void QSaveFileLineEdit::setFilter(const QStringList &filter)
{
    d->action->setFilter(filter);
}

QFileDialog::Options QSaveFileLineEdit::options() const
{
    return d->action->options();
}

void QSaveFileLineEdit::setOptions(QFileDialog::Options options)
{
    d->action->setOptions(options);
}

#include "QSaveFileLineEdit.moc"
