#include "cliente.h"

QString Cliente::cedula() const
{
    return m_cedula;
}

void Cliente::setCedula(const QString &cedula)
{
    m_cedula = cedula;
}

QString Cliente::nombre() const
{
    return m_nombre;
}

void Cliente::setNombre(const QString &nombre)
{
    m_nombre = nombre;
}

QString Cliente::telefono() const
{
    return m_telefono;
}

void Cliente::setTelefono(const QString &telefono)
{
    m_telefono = telefono;
}

QString Cliente::direccion() const
{
    return m_direccion;
}

void Cliente::setDireccion(const QString &direccion)
{
    m_direccion = direccion;
}

QString Cliente::email() const
{
    return m_email;
}

void Cliente::setEmail(const QString &email)
{
    m_email = email;
}

Cliente::Cliente(QObject *parets):QObject(parets)
{
    this->m_email="";
    this->m_cedula="";
    this->m_nombre="";
    this->m_direccion="";
    this->m_telefono="";
}

Cliente::Cliente(QString cedula, QString nombre, QString telefono, QString direccion, QString email)
{
    this->m_email=email;
    this->m_cedula=cedula;
    this->m_nombre=nombre;
    this->m_direccion=direccion;
    this->m_telefono=telefono;
}
