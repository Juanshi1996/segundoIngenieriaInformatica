1.	/* Creación de las entidades y atributos así como relaciones de nuestro problema a partir de sql:*/
2.	
3.	drop table if exists usuario_redes;
4.	drop table if exists usuario_producto;
5.	drop table if exists oferta_usuario;
6.	drop table if exists oferta_producto;
7.	drop table if exists oferta_establecimiento;
8.	drop table if exists oferta;
9.	drop table if exists producto;
10.	drop table if exists establecimiento;
11.	drop table if exists usuario;
12.	
13.	/*Se crea la tabla USUARIOS */
14.	create table usuario
15.	 (id_usuario varchar2(24) primary key,
16.	  nombre varchar2(24),
17.	  apellido1 varchar2(24),
18.	  apellido2 varchar2(24),
19.	  fecha_nacimiento date,
20.	  sexo char(1),
21.	  direccion varchar2(64),
22.	  localidad varchar2(32),
23.	  provincia varchar2(32),
24.	  postal number(5),
25.	  telefono_movil number(9),
26.	  facebook varchar2(64),
27.	  twitter varchar2(64),
28.	  fecha_alta date not null,
29.	  fecha_baja date,
30.	  estado char(1) not null,
31.	
32.	  /*El sexo del usuario puede tener uno de los tres valores diferentes (I, H, M)*/
33.	  constraint usuario_sexo_ck check (sexo in ('I', 'H', 'M')),
34.	
35.	  /*El estado del usuario puede tomar el valor 0 o 1 */
36.	  constraint usuario_estado_ck check (estado in ('0', '1')));
37.	
38.	/*Se crea la tabla ESTABLECIMIENTO */
39.	create table establecimiento
40.	 (id_shop number(9) primary key,
41.	  nombre varchar2(24) not null,
42.	  direccion varchar2(64),
43.	  localidad varchar2(32),
44.	  provincia varchar2(32),
45.	  postal number(5),
46.	  telefono number(9),
47.	  latitud varchar2(16),
48.	  longitud varchar2(16),
49.	  fecha_alta date not null,
50.	  fecha_baja date,
51.	  estado char(1) not null,
52.	
53.	  /*El estado del establecimiento puede tomar el valor 0 o 1 */
54.	  constraint establecimiento_estado_ck check (estado in ('0', '1')));
55.	
56.	/*Se crea la tabla PRODUCTOS*/
57.	create table producto
58.	 (id_producto number(9) primary key,
59.	  nombre varchar2(24) not null,
60.	  descripcion varchar2(64) not null,
61.	  detalle varchar2(512) not null,
62.	  foto varchar2(512) not null,
63.	  coste number(14, 2) not null,
64.	  venta number(14, 2) not null,
65.	  fecha_alta date not null,
66.	  fecha_baja date,
67.	  estado char(1) not null,
68.	
69.	  /*El estado del producto puede tomar el valor 0 o 1 */
70.	  constraint producto_estado_ck check (estado in ('0', '1')));
71.	
72.	/*Se crea la tabla OFERTAS */
73.	create table oferta
74.	 (id_oferta number(9) primary key,
75.	  nombre varchar2(24) not null,
76.	  descripcion varchar2(64) not null,
77.	  detalle varchar2(512) not null,
78.	  foto varchar2(512) not null,
79.	  venta number(14, 2) not null,
80.	  fecha_inicio date not null,
81.	  fecha_fin date,
82.	  fecha_alta date not null,
83.	  fecha_baja date,
84.	  estado char(1) not null,
85.	
86.	  /*El estado de la oferta puede tomar el valor 0 o 1 */
87.	  constraint oferta_estado_ck check (estado in ('0', '1')));
88.	
89.	/*Se crea la tabla OFERTA_ESTABLECIMIENTOS */
90.	create table oferta_establecimiento
91.	 (id_of_es number(9) primary key,
92.	  id_oferta number(9),
93.	  id_shop number(9),
94.	  constraint of_es_id_of_fk foreign key (id_oferta) references oferta(id_oferta),
95.	  constraint of_es_id_es_fk foreign key (id_shop) references establecimiento(id_shop));
96.	
97.	/*Se crea la tabla OFERTA_PRODUCTOS */
98.	create table oferta_producto
99.	 (id_of_pr number(9) primary key,
100.	  id_oferta number(9),
101.	  id_producto number(9),
102.	  venta number(14, 2) not null,
103.	  constraint of_pr_id_of_fk foreign key (id_oferta) references oferta(id_oferta),
104.	  constraint of_pr_id_pr_fk foreign key (id_producto) references producto(id_producto));
105.	
106.	/*Se crea la tabla OFERTA_USUARIOS */
107.	create table oferta_usuario
108.	 (id_of_us number(9) primary key,
109.	  id_oferta number(9),
110.	  id_usuario varchar2(24),
111.	  fecha_envio date not null,
112.	  estado_envio char(1) not null,
113.	  fecha_lectura date,
114.	  fecha_uso date,
115.	  venta number(14, 2),
116.	  constraint of_us_id_of_fk foreign key (id_oferta) references oferta(id_oferta),
117.	  constraint of_us_id_us_fk foreign key (id_usuario) references usuario(id_usuario));
118.	
119.	/*Se crea la tabla USUARIO_PRODUCTO */
120.	create table usuario_producto
121.	 (id_us_pr number(9) primary key,
122.	  id_of_us number(9),
123.	  id_producto number(9),
124.	  unidades number(9) not null,
125.	  venta number(14, 2) not null,
126.	  constraint us_pr_id_of_us_fk foreign key (id_of_us) references oferta_usuario(id_of_us),
127.	  constraint us_pr_id_pr_fk foreign key (id_producto) references producto(id_producto));
128.	
129.	/*Se crea la tabla USUARIO_REDES */
130.	create table usuario_redes
131.	 (id_redes number(9) primary key,
132.	  id_usuario varchar2(24),
133.	  id_oferta number(9),
134.	  fecha_accion date not null,
135.	  tipo_red char(1) not null,
136.	  tipo_accion char(1) not null,
137.	  seguimiento number(12),
138.	  constraint us_re_id_us_fk foreign key (id_usuario) references usuario(id_usuario),
139.	  constraint us_re_id_of_fk foreign key (id_oferta) references oferta(id_oferta),
140.	  constraint us_re_ti_re_ck check (tipo_red in ('0', '1')),
141.	  constraint us_re_ti_ac_ck check (tipo_accion in ('0', '1', '2', '3')));
