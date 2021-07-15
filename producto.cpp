#include "producto.h"

int Producto::codigo() const
{
    return m_codigo;
}

void Producto::setCodigo(int codigo)
{
    m_codigo = codigo;
}

QString Producto::nombre() const
{
    return m_nombre;
}

void Producto::setNombre(const QString &nombre)
{
    m_nombre = nombre;
}


float Producto::precio() const
{
    return m_precio;
}

void Producto::setPrecio(float precio)
{
    m_precio = precio;
}

Producto::Producto(QObject *parent) : QObject(parent)
{

}

Producto::Producto(QString nombre,int codigo, float precio)
{
    this->m_nombre=nombre;
    this->m_precio=precio;
    this->m_codigo=codigo;
}
