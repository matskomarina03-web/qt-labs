#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QString>
#include <QStringList>

class processor
{
public:
    processor();

    QString getCurrentLine();    // поточ
    QString getPreviousLine();   // поперед
    void nextChar();

private:
    QStringList lines;
    int lineIndex;
    int charIndex;
};

#endif
