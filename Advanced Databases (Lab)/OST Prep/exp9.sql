create table frand
(
	name_ text,
	age int,
	roll_no int
);

drop type frand

insert into frand
values('Aarya',23,1),
('Dhairya',12,2),
('Dhruv',123,3),
('Rohan',153,4),
('Gonk',12,5);

select name_ , roll_no , sum(age) as SUM__
from frand
group by rollup(name_,roll_no);

select name_ , roll_no , sum(age) as SUM__
from frand
group by cube(name_,roll_no);