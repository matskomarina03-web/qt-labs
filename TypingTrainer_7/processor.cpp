#include "processor.h"

processor::processor()
{
    QString text =
        "AAAAAAAAAAAA   AAAAAAAA  AAAAAAAA\n"
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBB\n"
        "HHHHH  HHHHHHHHH HHHHH  HHHHHHHHh\n"
        "AAAAAAAAAAAAaAAAAAAAAaAAAAAAA";

    lines = text.split('\n');
    lineIndex = 0;
    charIndex = 0;
}

QString processor::getCurrentLine()
{
    if(lines.isEmpty() || lineIndex >= lines.size()) return "";
    return lines[lineIndex];
}

QString processor::getPreviousLine()
{
    if(lineIndex == 0 || lines.isEmpty()) return "mmmm dddd WWWWW QQQQ";
    return lines[lineIndex - 1];
}

void processor::nextChar()
{
    if(lines.isEmpty()) return;

    charIndex++;
    if(charIndex >= lines[lineIndex].length()) {
        charIndex = 0;
        if(lineIndex < lines.size() - 1) lineIndex++;
    }
}
