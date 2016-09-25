create table usu
(usuid varchar(50),
nombreus varchar(50),
dir varchar (50),
tlf number(9),
constraint usu_custid_pk primary key (usuid)
);

create table ofer
(ofid varchar(50),
nombreof varchar(50),
descof varchar(50),
constraint ofer_custid_pk primary key (ofid)
);

create table usuof
(usuid varchar(50),
ofid varchar(50),
fdis date,
constraint usuof_custid_pk primary key (usuid, ofid, fdis)
);

alter table ofer add 
(finicio date,
ffin date
);

alter table ofer modify
(finicio default sysdate 
);

insert into ofer (OFID, NOMBREOF, DESCOF,FFIN) values ('hola','pepe','adios',sysdate);

alter table usu modify 
(nombreus varchar(60)
);

comment on table usu
is 'Crea una tabla llamada usu en la que se guardara información sobre los usuarios de La Pizzeta'
;

comment on table ofer
is 'Tabla en la que se guarda información sobre las ofertas de La Pizzeta'
;

comment on table usuof
is'Tabla en la que se guardará información sobre el uso que hacen los usuarios de las ofertas'
;

alter table usuof add
(
constraint restriccioneje8 foreign key (usuid) references usu(usuid)
);

alter table ofer add
constraint restriccioneje9 unique (nombreof, finicio);

alter table ofer add
constraint restriccioneje10 check (finicio<ffin);

alter table ofer drop
constraint restriccioneje9;

insert into usu(USUID, NOMBREUS, DIR, TLF) values ('U1000', 'ANA CRUZ CASTRO', 'CRUCES,4', 697123456);

insert into usu(USUID, NOMBREUS, DIR, TLF) values('U1001', 'JUAN CRUZ CASTRO', 'CARRETERO',NULL);

insert into usu(USUID, NOMBREUS, DIR, TLF) values ('U1002', 'ANTONIO SALAS GARRIDO', 'GONDOMAR, 11', 617123456);

insert into usu(USUID, NOMBREUS, DIR, TLF) values ('U1003', 'CLARA BELLIDO LUQUE', NULL, NULL);

insert into usu(USUID, NOMBREUS, DIR, TLF) values ('U1004', 'ENRIQUE CASAS TRILLO', 'CLAVELES, 2', 677223344);

insert into usu(USUID, NOMBREUS, DIR, TLF) values (&USUID, &NOMBREUS, &DIR, &TLF);

update usu
set DIR='CARTAGO, 1'
where USUID='U1002';

delete from usu
where USUID='U1004';

delete from usu
where USUID='U1006';

insert into usu(USUID, NOMBREUS, DIR, TLF) values ('U1008', 'CARLOS MERINO MATAS', 'PALOMAS, 22', 677667788);

insert into usu(USUID, NOMBREUS, DIR, TLF) values ('U1009', 'SARA MELLADO BUSTOS', 'MADRID, 33' , 677778899);

select * from usu order by USUID asc o desc;

savepoint seguridad_usu;

delete from usu;

rollback to savepoint seguridad_usu;

select * from usu order by USUID asc;

