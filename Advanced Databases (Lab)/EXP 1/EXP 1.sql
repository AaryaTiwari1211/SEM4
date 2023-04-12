
-- Creating Table Ledger
create table ledger 
( 
	id serial primary key, 
	date date not null, 
	amount decimal(12,2)  not null 
); 
-- Generating values for 500000000 values
insert into ledger (date, amount) 
select current_date - (random() * 3650)::integer, (random() * 1000000)::decimal(12,2) - 
50000 from generate_series(1,50000000); 

select * from ledger;

-- Analyzing the query
explain analyze select sum(amount)  from ledger;

-- Checking the maximum parallel workers 
show max_parallel_workers_per_gather;

-- Setting new value for maximum parallel workers
set max_parallel_workers_per_gather to 4;

explain analyze select sum(amount)  from ledger; 