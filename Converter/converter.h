#ifndef CONVERTER_H
#define CONVERTER_H

#include <QString>

class Converter
{
public:
    Converter() = default;
    double convert(double value, const QString &fromUnit, const QString &toUnit, const QString &mode);

private:
    double toMeter(double value, const QString &unit);
    double fromMeter(double value, const QString &unit);

    double toKg(double value, const QString &unit);
    double fromKg(double value, const QString &unit);

    double toKelvin(double value, const QString &unit);
    double fromKelvin(double value, const QString &unit);
};

#endif // CONVERTER_H
