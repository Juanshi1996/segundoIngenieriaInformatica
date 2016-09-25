1.	/*Inserta establecimientos en las tablas */
2.	insert into establecimiento
3.	values ('0000', 'BRILLANTE', 'BRILLANTE', 'CORDOBA', 'CORDOBA', '14001', '957465935', '15', '20', '10-11-2014', NULL, '1');
4.	insert into establecimiento
5.	values ('0001', 'MEZQUITA', 'MEZQUITA', 'CORDOBA', 'CORDOBA', '14014', '957474545', '15', '21', '08-07-2014', NULL, '1');
6.	insert into establecimiento
7.	values ('0002', 'PATIOS', 'SERRANO', 'CORDOBA', 'CORDOBA', '142213', '957433935', '17', '19', '19-12-2014', NULL, '1');
8.	
9.	/*Inserta productos en las tablas */
10.	insert into producto
11.	values ('0000', 'CARBONARA', 'RICA', 'NATA', 'http://www.pizzeta.es/producto0000.png', '4', '9', '10-04-2014',  NULL, '1');
12.	insert into producto
13.	values ('0001', 'BARBACOA', 'CRUJIENTE', 'SALSA', 'http://www.pizzeta.es/producto0001.png', '4', '9', '10-04-2014',  NULL, '1');
14.	insert into producto
15.	values ('0002', 'MARGARITA', 'TÍPICA', 'TOMATE', 'http://www.pizzeta.es/producto0002.png', '4', '9', '10-04-2014',  NULL, '1');
16.	
17.	/*Inserta ofertas en las tablas */
18.	insert into oferta
19.	values ('0000', '2x1', 'REBAJA', 'LUNES', 'http://www.pizzeta.es/oferta0000.png', '9', '10-04-2014',  '10-05-2014', '08-04-2014', NULL, '1');
20.	insert into oferta
21.	values ('0001', '3x1', 'REBAJA', 'MARTES', 'http://www.pizzeta.es/oferta0001.png', '9', '10-08-2014',  '10-10-2014', '08-04-2014', NULL, '1');
22.	insert into oferta
23.	values ('0002', 'REGALO', 'PIZZA', 'ANIVERSARIO', 'http://www.pizzeta.es/oferta0002.png', '0', '10-02-2014',  '11-02-2014', '08-01-2014', NULL, '1');
24.	
25.	/*Inserta usuarios en las tablas */
26.	insert into usuario
27.	values ('U0000', 'PEDRO', 'CASTRO', 'ROMERO', SYSDATE-365*25, 'M', 'CRUCES, 4',
28.		'MALAGA', 'MALAGA', 29007, 697123456, 'ACC', '@ACC', SYSDATE-410, NULL, '1');
29.	insert into usuario
30.	values ('U0001', 'ANTONIO', 'MERINO', 'LUQUE', SYSDATE-365*22, 'H', 'CARRETERO, 4',
31.		'MALAGA', 'MALAGA', 29003, 677123456, 'JCC', '@JCC', SYSDATE-400, NULL, '1');
32.	insert into usuario
33.	values ('U0002', 'FRANCISCA', 'LEAL', 'VILLATORO', SYSDATE-365*19-100, 'H', 'GONDOMAR, 11',
34.		'CORDOBA', 'CORDOBA', 14003, 617123456, 'ASG', '@ASG', SYSDATE-390, NULL, '1');
35.	insert into usuario
36.	values ('U0003', 'VANESA', 'CRUZ', 'PORTILLO', SYSDATE-365*39-33, 'M', 'REAL, 21',
37.		'CASTRO DEL RIO', 'CORDOBA', 14321, 677112233, NULL, NULL, SYSDATE-380, NULL, '1');
38.	insert into usuario
39.	values ('U0004', 'KLEBER', 'VALDIVIESO', 'FAJARDO', SYSDATE-365*27-45, 'H', 'CLAVELES, 2',
40.		'RONDA', 'MALAGA', 29207, 677223344, 'ECT', '@ECT', SYSDATE-370, SYSDATE-20, '0');
41.	insert into usuario
42.	values ('U0005', 'ANTONIO', 'CAZALLA', 'REYES', SYSDATE-365*27, 'M', 'ALDERETES, 15',
43.		'CORDOBA', 'CORDOBA', 14004, 677334455, 'SHV', '@SHV', SYSDATE-360, NULL, '1');
44.	insert into usuario
45.	values ('U0006', 'ROBERTO', 'GALLARDO', 'MORENO', SYSDATE-365*19-27, 'H', 'QUESO, 2',
46.		'CORDOBA', 'CORDOBA', 14008, 677445566, 'JGL', '@JGL', SYSDATE-350, SYSDATE-121, '0');
47.	insert into usuario
48.	values ('U0007', 'JOAQUINA', 'SERRANO', 'MONEDERO', SYSDATE-365*28-12, 'M', 'QUINTANAR, 11',
49.		'POSADAS', 'CORDOBA', 14302, 677556677, 'JMBM', '@JMBM', SYSDATE-340, SYSDATE-25, '0');
50.	insert into usuario
51.	values ('U0008', 'GASPAR', 'REYES', 'MELERO', SYSDATE-365*19-65, 'H', 'PALOMAS, 22',
52.		'ANTEQUERA', 'MALAGA', 29220, 677667788, NULL, NULL, SYSDATE-330, NULL, '1');
53.	insert into usuario
54.	values ('U0009', 'DAVID', 'BISBAL', 'CONTRERAS', SYSDATE-365*44, 'M', 'MADRID, 33',
55.		'BAEZA', 'JAEN', 23403, 722112233, 'SMB', '@SMB', SYSDATE-320, SYSDATE-79, '0');
56.	insert into usuario
57.	values ('U1010', 'DAVID', 'BUSTAMANTE', 'MORA', SYSDATE-365*24-100, 'H', 'BARRILES, 4',
58.		'BAEZA', 'JAEN', 23403, 677778899, 'MCC', '@MCC', SYSDATE-310, NULL, '1');
59.	insert into usuario
60.	values ('U1011', 'RISTO', 'MEJIDE', 'HURTADO', SYSDATE-365*21, 'M', NULL,
61.		'BAEZA', 'JAEN', 23403, 611987654, 'MCH', '@MCH', SYSDATE-300, SYSDATE-2, '0');
62.	insert into usuario
63.	values ('U1012', 'JUANA', 'RIVAS', 'NAVAS', SYSDATE-365*33-33, 'H', 'QUINTANAR, 7',
64.		'JAEN', 'JAEN', 23006, 611111111, 'VLO', '@VLO', SYSDATE-290, NULL, '1');
65.	insert into usuario
66.	values ('U1013', 'CARLA', 'BRUNI', 'ARBELOA', SYSDATE-365*25-25, 'M', NULL,
67.		NULL, NULL, NULL, 677123456, NULL, NULL, SYSDATE-280, NULL, '1');
68.	insert into usuario
69.	values ('U1014', 'ALBERTO', 'HENS', 'MAGDALENO', SYSDATE-365*34-14, 'H', 'BASTIDORES, 6',
70.		'JAEN', 'JAEN', 23006, 6112222, 'ILI', '@ILI', SYSDATE-270, NULL, '1');
