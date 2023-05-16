create table frands
(
	roll_no serial primary key,
	frand_data json
);
drop table frands;

Insert into frands(frand_data) 
values('{"Name": "Aarya" , "info" : {"age":9,"DOB":123,"bg":"B+"}}'),
('{"Name": "Dhairya" , "info" : {"age":1,"DOB":123,"bg":"A+"}}'),
('{"Name": "Pratham" , "info" : {"age":41,"DOB":234,"bg":"O+"}}'),
('{"Name": "Dhruv" , "info" : {"age":12,"DOB":2313,"bg":"A-"}}'),
('{"Name": "Rohan" , "info" : {"age":36,"DOB":124,"bg":"O-" , "height":"173cm"}}');

select * from frands;
select frand_data ->> 'Name' as Name
from frands;

select frand_data -> 'info' ->> 'age' as age
from frands;

COPY(SELECT * FROM frands) TO 'D:\Github\SEM4\Advanced Databases (Lab)\EXP 6\exp6_1.csv';
