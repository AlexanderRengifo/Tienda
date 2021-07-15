#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "producto.h"
#include <QMessageBox>

#define IVA 12

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_CMDAgregar_released();

    void on_inProducto_currentIndexChanged(int index);

    void on_cmdVenta_clicked();

private:
    Ui::Principal *ui;
    QList<Producto*>m_productos;
    float m_subtotal;
    void calcular(float stProducto);
    bool verificarCedula();
    void limpiar();
};
#endif // PRINCIPAL_H
