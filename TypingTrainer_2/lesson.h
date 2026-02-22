#ifndef LESSON_H
#define LESSON_H
#include <QString>
#include <QStringList>

class Lesson
{
public:
    Lesson();

    QString fullText;      // весь текст
    QStringList lines;     // розбиті рядки
    int lineIndex;         // поточний рядок
    int charIndex;         // позиція всередині рядка

    void reset();          // скинути на початок
    void moveNextChar();   // перейти на наступний символ
    QString currentLine() const;      // поточний рядок
    QString previousLine() const;     // попередній рядок
    QString passedPart() const;       // вже пройдено
    QString remainingPart() const;    // ще залишилось
};
#endif // LESSON_H
