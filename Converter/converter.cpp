#include "converter.h"

double Converter::toMeter(double value, const QString &unit){
    if(unit=="meters (m)") return value;
    if(unit=="kilometers (km)") return value*1000;
    if(unit=="inches (in)") return value*0.0254;
    if(unit=="feet (ft)") return value*0.3048;
    if(unit=="miles (mi)") return value*1609.34;
    return value;
}

double Converter::fromMeter(double value, const QString &unit){
    if(unit=="meters (m)") return value;
    if(unit=="kilometers (km)") return value/1000;
    if(unit=="inches (in)") return value/0.0254;
    if(unit=="feet (ft)") return value/0.3048;
    if(unit=="miles (mi)") return value/1609.34;
    return value;
}

double Converter::toKg(double value, const QString &unit){
    if(unit=="kilograms (kg)") return value;
    if(unit=="pounds (lb)") return value*0.453592;
    if(unit=="ounces (oz)") return value*0.0283495;
    return value;
}

double Converter::fromKg(double value, const QString &unit){
    if(unit=="kilograms (kg)") return value;
    if(unit=="pounds (lb)") return value/0.453592;
    if(unit=="ounces (oz)") return value/0.0283495;
    return value;
}

double Converter::toKelvin(double value, const QString &unit){
    if(unit=="Celsius (°C)") return value + 273.15;
    if(unit=="Fahrenheit (°F)") return (value + 459.67)*5.0/9.0;
    if(unit=="Kelvin (K)") return value;
    return value;
}

double Converter::fromKelvin(double value, const QString &unit){
    if(unit=="Celsius (°C)") return value - 273.15;
    if(unit=="Fahrenheit (°F)") return value*9.0/5.0 - 459.67;
    if(unit=="Kelvin (K)") return value;
    return value;
}

double Converter::convert(double value, const QString &fromUnit, const QString &toUnit, const QString &mode){
    if(mode=="Length"){
        double m = toMeter(value, fromUnit);
        return fromMeter(m, toUnit);
    }
    else if(mode=="Mass"){
        double kg = toKg(value, fromUnit);
        return fromKg(kg, toUnit);
    }
    else if(mode=="Temperature"){
        double K = toKelvin(value, fromUnit);
        return fromKelvin(K, toUnit);
    }
    return value;
}
