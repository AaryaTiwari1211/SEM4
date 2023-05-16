-- Create a database from 70k entries and calculate the mobile bill. No attributes or method
-- of solving was given so make a function that takes in the data and does the calculation.
-- Also show no of processors used and analytics of the program (Exp 1)

create table mobile
(
	id_ serial primary key,
	cost_per_min int,
	time_per_min int
);

select id_ , total_bill(cost_per_min,time_per_min) as bill
from mobile;

select * from mobile;

Insert into mobile
values(generate_series(1,70000),random()*100,random()*10);

create or replace function total_bill(x1 int , x2 int) RETURNS int as $$ 
BEGIN
RETURN (x1*x2);
END;
$$ LANGUAGE plpgsql;

explain analyse select * from mobile;


Insert into bill
select(generate_series(1,70000),total_bill(random()*100,random()*10))
from mobile;


show max_parallel_workers_per_gather;
set max_parallel_workers_per_gather to 10;