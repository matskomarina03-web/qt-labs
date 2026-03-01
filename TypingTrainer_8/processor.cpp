#include "processor.h"
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>

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
        return "eeeee yyyyyyy ooooo";
    return lines[lineIndex - 1];
}

void processor::nextChar()
{
    if(lines.isEmpty()) return;

    charIndex++;
    if(charIndex >= lines[lineIndex].length()) {
        charIndex = 0;
        if(lineIndex < lines.size() - 1)
            lineIndex++;
    }
}

void processor::loadAllLessons()
{
    lessons.clear();
    QDir dir(lessonsDirPath);
    if (!dir.exists()) {
        qDebug() << "Folder 'lessons' does not exist!";//Папки «уроки» не існує!
        return;
    }

    QStringList nameFilters = {"*.txt"};
    QStringList files = dir.entryList(nameFilters, QDir::Files);

    for (int i = 0; i < files.size(); ++i) {
        QFileInfo fi(dir.filePath(files[i]));
        lessons.append({fi.baseName(), fi.filePath()});
        qDebug() << "Found lesson:" << fi.fileName();
    }
}

void processor::loadLesson(const QString &filePath) {
    if (filePath.isEmpty()) {
        qDebug() << "Cannot open lesson file: empty path";//Не вдається відкрити файл уроку: шлях порожній
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open lesson file:" << filePath;//Не вдається відкрити файл уроку
        return;
    }

    QTextStream in(&file);
    lessonText = in.readAll();
    lessonText.replace("\r\n", "\n");
    lines = lessonText.split('\n');
    lineIndex = 0;
    charIndex = 0;
    qDebug() << "Loaded lesson:" << filePath;
}
