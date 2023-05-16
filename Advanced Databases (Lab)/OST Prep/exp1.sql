create table library_
(
	shelf int,
	ISBN int PRIMARY KEY
);
create table library2_
(
	shelf int,
	ISBN int PRIMARY KEY
);
insert into library_ 
values(1+random()*10, generate_series(201,50000000));

-- Analyzing the Query
explain analyse select sum(shelf) from library_  

-- Checking maximum workers assigned to the job
show max_parallel_workers_per_gather;

-- Setting maximum workers assigned to the job from 2 to 8
set max_parallel_workers_per_gather to 8;

-- Analyzing the Query again
explain analyse select sum(shelf) from library_

explain analyse select library1.id,library1.quantity,library2.location from library2,library1 
where library1.id=library2.id; 
SET max_parallel_workers_per_gather TO 3; 
explain analyse select library1.id,library1.quantity,library2.location from library2,library1 
where library1.id=library2.id; 