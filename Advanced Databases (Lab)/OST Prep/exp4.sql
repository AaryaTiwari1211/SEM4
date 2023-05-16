create type Complex as
(
	real_ int,
	imag_ int
);

create or replace function real_addition(r1 int,r2 int) returns int as $$
BEGIN
RETURN (r1+r2);
END;
$$ LANGUAGE plpgsql;

create or replace function imag_addition(r3 int,r4 int) returns int as $$
BEGIN
RETURN (r3+r4);
END;
$$ LANGUAGE plpgsql;

create table numbers
(
	number_ Complex
);

select * from numbers;

insert into numbers values((0,1));
insert into numbers values((2,3));
insert into numbers values((real_addition(0,2),imag_addition(1,3)));
insert into numbers values((0,1));
insert into numbers values((0,1));
