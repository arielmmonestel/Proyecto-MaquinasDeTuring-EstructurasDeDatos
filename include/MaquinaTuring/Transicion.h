#ifndef TRANSICION_H
#define TRANSICION_H


class Transicion
{
    private:

        string siguienteEstado;
        char simboloAPoner;
        char direccion;


    public:

        Transicion(){

        }

        Transicion(string pSiguienteEstado, char pSimboloAPoner, char pDireccion) {
            siguienteEstado = pSiguienteEstado;
            simboloAPoner = pSimboloAPoner;
            direccion = pDireccion;
        }

        char ObtenerDireccion(){
            return direccion;
        }

        char ObtenerSimboloAPoner(){
            return simboloAPoner;
        }

        string ObtenerSiguienteEstado(){
            return siguienteEstado;
        }

    virtual ~Transicion() {}

    //protected:

};

#endif // TRANSICION_H
