#ifndef VENTA_H
#define VENTA_H

#include <QObject>
#include "cliente.h"
#include "producto.h"

class Venta : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Cliente cliente READ cliente WRITE setCliente)
private:
    Cliente *m_cliente;
    QList<Producto>m_productos;
public:
    explicit Venta(QObject *parent = nullptr);    
    void addProducto(const Producto &producto);

    Cliente *cliente() const;
    void setCliente(Cliente *cliente);


    QList<Producto> productos() const;

signals:

};

#endif // VENTA_H
