--  Create a database as institutes with id and dept and using json input id, name, start_yr
-- under dept category. Add 5 attributes. Sort in decreasing order of id wrt start_yr

create table institutes
(
	id_ int primary key,
	dept json
);

drop table institutes;

INSERT INTO institutes
values(1,'{"id_":2,"name":"Aarya","start_yr":2003,"under_dept":"MECH"}'),
(2,'{"id_":3,"name":"Dhairya","start_yr":2004,"under_dept":"IT"}'),
(3,'{"id_":4,"name":"Dhruv","start_yr":2005,"under_dept":"COMPS"}'),
(4,'{"id_":5,"name":"Awhad","start_yr":2006,"under_dept":"EXTC"}');

select dept->>'id_' as ID_ , dept->>'start_yr' as start_year 
from institutes
order by dept->>'start_yr' DESC; 
