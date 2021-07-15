#include "principal.h"
#include "ui_principal.h"
#include <QDebug>
Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //lista de prodcuto
    m_productos.append(new Producto("leche",1,0.85));
    m_productos.append(new Producto("pan",2,0.12));
    m_productos.append(new Producto("huevos",3,0.10));
    //mostar la lista en ventana
    for (int i=0 ;i<m_productos.size();i++) {
        ui->inProducto->addItem(m_productos.at(i)->nombre());
    }
    //colocar cabezera de la tabla
    QStringList cabecera ={"Cantidad","Producto","Subtotal"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
    m_subtotal =0;
    if(ui->inNombre->text().isNull()==true){
        ui->inNombre->setText("consumidor Final");
    }
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_CMDAgregar_released()
{
    //obtener datos de GUi
    int index = ui->inProducto->currentIndex();
    Producto *p=m_productos.at(index);
    int cantidad = ui->inCantidad->value();
    cantidad++;
    //validar que no se agregue productos con 0 cabtidad
    if(cantidad==0){
        return;
    }

    //calcular el sub total
    float subtotal= cantidad * p->precio();

    //agregar datos al al tabla
    int fila = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(fila);
    ui->outDetalle->setItem(fila,0,new QTableWidgetItem(QString::number(cantidad)));
    ui->outDetalle->setItem(fila,1,new QTableWidgetItem(p->nombre()));
    ui->outDetalle->setItem(fila,2,new QTableWidgetItem(QString::number(subtotal,'f',2)));
    //limpiar valores
    ui->inCantidad->setValue(0);
    ui->inProducto->setFocus();
    //invocar a calcular
    calcular(subtotal);
}

void Principal::on_inProducto_currentIndexChanged(int index)
{
    //obtener el precio del producto
    float precio = m_productos.at(index)->precio();
    //mostrar precio
    ui->outPrecio->setText("$"+QString::number(precio,'f',2));

}

void Principal::calcular(float stProducto)
{
    m_subtotal += stProducto;
    float iva= (m_subtotal *IVA) /100;
    float total = m_subtotal+IVA;
    ui->outSubtotal->setText(QString::number(m_subtotal,'f',2));
    ui->outIvan->setText(QString::number(iva,'f',2));
    ui->outTotal->setText(QString::number(total,'f',2));
}

bool Principal::verificarCedula()
{
    QString cedula=ui->inCedula->text();
    //validacion basica
    //numeros de digitos
    if(cedula.size()!=10||cedula.toInt()==false){
        return false;
    }else if(cedula.isNull()==true){
        return  false;

    }
    //primeros 2 digitos de provincia
    QString provincia= cedula.left(2);
    if(provincia.toInt()>24||provincia.toInt()<1){
        qDebug()<<provincia;
    }
    //tercer digito menor a 6
    QChar digto3 =cedula[3];
    if(digto3>6||digto3<0){
        qDebug()<<digto3;
    }


    //verificar el 10 digito

    int sumador=0;
    int coeficiente1=1;
    int coeficiente2=2;

    //multiplicar cada digito de la cedula por los coeficiente 1 y 2
    for(int i=0;i<cedula.size()-1;i++){
        //obtnemos los digitos de la sedula
        QString dig= cedula.at(i);
        //transformamos a enteros los digitos
        int p = dig.toInt();
        //una condicion para alternar la multiplicacion entre 1 y 2
        if(i%2==0){
            //en caso de que la operacion sea mayor a 10 restamos 9
            if(p*coeficiente2>10){
                //sumamos los digitos - 9 en caso de que sea mayor
                sumador+=p*coeficiente2-9;
            }else{
                //caso contrario se opera normal mente
                sumador+= p*coeficiente2;
            }
        }else {
            if(p*coeficiente1>10){
                sumador+=p*coeficiente1-9;
            }else{
                sumador+= p*coeficiente1;
            }

        }
    }
    //restar sumador menos decena superior
     //sumamos 10 para obtener una decena
    int resultado =sumador+10;
    //transformamos a QString para modifcar las unidades
     QString newSumador = QString::number(resultado);
     //modificamos la unidad a 0
     newSumador.replace(newSumador.at(1),'0');
     //transformamos a entero
     int decenaSup = newSumador.toInt();
     //tomamos el decimo digito
    QString digito10= cedula.at(9);
    //los transformamos a entero
    int dig10= digito10.toInt();
    int resta=decenaSup-sumador;
    //si son iguales
    if (resta==dig10){
        return true;
    }else if(resta==10 && dig10==0){
        return true;
    }else {
        return false;
    }
    return 0;
}

void Principal::limpiar()
{
    ui->inEmail->clear();
    ui->inCedula->clear();
    ui->inNombre->clear();
    ui->inCantidad->clear();
    ui->inProducto->clear();
    ui->inTelefono->clear();
    ui->inDireccion->clear();
    ui->outDetalle->clear();
    ui->outIvan->setText("0.0");
    ui->outTotal->setText("0.0");
    ui->outPrecio->clear();
    ui->outSubtotal->setText("0.0");
}



void Principal::on_cmdVenta_clicked()
{
 qDebug()<<"1";
   if(verificarCedula()==false && ui->inNombre->text().isNull()==true){
      QMessageBox::critical(this,"Tienda","Cedula erronea ingresala nuevamente");
    }else {
    QMessageBox::information(this,"tienda","Venta Exitosa\n pagar:"+QString::number(m_subtotal+IVA,'f',2));
    }

}
