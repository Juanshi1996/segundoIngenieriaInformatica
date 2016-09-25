#include "ruleta.h"
#include <list>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

Ruleta::Ruleta(Crupier initCrupier) : crupier_(initCrupier){
	setBanca(1000000);
	bola_ = -1;
	crupier_ = initCrupier;
	srand(time(NULL));
}

bool Ruleta::setBanca(int banca){
	if(banca>0){
		banca_ = banca;
		return(true);
	}
	else{
		return(false);
	}
}

bool Ruleta::setBola(int bola)
{
	if((bola>-1) && (bola<37)){
		bola_ = bola;
		return(true);
	}
	else{
		return(false);
	}
}

void Ruleta::setCrupier(Crupier crupier){
	crupier_ = crupier;
}

void Ruleta::addJugador(Jugador jugador){
	ifstream ifile;

	jugadores_.push_back(jugador);
	ifile.open((jugador.getDNI()+".txt").c_str());
	if(!ifile.is_open()){
		ofstream ofile((jugador.getDNI()+".txt").c_str());
	}
}

int Ruleta::deleteJugador(Jugador jugador){
	list<Jugador>::iterator i;

	if(jugadores_.empty()){
		return(-1);
	}
	for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
		if((*i).getDNI() == jugador.getDNI()){
			jugadores_.erase(i);
			return(1);
		}
	}
	return(-2);
}

int Ruleta::deleteJugador(string DNI){
	list<Jugador>::iterator i;

	if(jugadores_.empty()){
		return(-1);
	}
	for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
		if((*i).getDNI() == DNI){
			jugadores_.erase(i);
			return(1);
		}
	}
	return(-2);
}

void Ruleta::escribeJugadores(){
	ifstream ifile;

	ifile.open("jugadores.txt");
	if(!ifile.is_open()){
		ofstream ofile("jugadores.txt");
	}
}

void Ruleta::leeJugadores(){
	ifstream ifile;
	string line;
	Jugador aux("auxDNI", "auxCodigo");

	jugadores_.clear();
	ifile.open("jugadores.txt");
	if(ifile.is_open()){
		while(getline(ifile, line, ',')){
			aux.setDNI(line);
			getline(ifile, line, ',');
			aux.setCodigoJugador(line);
			getline(ifile, line, ',');
			aux.setNombre(line);
			getline(ifile, line, ',');
			aux.setApellidos(line);
			getline(ifile, line, ',');
			aux.setDireccion(line);
			getline(ifile, line, ',');
			aux.setLocalidad(line);
			getline(ifile, line, ',');
			aux.setProvincia(line);
			getline(ifile, line, ',');
			aux.setPais(line);
			getline(ifile, line, ',');
			aux.setDinero(atoi(line.c_str()));
			getline(ifile, line, '\n');
			jugadores_.push_back(aux);
		}
		ifile.close();
	}else{
		printf("\nEl archivo jugadores.txt no se ha podido abrir correctamente o no existe.\n");
	}
}

void Ruleta::giraRuleta(){
	int bola;

	bola = rand()%37;
	setBola(bola);
}

void Ruleta::getPremios(){
	list<Jugador>::iterator i;
	list<Apuesta> aux;
	list<Apuesta>::iterator j;

	for(i=jugadores_.begin(); i!=jugadores_.end(); i++){
		ifstream ifile(((*i).getDNI()+".txt").c_str(), ios::in);
		(*i).setApuestas();
		aux = (*i).getApuestas();
		for(j=aux.begin(); j!=aux.end(); j++){

		}
	}

}
