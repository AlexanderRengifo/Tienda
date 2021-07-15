#ifndef CLIENTE_H
#define CLIENTE_H

#include <QObject>

class Cliente:public QObject
{
    Q_OBJECT
    Q_PROPERTY(Qstring cedula READ cedula WRITE setCedulacedula)
    Q_PROPERTY(QString telefono READ telefono WRITE setTelefono)
    Q_PROPERTY(QString nombre READ nombre WRITE setNombre)
    Q_PROPERTY(Qstring direccion READ direccion WRITE setDireccion)
    Q_PROPERTY(Qstring email READ email WRITE setEmail)

private:
    QString m_cedula;
    QString m_nombre;
    QString m_telefono;
    QString m_direccion;
    QString m_email;

public:
    explicit Cliente(QObject *parents=nullptr);
    Cliente(QString cedula,QString nombre,QString telefono,QString direccion,QString email);
    QString cedula() const;
    void setCedula(const QString &cedula);

    QString nombre() const;
    void setNombre(const QString &nombre);

    QString telefono() const;
    void setTelefono(const QString &telefono);

    QString direccion() const;
    void setDireccion(const QString &direccion);

    QString email() const;
    void setEmail(const QString &email);

signals:

};

#endif // CLIENTE_H
