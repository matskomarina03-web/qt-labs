#include "processor.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QTextStream>

processor::processor()
{
    lines.clear();
    lineIndex = 0;
    charIndex = 0;
}

QString processor::getCurrentLine()
{
    if(lines.isEmpty() || lineIndex >= lines.size())
        return "";
    return lines[lineIndex];
}

QString processor::getPreviousLine()
{
    if(lineIndex == 0 || lines.isEmpty())
        return lines[lineIndex];
    return lines[lineIndex - 1];
}

void processor::nextChar()
{
    if(lines.isEmpty()) return;

    charIndex++;

    if(charIndex >= lines[lineIndex].length())
    {
        charIndex = 0;

        if(lineIndex < lines.size() - 1)
        {
            lineIndex++;
            errorFlags = QVector<bool>(lines[lineIndex].length(), false);
        }
    }
}

void processor::loadAllLessons()
{
    lessons.clear();
    QDir dir(lessonsDirPath);

    if (!dir.exists()) {
        qDebug() << "Folder 'lessons' does not exist!";
        return;
    }

    QStringList files = dir.entryList({"*.txt"}, QDir::Files);

    for (const QString &file : files) {
        QFileInfo fi(dir.filePath(file));
        lessons.append({fi.baseName(), fi.filePath()});
    }
}

void processor::loadLesson(const QString &filePath)
{
    if (filePath.isEmpty()) return;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    lessonText = in.readAll();
    lessonText.replace("\r\n", "\n");

    lines = lessonText.split('\n').toVector();

    lineIndex = 0;
    charIndex = 0;

    if(!lines.isEmpty())
        errorFlags = QVector<bool>(lines[0].length(), false);
}
