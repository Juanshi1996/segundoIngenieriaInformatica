/****      FICHERO PERSISTENCIAFICHERO.CPP    ****/
#include "../hpp/persistenciaFichero.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

void persistenciaFichero::guardarContactos(std::list<Contacto> listaContactos){
    std::ofstream fichero;
    std::list<Contacto>::iterator it;
    struct redSocial redes;
    fichero.open(nombreFichero_.c_str());
    if(fichero.is_open()){
      for(it=listaContactos.begin(); it!=listaContactos.end(); it++){
        std::cout << (*it).getUso() << std::endl;
        fichero << (*it).getDNI() << '\n' << (*it).getNombre() << '\n' << (*it).getApellido1() << '\n'
                << (*it).getApellido2() << '\n' << (*it).getAnotaciones() << '\n'
                << (*it).getFavorito() << '\n' << (*it).getUso() << std::endl; //Hasta aquí sin listas

        almacenaTelefonos((*it).getTelefonos(), &fichero);
        almacenaMail((*it).getCorreosElectronicos(), &fichero);
        almacenaDirecciones((*it).getDireccionesPostales(), &fichero);
        redes = (*it).getRedesSociales();
        fichero << redes.Twitter << ',' << redes.Facebook << std::endl;
        fichero << (*it).getFoto() << std::endl;
      }
    }
    else{
      std::cout << "Fallo al abrir el fichero." << std::endl;
    }
}

void persistenciaFichero::almacenaTelefonos(std::list<unsigned long int> listaTelefonos, std::ofstream *fichero){
  std::list<unsigned long int>:: iterator itel;
  std::list<unsigned long int>:: iterator aux;
  (*fichero) << listaTelefonos.size() << std::endl;
  for(itel=listaTelefonos.begin(); itel!=listaTelefonos.end(); itel++){
    (*fichero) << (*itel);
    aux = itel;
    if((++aux) == listaTelefonos.end()){
      (*fichero) << std::endl;
    }
    else{
      (*fichero) << ',';
    }
  }
}

void persistenciaFichero::almacenaMail(std::list<std::string> listaMail, std::ofstream *fichero){
  std::list<std::string>::iterator imail;
  std::list<std::string>::iterator aux;
  (*fichero) << listaMail.size() << std::endl;
  for(imail=listaMail.begin(); imail!=listaMail.end(); imail++){
    (*fichero) << (*imail);
    aux = imail;
    if((++aux) == listaMail.end()){
      (*fichero) << std::endl;
    }
    else{
      (*fichero) << ',';
    }
  }
}

void persistenciaFichero::almacenaDirecciones(std::list<direccion> listaDirecciones, std::ofstream *fichero){
  std::list<direccion>::iterator idir;
  std::list<direccion>::iterator aux;
  (*fichero) << listaDirecciones.size() << std::endl;
  for(idir=listaDirecciones.begin(); idir!=listaDirecciones.end(); idir++){
    (*fichero) << (*idir).tipoVia << ',' << (*idir).nombreVia << ',' << (*idir).numero
            << ',' << (*idir).codigoPostal << ',' << (*idir).ciudad << ',' << (*idir).provincia;
    aux = idir;
    if((++aux) == listaDirecciones.end()){
        (*fichero) << ',' << std::endl;
    }
    else{
        (*fichero) << ',';
    }
  }
}


