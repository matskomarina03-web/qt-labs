#include "lesson.h"

Lesson::Lesson()
{
    // дуже простий текст для прикладу
    fullText = "8 рядок\nдиво наша брати\nнайдіші\nдуже елементарний\nповторюється\nі так далі";
    lines = fullText.split('\n');
    reset();
}

void Lesson::reset()
{
    lineIndex = 0;
    charIndex = 0;
}

void Lesson::moveNextChar()
{
    if (lineIndex >= lines.size()) return;

    charIndex++;
    if (charIndex > lines[lineIndex].size()) {
        lineIndex++;
        charIndex = 0;
    }
}

QString Lesson::currentLine() const
{
    if (lineIndex >= lines.size()) return "";
    return lines[lineIndex];
}

QString Lesson::previousLine() const
{
    if (lineIndex == 0) return "";
    return lines[lineIndex - 1];
}

QString Lesson::passedPart() const
{
    if (lineIndex >= lines.size()) return "";
    return lines[lineIndex].left(charIndex);
}

QString Lesson::remainingPart() const
{
    if (lineIndex >= lines.size()) return "";
    return lines[lineIndex].mid(charIndex);
}
