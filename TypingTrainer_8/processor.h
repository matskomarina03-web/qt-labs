#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QString>
#include <QStringList>
#include <QList>

struct Lesson {
    QString name; // назва
    QString path; // шлях
};

class processor {
public:
    processor();

    QString getCurrentLine();
    QString getPreviousLine();
    void nextChar();

    void loadLesson(const QString &filePath);
    void loadAllLessons();

    QStringList lines;
    QString lessonText;
    int lineIndex;
    int charIndex;
    QList<Lesson> lessons;

private:
    QString lessonsDirPath = "lessons";
};

#endif // PROCESSOR_H