std::list<Contacto> persistenciaFichero::cargarContactos(){
  std::ifstream fichero;
  std::list<Contacto> auxlist;
  std::list<std::string> mail;
  std::list<direccion> direcciones;
  std::list<unsigned long int> telefonos;
  struct direccion dire;
  struct redSocial redes;
  int ntel, nmail, ndir, i;
  Contacto aux;
  fichero.open(nombreFichero_.c_str());
  std::string cadena;
  unsigned long int telefono;

  if(fichero.is_open()){
    while(std::getline(fichero, cadena, '\n')){
      aux.setDNI(cadena);
      std::getline(fichero, cadena, '\n');
      aux.setNombre(cadena);
      std::getline(fichero, cadena, '\n');
      aux.setApellido1(cadena);
      std::getline(fichero, cadena, '\n');
      aux.setApellido2(cadena);
      std::getline(fichero, cadena, '\n');
      aux.setAnotaciones(cadena);
      std::getline(fichero, cadena, '\n');
      if(cadena == "1"){
        aux.setFavorito(1);
      }
      else{
        aux.setFavorito(0);
      }
      std::getline(fichero, cadena, '\n');
      aux.setUso((unsigned int) atoi(cadena.c_str()));

      //OBTENEMOS LISTAS
      //Telefonos
      std::getline(fichero, cadena, '\n');
      ntel = atoi(cadena.c_str());
      for(i=0; i<ntel-1; i++){
        std::getline(fichero, cadena, ',');
        telefono = (unsigned long int) atoi(cadena.c_str());
        telefonos.push_back(telefono);
      }
      //SE CARGA EL ULTIMO ELEMENTO QUE NO TIENE COMA A LA DERECHA
      std::getline(fichero, cadena, '\n');
      telefono = (unsigned long int) atoi(cadena.c_str());
      telefonos.push_back(telefono);
      aux.setTelefonos(telefonos);

      //Mail
      std::getline(fichero, cadena, '\n');
      nmail = atoi(cadena.c_str());
      for(i=0; i<nmail-1; i++){
        std::getline(fichero, cadena, ',');
        mail.push_back(cadena);
      }
      //SE CARGA EL ULTIMO ELEMENTO QUE NO TIENE COMA A LA DERECHA
      std::getline(fichero, cadena, '\n');
      mail.push_back(cadena);
      aux.setCorreosElectronicos(mail);


      //Direcciones
      std::getline(fichero, cadena, '\n');
      ndir = atoi(cadena.c_str());
      for(i=0; i<ndir-1; i++){
        std::getline(fichero, cadena, ',');
        dire.tipoVia = cadena;
        std::getline(fichero, cadena, ',');
        dire.nombreVia = cadena;
        std::getline(fichero, cadena, ',');
        dire.numero = cadena;
        std::getline(fichero, cadena, ',');
        dire.codigoPostal = cadena;
        std::getline(fichero, cadena, ',');
        dire.ciudad = cadena;
        std::getline(fichero, cadena, ',');
        dire.provincia = cadena;
        direcciones.push_back(dire);
      }
      //SE CARGA EL ULTIMO ELEMENTO QUE NO TIENE COMA A LA DERECHA
      std::getline(fichero, cadena, ',');
      dire.tipoVia = cadena;
      std::getline(fichero, cadena, ',');
      dire.nombreVia = cadena;
      std::getline(fichero, cadena, ',');
      dire.numero = cadena;
      std::getline(fichero, cadena, ',');
      dire.codigoPostal = cadena;
      std::getline(fichero, cadena, ',');
      dire.ciudad = cadena;
      std::getline(fichero, cadena, '\n');
      dire.provincia = cadena;
      direcciones.push_back(dire);
      aux.setDireccionesPostales(direcciones);

      //Redes sociales
      std::getline(fichero, cadena, ',');
      redes.Twitter = cadena;
      std::getline(fichero, cadena, '\n');
      redes.Facebook = cadena;
      aux.setRedesSociales(redes);
      std::getline(fichero, cadena, '\n');
      aux.setFoto(cadena);
      auxlist.push_back(aux);
      mail.clear();
      direcciones.clear();
      telefonos.clear();
      //std::getline(fichero,cadena, '\n');
    }
  }
  else{
    std::cout << "Fallo al abrir el fichero." << std::endl;
  }
  return auxlist;
}

void persistenciaFichero::setNombreFichero(std::string nombre){
  nombreFichero_ = nombre;
}
