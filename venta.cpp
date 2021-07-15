#include "venta.h"

Cliente *Venta::cliente() const
{
    return m_cliente;
}

void Venta::setCliente(Cliente *cliente)
{
    m_cliente = cliente;
}

QList<Producto> Venta::productos() const
{
    return m_productos;
}

Venta::Venta(QObject *parent) : QObject(parent)
{
    m_cliente = nullptr;
}

void Venta::addProducto(const Producto &producto)
{
    this->m_productos.append(producto);
}
